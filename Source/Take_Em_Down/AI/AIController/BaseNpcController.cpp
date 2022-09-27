// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNpcController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
ABaseNpcController::ABaseNpcController():AISightRadius(500.f), AISightAge(5.0f),
AILooseSightRadius(AISightRadius + 50.f), AIFOV(145.f)
{
	PrimaryActorTick.bCanEverTick = true;
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("NoSense");
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>("Per Comp"));
	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILooseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFOV;
	SightConfig->SetMaxAge(AISightAge);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ThisClass::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void ABaseNpcController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetPerceptionComponent())
	{
		UE_LOG(LogTemp, Warning, TEXT("Shit"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("StartMusic"));
	}
}

void ABaseNpcController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseNpcController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UE_LOG(LogTemp, Warning, TEXT("Possessed"));
}

FRotator ABaseNpcController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.f,0.f,0.f);
	}
	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.f);
}

void ABaseNpcController::OnPawnDetected(const TArray<AActor*>& UpdatedActors)
{
}
