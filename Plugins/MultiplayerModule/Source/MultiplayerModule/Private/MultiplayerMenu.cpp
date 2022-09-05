// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"
#include "Components/Button.h"
#include "MultiplayerModuleSubsystem.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"

UMultiplayerMenu* UMultiplayerMenu::MenuSetup(int32 NumberPublicConnection, FString TypeofMatch, FString LobbyPath)
{
	PathToLobby = FString::Printf(TEXT("%s?listen"), *LobbyPath);
	NumPublicConnection = NumberPublicConnection;
	MatchType = TypeofMatch;
	//AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Black, FString(TEXT("Mouse")));
			}
		}
	}
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		MultiplayerModuleSubSystem = GameInstance->GetSubsystem<UMultiplayerModuleSubsystem>();
	}
	if (MultiplayerModuleSubSystem)
	{
		MultiplayerModuleSubSystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
		MultiplayerModuleSubSystem->MultiplayerOnFindSessionComplete.AddUObject(this, &ThisClass::OnFindSession);
		MultiplayerModuleSubSystem->MultiplayerOnJoinSessionComplete.AddUObject(this, &ThisClass::OnJoinSession);
		MultiplayerModuleSubSystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);
		MultiplayerModuleSubSystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
	}
	return this;
}



bool UMultiplayerMenu::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	if (HostButton)
	{
		HostButton->OnClicked.AddDynamic(this,&ThisClass::HostButtonClicked);
	}
	if (JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
	}
	return true;
}

void UMultiplayerMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	MenuTearDown();
}

void UMultiplayerMenu::OnCreateSession(bool bWasSucessfull)
{
	if (bWasSucessfull)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Black, FString(TEXT("Success!")));
		}
		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel(PathToLobby);
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString(TEXT("Failed!")));
		}
		HostButton->SetIsEnabled(true);
	}
}

void UMultiplayerMenu::OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccessful)
{
	if (MultiplayerModuleSubSystem == nullptr)
	{
		return;
	}
	for (auto Results : SessionResult)
	{
		FString SettingsValue;
		Results.Session.SessionSettings.Get(FName("MatchType"), SettingsValue);
		if (SettingsValue == MatchType)
		{
			MultiplayerModuleSubSystem->JoinSession(Results);
			return;
		}
	}
	if (!bWasSuccessful || SessionResult.Num() == 0)
	{
		JoinButton->SetIsEnabled(true);
	}

}

void UMultiplayerMenu::OnJoinSession(EOnJoinSessionCompleteResult::Type Result)
{
	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get();
	if (SubSystem)
	{
		IOnlineSessionPtr SessionInterface = SubSystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			FString Address;
			SessionInterface->GetResolvedConnectString(NAME_GameSession, Address);

			APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
			if (PlayerController)
			{
				PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
			}
		}
	}
	if (Result != EOnJoinSessionCompleteResult::Success)
	{
		JoinButton->SetIsEnabled(true);
	}
}

void UMultiplayerMenu::OnDestroySession(bool bWasSuccessful)
{
}

void UMultiplayerMenu::OnStartSession(bool bWasSuccessful)
{
}

void UMultiplayerMenu::HostButtonClicked()
{
	HostButton->SetIsEnabled(false);
	if (MultiplayerModuleSubSystem)
	{
		MultiplayerModuleSubSystem->CreateSession(NumPublicConnection, MatchType);
	}
}

void UMultiplayerMenu::JoinButtonClicked()
{
	HostButton->SetIsEnabled(false);
	if (MultiplayerModuleSubSystem)
	{
		MultiplayerModuleSubSystem->FindSessions(10000);
	}
}

void UMultiplayerMenu::MenuTearDown()
{
	RemoveFromParent();
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeGameOnly Inputdata;
			PlayerController->SetShowMouseCursor(false);
			PlayerController->SetInputMode(Inputdata);

		}
	}
}
