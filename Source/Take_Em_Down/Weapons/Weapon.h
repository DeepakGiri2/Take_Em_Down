// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(Blueprintable)
enum class EWeaponState:uint8
{
	EWS_Fresh UMETA(DisplayName = "Fresh_State"),
	EWS_Equiped UMETA(DisplayName = "Equiped_State"),
	EWS_Droped UMETA(DisplayName = "EWSDroped_State"),
	EWS_MAX UMETA(DisplayName = "DefaultMAX_State"),
};

UCLASS()
class TAKE_EM_DOWN_API AWeapon : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AWeapon();
	void ShowPickUpWidget(bool InVisibility);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr < USkeletalMeshComponent> WeaponMesh;
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr<class USphereComponent> AreaSphere;
	UPROPERTY(VisibleAnywhere, Category = "Details")
	EWeaponState WeaponState;
	UPROPERTY(VisibleAnywhere, Category = "Details")
		TObjectPtr <class UWidgetComponent> PickUpWidget;
	UFUNCTION()
	void OnAreaSphereOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnAreaSphereEndOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE EWeaponState GetWeaponState() const { return WeaponState; }
	FORCEINLINE void SetWeaponState(EWeaponState InWeaponState)  { WeaponState = InWeaponState; }
};
