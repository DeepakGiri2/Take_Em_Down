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
	virtual void Fire(const FVector& HitLocation);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr < USkeletalMeshComponent> WeaponMesh;
	UPROPERTY(VisibleAnywhere, Category = "Details")
	TObjectPtr<class USphereComponent> AreaSphere;
	UPROPERTY(ReplicatedUsing = OnRep_WeaponState,VisibleAnywhere, Category = "Details")
	EWeaponState WeaponState;
	UPROPERTY(VisibleAnywhere, Category = "Details")
		TObjectPtr <class UWidgetComponent> PickUpWidget;
	UPROPERTY(EditAnywhere, Category = "Details")
	TObjectPtr <class UAnimationAsset> FireAnimation;
	UFUNCTION()
	void OnAreaSphereOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnAreaSphereEndOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex);
	UFUNCTION()
		void OnRep_WeaponState();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	FORCEINLINE EWeaponState GetWeaponState() const { return WeaponState; }
	void SetWeaponState(EWeaponState InWeaponState);
	FORCEINLINE TObjectPtr<USphereComponent> GetAreaSphere() const { return AreaSphere; }
	FORCEINLINE void SetAreaSphere(TObjectPtr<USphereComponent> InAreaSphere) { AreaSphere = InAreaSphere; }
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetWeaponMesh() const { return WeaponMesh; }
};
