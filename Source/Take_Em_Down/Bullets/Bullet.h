// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TAKE_EM_DOWN_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual	void OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION(NetMulticast, Reliable)
	void Multi_SpawnEffects(AActor* ACT);
	UFUNCTION(Server, Reliable)
	void Ser_SpawnEffects(AActor* ACT);
private:
	UPROPERTY(EditAnywhere, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr <class UBoxComponent> m_BulletCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr <UStaticMeshComponent> m_BulletMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UParticleSystem> P_FireParticle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UParticleSystem> P_TracerParticles;
	TObjectPtr<class UParticleSystemComponent> PC_TracerComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UProjectileMovementComponent> m_BullectProjectile;
	UPROPERTY()
	FHitResult m_HitResult;
	UPROPERTY()
	TObjectPtr <AActor> m_OtherActor;
	UPROPERTY()
	float Damage = 3.1415;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE TObjectPtr <UStaticMeshComponent> GetBulletMesh() const { return m_BulletMesh; };
	FORCEINLINE void SetBulletMesh(TObjectPtr<UStaticMesh> InMesh) { m_BulletMesh->SetStaticMesh(InMesh); }
	FORCEINLINE float GetDamage() const { return Damage; }
};
