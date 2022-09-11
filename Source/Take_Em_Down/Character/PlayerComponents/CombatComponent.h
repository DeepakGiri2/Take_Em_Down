// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Take_Em_Down/UI/ACTHUD.h"
#include "CombatComponent.generated.h"

#define TRACE_LENGTH 80000.f

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAKE_EM_DOWN_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	friend class APlayerCharacter;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SetAiming(bool bIsAiming);
	UFUNCTION(Server, Reliable)
	void Ser_SetAiming(bool bIsAiming);
	UFUNCTION()
		void OnRep_EquipedWeapon();
	void FireButtonPressed(bool bPressed);
	UFUNCTION(NetMulticast, Reliable)
		void Multi_Fire(const FVector_NetQuantize& HitLocation);
	UFUNCTION(Server, Reliable)
		void Ser_Fire(const FVector_NetQuantize& HitLocation);
	void TraceUnderCrossHairs(FHitResult& TraceHit);
	void SetHUDCrossHairs(float Deltatime);
	void InterpFOV(float DeltaTime);
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Details, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <APlayerCharacter> ACT;
	TObjectPtr <class AACTPlayerController> ACTController;
	TObjectPtr <class AACTHUD> ACTHUD;
	UPROPERTY(ReplicatedUsing = OnRep_EquipedWeapon)
	TObjectPtr<class AWeapon> EquipedWeapon;
	bool bFireButtonPressed;
	UPROPERTY(Replicated,VisibleAnywhere, BlueprintReadWrite, Category = combat, meta = (AllowPrivateAccess = "true"))
		bool bAiming;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Details, meta = (AllowPrivateAccess = "true"))
	float BaseWalkWalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Details, meta = (AllowPrivateAccess = "true"))
	float AimWalkWalkSpeed;
	// Crosshair
	float CrosshairVelocityFactor;
	float CrosshairAimFactor;
	float CrosshairFireFactor;
	float CrosshairInAirFactor;
	FHUDCollection HUDPackage;
	//Aiming Hand Correction
	FVector HitTarget;

	/**
	* Aiming and FOV
	*/

	// Field of view when not aiming; set to the camera's base FOV in BeginPlay
	float DefaultFOV;

	UPROPERTY(EditAnywhere, Category = Combat)
		float ZoomedFOV;

	float CurrentFOV;

	UPROPERTY(EditAnywhere, Category = Combat)
		float ZoomInterpSpeed;

public:	
	void EquipWeapon(TObjectPtr <AWeapon> WeaponToEquip);
};
