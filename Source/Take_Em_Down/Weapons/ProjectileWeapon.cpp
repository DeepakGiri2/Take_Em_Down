// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Take_Em_Down/Bullets/Bullet.h"
AProjectileWeapon::AProjectileWeapon()
{
}

void AProjectileWeapon::Fire(const FVector& HitLocation)
{
	Super::Fire(HitLocation);
	if (!HasAuthority()) return;
	APawn* InstigatorPawn = Cast<APawn>(GetOwner());
	const USkeletalMeshSocket* MuzzelSocket = GetWeaponMesh()->GetSocketByName(FName("MuzzleFlash"));
	if (MuzzelSocket)
	{
		FTransform MeshTransform = MuzzelSocket->GetSocketTransform(GetWeaponMesh());
		FVector ToTarget = HitLocation - MeshTransform.GetLocation();
		FRotator TargetRotation = ToTarget.Rotation();
		if (Bullet && InstigatorPawn)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = GetOwner();
			SpawnParams.Instigator = InstigatorPawn;
			UWorld* World = GetWorld();
			if (World)
			{
				World->SpawnActor<ABullet>(	Bullet, MeshTransform.GetLocation(),	TargetRotation,	SpawnParams);
			}
		}
	}
}
