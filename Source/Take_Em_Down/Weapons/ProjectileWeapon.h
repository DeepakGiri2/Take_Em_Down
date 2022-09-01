// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API AProjectileWeapon : public AWeapon
{
	GENERATED_BODY()
public:
	AProjectileWeapon();
	virtual void Fire(const FVector& HitLocation) override;
private:
	UPROPERTY(EditAnywhere,Category = Details)
	TSubclassOf <class ABullet> Bullet;
};
