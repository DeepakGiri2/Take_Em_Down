// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerMenu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERMODULE_API UMultiplayerMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup(int32 NumberPublicConnection = 4, FString TypeofMatch = FString(TEXT("FreeForAll")),FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));
protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel,UWorld* InWorld)override;
	/*
	* Call back for our Custom delegate on MultiplayerModuleSubSystem
	*/
	UFUNCTION()
	void OnCreateSession(bool bWasSucessfull);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool  bWasSuccessful);
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;
private:
	UFUNCTION()
	void HostButtonClicked();
	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();
	int32 NumPublicConnection{4};
	FString MatchType{ TEXT("FreeForAll") };
	class UMultiplayerModuleSubsystem* MultiplayerModuleSubSystem;
	FString PathToLobby{TEXT("")};
};
