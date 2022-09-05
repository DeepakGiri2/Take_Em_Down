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
	void TurnInPlace(float DeltaTime);
	//Animation BP
	
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

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCombatComponent> CombatComponent;

	UFUNCTION(Server,Reliable)
	void Ser_SelectButtonPressed();

	UFUNCTION(Server, Reliable)
		void Ser_SprintButtonPressed(float Speed);
	float AO_Yaw;
	float Interp_AO_Yaw;
	float AO_Pitch;
	FRotator StartingAimRotation;
	ETurningInPlace TurinngInPlace;


	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<class UAnimMontage> FireWeaponMontage;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PostInitializeComponents() override;

	void PlayFireMontage(bool bInAiming);

	void SetOverlappingWeapon(TObjectPtr<AWeapon> InWeapon);
	
	//Anim blurprint
	bool IsWeaponEquiped();

	bool IsAiming();

	FORCEINLINE TObjectPtr<USpringArmComponent> GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE TObjectPtr < UCameraComponent> GetCamera() const { return Camera; }

	FORCEINLINE TObjectPtr<AWeapon> GetOverlappingWeapon() const { return OverlappingWeapon; }

	FORCEINLINE float GetAO_Yaw() const { return AO_Yaw; }

	FORCEINLINE float GetAO_Pitch() const { return AO_Pitch; }

	FORCEINLINE ETurningInPlace GetTurningInPlace() const { return TurinngInPlace; }

	TObjectPtr <AWeapon> GetEquipedWeapon();

	

};
