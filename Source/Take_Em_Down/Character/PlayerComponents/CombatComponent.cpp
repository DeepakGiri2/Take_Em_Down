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
// Sets default values for this component's properties
UCombatComponent::UCombatComponent() :bFireButtonPressed(false), bAiming(false),BaseWalkWalkSpeed(300),
AimWalkWalkSpeed(250)
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

		FVector End = Start + CrosshairWorldDirection * TRACE_LENGTH;

		GetWorld()->LineTraceSingleByChannel(TraceHit,Start,End,	ECollisionChannel::ECC_GameTraceChannel2);
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


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCombatComponent, EquipedWeapon);
	DOREPLIFETIME(UCombatComponent, bAiming);
}

