// Apache 2.0
#include "ProBullet.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

void AProBullet::OnTheHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacter* OwnedChar = Cast<ACharacter>(GetOwner());
	if (OwnedChar)
	{
		AController* OwnedController = OwnedChar->Controller;
		if (OwnedController)
		{
			UGameplayStatics::ApplyDamage(OtherActor, GetDamage(), OwnedController, this, UDamageType::StaticClass());
		}
	}
	Super::OnTheHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}
