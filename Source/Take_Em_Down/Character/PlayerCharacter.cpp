// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "Take_Em_Down/Character/PlayerComponents/CombatComponent.h"
#include "Take_Em_Down/Character/Player_Anim/PlayerAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "GroomComponent.h"
// Sets default values
APlayerCharacter::APlayerCharacter() :MouseAimLookUpRate(0.2f), MouseHipTurnRate(1.0f),bIsSprinting(false),
MouseHipLookUpRate(1.0f), MouseAimTurnRate(0.2f),TurinngInPlace(ETurningInPlace::ETIP_NotTuring), CameraThreshold(100.f)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 130.0f), FRotator(0.f, 90.0f, 0.f));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(CameraBoom);
	Camera->SetActive(true);
	CameraBoom->TargetArmLength = 250.f;
	CameraBoom->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;


	CombatComponent = CreateDefaultSubobject<UCombatComponent>("Combat");
	CombatComponent->SetIsReplicated(true);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.0f), FRotator(0.f, -90.0f, 0.f));
	GetCharacterMovement()->JumpZVelocity = 350.f;
	GetCharacterMovement()->MaxWalkSpeed = CombatComponent->BaseWalkWalkSpeed;
	GetCharacterMovement()->AirControl = 0.3f;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 200.f;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	NetUpdateFrequency = 66.f;
	MinNetUpdateFrequency = 33.f;
}
// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::HideCharacterWhileOverlapping()
{
	if (!IsLocallyControlled()) return;
	if ((Camera->GetComponentLocation() - GetActorLocation()).Size() < CameraThreshold)
	{
		GetMesh()->SetVisibility(false);
		GetFace()->SetVisibility(false);
		GetTorso()->SetVisibility(false);
		GetFeet()->SetVisibility(false);
		GetLegs()->SetVisibility(false);
		GetHair()->SetVisibility(false);
		GetEyelashes()->SetVisibility(false);
		GetEyebrows()->SetVisibility(false);
		GetMustache()->SetVisibility(false);
		GetBeard()->SetVisibility(false);
		if (CombatComponent && CombatComponent->EquipedWeapon && CombatComponent->EquipedWeapon->GetWeaponMesh())
		{
			CombatComponent->EquipedWeapon->GetWeaponMesh()->bOwnerNoSee = true;
		}
	}
	else
	{
		GetMesh()->SetVisibility(true);
		GetFace()->SetVisibility(true);
		GetTorso()->SetVisibility(true);
		GetFeet()->SetVisibility(true);
		GetLegs()->SetVisibility(true);
		GetHair()->SetVisibility(true);
		GetEyelashes()->SetVisibility(true);
		GetEyebrows()->SetVisibility(true);
		GetMustache()->SetVisibility(true);
		GetBeard()->SetVisibility(true);	
		if (CombatComponent && CombatComponent->EquipedWeapon && CombatComponent->EquipedWeapon->GetWeaponMesh())
		{
			CombatComponent->EquipedWeapon->GetWeaponMesh()->bOwnerNoSee = false;
		}
	}
}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimOffset(DeltaTime);
	HideCharacterWhileOverlapping();
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(APlayerCharacter, OverlappingWeapon, COND_OwnerOnly);
}

