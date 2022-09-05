// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerModule/Public/MultiplayerMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerMenu() {}
// Cross Module References
	MULTIPLAYERMODULE_API UClass* Z_Construct_UClass_UMultiplayerMenu_NoRegister();
	MULTIPLAYERMODULE_API UClass* Z_Construct_UClass_UMultiplayerMenu();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MultiplayerModule();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMultiplayerMenu::execJoinButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execHostButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HostButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execOnStartSession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStartSession(Z_Param_bWasSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execOnDestroySession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDestroySession(Z_Param_bWasSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execOnCreateSession)
	{
		P_GET_UBOOL(Z_Param_bWasSucessfull);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCreateSession(Z_Param_bWasSucessfull);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMultiplayerMenu::execMenuSetup)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NumberPublicConnection);
		P_GET_PROPERTY(FStrProperty,Z_Param_TypeofMatch);
		P_GET_PROPERTY(FStrProperty,Z_Param_LobbyPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMultiplayerMenu**)Z_Param__Result=P_THIS->MenuSetup(Z_Param_NumberPublicConnection,Z_Param_TypeofMatch,Z_Param_LobbyPath);
		P_NATIVE_END;
	}
	void UMultiplayerMenu::StaticRegisterNativesUMultiplayerMenu()
	{
		UClass* Class = UMultiplayerMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HostButtonClicked", &UMultiplayerMenu::execHostButtonClicked },
			{ "JoinButtonClicked", &UMultiplayerMenu::execJoinButtonClicked },
			{ "MenuSetup", &UMultiplayerMenu::execMenuSetup },
			{ "OnCreateSession", &UMultiplayerMenu::execOnCreateSession },
			{ "OnDestroySession", &UMultiplayerMenu::execOnDestroySession },
			{ "OnStartSession", &UMultiplayerMenu::execOnStartSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "HostButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "JoinButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics
	{
		struct MultiplayerMenu_eventMenuSetup_Parms
		{
			int32 NumberPublicConnection;
			FString TypeofMatch;
			FString LobbyPath;
			UMultiplayerMenu* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumberPublicConnection;
		static const UECodeGen_Private::FStrPropertyParams NewProp_TypeofMatch;
		static const UECodeGen_Private::FStrPropertyParams NewProp_LobbyPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_NumberPublicConnection = { "NumberPublicConnection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetup_Parms, NumberPublicConnection), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_TypeofMatch = { "TypeofMatch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetup_Parms, TypeofMatch), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_LobbyPath = { "LobbyPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetup_Parms, LobbyPath), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MultiplayerMenu_eventMenuSetup_Parms, ReturnValue), Z_Construct_UClass_UMultiplayerMenu_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_NumberPublicConnection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_TypeofMatch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_LobbyPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_LobbyPath", "/Game/ThirdPerson/Maps/Lobby" },
		{ "CPP_Default_NumberPublicConnection", "4" },
		{ "CPP_Default_TypeofMatch", "FreeForAll" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "MenuSetup", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::MultiplayerMenu_eventMenuSetup_Parms), Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_MenuSetup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_MenuSetup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics
	{
		struct MultiplayerMenu_eventOnCreateSession_Parms
		{
			bool bWasSucessfull;
		};
		static void NewProp_bWasSucessfull_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSucessfull;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSucessfull_SetBit(void* Obj)
	{
		((MultiplayerMenu_eventOnCreateSession_Parms*)Obj)->bWasSucessfull = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSucessfull = { "bWasSucessfull", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MultiplayerMenu_eventOnCreateSession_Parms), &Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSucessfull_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::NewProp_bWasSucessfull,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09* Call back for our Custom delegate on MultiplayerModuleSubSystem\n\x09*/" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
		{ "ToolTip", "* Call back for our Custom delegate on MultiplayerModuleSubSystem" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "OnCreateSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::MultiplayerMenu_eventOnCreateSession_Parms), Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics
	{
		struct MultiplayerMenu_eventOnDestroySession_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((MultiplayerMenu_eventOnDestroySession_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MultiplayerMenu_eventOnDestroySession_Parms), &Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "OnDestroySession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::MultiplayerMenu_eventOnDestroySession_Parms), Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics
	{
		struct MultiplayerMenu_eventOnStartSession_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((MultiplayerMenu_eventOnStartSession_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MultiplayerMenu_eventOnStartSession_Parms), &Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultiplayerMenu, nullptr, "OnStartSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::MultiplayerMenu_eventOnStartSession_Parms), Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMultiplayerMenu_OnStartSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultiplayerMenu_OnStartSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultiplayerMenu);
	UClass* Z_Construct_UClass_UMultiplayerMenu_NoRegister()
	{
		return UMultiplayerMenu::StaticClass();
	}
	struct Z_Construct_UClass_UMultiplayerMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HostButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HostButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinButton;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMultiplayerMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerModule,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMultiplayerMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMultiplayerMenu_HostButtonClicked, "HostButtonClicked" }, // 1381372818
		{ &Z_Construct_UFunction_UMultiplayerMenu_JoinButtonClicked, "JoinButtonClicked" }, // 9383732
		{ &Z_Construct_UFunction_UMultiplayerMenu_MenuSetup, "MenuSetup" }, // 3020142121
		{ &Z_Construct_UFunction_UMultiplayerMenu_OnCreateSession, "OnCreateSession" }, // 1644577233
		{ &Z_Construct_UFunction_UMultiplayerMenu_OnDestroySession, "OnDestroySession" }, // 1967505226
		{ &Z_Construct_UFunction_UMultiplayerMenu_OnStartSession, "OnStartSession" }, // 927875649
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MultiplayerMenu.h" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton = { "HostButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMultiplayerMenu, HostButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MultiplayerMenu.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton = { "JoinButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMultiplayerMenu, JoinButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_HostButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultiplayerMenu_Statics::NewProp_JoinButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMultiplayerMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultiplayerMenu>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultiplayerMenu_Statics::ClassParams = {
		&UMultiplayerMenu::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerMenu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMultiplayerMenu()
	{
		if (!Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton, Z_Construct_UClass_UMultiplayerMenu_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMultiplayerMenu.OuterSingleton;
	}
	template<> MULTIPLAYERMODULE_API UClass* StaticClass<UMultiplayerMenu>()
	{
		return UMultiplayerMenu::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMultiplayerMenu);
	struct Z_CompiledInDeferFile_FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMultiplayerMenu, UMultiplayerMenu::StaticClass, TEXT("UMultiplayerMenu"), &Z_Registration_Info_UClass_UMultiplayerMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultiplayerMenu), 2072048903U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_1886508156(TEXT("/Script/MultiplayerModule"),
		Z_CompiledInDeferFile_FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
