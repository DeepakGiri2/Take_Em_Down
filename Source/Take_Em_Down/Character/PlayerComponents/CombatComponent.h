// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAKE_EM_DOWN_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	friend class APlayerCharacter;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	TObjectPtr <APlayerCharacter> Character;
	TObjectPtr<class AWeapon> EquipedWeapon;
public:	
	void EquipWeapon(TObjectPtr <AWeapon> WeaponToEquip);

		
};