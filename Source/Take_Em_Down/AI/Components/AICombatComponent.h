// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AICombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAKE_EM_DOWN_API UAICombatComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UAICombatComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SetAiming(bool bIsAiming);
	UFUNCTION(Server, Reliable)
		void Ser_SetAiming(bool bIsAiming);
	UFUNCTION()
		void OnRep_EquipedWeapon();
	UFUNCTION(BlueprintCallable)
	void FireButtonPressed(bool bPressed);
	void Fire();
	UFUNCTION(NetMulticast, Reliable)
		void Multi_Fire(const FVector_NetQuantize& HitLocation);
	UFUNCTION(Server, Reliable)
		void Ser_Fire(const FVector_NetQuantize& HitLocation);
	void TraceFormSocketLocation(FHitResult& HitResult);
private:
	UPROPERTY(ReplicatedUsing = OnRep_EquipedWeapon)
		TObjectPtr<class AWeapon> EquipedWeapon;
	bool bFireButtonPressed;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = combat, meta = (AllowPrivateAccess = "true"))
		bool bAiming;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Details, meta = (AllowPrivateAccess = "true"))
		float BaseWalkWalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Details, meta = (AllowPrivateAccess = "true"))
		float AimWalkWalkSpeed;
	FVector HitTarget;

	UPROPERTY(EditAnywhere, Category = "Aim")
		FVector DefaultSocketLocation;
	UPROPERTY(EditAnywhere, Category = "Aim")
		FVector CurrentSocketLocation;
	/*
	* Automatic Fire
	*/

	FTimerHandle FireTimer;
	bool bCanFire;
	void StartFireTimer();
	void FireTimerCompleted();
	TObjectPtr<class ABaseNPC> ACT;
public:
	void EquipWeapon(TObjectPtr <AWeapon> WeaponToEquip);
	FORCEINLINE bool GetAiming() { return bAiming; };
};
