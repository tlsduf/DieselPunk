// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKPlugin_init() {}
	DRAGONIKPLUGIN_API UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature();
	DRAGONIKPLUGIN_API UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DragonIKPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DragonIKPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_DragonIKPlugin.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/DragonIKPlugin",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x6FD84C0B,
				0xA2C40815,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DragonIKPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_DragonIKPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DragonIKPlugin(Z_Construct_UPackage__Script_DragonIKPlugin, TEXT("/Script/DragonIKPlugin"), Z_Registration_Info_UPackage__Script_DragonIKPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x6FD84C0B, 0xA2C40815));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
