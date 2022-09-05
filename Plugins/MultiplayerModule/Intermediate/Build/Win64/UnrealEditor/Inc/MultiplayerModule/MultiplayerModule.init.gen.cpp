// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerModule_init() {}
	MULTIPLAYERMODULE_API UFunction* Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnCreateSessionComplete__DelegateSignature();
	MULTIPLAYERMODULE_API UFunction* Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnDestroySessionComplete__DelegateSignature();
	MULTIPLAYERMODULE_API UFunction* Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnStartSessionComplete__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MultiplayerModule;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MultiplayerModule()
	{
		if (!Z_Registration_Info_UPackage__Script_MultiplayerModule.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnCreateSessionComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnDestroySessionComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MultiplayerModule_MultiplayerOnStartSessionComplete__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MultiplayerModule",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1C818986,
				0x18CF64C3,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MultiplayerModule.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MultiplayerModule.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MultiplayerModule(Z_Construct_UPackage__Script_MultiplayerModule, TEXT("/Script/MultiplayerModule"), Z_Registration_Info_UPackage__Script_MultiplayerModule, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1C818986, 0x18CF64C3));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
