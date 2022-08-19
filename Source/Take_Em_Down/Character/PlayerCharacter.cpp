// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "Take_Em_Down/Character/PlayerComponents/CombatComponent.h"
// Sets default values
APlayerCharacter::APlayerCharacter() :BaseTurnRate(50.f), BaseLookUpRate(50.f), bAiming(false), HipLookUpRate(90.f), HipTurnRate(90.f), AimLookUpRate(20.f), AimTurnRate(20.f),
MouseHipTurnRate(1.0f), MouseHipLookUpRate(1.0f), MouseAimTurnRate(0.2f), MouseAimLookUpRate(0.2f)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 130.0f), FRotator(0.f, 90.0f, 0.f));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(CameraBoom);
	Camera->SetActive(true);
	CameraBoom->TargetArmLength = 250;
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.0f), FRotator(0.f, -90.0f, 0.f));
	GetCharacterMovement()->JumpZVelocity = 690.f;
	GetCharacterMovement()->MaxWalkSpeed = 450.f;
	GetCharacterMovement()->AirControl = 0.3f;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

	CombatComponent = CreateDefaultSubobject<UCombatComponent>("Combat");
	CombatComponent->SetIsReplicated(true);
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

void APlayerCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookUpRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::Turn(float value)
{
	float TurnScaleFactor{};
	if (bAiming)
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
	if (bAiming)
	{
		LookUpScaleFactor = MouseAimLookUpRate;
	}
	else
	{
		LookUpScaleFactor = MouseHipLookUpRate;
	} AddControllerPitchInput(value * LookUpScaleFactor);
}

void APlayerCharacter::AimingButtonPressed()
{
	bAiming = true;
}

void APlayerCharacter::AimingButtonReleased()
{
	bAiming = false;
}

void APlayerCharacter::SelectPressed()
{
	if (CombatComponent && HasAuthority())
	{
		CombatComponent->EquipWeapon(OverlappingWeapon);
	}
}

void APlayerCharacter::SelectReleased()
{
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(APlayerCharacter, OverlappingWeapon, COND_OwnerOnly);
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (CombatComponent)
	{
		CombatComponent->Character = this;
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
}


// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)
		PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerCharacter::LookUpRate);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::AimingButtonPressed);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::AimingButtonReleased);
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::SelectPressed);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::SelectReleased);
}


