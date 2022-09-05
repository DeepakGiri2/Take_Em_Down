// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTHUD.h"

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
			DrawCrosshair(HUDCollection.CrossHairCenter, ViewportCenter, Spread);
		}
		if (HUDCollection.CrossHairRight)
		{
			FVector2D Spread(SpreadScaled, 0.f);
			DrawCrosshair(HUDCollection.CrossHairRight, ViewportCenter, Spread);
		}
		if (HUDCollection.CrossHairLeft)
		{
			FVector2D Spread(-SpreadScaled, 0.f);
			DrawCrosshair(HUDCollection.CrossHairLeft, ViewportCenter, Spread);
		}
		if (HUDCollection.CrossHairTop)
		{
			FVector2D Spread(0.f, -SpreadScaled);
			DrawCrosshair(HUDCollection.CrossHairTop, ViewportCenter, Spread);
		}
		if (HUDCollection.CrossHairBottom)
		{
			FVector2D Spread(0.f, SpreadScaled);
			DrawCrosshair(HUDCollection.CrossHairBottom, ViewportCenter,Spread);
		}
	}
}

void AACTHUD::DrawCrosshair(UTexture2D* Texture, FVector2D ViewportCenter, FVector2D Spread)
{
	const float TextureWidth = Texture->GetSizeX();
	const float TextureHeight = Texture->GetSizeY();
	const FVector2D TextureDrawPoint(ViewportCenter.X - (TextureWidth / 2.f) + Spread.X,ViewportCenter.Y - (TextureHeight / 2.f) + Spread.Y);
	DrawTexture(Texture,TextureDrawPoint.X,TextureDrawPoint.Y,TextureWidth,TextureHeight,0.f,0.f,1.f,1.f,FLinearColor::White);
}