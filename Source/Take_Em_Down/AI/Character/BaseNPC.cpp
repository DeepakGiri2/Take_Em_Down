// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
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

void ABaseNPC::ITakeDamage(FHitResult InHit)
{
	if (P_BloodParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_BloodParticle, InHit.Location, FRotator(0.f, 0.f, 0.f));
	}
	float TempHelath = GetHealth() - 25;
	SetHealth(TempHelath);
	if (GetHealth() <= 0)
	{
		UnPossessed();
		GetMesh()->SetSimulatePhysics(true);
	}
}

ETurningInPlace ABaseNPC::GetTurningInPlace()
{
	return ETurningInPlace();
}

ABaseNPC::ABaseNPC()
{

}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}

void ABaseNPC::EquipeWeapon(TObjectPtr<class AWeapon> WeaponToEquip)
{
	if (!WeaponToEquip) return;
	EquipedWeapon = WeaponToEquip;
	EquipedWeapon->SetWeaponState(EWeaponState::EWS_Equiped);
	const USkeletalMeshSocket* RightHandSocket = GetMesh()->GetSocketByName(FName("AI_RHS"));
	if (RightHandSocket)
	{
		RightHandSocket->AttachActor(EquipedWeapon, GetMesh());
	}
	EquipedWeapon->SetOwner(this);
	GetCharacterMovement()->bOrientRotationToMovement = false;
	bUseControllerRotationYaw = true;
}

void ABaseNPC::SpawnWeapon()
{
	AWeapon* TempWeapon = GetWorld()->SpawnActor<AWeapon>(ActWeapon);
	EquipeWeapon(TempWeapon);
}
