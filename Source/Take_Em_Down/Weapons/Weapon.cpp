// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"
#include "Take_Em_Down/Bullets/BulletShells.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimationAsset.h"
#include "Engine/SkeletalMeshSocket.h"
// Sets default values
AWeapon::AWeapon():ZoomedFov(30), ZoomInterpSpeed(20), AimSocketLocation(0.f, 10.f, 20.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	RootComponent = WeaponMesh;
	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	AreaSphere = CreateDefaultSubobject<USphereComponent>("AreaSphere");
	AreaSphere->SetupAttachment(GetRootComponent());

	//For MultiPlayer Stuff
	AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickUpWidget = CreateDefaultSubobject<UWidgetComponent>("PickMeUp");
	PickUpWidget->SetupAttachment(GetRootComponent());
	PickUpWidget->SetWidgetSpace(EWidgetSpace::Screen);
	PickUpWidget->SetDrawAtDesiredSize(true);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	if (PickUpWidget)
	{
		PickUpWidget->SetVisibility(false);
	}
	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		//Enable Collision Only For Server

		AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);
		AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnAreaSphereOverlap);
		AreaSphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnAreaSphereEndOverlap);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Cyan, FString("Function"));
		}
	}
}

void AWeapon::ShowPickUpWidget(bool InVisibility)
{
	if (PickUpWidget)
	{
		PickUpWidget->SetVisibility(InVisibility);
	}
}

void AWeapon::Fire(const FVector& HitLocation)
{
	if (FireAnimation)
	{
		WeaponMesh->PlayAnimation(FireAnimation, false);
	}
	if (BulletShellActor)
	{
		const USkeletalMeshSocket* AmmoEjectSocket = GetWeaponMesh()->GetSocketByName(FName("AmmoEject"));
		if (AmmoEjectSocket)
		{
			FTransform MeshTransform = AmmoEjectSocket->GetSocketTransform(GetWeaponMesh());
			UWorld* World = GetWorld();
			if (World)
			{
				World->SpawnActor<ABulletShells>(BulletShellActor, MeshTransform.GetLocation(), FRotator(MeshTransform.GetRotation()));
			}
		}
	}
}

void AWeapon::OnAreaSphereOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	if (Player && PickUpWidget)
	{
		Player->SetOverlappingWeapon(this);
	}
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Cyan, FString("Function"));
}

void AWeapon::OnAreaSphereEndOverlap(UPrimitiveComponent* OverLappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	if (Player && PickUpWidget)
	{
		Player->SetOverlappingWeapon(nullptr);
	}
}

void AWeapon::SetWeaponState(EWeaponState InWeaponState)
{
	WeaponState = InWeaponState;
	switch (WeaponState)
	{
	case EWeaponState::EWS_Equiped:
		ShowPickUpWidget(false);
		AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EWeaponState::EWS_Droped:
		break;
	case EWeaponState::EWS_Fresh:
		break;
	case EWeaponState::EWS_MAX:
		break;
	}
}

void AWeapon::OnRep_WeaponState()
{
	switch (WeaponState)
	{
	case EWeaponState::EWS_Equiped:
		ShowPickUpWidget(false);
		WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EWeaponState::EWS_Droped:
		break;
	case EWeaponState::EWS_Fresh:
		break;
	case EWeaponState::EWS_MAX:
		break;
	}
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWeapon, WeaponState);
}



