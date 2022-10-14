// Fill out your copyright notice in the Description page of Project Settings.


#include "ACTPlayerController.h"
#include "Take_Em_Down/UI/ACTHUD.h"
#include "Take_Em_Down/UI/Online/PlayerOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void AACTPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ACTHUD = Cast<AACTHUD>(GetHUD());
}

void AACTPlayerController::SetHUDHealth(float Health, float MaxHealth, float Percentage)
{
	ACTHUD = ACTHUD == nullptr ? Cast<AACTHUD>(GetHUD()) : ACTHUD;
	bool Proceed = ACTHUD && ACTHUD->m_PlayerOverlay && ACTHUD->m_PlayerOverlay->P_HealthBar && ACTHUD->m_PlayerOverlay->T_HealthPercentage;
	if (Proceed)
	{
		ACTHUD->m_PlayerOverlay->P_HealthBar->SetPercent(Percentage / 100);
		FString HealthText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));
		ACTHUD->m_PlayerOverlay->T_HealthPercentage->SetText(FText::FromString(HealthText));
		FColor Red = FColor::Red;
		FColor Green = FColor::Green;
		float Alpha = Percentage / 100;
		FLinearColor LCol = FLinearColor::LerpUsingHSV(Red, Green, Alpha);
		//FLinearColor Color = FMath::Lerp<FColor,  float>(Red, Green, Alpha);
		ACTHUD->m_PlayerOverlay->P_HealthBar->SetFillColorAndOpacity(LCol);
	}
		
}