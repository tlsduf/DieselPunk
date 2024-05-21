// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DragonIKPhysicsHolder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKPhysicsHolder() {}
// Cross Module References
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_ADragonIKPhysicsHolder();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_ADragonIKPhysicsHolder_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	void ADragonIKPhysicsHolder::StaticRegisterNativesADragonIKPhysicsHolder()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADragonIKPhysicsHolder);
	UClass* Z_Construct_UClass_ADragonIKPhysicsHolder_NoRegister()
	{
		return ADragonIKPhysicsHolder::StaticClass();
	}
	struct Z_Construct_UClass_ADragonIKPhysicsHolder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_connected_actor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_connected_actor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DragonIKPhysicsHolder.h" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsHolder.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::NewProp_connected_actor_MetaData[] = {
		{ "Category", "DisplaySettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//bool holder_initialized = false;\n" },
#endif
		{ "DisplayName", "Connected Actor" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsHolder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "bool holder_initialized = false;" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::NewProp_connected_actor = { "connected_actor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADragonIKPhysicsHolder, connected_actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::NewProp_connected_actor_MetaData), Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::NewProp_connected_actor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::NewProp_connected_actor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADragonIKPhysicsHolder>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::ClassParams = {
		&ADragonIKPhysicsHolder::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::Class_MetaDataParams), Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ADragonIKPhysicsHolder()
	{
		if (!Z_Registration_Info_UClass_ADragonIKPhysicsHolder.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADragonIKPhysicsHolder.OuterSingleton, Z_Construct_UClass_ADragonIKPhysicsHolder_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADragonIKPhysicsHolder.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UClass* StaticClass<ADragonIKPhysicsHolder>()
	{
		return ADragonIKPhysicsHolder::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADragonIKPhysicsHolder);
	ADragonIKPhysicsHolder::~ADragonIKPhysicsHolder() {}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsHolder_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsHolder_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADragonIKPhysicsHolder, ADragonIKPhysicsHolder::StaticClass, TEXT("ADragonIKPhysicsHolder"), &Z_Registration_Info_UClass_ADragonIKPhysicsHolder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADragonIKPhysicsHolder), 3299117226U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsHolder_h_1724988367(TEXT("/Script/DragonIKPlugin"),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsHolder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsHolder_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