void APlayerCharacter::MoveForward(float value)
{
	if ((Controller != nullptr) && (value != 0))
	{
		const FRotator ControllerRotation = Controller->GetControlRotation();
		const FRotator Controller_Yaw = FRotator(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix{ Controller_Yaw }.GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if ((Controller != nullptr) && (value != 0))
	{
		const FRotator ControllerRotation = Controller->GetControlRotation();
		const FRotator Controller_Yaw = FRotator(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix{ Controller_Yaw }.GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::Turn(float value)
{
	float TurnScaleFactor{};
	if (CombatComponent->bAiming)
	{
		TurnScaleFactor = MouseAimTurnRate;
	}
	else
	{
		TurnScaleFactor = MouseHipTurnRate;
	} AddControllerYawInput(value * TurnScaleFactor);
}

void APlayerCharacter::LookUp(float value)
{
	float LookUpScaleFactor{};
	if (CombatComponent->bAiming)
	{
		LookUpScaleFactor = MouseAimLookUpRate;
	}
	else
	{
		LookUpScaleFactor = MouseHipLookUpRate;
	} AddControllerPitchInput(value * LookUpScaleFactor);
}

void APlayerCharacter::Sprint()
{
	if (bIsSprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed = 300.f;
		if (!HasAuthority())
		{
			Ser_SprintButtonPressed(300.f);
		}
		bIsSprinting = false;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.f;
		if (!HasAuthority())
		{
			Ser_SprintButtonPressed(600.f);
		}
		bIsSprinting = true;
	}
}


void APlayerCharacter::AimingButtonPressed()
{
	if (CombatComponent)
	{
		CombatComponent->SetAiming(true);
	}
}

void APlayerCharacter::AimingButtonReleased()
{
	if (CombatComponent)
	{
		CombatComponent->SetAiming(false);
	}
}

void APlayerCharacter::SelectPressed()
{
	if (CombatComponent)
	{
		CombatComponent->EquipWeapon(OverlappingWeapon);
		Ser_SelectButtonPressed();//ServerEquipButtonPressed
	  /*if (HasAuthority())
		{
			CombatComponent->EquipWeapon(OverlappingWeapon);
			GEngine->AddOnScreenDebugMessage(2, 4, FColor::Black, FString("Server Da"));
		}
		else
		{
			Ser_SelectButtonPressed();//ServerEquipButtonPressed
		}*/
	}
}

void APlayerCharacter::FireButtonPressed()
{
	if (CombatComponent)
	{
		CombatComponent->FireButtonPressed(true);
	}
}

void APlayerCharacter::FireButtonReleased()
{
	if (CombatComponent)
	{
		CombatComponent->FireButtonPressed(false);
	}
}

void APlayerCharacter::CrouchButtonPressed()
{
	if (bIsCrouched)
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}

void APlayerCharacter::AimOffset(float DeltaTime)
{
	if (CombatComponent && !CombatComponent->EquipedWeapon) return;
	FVector Velocity = GetVelocity();
	Velocity.Z = 0.f;
	float Speed = Velocity.Size();
	bool bInAir = GetCharacterMovement()->IsFalling();
	if (Speed == 0.f && !bInAir) // Standing Not Jumping
	{
		FRotator CurrentAimRotation = FRotator(0.f, GetBaseAimRotation().Yaw, 0.f);
		FRotator DeltaRotation = UKismetMathLibrary::NormalizedDeltaRotator(CurrentAimRotation, StartingAimRotation);
		AO_Yaw = DeltaRotation.Yaw;
		if (TurinngInPlace == ETurningInPlace::ETIP_NotTuring)
		{
			Interp_AO_Yaw = AO_Yaw;
		}
		bUseControllerRotationYaw = true;
		TurnInPlace(DeltaTime);
	}
	if (Speed > 0.f || bInAir) // Running And Jumping
	{
		StartingAimRotation = FRotator(0.f, GetBaseAimRotation().Yaw, 0.f);
		AO_Yaw = 0.f;
		bUseControllerRotationYaw = true;
		TurinngInPlace = ETurningInPlace::ETIP_NotTuring;
	}
	AO_Pitch = GetBaseAimRotation().Pitch;
	if (AO_Pitch > 90.f && !IsLocallyControlled())
	{
		// map the Range [270,360] to [-90,0]
		FVector2D InRange(270.f, 360.f);
		FVector2D OutRange(-90.f, 0.f);
		AO_Pitch = FMath::GetMappedRangeValueClamped(InRange, OutRange,AO_Pitch);
	}
	UE_LOG(LogTemp, Warning, TEXT("Pitch %f"), AO_Pitch);
}

void APlayerCharacter::TurnInPlace(float DeltaTime)
{
	if (AO_Yaw > 90.f)
	{
		TurinngInPlace = ETurningInPlace::ETIP_Right;
	}
	else if (AO_Yaw < -90.f)
	{
		TurinngInPlace = ETurningInPlace::ETIP_Left;
	}
	if (TurinngInPlace != ETurningInPlace::ETIP_NotTuring)
	{
		Interp_AO_Yaw = FMath::FInterpTo(Interp_AO_Yaw, 0.f, DeltaTime, 4.f);
		AO_Yaw = Interp_AO_Yaw;
		if (FMath::Abs(AO_Yaw) < 15.f)
		{
			TurinngInPlace = ETurningInPlace::ETIP_NotTuring;
			StartingAimRotation = FRotator(0.f, GetBaseAimRotation().Yaw, 0.f);
		}
	}
}


void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (CombatComponent)
	{
		CombatComponent->ACT = this;
	}
}

void APlayerCharacter::PlayFireMontage(bool bInAiming)
{
	if (!CombatComponent || !CombatComponent->EquipedWeapon) return;
	UAnimInstance* AnimIns = GetMesh()->GetAnimInstance();
	if (AnimIns && FireWeaponMontage)
	{
		AnimIns->Montage_Play(FireWeaponMontage);
		FName SectionName;
		SectionName = bInAiming ? FName("Rifle_Aim") : FName("Rifle_Hip");
		AnimIns->Montage_JumpToSection(SectionName);
	}
}

void APlayerCharacter::OnRep_OnerlappingWeapon(AWeapon* LastWeapon)
{
	if (OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickUpWidget(true);
	}
	if (LastWeapon)
	{
		LastWeapon->ShowPickUpWidget(false);
	}
}

void APlayerCharacter::Multi_SelectButtonPressed_Implementation()
{
	if (CombatComponent)
	{
		CombatComponent->EquipWeapon(OverlappingWeapon);
	}
}

void APlayerCharacter::SetOverlappingWeapon(TObjectPtr<AWeapon> InWeapon)
{
	if (OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickUpWidget(false);
	}
	OverlappingWeapon = InWeapon;
	if (IsLocallyControlled())
	{
		if (OverlappingWeapon)
		{
			OverlappingWeapon->ShowPickUpWidget(true);
		}
	}
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Blue, FString("Condition"));
}

void APlayerCharacter::PlayHitReactMontage()
{
	if (!CombatComponent || !CombatComponent->EquipedWeapon) return;
	UAnimInstance* AnimIns = GetMesh()->GetAnimInstance();
	if (AnimIns && HitReactMontage)
	{
		AnimIns->Montage_Play(HitReactMontage);
		FName SectionName = FName("FromCenter");
		AnimIns->Montage_JumpToSection(SectionName);
	}
}

bool APlayerCharacter::IsWeaponEquiped()
{

	return (CombatComponent && CombatComponent->EquipedWeapon);
}

bool APlayerCharacter::IsAiming()
{

	return (CombatComponent && CombatComponent->bAiming);
}

TObjectPtr<AWeapon> APlayerCharacter::GetEquipedWeapon()
{
	if (!CombatComponent) return nullptr;
	return CombatComponent->EquipedWeapon;

}

FVector APlayerCharacter::GetHitTarget() const
{
	if (!CombatComponent) return FVector();
	return CombatComponent->HitTarget;
}




void APlayerCharacter::Ser_SelectButtonPressed_Implementation()//ServerEquipButtonPressed
{
	Multi_SelectButtonPressed();
}

void APlayerCharacter::Ser_SprintButtonPressed_Implementation(float Speed)
{
		GetCharacterMovement()->MaxWalkSpeed = Speed;
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::AimingButtonPressed);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::AimingButtonReleased);
	PlayerInputComponent->BindAction("E", IE_Pressed, this, &APlayerCharacter::SelectPressed);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::FireButtonPressed);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::FireButtonReleased);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::CrouchButtonPressed);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}


