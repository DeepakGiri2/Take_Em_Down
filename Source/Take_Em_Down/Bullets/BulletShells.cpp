// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletShells.h"

// Sets default values
ABulletShells::ABulletShells()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BulletShellMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(BulletShellMesh);
	BulletShellMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	BulletShellMesh->SetSimulatePhysics(true);
	BulletShellMesh->SetEnableGravity(true);

}

// Called when the game starts or when spawned
void ABulletShells::BeginPlay()
{
	Super::BeginPlay();
	BulletShellMesh->AddImpulse(GetActorForwardVector() * 10.f);
}

// Called every frame
void ABulletShells::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

