// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Take_Em_Down/Interface/CrossHairInterface.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	m_BulletCollision = CreateDefaultSubobject<UBoxComponent>("Collision");
	SetRootComponent(m_BulletCollision);
	m_BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	m_BulletMesh->SetupAttachment(m_BulletCollision);
	m_BulletCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	m_BulletCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	m_BulletCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	m_BulletCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
	m_BulletCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	m_BullectProjectile = CreateDefaultSubobject<UProjectileMovementComponent>("BullectProjectile");
	m_BullectProjectile->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	if (P_TracerParticles)
	{
		PC_TracerComponent = UGameplayStatics::SpawnEmitterAttached(
			P_TracerParticles,
			m_BulletCollision,
			FName(),
			GetActorLocation(),
			GetActorRotation(),
			EAttachLocation::KeepWorldPosition
		);
	}
	if (HasAuthority())
	{
		m_BulletCollision->OnComponentHit.AddDynamic(this, &ABullet::OnTheHit);
	}
}

void ABullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	m_HitResult = Hit;
	m_OtherActor = OtherActor;
	if (Hit.bBlockingHit)
	{
		Multi_SpawnEffects(OtherActor);
	}
}

void ABullet::Multi_SpawnEffects_Implementation(AActor* ACT)
{
	if (!HasAuthority())
	{
		if (P_FireParticle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, GetActorTransform());
		}
	}
	if (m_HitResult.bBlockingHit)
	{
		if (P_FireParticle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, GetActorTransform());
		}
	}
	Destroy();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

