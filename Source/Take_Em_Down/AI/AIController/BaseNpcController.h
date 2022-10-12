// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h" 
#include "BaseNpcController.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class TAKE_EM_DOWN_API ABaseNpcController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ABaseNpcController(FObjectInitializer const& object_intializer = FObjectInitializer::Get());
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
	virtual FRotator GetControlRotation() const override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Comps, meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* m_BTComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Comps, meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* m_BT_Asset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Comps, meta = (AllowPrivateAccess = "true"))
	UBlackboardComponent* m_BB_Comp;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ABaseNPC> m_OwningNPC;
public:
	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*>& UpdatedActors);
	UFUNCTION()
		void OnTargetUpdate(AActor* Actor, FAIStimulus Stimulus);
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float m_AISightRadius;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float m_AISightAge;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float m_AILooseSightRadius;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float m_AIFOV;
	UPROPERTY(BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UAISenseConfig_Sight> m_SightConfig;
	UPROPERTY(BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> m_GitClass;

};
