// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNpcController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
ABaseNpcController::ABaseNpcController(FObjectInitializer const& object_intializer):m_AISightRadius(500.f), m_AISightAge(5.0f),
m_AILooseSightRadius(m_AISightRadius + 50.f), m_AIFOV(145.f)
{
	PrimaryActorTick.bCanEverTick = true;
	/*static ConstructorHelpers::FObjectFinder<UBehaviorTree>obj(TEXT("BehaviorTree'/Game/AI/BB_BT/Test_BT.Test_BT'"));
	if (obj.Succeeded())
	{
		m_BT_Asset = obj.Object;
	}*/
	m_BTComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	m_BB_Comp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	m_SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("NoSense");
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>("Per Comp"));
	m_SightConfig->SightRadius = m_AISightRadius;
	m_SightConfig->LoseSightRadius = m_AILooseSightRadius;
	m_SightConfig->PeripheralVisionAngleDegrees = m_AIFOV;
	m_SightConfig->SetMaxAge(m_AISightAge);
	m_SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	m_SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	m_SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*m_SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ThisClass::OnPawnDetected);
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnTargetUpdate);
	GetPerceptionComponent()->ConfigureSense(*m_SightConfig);
}

void ABaseNpcController::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseNpcController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseNpcController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (m_BT_Asset)
	{
		RunBehaviorTree(m_BT_Asset);
		m_BTComp->StartTree(*m_BT_Asset);
		if (m_BB_Comp)
		{
			m_BB_Comp->InitializeBlackboard(*m_BT_Asset->BlackboardAsset);
		}
	}
}

FRotator ABaseNpcController::GetControlRotation() const
{
	if (!GetPawn())
	{
		return FRotator(0.f,0.f,0.f);
	}
	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.f);
}

APawn* ABaseNpcController::GetPlayerPawn() const
{
	return GetPawn();
}

FVector ABaseNpcController::GetPlayerLocation() const
{
	return GetPawn()->GetActorLocation();
}

UBlackboardComponent* ABaseNpcController::GetBlackboardComponent() const
{
	return m_BB_Comp;
}

void ABaseNpcController::OnPawnDetected(const TArray<AActor*>& UpdatedActors)
{
}

void ABaseNpcController::OnTargetUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello my name is "));
	}
}


