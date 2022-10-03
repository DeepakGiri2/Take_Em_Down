// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Take_Em_Down/AI/Components/AICombatComponent.h"
bool ABaseNPC::IsWeaponEquiped()
{
	if (EquipedWeapon)
	{
		return true;
	}
  return false;
}

bool ABaseNPC::IsAiming()
{
	return false;
}

void ABaseNPC::PlayFireMontage(bool bInAiming)
{
}

void ABaseNPC::ITakeDamage(FHitResult InHit ,FRotator InRotation)
{
	if (P_BloodParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_BloodParticle, InHit.Location, InRotation);
	}
	float TempHelath = GetHealth() - 25;
	SetHealth(TempHelath);
	if (GetHealth() <= 0)
	{
	}
}

ETurningInPlace ABaseNPC::GetTurningInPlace()
{
	return ETurningInPlace();
}

ABaseNPC::ABaseNPC()
{
	CombatComponent = CreateDefaultSubobject<UAICombatComponent>("AiCombat");
}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}

void ABaseNPC::SpawnWeapon()
{
	AWeapon* TempWeapon = GetWorld()->SpawnActor<AWeapon>(ActWeapon);
	if (CombatComponent)
	{
		CombatComponent->EquipWeapon(TempWeapon);
	}
}
