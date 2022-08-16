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
class USphereComponent;
class UWidgetComponent;

UCLASS()
class TAKE_EM_DOWN_API AWeapon : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr < USkeletalMeshComponent> WeaponMesh;
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr<USphereComponent> AreaSphere;
	UPROPERTY(VisibleAnywhere, Category = "Details")
	EWeaponState WeaponState;
	UPROPERTY(VisibleAnywhere, Category = "Details")
		TObjectPtr <UWidgetComponent> PickUpWidget;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
