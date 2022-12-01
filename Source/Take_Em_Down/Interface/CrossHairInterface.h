// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CrossHairInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCrossHairInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TAKE_EM_DOWN_API ICrossHairInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ITakeDamage(FHitResult InResult,FRotator InRotation = FRotator(0.f,0.f,0.f));
	virtual float IGetHealth() const = 0;
	virtual float IGetHealthPercentage() const = 0;
	virtual TObjectPtr<class AController> GetController() const { return nullptr; }
};
