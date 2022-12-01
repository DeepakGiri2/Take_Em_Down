// Owned By Deepak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MultiplayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TAKE_EM_DOWN_API AMultiplayerGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void PlayerEliminated(class ABaseCharacter* Eliminated, class AACTPlayerController* VictimController, AACTPlayerController* AttackerContoller, class ABaseNpcController* EliminatedAIController);
};
