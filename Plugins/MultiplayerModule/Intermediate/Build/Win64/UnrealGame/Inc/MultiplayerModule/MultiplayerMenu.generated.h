// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIPLAYERMODULE_MultiplayerMenu_generated_h
#error "MultiplayerMenu.generated.h already included, missing '#pragma once' in MultiplayerMenu.h"
#endif
#define MULTIPLAYERMODULE_MultiplayerMenu_generated_h

#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_SPARSE_DATA
#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execJoinButtonClicked); \
	DECLARE_FUNCTION(execHostButtonClicked); \
	DECLARE_FUNCTION(execOnStartSession); \
	DECLARE_FUNCTION(execOnDestroySession); \
	DECLARE_FUNCTION(execOnCreateSession); \
	DECLARE_FUNCTION(execMenuSetup);


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execJoinButtonClicked); \
	DECLARE_FUNCTION(execHostButtonClicked); \
	DECLARE_FUNCTION(execOnStartSession); \
	DECLARE_FUNCTION(execOnDestroySession); \
	DECLARE_FUNCTION(execOnCreateSession); \
	DECLARE_FUNCTION(execMenuSetup);


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMultiplayerMenu(); \
	friend struct Z_Construct_UClass_UMultiplayerMenu_Statics; \
public: \
	DECLARE_CLASS(UMultiplayerMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerModule"), NO_API) \
	DECLARE_SERIALIZER(UMultiplayerMenu)


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUMultiplayerMenu(); \
	friend struct Z_Construct_UClass_UMultiplayerMenu_Statics; \
public: \
	DECLARE_CLASS(UMultiplayerMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerModule"), NO_API) \
	DECLARE_SERIALIZER(UMultiplayerMenu)


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMultiplayerMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMultiplayerMenu) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultiplayerMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultiplayerMenu); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMultiplayerMenu(UMultiplayerMenu&&); \
	NO_API UMultiplayerMenu(const UMultiplayerMenu&); \
public:


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMultiplayerMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMultiplayerMenu(UMultiplayerMenu&&); \
	NO_API UMultiplayerMenu(const UMultiplayerMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultiplayerMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultiplayerMenu); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMultiplayerMenu)


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_13_PROLOG
#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_SPARSE_DATA \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_RPC_WRAPPERS \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_INCLASS \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_SPARSE_DATA \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_INCLASS_NO_PURE_DECLS \
	FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYERMODULE_API UClass* StaticClass<class UMultiplayerMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Attack_On_US_Plugins_MultiplayerModule_Source_MultiplayerModule_Public_MultiplayerMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
