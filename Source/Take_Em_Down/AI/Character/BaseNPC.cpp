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
	if (CombatComponent->GetEquipedWeapon())
	{
		return true;
	}
  return false;
}

bool ABaseNPC::IsAiming()
{
	if (CombatComponent->GetAiming())
	{
		return true;
	}
	return false;
}

void ABaseNPC::SetAiming(bool InAiming)
{
	if (CombatComponent)
	{
		CombatComponent->SetAiming(InAiming);
	}
}

void ABaseNPC::PlayFireMontage(bool bInAiming)
{
	if (!CombatComponent || !CombatComponent->GetEquipedWeapon()) return;
	UAnimInstance* AnimIns = GetMesh()->GetAnimInstance();
	if (AnimIns && FireWeaponMontage)
	{
		AnimIns->Montage_Play(FireWeaponMontage);
		FName SectionName;
		SectionName = bInAiming ? FName("Rifle_Aim") : FName("Rifle_Hip");
		AnimIns->Montage_JumpToSection(SectionName);
	}
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
		CombatComponent->DetachWeapon();
	}
}

ETurningInPlace ABaseNPC::GetTurningInPlace()
{
	return ETurningInPlace();
}

ABaseNPC::ABaseNPC()
{
	CombatComponent = CreateDefaultSubobject<UAICombatComponent>("AiCombat");
	CombatComponent->ACT = this;
	CombatComponent->SetIsReplicated(true);
	NetUpdateFrequency = 66.f;
	MinNetUpdateFrequency = 33.f;
}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}

void ABaseNPC::SpawnWeapon()
{
	AWeapon* TempWeapon = GetWorld()->SpawnActor<AWeapon>(ActWeapon);
	if (CombatComponent && TempWeapon)
	{
		CombatComponent->EquipWeapon(TempWeapon);
	}
}

TObjectPtr<AWeapon> ABaseNPC::GetEquipedWeapon() const
{
	if (CombatComponent)
	{
		return CombatComponent->GetEquipedWeapon();
	}
	return nullptr;
}
