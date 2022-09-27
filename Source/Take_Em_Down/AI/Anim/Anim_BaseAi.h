// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Take_Em_Down/playerStates/TurnInPlace.h"
#include "Anim_BaseAi.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API UAnim_BaseAi : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class ABaseNPC> ACT;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float Speed;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
		bool bIsEqupiedWeapon;

	UPROPERTY()
		TObjectPtr <class AWeapon> EquipedWeapon;

	UPROPERTY(BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
		bool bIsCrouched;
	UPROPERTY(BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
		bool bAiming;
	UPROPERTY(BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
		ETurningInPlace TurinngInPlace;
};
