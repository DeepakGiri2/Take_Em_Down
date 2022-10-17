// Apache 2.0

#pragma once

#include "CoreMinimal.h"
#include "Take_Em_Down/Bullets/Bullet.h"
#include "ProBullet.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API AProBullet : public ABullet
{
	GENERATED_BODY()
protected:
	virtual	void OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
