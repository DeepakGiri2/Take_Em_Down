// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim_BaseAi.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Take_Em_Down/AI/Character/BaseNPC.h"
#include "Kismet/KismetMathLibrary.h"
#include "Take_Em_Down/Weapons/Weapon.h"

void UAnim_BaseAi::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ACT = Cast<ABaseNPC>(TryGetPawnOwner());
}

void UAnim_BaseAi::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (ACT == nullptr)
	{
		ACT = Cast<ABaseNPC>(TryGetPawnOwner());
	}
	if (ACT == nullptr) return;
	FVector Velocity = ACT->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();
	bIsInAir = ACT->GetCharacterMovement()->IsFalling();
	bIsAccelerating = ACT->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	bIsEqupiedWeapon = ACT->IsWeaponEquiped();
	EquipedWeapon = ACT->GetEquipedWeapon();
	bIsCrouched = ACT->bIsCrouched;
	bAiming = ACT->IsAiming();
	TurinngInPlace = ACT->GetTurningInPlace();
}
