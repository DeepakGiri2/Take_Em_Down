// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "MotionWarpingComponent.h"
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

	Face->SetMasterPoseComponent(GetMesh());
	Torso->SetMasterPoseComponent(GetMesh());
	Feet->SetMasterPoseComponent(GetMesh());
	Legs->SetMasterPoseComponent(GetMesh());

	SetUpMetaSync();
	MetaLod->ForcedLOD = 3;

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarping"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseCharacter::SetUpMetaSync()
{
	/** LodComponent **/
	MetaLod = CreateDefaultSubobject<ULODSyncComponent>(TEXT("LodManager"));
	FComponentSync Facesync = FComponentSync(FName("Face"), ESyncOption::Drive);
	FComponentSync Meshsync = FComponentSync(FName("Mesh"), ESyncOption::Drive);
	FComponentSync Feetsync = FComponentSync(FName("Feet"), ESyncOption::Passive);
	FComponentSync Legssync = FComponentSync(FName("Legs"), ESyncOption::Passive);
	FComponentSync Torsosync = FComponentSync(FName("Torso"), ESyncOption::Passive);
	FComponentSync Hairsync = FComponentSync(FName("Hair"), ESyncOption::Passive);
	FComponentSync Eyelashessync = FComponentSync(FName("Eyelashes"), ESyncOption::Passive);
	FComponentSync Eyebrowssync = FComponentSync(FName("Eyebrows"), ESyncOption::Passive);
	FComponentSync Mustachesync = FComponentSync(FName("Mustache"), ESyncOption::Passive);
	FComponentSync Beardsync = FComponentSync(FName("Beard"), ESyncOption::Passive);
	MetaLod->ComponentsToSync.Add(Facesync);
	MetaLod->ComponentsToSync.Add(Meshsync);
	MetaLod->ComponentsToSync.Add(Feetsync);
	MetaLod->ComponentsToSync.Add(Legssync);
	MetaLod->ComponentsToSync.Add(Torsosync);
	MetaLod->ComponentsToSync.Add(Hairsync);
	MetaLod->ComponentsToSync.Add(Eyelashessync);
	MetaLod->ComponentsToSync.Add(Eyebrowssync);
	MetaLod->ComponentsToSync.Add(Mustachesync);
	MetaLod->ComponentsToSync.Add(Beardsync);
	FLODMappingData BodyData;
	BodyData.Mapping.Add(0);
	BodyData.Mapping.Add(0);
	BodyData.Mapping.Add(1);
	BodyData.Mapping.Add(1);
	BodyData.Mapping.Add(2);
	BodyData.Mapping.Add(2);
	BodyData.Mapping.Add(3);
	BodyData.Mapping.Add(3);
	FLODMappingData TorsoData;
	TorsoData.Mapping.Add(0);
	TorsoData.Mapping.Add(0);
	TorsoData.Mapping.Add(1);
	TorsoData.Mapping.Add(1);
	TorsoData.Mapping.Add(2);
	TorsoData.Mapping.Add(2);
	TorsoData.Mapping.Add(3);
	TorsoData.Mapping.Add(3);
	FLODMappingData FeetData;
	FeetData.Mapping.Add(0);
	FeetData.Mapping.Add(0);
	FeetData.Mapping.Add(1);
	FeetData.Mapping.Add(1);
	FeetData.Mapping.Add(2);
	FeetData.Mapping.Add(2);
	FeetData.Mapping.Add(3);
	FeetData.Mapping.Add(3);
	FLODMappingData LegsData;
	LegsData.Mapping.Add(0);
	LegsData.Mapping.Add(0);
	LegsData.Mapping.Add(1);
	LegsData.Mapping.Add(1);
	LegsData.Mapping.Add(2);
	LegsData.Mapping.Add(2);
	LegsData.Mapping.Add(3);
	LegsData.Mapping.Add(3);

	MetaLod->CustomLODMapping.Add(FName("Mesh"), BodyData);
	MetaLod->CustomLODMapping.Add(FName("Feet"), FeetData);
	MetaLod->CustomLODMapping.Add(FName("Torso"), TorsoData);
	MetaLod->CustomLODMapping.Add(FName("Legs"), LegsData);
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

