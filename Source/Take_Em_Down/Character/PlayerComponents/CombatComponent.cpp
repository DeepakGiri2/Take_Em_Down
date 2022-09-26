// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Take_Em_Down/PlayerController/ACTPlayerController.h"
//#include "Take_Em_Down/UI/ACTHUD.h"
// Sets default values for this component's properties
UCombatComponent::UCombatComponent() :bFireButtonPressed(false), bAiming(false),BaseWalkWalkSpeed(300),
AimWalkWalkSpeed(250), ZoomedFOV(30), ZoomInterpSpeed(20),CrosshairAimFactor(0.f),CrosshairFireFactor(0.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (ACT)
	{
		ACT->GetCharacterMovement()->MaxWalkSpeed = BaseWalkWalkSpeed;

		if (ACT->GetFollowCamera())
		{
			DefaultFOV = ACT->GetFollowCamera()->FieldOfView;
			CurrentFOV = DefaultFOV;
			DefaultSocketLocation = ACT->GetCameraBoom()->SocketOffset;
		}
	}
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ACT && ACT->IsLocallyControlled())
	{
		if (!EquipedWeapon) return;
		FHitResult HitResult;
		TraceUnderCrossHairs(HitResult);
		HitTarget = HitResult.ImpactPoint;
		SetHUDCrossHairs(DeltaTime);
		InterpFOV(DeltaTime);
	}
	// ...
}

void UCombatComponent::InterpFOV(float DeltaTime)
{
	if (EquipedWeapon == nullptr) return;

	if (bAiming)
	{
		CurrentFOV = FMath::FInterpTo(CurrentFOV, EquipedWeapon->GetZoomedFOV(), DeltaTime, EquipedWeapon->GetZoomInterpSpeed());
		CurrentSocketLocation = FMath::VInterpTo(CurrentSocketLocation, EquipedWeapon->AimSocketLocation, DeltaTime, EquipedWeapon->GetZoomInterpSpeed());
	}
	else
	{
		CurrentFOV = FMath::FInterpTo(CurrentFOV, DefaultFOV, DeltaTime, ZoomInterpSpeed);
		CurrentSocketLocation = FMath::VInterpTo(CurrentSocketLocation, DefaultSocketLocation, DeltaTime, ZoomInterpSpeed);
	}
	if (ACT && ACT->GetFollowCamera())
	{
		ACT->GetFollowCamera()->SetFieldOfView(CurrentFOV);
		ACT->GetCameraBoom()->SocketOffset = CurrentSocketLocation;
	}
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCombatComponent, EquipedWeapon);
	DOREPLIFETIME(UCombatComponent, bAiming);
}

void UCombatComponent::SetAiming(bool bIsAiming)
{
	bAiming = bIsAiming;
	Ser_SetAiming(bIsAiming);
	if (ACT)
	{
		ACT->GetCharacterMovement()->MaxWalkSpeed = bIsAiming ? AimWalkWalkSpeed : BaseWalkWalkSpeed;
	}
}

void UCombatComponent::Ser_SetAiming_Implementation(bool bIsAiming)
{
	bAiming = bIsAiming;
	if (ACT)
	{
		ACT->GetCharacterMovement()->MaxWalkSpeed = bIsAiming ? AimWalkWalkSpeed : BaseWalkWalkSpeed;
	}
}

void UCombatComponent::OnRep_EquipedWeapon()
{
	if (EquipedWeapon && ACT)
	{
		ACT->GetCharacterMovement()->bOrientRotationToMovement = false;
		ACT->bUseControllerRotationYaw = true;
	}
	
}

void UCombatComponent::FireButtonPressed(bool bPressed)
{
	
	bFireButtonPressed = bPressed;
	if (bFireButtonPressed)
	{
		FHitResult Hit;
		TraceUnderCrossHairs(Hit);
		Ser_Fire(Hit.ImpactPoint);
		if (EquipedWeapon)
		{
			CrosshairFireFactor = 0.95f;
		}
	}
}

void UCombatComponent::TraceUnderCrossHairs(FHitResult& TraceHit)
{
	FVector2D ViewportSize;
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}
	FVector2D CrosshairLocation(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);
	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0),	CrosshairLocation,	CrosshairWorldPosition,	CrosshairWorldDirection);

	if (bScreenToWorld)
	{
		FVector Start = CrosshairWorldPosition;
		if (ACT)
		{
			float DistanceToCharacter = (ACT->GetActorLocation() - Start).Size();
			Start += CrosshairWorldDirection * (DistanceToCharacter + 15.f);
			DrawDebugBox(GetWorld(), Start, FVector(5.f, 5.f, 5.f), FColor::Magenta);
		}
		FVector End = Start + CrosshairWorldDirection * TRACE_LENGTH;

		GetWorld()->LineTraceSingleByChannel(TraceHit,Start,End,	ECollisionChannel::ECC_GameTraceChannel2);
		if (!TraceHit.bBlockingHit)
		{
			TraceHit.ImpactPoint = End;
		}
		if (TraceHit.GetActor() && TraceHit.GetActor()->Implements<UCrossHairInterface>())
		{
			HUDPackage.CrossHairsColor = FLinearColor::Red;
		}
		else
		{
			HUDPackage.CrossHairsColor = FLinearColor::White;
		}
	}
}

