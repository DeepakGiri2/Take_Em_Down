// Fill out your copyright notice in the Description page of Project Settings.


#include "AICombatComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Take_Em_Down/AI/Character/BaseNPC.h"

// Sets default values for this component's properties
UAICombatComponent::UAICombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAICombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAICombatComponent::SetAiming(bool bIsAiming)
{
	bAiming = bIsAiming;
	Ser_SetAiming(bIsAiming);
	if (ACT)
	{
		ACT->GetCharacterMovement()->MaxWalkSpeed = bIsAiming ? AimWalkWalkSpeed : BaseWalkWalkSpeed;
	}
}


// Called every frame
void UAICombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ACT && ACT->IsLocallyControlled())
	{
		if (!EquipedWeapon) return;
		FHitResult HitResult;
		TraceFormSocketLocation(HitResult);
		HitTarget = HitResult.ImpactPoint;
	}
	// ...
}

void UAICombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAICombatComponent, EquipedWeapon);
	DOREPLIFETIME(UAICombatComponent, bAiming);
}

void UAICombatComponent::StartFireTimer()
{
	if (!EquipedWeapon || !ACT) return;
	ACT->GetWorldTimerManager().SetTimer(FireTimer, this, &UAICombatComponent::FireTimerCompleted, EquipedWeapon->FireDelay);
}

void UAICombatComponent::FireTimerCompleted()
{
	bCanFire = true;
	if (bFireButtonPressed && EquipedWeapon->bAutomatic)
	{
		Fire();
	}
}

void UAICombatComponent::EquipWeapon(TObjectPtr<AWeapon> WeaponToEquip)
{
	if (!WeaponToEquip) return;
	EquipedWeapon = WeaponToEquip;
	EquipedWeapon->SetWeaponState(EWeaponState::EWS_Equiped);
	const USkeletalMeshSocket* RightHandSocket = ACT->GetMesh()->GetSocketByName(FName("AI_RHS"));
	if (RightHandSocket)
	{
		RightHandSocket->AttachActor(EquipedWeapon, ACT->GetMesh());
	}
	EquipedWeapon->SetOwner(ACT);
	ACT->GetCharacterMovement()->bOrientRotationToMovement = false;
	ACT->bUseControllerRotationYaw = true;
}

void UAICombatComponent::Ser_SetAiming_Implementation(bool bIsAiming)
{
	bAiming = bIsAiming;
	if (ACT)
	{
		ACT->GetCharacterMovement()->MaxWalkSpeed = bIsAiming ? AimWalkWalkSpeed : BaseWalkWalkSpeed;
	}
}

void UAICombatComponent::OnRep_EquipedWeapon()
{
	if (EquipedWeapon && ACT)
	{
		ACT->GetCharacterMovement()->bOrientRotationToMovement = false;
		ACT->bUseControllerRotationYaw = true;
	}
}

void UAICombatComponent::FireButtonPressed(bool bPressed)
{
	bFireButtonPressed = bPressed;
	if (bFireButtonPressed)
	{
		Fire();
	}
}

void UAICombatComponent::Fire()
{
	if (bCanFire)
	{
		bCanFire = false;
		Ser_Fire(HitTarget);
		StartFireTimer();
	}
}

void UAICombatComponent::TraceFormSocketLocation(FHitResult& HitResult)
{
	if (EquipedWeapon)
	{
		FVector Start = EquipedWeapon->GetWeaponMesh()->GetSocketLocation(FName("MuzzleFlash"));
		FVector End = Start + EquipedWeapon->GetWeaponMesh()->GetForwardVector() * 80000;

		GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel2);
		if (!HitResult.bBlockingHit)
		{
			HitResult.ImpactPoint = End;
		}


	}

}

void UAICombatComponent::Multi_Fire_Implementation(const FVector_NetQuantize& HitLocation)
{
	if (!EquipedWeapon) return;
	if (ACT)
	{
		ACT->PlayFireMontage(bAiming);
		EquipedWeapon->Fire(HitLocation);
	}
}

void UAICombatComponent::Ser_Fire_Implementation(const FVector_NetQuantize& HitLocation)
{
	Multi_Fire(HitLocation);
}
