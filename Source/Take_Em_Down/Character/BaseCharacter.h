// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Take_Em_Down/Interface/CrossHairInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TAKE_EM_DOWN_API ABaseCharacter : public ACharacter, public ICrossHairInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
private:
	/*Groom*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UGroomComponent> Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UGroomComponent> Eyelashes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UGroomComponent> Eyebrows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UGroomComponent> Mustache;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UGroomComponent> Beard;
	/*SkeletalMesh*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr <USkeletalMeshComponent> Face;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USkeletalMeshComponent> Torso;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr <USkeletalMeshComponent> Feet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USkeletalMeshComponent> Legs;
	/** LodSyncComp **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class ULODSyncComponent> MetaLod;
	/** MotionWarping Component **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UMotionWarpingComponent> MotionWarpingComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats, meta = (AllowPrivateAccess = "true"))
		float Health = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats, meta = (AllowPrivateAccess = "true"))
		float MaxHealth = 100.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetUpMetaSync();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** Groom **/
	FORCEINLINE TObjectPtr<UGroomComponent> GetHair()const { return Hair; }
	FORCEINLINE TObjectPtr<UGroomComponent> GetEyelashes()const { return Eyelashes; }
	FORCEINLINE TObjectPtr < UGroomComponent> GetEyebrows()const { return Eyebrows; }
	FORCEINLINE TObjectPtr<UGroomComponent> GetMustache()const { return Mustache; }
	FORCEINLINE TObjectPtr < UGroomComponent> GetBeard()const { return Beard; }
	/** SkeletalMesh **/
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetFace()const { return Face; }
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetTorso()const { return Torso; }
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetFeet()const { return Feet; }
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetLegs()const { return Legs; }
	/** LODMANAGER **/
	FORCEINLINE TObjectPtr <ULODSyncComponent> GetLODSYNC()const { return MetaLod; }
	/*Char Stats*/
	FORCEINLINE float GetHealth() const { return Health; }
	void SetHealth(float InHelath);
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }
	FORCEINLINE void SetMaxHealth(float InHelath) { MaxHealth = InHelath; }
};
