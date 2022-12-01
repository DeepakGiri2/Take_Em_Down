// Apache 2.0
#include "ProBullet.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Take_Em_Down/Interface/CrossHairInterface.h"

void AProBullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ICrossHairInterface* OwnedChar = Cast<ICrossHairInterface>(OtherActor);
	if (OwnedChar)
	{
		AController* OwnedController = OwnedChar->GetController();
		if (OwnedController)
		{
			Multi_BloodEffects(OtherActor);
			UGameplayStatics::ApplyDamage(OtherActor, GetDamage(), OwnedController, this, UDamageType::StaticClass());
		}
	}
	else
	{
		Super::OnTheHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
	}
	
}

void AProBullet::Multi_BloodEffects_Implementation(AActor* ACT)
{
	if (P_BloodParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_BloodParticle, GetActorTransform());
	}
}