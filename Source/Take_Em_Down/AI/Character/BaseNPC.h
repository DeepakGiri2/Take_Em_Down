// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Take_Em_Down/Character/BaseCharacter.h"
#include "Take_Em_Down/playerStates/TurnInPlace.h"
#include "BaseNPC.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API ABaseNPC : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABaseNPC();
	bool IsWeaponEquiped();
	bool IsAiming();
	void PlayFireMontage(bool bInAiming);
	virtual void ITakeDamage(FHitResult InHit, FRotator InRotation = FRotator(0.f, 0.f, 0.f)) override;
	ETurningInPlace GetTurningInPlace();
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeapon> ActWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UParticleSystem> P_BloodParticle;
protected:
	virtual void BeginPlay() override;
public:
	bool bIsCrouched;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Comps, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAICombatComponent> CombatComponent;
	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<class UAnimMontage> FireWeaponMontage;
private:
	void SpawnWeapon();
private:
	TObjectPtr<AWeapon> EquipedWeapon;
public:
	FORCEINLINE TObjectPtr<AWeapon> GetEquipedWeapon() const { return EquipedWeapon; }
};
