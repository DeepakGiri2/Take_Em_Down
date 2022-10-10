// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Take_Em_Down/AI/Interfaces/AIInterface.h"
#include "Perception/AIPerceptionTypes.h" 
#include "BaseNpcController.generated.h"

/**
 * 
 */

UCLASS()
class TAKE_EM_DOWN_API ABaseNpcController : public AAIController , public IAIInterface
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ABaseNpcController();
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
	virtual FRotator GetControlRotation() const override;
public:
	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*>& UpdatedActors);
	UFUNCTION()
		void OnTargetUpdate(AActor* Actor, FAIStimulus Stimulus);
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float AISightRadius;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float AISightAge;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float AILooseSightRadius;
	UPROPERTY(BlueprintReadWrite, Category = Properites, meta = (AllowPrivateAccess = "true"))
		float AIFOV;
	UPROPERTY(BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UAISenseConfig_Sight> SightConfig;
	UPROPERTY(BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class APlayerCharacter> ACT;
	UPROPERTY(BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> GitClass;

};
