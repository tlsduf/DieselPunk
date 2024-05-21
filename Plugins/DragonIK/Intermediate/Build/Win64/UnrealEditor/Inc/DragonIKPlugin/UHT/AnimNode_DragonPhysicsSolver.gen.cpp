// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonPhysicsSolver.h"
#include "../../Source/Runtime/Engine/Public/Animation/BoneReference.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonPhysicsSolver() {}
// Cross Module References
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneReference();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip;
class UScriptStruct* FDragonData_PhysicsBoneStrip::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonData_PhysicsBoneStrip"));
	}
	return Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonData_PhysicsBoneStrip>()
{
	return FDragonData_PhysicsBoneStrip::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_Chain_Start_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bone_Chain_Start;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bone_Chain_End_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Bone_Chain_End;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//class UDragonIKPhysicsComponent;\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonPhysicsSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "class UDragonIKPhysicsComponent;" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonData_PhysicsBoneStrip>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_Start_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Bone Chain Start" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonPhysicsSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_Start = { "Bone_Chain_Start", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsBoneStrip, Bone_Chain_Start), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_Start_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_Start_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_End_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Bone Chain End" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonPhysicsSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_End = { "Bone_Chain_End", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsBoneStrip, Bone_Chain_End), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_End_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_End_MetaData) }; // 1286936164
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewProp_Bone_Chain_End,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonData_PhysicsBoneStrip",
		Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::PropPointers),
		sizeof(FDragonData_PhysicsBoneStrip),
		alignof(FDragonData_PhysicsBoneStrip),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.InnerSingleton, Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip.InnerSingleton;
	}

static_assert(std::is_polymorphic<FAnimNode_DragonPhysicsSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonPhysicsSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver;
class UScriptStruct* FAnimNode_DragonPhysicsSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonPhysicsSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonPhysicsSolver>()
{
	return FAnimNode_DragonPhysicsSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_physanim_tag_index_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_physanim_tag_index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonPhysicsSolver.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonPhysicsSolver>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewProp_physanim_tag_index_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Physanim component tag" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonPhysicsSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewProp_physanim_tag_index = { "physanim_tag_index", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonPhysicsSolver, physanim_tag_index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewProp_physanim_tag_index_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewProp_physanim_tag_index_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewProp_physanim_tag_index,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonPhysicsSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonPhysicsSolver),
		alignof(FAnimNode_DragonPhysicsSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonPhysicsSolver_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonPhysicsSolver_h_Statics::ScriptStructInfo[] = {
		{ FDragonData_PhysicsBoneStrip::StaticStruct, Z_Construct_UScriptStruct_FDragonData_PhysicsBoneStrip_Statics::NewStructOps, TEXT("DragonData_PhysicsBoneStrip"), &Z_Registration_Info_UScriptStruct_DragonData_PhysicsBoneStrip, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonData_PhysicsBoneStrip), 3208284750U) },
		{ FAnimNode_DragonPhysicsSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonPhysicsSolver_Statics::NewStructOps, TEXT("AnimNode_DragonPhysicsSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonPhysicsSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonPhysicsSolver), 2886120488U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonPhysicsSolver_h_4042864640(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonPhysicsSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonPhysicsSolver_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
