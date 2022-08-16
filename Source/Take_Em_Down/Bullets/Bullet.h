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
		void OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletProperties, meta = (AllowPrivateAccess = "true"))
		TObjectPtr <UStaticMeshComponent> BulletMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE TObjectPtr <UStaticMeshComponent> GetBulletMesh() const { return BulletMesh; };
	FORCEINLINE void SetBulletMesh(TObjectPtr<UStaticMesh> InMesh) { BulletMesh->SetStaticMesh(InMesh); }
};
