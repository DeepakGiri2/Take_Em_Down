// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Take_Em_Down/playerStates/TurnInPlace.h"
#include "PlayerCharacter.generated.h"

/**
 *
 */
UCLASS()
class TAKE_EM_DOWN_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	APlayerCharacter();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnRep_ReplicatedMovement() override;

	// Movement
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
	void Sprint();
	// Movement

	//FiringStuff
	void AimingButtonPressed();
	void AimingButtonReleased();
	void SelectPressed();
	void FireButtonPressed();
	void FireButtonReleased();
	void CrouchButtonPressed();
	//FiringStuff

	//AnimationBp
	void AimOffset(float DeltaTime);
	void CalculateAO_Pitch();
	void TurnInPlace(float DeltaTime);
	void SimulatedProxyTurn();
	float CalculateSpeed();
	//Animation BP

	//CameraHide
	void HideCharacterWhileOverlapping();
	//CameraHide

	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UCameraComponent> Camera;

	//Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsSprinting;

	UPROPERTY()
	float MouseAimLookUpRate;

	UPROPERTY()
	float MouseHipTurnRate;

	UPROPERTY()
		float MouseAimTurnRate;

	UPROPERTY()
		float MouseHipLookUpRate;
	
	//
	UPROPERTY(ReplicatedUsing = OnRep_OnerlappingWeapon)
	 TObjectPtr<class AWeapon> OverlappingWeapon;

	UFUNCTION()
	void OnRep_OnerlappingWeapon(AWeapon* LastWeapon);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCombatComponent> CombatComponent;

	UFUNCTION(Server,Reliable)
	void Ser_SelectButtonPressed();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_SelectButtonPressed();

	UFUNCTION(Server, Reliable)
		void Ser_SprintButtonPressed(float Speed);
	float AO_Yaw;
	float Interp_AO_Yaw;
	float AO_Pitch;
	FRotator StartingAimRotation;
	ETurningInPlace TurinngInPlace;


	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<class UAnimMontage> FireWeaponMontage;
	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(EditAnywhere)
		float CameraThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UParticleSystem> P_BloodParticle;
	//Simulated Proxy Rotation
	bool m_bRotateRootBone;
	float m_TurnThreshold = 0.5f;
	FRotator m_ProxyRotationLastFrame;
	FRotator m_ProxyRotation;
	float m_ProxyYaw;
	float m_TimeSinceLastMovementReplication;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PostInitializeComponents() override;

	void PlayFireMontage(bool bInAiming);

	void PlayHitReactMontage();

	void SetOverlappingWeapon(TObjectPtr<AWeapon> InWeapon);
	
	//Anim blurprint
	bool IsWeaponEquiped();

	bool IsAiming();

	// CrossHair Interface Implemetation 

	virtual void ITakeDamage(FHitResult InHit,FRotator InRotation = FRotator(0.f, 0.f, 0.f)) override;

	FORCEINLINE TObjectPtr<USpringArmComponent> GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE TObjectPtr < UCameraComponent> GetCamera() const { return Camera; }

	FORCEINLINE TObjectPtr<AWeapon> GetOverlappingWeapon() const { return OverlappingWeapon; }

	FORCEINLINE float GetAO_Yaw() const { return AO_Yaw; }

	FORCEINLINE float GetAO_Pitch() const { return AO_Pitch; }

	FORCEINLINE ETurningInPlace GetTurningInPlace() const { return TurinngInPlace; }

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return Camera; }

	FORCEINLINE bool GetIsServer() const { return !IsLocallyControlled(); }
	FORCEINLINE bool GetShouldRotateRootBone() const{ return m_bRotateRootBone; }

	TObjectPtr <AWeapon> GetEquipedWeapon();

	/* Aim At Correct Direction */
	FVector GetHitTarget() const;

};
