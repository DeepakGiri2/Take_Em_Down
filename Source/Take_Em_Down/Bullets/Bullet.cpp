// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	BulletCollision = CreateDefaultSubobject<UBoxComponent>("Collision");
	SetRootComponent(BulletCollision);
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	BulletMesh->SetupAttachment(BulletCollision);
	BulletCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BulletCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BulletCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BulletCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
	BulletCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	BullectProjectile = CreateDefaultSubobject<UProjectileMovementComponent>("BullectProjectile");
	BullectProjectile->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	if (P_TracerParticles)
	{
		PC_TracerComponent = UGameplayStatics::SpawnEmitterAttached(
			P_TracerParticles,
			BulletCollision,
			FName(),
			GetActorLocation(),
			GetActorRotation(),
			EAttachLocation::KeepWorldPosition
		);
	}
	if (HasAuthority())
	{
		BulletCollision->OnComponentHit.AddDynamic(this, &ABullet::OnTheHit);
	}
	Debug.Add(this->GetActorLocation());
}

void ABullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Hit.bBlockingHit)
	{

		if (GetVelocity().Size() < 200 && BullectProjectile)
		{
			BulletMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			BulletMesh->SetSimulatePhysics(true);
		}
		else
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, Hit.Location, FRotator(0.f, 0.f, 0.f));
		}
	}
	SpawnEffects(Hit);
	Debug.Add(Hit.Location);
	if (Debug.Num() > 1)
	{
		DrawDebugLine(GetWorld(), Debug[Debug.Num() - 2], Debug[Debug.Num() - 1], FColor::Blue,true);
	}
	DrawDebugSphere(GetWorld(), Hit.Location, 5.f, 4, FColor::Blue,true);
	APlayerCharacter* ACT = Cast<APlayerCharacter>(OtherActor);
	if (ACT)
	{
		ACT->PlayHitReactMontage();
	}
	
}

void ABullet::SpawnEffects_Implementation(const FHitResult& Hit)
{
	if (Hit.bBlockingHit)
	{
	
		if (GetVelocity().Size() < 5000)
		{
			if (PC_TracerComponent)
			{
				PC_TracerComponent->DestroyComponent();
			}
		}
		else if (GetVelocity().Size() < 200 && BullectProjectile)
		{
			if (BullectProjectile)
			{
				BullectProjectile->Deactivate();
				BullectProjectile->DestroyComponent();
			}
			BulletMesh->SetSimulatePhysics(true);
		}
		else
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, Hit.Location, FRotator(0.f, 0.f, 0.f));
		}

	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

