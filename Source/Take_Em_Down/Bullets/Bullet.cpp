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

	//BulletCollision->OnComponentHit.AddDynamic(this, &ABullet::OnTheHit);
}

void ABullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	m_HitResult = Hit;
	m_OtherActor = OtherActor;
	if (Hit.bBlockingHit)
	{
		Ser_SpawnEffects(m_OtherActor);
	}
}

void ABullet::Ser_SpawnEffects_Implementation(AActor* ACT)
{
	Multi_SpawnEffects(ACT);
}

void ABullet::Multi_SpawnEffects_Implementation(AActor* ACT)
{
	if (!HasAuthority())
	{
		ICrossHairInterface* HitActor = Cast<ICrossHairInterface>(ACT);
		if (HitActor)
		{
			FHitResult TemResultTest;
			TemResultTest.Location = GetActorLocation();
			HitActor->ITakeDamage(TemResultTest, GetActorRotation());
		}
		else
		{
			if (P_FireParticle)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, GetActorTransform());
			}
		}
	}
	if (m_HitResult.bBlockingHit)
	{
		ICrossHairInterface* HitActor = Cast<ICrossHairInterface>(m_OtherActor);
		if (m_OtherActor && HitActor)
		{
			HitActor->ITakeDamage(m_HitResult, FRotator(90, 0, 0));
			if (!HasAuthority())
			{
				UE_LOG(LogTemp, Warning, TEXT("Check for coll"));
			}
		}
		else
		{
			if (P_FireParticle)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, GetActorTransform());
			}
		}
	}
	Destroy();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Destroyed()
{
	Super::Destroyed();
}

