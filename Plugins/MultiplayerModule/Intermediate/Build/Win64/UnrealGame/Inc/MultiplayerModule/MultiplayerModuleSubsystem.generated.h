// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIPLAYERMODULE_MultiplayerModuleSubsystem_generated_h
#error "MultiplayerModuleSubsystem.generated.h already included, missing '#pragma once' in MultiplayerModuleSubsystem.h"
#endif
#define MULTIPLAYERMODULE_MultiplayerModuleSubsystem_generated_h

#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_14_DELEGATE \
struct _Script_MultiplayerModule_eventMultiplayerOnCreateSessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnCreateSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnCreateSessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerModule_eventMultiplayerOnCreateSessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnCreateSessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_17_DELEGATE \
struct _Script_MultiplayerModule_eventMultiplayerOnDestroySessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnDestroySessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnDestroySessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerModule_eventMultiplayerOnDestroySessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnDestroySessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_18_DELEGATE \
struct _Script_MultiplayerModule_eventMultiplayerOnStartSessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnStartSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnStartSessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerModule_eventMultiplayerOnStartSessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnStartSessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_SPARSE_DATA
#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_RPC_WRAPPERS
#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMultiplayerModuleSubsystem(); \
	friend struct Z_Construct_UClass_UMultiplayerModuleSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMultiplayerModuleSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerModule"), NO_API) \
	DECLARE_SERIALIZER(UMultiplayerModuleSubsystem)


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUMultiplayerModuleSubsystem(); \
	friend struct Z_Construct_UClass_UMultiplayerModuleSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMultiplayerModuleSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerModule"), NO_API) \
	DECLARE_SERIALIZER(UMultiplayerModuleSubsystem)


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMultiplayerModuleSubsystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMultiplayerModuleSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultiplayerModuleSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultiplayerModuleSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMultiplayerModuleSubsystem(UMultiplayerModuleSubsystem&&); \
	NO_API UMultiplayerModuleSubsystem(const UMultiplayerModuleSubsystem&); \
public:


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMultiplayerModuleSubsystem(UMultiplayerModuleSubsystem&&); \
	NO_API UMultiplayerModuleSubsystem(const UMultiplayerModuleSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultiplayerModuleSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultiplayerModuleSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMultiplayerModuleSubsystem)


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_20_PROLOG
#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_SPARSE_DATA \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_RPC_WRAPPERS \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_INCLASS \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_SPARSE_DATA \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_INCLASS_NO_PURE_DECLS \
	FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYERMODULE_API UClass* StaticClass<class UMultiplayerModuleSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Take_Em_Down_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerModuleSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
