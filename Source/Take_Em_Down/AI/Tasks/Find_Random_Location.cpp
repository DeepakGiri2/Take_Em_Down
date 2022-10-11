// Fill out your copyright notice in the Description page of Project Settings.


#include "Find_Random_Location.h"
#include "Take_Em_Down/AI/Interfaces/AIInterface.h"
#include "Take_Em_Down/AI/Defenitions/Blackboard_Keys.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Take_Em_Down/AI/AIController/BaseNpcController.h"

UFind_Random_Location::UFind_Random_Location()
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFind_Random_Location::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* nodeMemory)
{
	AAIController* const AIController = Cast<AAIController>(OwnerComp.GetAIOwner());
	auto const Npc = AIController->GetPawn();
	FVector OrginLocation = Npc->GetActorLocation();
	FNavLocation Loc;
	UNavigationSystemV1* const Nav_Sys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (Nav_Sys->GetRandomPointInNavigableRadius(OrginLocation,m_SearchRadius,Loc,nullptr))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BB_Keys::TargetLocation, Loc.Location);
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
