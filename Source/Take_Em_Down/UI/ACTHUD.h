// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ACTHUD.generated.h"


USTRUCT()
struct FHUDCollection
{
	GENERATED_USTRUCT_BODY()
public:
		TObjectPtr<class UTexture2D> CrossHairCenter;
		TObjectPtr<UTexture2D> CrossHairLeft;
		TObjectPtr<UTexture2D> CrossHairRight;
		TObjectPtr<UTexture2D> CrossHairTop;
		TObjectPtr<UTexture2D> CrossHairBottom;
		float CrosshairSpread;
};

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API AACTHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;
private:
	FHUDCollection HUDCollection;
	void DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread);
	UPROPERTY(EditAnywhere)
		float CrosshairSpreadMax = 16.f;
public:
	FORCEINLINE void SetHudCollection(const FHUDCollection& Collection) { HUDCollection = Collection; }
};
