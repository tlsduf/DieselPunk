// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimGraphNode_DragonAimSolver.h"
#include "AnimNode_DragonAimSolver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_DragonAimSolver() {}
// Cross Module References
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonAimSolver();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonAimSolver();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_NoRegister();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonControlBase();
	UPackage* Z_Construct_UPackage__Script_DragonIKPluginEditor();
// End Cross Module References
	void UAnimGraphNode_DragonAimSolver::StaticRegisterNativesUAnimGraphNode_DragonAimSolver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_DragonAimSolver);
	UClass* Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_NoRegister()
	{
		return UAnimGraphNode_DragonAimSolver::StaticClass();
	}
	struct Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ik_node_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ik_node;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_DragonControlBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPluginEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AnimGraphNode_DragonAimSolver.h" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_DragonAimSolver.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::NewProp_ik_node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_DragonAimSolver.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::NewProp_ik_node = { "ik_node", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimGraphNode_DragonAimSolver, ik_node), Z_Construct_UScriptStruct_FAnimNode_DragonAimSolver, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::NewProp_ik_node_MetaData), Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::NewProp_ik_node_MetaData) }; // 2676490561
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::NewProp_ik_node,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_DragonAimSolver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::ClassParams = {
		&UAnimGraphNode_DragonAimSolver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAnimGraphNode_DragonAimSolver()
	{
		if (!Z_Registration_Info_UClass_UAnimGraphNode_DragonAimSolver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_DragonAimSolver.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_DragonAimSolver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimGraphNode_DragonAimSolver.OuterSingleton;
	}
	template<> DRAGONIKPLUGINEDITOR_API UClass* StaticClass<UAnimGraphNode_DragonAimSolver>()
	{
		return UAnimGraphNode_DragonAimSolver::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_DragonAimSolver);
	UAnimGraphNode_DragonAimSolver::~UAnimGraphNode_DragonAimSolver() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonAimSolver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonAimSolver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_DragonAimSolver, UAnimGraphNode_DragonAimSolver::StaticClass, TEXT("UAnimGraphNode_DragonAimSolver"), &Z_Registration_Info_UClass_UAnimGraphNode_DragonAimSolver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_DragonAimSolver), 760338506U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonAimSolver_h_1583513518(TEXT("/Script/DragonIKPluginEditor"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonAimSolver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonAimSolver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
