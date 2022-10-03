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
#include "Take_Em_Down/Character/BaseCharacter.h"
#include "Take_Em_Down/Interface/CrossHairInterface.h"


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
	//if (HasAuthority())
	//{
		BulletCollision->OnComponentHit.AddDynamic(this, &ABullet::OnTheHit);
	//}
	Debug.Add(this->GetActorLocation());
}

void ABullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACT = OtherActor;
	HitResult = Hit;
	if (Hit.bBlockingHit)
	{
		ICrossHairInterface* HitActor = Cast<ICrossHairInterface>(OtherActor);
		if (OtherActor && HitActor)
		{
			HitActor->ITakeDamage(Hit,FRotator(90,0,0));
		}
		else
		{
			if (P_FireParticle)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, HitResult.Location, FRotator(0.f, 0.f, 0.f));
			}
			DrawDebugSphere(GetWorld(), HitResult.Location, 5.f, 4, FColor::Blue, true);
			if (ACT)
			{
				APlayerCharacter* LACT = Cast<APlayerCharacter>(ACT);
				if (LACT)
				{
					LACT->PlayHitReactMontage();
				}
			}
			Ser_SpawnEffects();
			Destroy();
		}
		
	}
}

void ABullet::Ser_SpawnEffects_Implementation()
{
	Multi_SpawnEffects();
}

void ABullet::Multi_SpawnEffects_Implementation()
{
	if (P_FireParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_FireParticle, HitResult.Location, FRotator(0.f, 0.f, 0.f));
	}
	DrawDebugSphere(GetWorld(), HitResult.Location, 5.f, 4, FColor::Blue, true);
	if (ACT)
	{
		APlayerCharacter* LACT = Cast<APlayerCharacter>(ACT);
		if (LACT)
		{
			LACT->PlayHitReactMontage();
		}
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Destroyed()
{
	Super::Destroyed();
	if (HitResult.bBlockingHit)
	{
		Ser_SpawnEffects();
	}
}

