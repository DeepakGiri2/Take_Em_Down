// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TAKE_EM_DOWN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
private:
	/*Groom*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
	class UGroomComponent* Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
	UGroomComponent* Eyelashes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
	UGroomComponent* Eyebrows;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
	UGroomComponent* Mustache;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Groom, meta = (AllowPrivateAccess = "true"))
	UGroomComponent* Beard;
	/*SkeletalMesh*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Face;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Torso;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Feet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Legs;
	/** LodSyncComp **/
	ULODSyncComponent* MetaLod;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** Groom **/
	FORCEINLINE UGroomComponent* GetHair()const { return Hair; }
	FORCEINLINE UGroomComponent* GetEyelashes()const { return Eyelashes; }
	FORCEINLINE UGroomComponent* GetEyebrows()const { return Eyebrows; }
	FORCEINLINE UGroomComponent* GetMustache()const { return Mustache; }
	FORCEINLINE UGroomComponent* GetBeard()const { return Beard; }
	/** SkeletalMesh **/
	FORCEINLINE USkeletalMeshComponent* GetFace()const { return Face; }
	FORCEINLINE USkeletalMeshComponent* GetTorso()const { return Torso; }
	FORCEINLINE USkeletalMeshComponent* GetFeet()const { return Feet; }
	FORCEINLINE USkeletalMeshComponent* GetLegs()const { return Legs; }
	/** LODMANAGER **/
	FORCEINLINE ULODSyncComponent* GetLODSYNC()const { return MetaLod; }
};
