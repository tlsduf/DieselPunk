// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimGraphNode_DragonTwistArmSolver.h"
#include "AnimNode_DragonTwistArmSolver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_DragonTwistArmSolver() {}
// Cross Module References
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonControlBase();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver();
	DRAGONIKPLUGINEDITOR_API UClass* Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_NoRegister();
	UPackage* Z_Construct_UPackage__Script_DragonIKPluginEditor();
// End Cross Module References
	void UAnimGraphNode_DragonTwistArmSolver::StaticRegisterNativesUAnimGraphNode_DragonTwistArmSolver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_DragonTwistArmSolver);
	UClass* Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_NoRegister()
	{
		return UAnimGraphNode_DragonTwistArmSolver::StaticClass();
	}
	struct Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics
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
	UObject* (*const Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_DragonControlBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPluginEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AnimGraphNode_DragonTwistArmSolver.h" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_DragonTwistArmSolver.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::NewProp_ik_node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimGraphNode_DragonTwistArmSolver.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::NewProp_ik_node = { "ik_node", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimGraphNode_DragonTwistArmSolver, ik_node), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::NewProp_ik_node_MetaData), Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::NewProp_ik_node_MetaData) }; // 2512573673
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::NewProp_ik_node,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_DragonTwistArmSolver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::ClassParams = {
		&UAnimGraphNode_DragonTwistArmSolver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver()
	{
		if (!Z_Registration_Info_UClass_UAnimGraphNode_DragonTwistArmSolver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_DragonTwistArmSolver.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimGraphNode_DragonTwistArmSolver.OuterSingleton;
	}
	template<> DRAGONIKPLUGINEDITOR_API UClass* StaticClass<UAnimGraphNode_DragonTwistArmSolver>()
	{
		return UAnimGraphNode_DragonTwistArmSolver::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_DragonTwistArmSolver);
	UAnimGraphNode_DragonTwistArmSolver::~UAnimGraphNode_DragonTwistArmSolver() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonTwistArmSolver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonTwistArmSolver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_DragonTwistArmSolver, UAnimGraphNode_DragonTwistArmSolver::StaticClass, TEXT("UAnimGraphNode_DragonTwistArmSolver"), &Z_Registration_Info_UClass_UAnimGraphNode_DragonTwistArmSolver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_DragonTwistArmSolver), 3113484885U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonTwistArmSolver_h_3174468797(TEXT("/Script/DragonIKPluginEditor"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonTwistArmSolver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPluginEditor_Public_AnimGraphNode_DragonTwistArmSolver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
