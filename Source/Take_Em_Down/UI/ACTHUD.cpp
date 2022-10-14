// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTHUD.h"
#include "GameFramework/PlayerController.h"
#include "Take_Em_Down/UI/Online/PlayerOverlay.h"
void AACTHUD::DrawHUD()
{
	Super::DrawHUD();
	FVector2D ViewportSize;
	if (GEngine)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		const FVector2D ViewportCenter(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);
		float SpreadScaled = CrosshairSpreadMax * HUDCollection.CrosshairSpread;

		if (HUDCollection.CrossHairCenter)
		{
			FVector2D Spread(0.f, 0.f);
			DrawCrosshair(HUDCollection.CrossHairCenter, ViewportCenter, Spread, HUDCollection.CrossHairsColor);
		}
		if (HUDCollection.CrossHairRight)
		{
			FVector2D Spread(SpreadScaled, 0.f);
			DrawCrosshair(HUDCollection.CrossHairRight, ViewportCenter, Spread, HUDCollection.CrossHairsColor);
		}
		if (HUDCollection.CrossHairLeft)
		{
			FVector2D Spread(-SpreadScaled, 0.f);
			DrawCrosshair(HUDCollection.CrossHairLeft, ViewportCenter, Spread, HUDCollection.CrossHairsColor);
		}
		if (HUDCollection.CrossHairTop)
		{
			FVector2D Spread(0.f, -SpreadScaled);
			DrawCrosshair(HUDCollection.CrossHairTop, ViewportCenter, Spread, HUDCollection.CrossHairsColor);
		}
		if (HUDCollection.CrossHairBottom)
		{
			FVector2D Spread(0.f, SpreadScaled);
			DrawCrosshair(HUDCollection.CrossHairBottom, ViewportCenter,Spread, HUDCollection.CrossHairsColor);
		}
	}
}

void AACTHUD::BeginPlay()
{
	Super::BeginPlay();
	AddPlayerOverlay();
}

void AACTHUD::AddPlayerOverlay()
{
	APlayerController* TempController = GetOwningPlayerController();
	if(TempController, m_PlayerOverlayClass)
	{
		m_PlayerOverlay = CreateWidget<UPlayerOverlay>(TempController, m_PlayerOverlayClass);
		m_PlayerOverlay->AddToViewport();
	}
}

void AACTHUD::DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread, FLinearColor InCrossHairsColor)
{
	const float TextureWidth = Texture->GetSizeX();
	const float TextureHeight = Texture->GetSizeY();
	const FVector2D TextureDrawPoint(ViewportCenter.X - (TextureWidth / 2.f) + Spread.X,ViewportCenter.Y - (TextureHeight / 2.f) + Spread.Y);
	DrawTexture(Texture,TextureDrawPoint.X,TextureDrawPoint.Y,TextureWidth,TextureHeight,0.f,0.f,1.f,1.f, InCrossHairsColor);
}
