// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "GroomComponent.h"
#include "Components/LODSyncComponent.h"
// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/** Skeletal Mesh **/
	Face = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FACE"));
	Torso = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TORSO"));
	Feet = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FEET"));
	Legs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LEGS"));

	/** Attach Body Parts To Main Body**/
	Face->SetupAttachment(GetMesh());
	Torso->SetupAttachment(GetMesh());
	Feet->SetupAttachment(GetMesh());
	Legs->SetupAttachment(GetMesh());

	/** Groom **/
	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("HAIR"));
	Eyelashes = CreateDefaultSubobject<UGroomComponent>(TEXT("EYELASH"));
	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("EYEBRO"));
	Mustache = CreateDefaultSubobject<UGroomComponent>(TEXT("MUST"));
	Beard = CreateDefaultSubobject<UGroomComponent>(TEXT("BEARD"));

	/** Attach Groom To Face**/
	Hair->SetupAttachment(Face);
	Eyelashes->SetupAttachment(Face);
	Eyebrows->SetupAttachment(Face);
	Mustache->SetupAttachment(Face);
	Beard->SetupAttachment(Face);

	/** LodComponent **/
	MetaLod = CreateDefaultSubobject<ULODSyncComponent>(TEXT("LodManager"));
	MetaLod->ForcedLOD = 3;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

