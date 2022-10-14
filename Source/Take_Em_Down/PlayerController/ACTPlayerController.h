// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ACTPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API AACTPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void SetHUDHealth(float Health,float MaxHealth, float Percentage);
protected:
	virtual void BeginPlay() override;
private:
	TObjectPtr<class AACTHUD> ACTHUD;
};
