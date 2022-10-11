// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Find_Random_Location.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TAKE_EM_DOWN_API UFind_Random_Location : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UFind_Random_Location();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,uint8* nodeMemory );
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Task, meta = (AllowPrivateAccess = "true"))
	float m_SearchRadius = 1500.f;
};