void UCombatComponent::SetHUDCrossHairs(float Deltatime)
{
	if (ACT == nullptr || ACT->Controller == nullptr) return;

	ACTController = ACTController == nullptr ? Cast<AACTPlayerController>(ACT->Controller) : ACTController;
	if (ACTController)
	{
		ACTHUD = ACTHUD == nullptr ? Cast<AACTHUD>(ACTController->GetHUD()) : ACTHUD;
		if (ACTHUD)
		{
			
			if (EquipedWeapon)
			{
				HUDPackage.CrossHairCenter = EquipedWeapon->CrossHairCenter;
				HUDPackage.CrossHairLeft = EquipedWeapon->CrossHairLeft;
				HUDPackage.CrossHairRight = EquipedWeapon->CrossHairRight;
				HUDPackage.CrossHairBottom = EquipedWeapon->CrossHairBottom;
				HUDPackage.CrossHairTop = EquipedWeapon->CrossHairTop;
			}
			else
			{
				HUDPackage.CrossHairCenter = nullptr;
				HUDPackage.CrossHairLeft = nullptr;
				HUDPackage.CrossHairRight = nullptr;
				HUDPackage.CrossHairBottom = nullptr;
				HUDPackage.CrossHairTop = nullptr;
			}
			// Calculate crosshair spread

			// [0, 600] -> [0, 1]
			FVector2D WalkSpeedRange(0.f, ACT->GetCharacterMovement()->MaxWalkSpeed);
			FVector2D VelocityMultiplierRange(0.f, 1.f);
			FVector Velocity = ACT->GetVelocity();
			Velocity.Z = 0.f;

			CrosshairVelocityFactor = FMath::GetMappedRangeValueClamped(WalkSpeedRange, VelocityMultiplierRange, Velocity.Size());

			if (ACT->GetCharacterMovement()->IsFalling())
			{
				CrosshairInAirFactor = FMath::FInterpTo(CrosshairInAirFactor, 2.25f, Deltatime, 2.25f);
			}
			else
			{
				CrosshairInAirFactor = FMath::FInterpTo(CrosshairInAirFactor, 0.f, Deltatime, 30.f);
			}
			if (bAiming && EquipedWeapon)
			{
				CrosshairAimFactor = FMath::FInterpTo(CrosshairAimFactor, -0.5f, Deltatime, EquipedWeapon->GetZoomInterpSpeed());
			}
			else
			{
				CrosshairAimFactor = FMath::FInterpTo(CrosshairAimFactor, 0.f, Deltatime, ZoomInterpSpeed);
			}
			CrosshairFireFactor = FMath::FInterpTo(CrosshairFireFactor, 0.f, Deltatime, 45.f);
			HUDPackage.CrosshairSpread = CrosshairVelocityFactor + CrosshairInAirFactor + CrosshairAimFactor + 0.5f + CrosshairFireFactor;

			ACTHUD->SetHudCollection(HUDPackage);
		}
	}
}


void UCombatComponent::Multi_Fire_Implementation(const FVector_NetQuantize& HitLocation)
{
	if (!EquipedWeapon) return;
	if (ACT)
	{
		ACT->PlayFireMontage(bAiming);
		EquipedWeapon->Fire(HitLocation);
	}
}

void UCombatComponent::Ser_Fire_Implementation(const FVector_NetQuantize& HitLocation)
{
	Multi_Fire(HitLocation);
}

void UCombatComponent::EquipWeapon(TObjectPtr<AWeapon> WeaponToEquip)
{
	if (!ACT || !WeaponToEquip) return;
	EquipedWeapon = WeaponToEquip;
	EquipedWeapon->SetWeaponState(EWeaponState::EWS_Equiped);
	const USkeletalMeshSocket* RightHandSocket = ACT->GetMesh()->GetSocketByName(FName("RightHandSocket"));
	if (RightHandSocket)
	{
		RightHandSocket->AttachActor(EquipedWeapon, ACT->GetMesh());
	}
	EquipedWeapon->SetOwner(ACT);
	ACT->GetCharacterMovement()->bOrientRotationToMovement = false;
	ACT->bUseControllerRotationYaw = true;
}


