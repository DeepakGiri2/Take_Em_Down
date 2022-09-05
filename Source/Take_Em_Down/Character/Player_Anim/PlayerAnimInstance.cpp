// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Take_Em_Down/Weapons/Weapon.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ACT = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (ACT == nullptr)
	{
		ACT = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
	if (ACT == nullptr) return;
	FVector Velocity = ACT->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();
	bIsInAir = ACT->GetCharacterMovement()->IsFalling();
	bIsAccelerating = ACT->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	bIsEqupiedWeapon = ACT ->IsWeaponEquiped();
	EquipedWeapon = ACT->GetEquipedWeapon();
	bIsCrouched = ACT->bIsCrouched;
	bAiming = ACT->IsAiming();
	TurinngInPlace = ACT->GetTurningInPlace();
	

	//YawOffset
	FRotator AimRotation = ACT->GetBaseAimRotation();
	FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(ACT->GetVelocity());
	FRotator DeltaRot = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation);
	DeltaRotation = FMath::RInterpTo(DeltaRotation, DeltaRot, DeltaTime, 6.f);
	YawOffset = DeltaRotation.Yaw;

	//Lean
	ACTRotaionLastFrame = ACTRotaion;
	ACTRotaion = ACT->GetActorRotation();
	const FRotator Delta = UKismetMathLibrary::NormalizedDeltaRotator(ACTRotaion, ACTRotaionLastFrame);
	const float Target = Delta.Yaw / DeltaTime;
	const float Interp = FMath::FInterpTo(Lean, Target,DeltaTime,6.f);
	Lean = FMath::Clamp(Interp,-90.f,90.f);
	AO_Yaw = ACT->GetAO_Yaw();
	AO_Pitch = ACT->GetAO_Pitch();
	if (bIsEqupiedWeapon && EquipedWeapon && EquipedWeapon->GetWeaponMesh())
	{
		LeftHandTransform = EquipedWeapon->GetWeaponMesh()->GetSocketTransform(FName("LHS"), ERelativeTransformSpace::RTS_World);
		FVector OutLoc;
		FRotator OutRot;
		ACT->GetMesh()->TransformToBoneSpace(FName("hand_r"), LeftHandTransform.GetLocation(), FRotator::ZeroRotator, OutLoc, OutRot);
		LeftHandTransform.SetLocation(OutLoc);
		LeftHandTransform.SetRotation(FQuat(OutRot));
	}
}