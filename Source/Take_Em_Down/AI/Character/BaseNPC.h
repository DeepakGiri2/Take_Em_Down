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
	bool IsWeaponEquiped();
	bool IsAiming();
	ETurningInPlace GetTurningInPlace();
	ABaseNPC();
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeapon> ActWeapon;
protected:
	virtual void BeginPlay() override;
public:
	bool bIsCrouched;
private:
	void EquipeWeapon(TObjectPtr<AWeapon> WeaponToEquip);
	void SpawnWeapon();
private:
	TObjectPtr<AWeapon> EquipedWeapon;
public:
	FORCEINLINE TObjectPtr<AWeapon> GetEquipedWeapon() const { return EquipedWeapon; }
};
