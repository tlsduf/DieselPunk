// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonControlBase.h"
#include "../../Source/Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "../../Source/Runtime/Engine/Classes/Animation/InputScaleBias.h"
#include "../../Source/Runtime/Engine/Public/Animation/BoneReference.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonControlBase() {}
// Cross Module References
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBoneDragonSocketTarget();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSocketDragonReference();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EAnimAlphaInputType();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_Base();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneReference();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentSpacePoseLink();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FInputAlphaBoolBlend();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FInputScaleBias();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FInputScaleBiasClamp();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SocketDragonReference;
class UScriptStruct* FSocketDragonReference::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SocketDragonReference.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SocketDragonReference.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSocketDragonReference, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("SocketDragonReference"));
	}
	return Z_Registration_Info_UScriptStruct_SocketDragonReference.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FSocketDragonReference>()
{
	return FSocketDragonReference::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSocketDragonReference_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSocketDragonReference_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSocketDragonReference>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewProp_SocketName_MetaData[] = {
		{ "Category", "FSocketDragonReference" },
		{ "Comment", "/** Target socket to look at. Used if LookAtBone is empty. - You can use  LookAtLocation if you need offset from this point. That location will be used in their local space. **/" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "ToolTip", "Target socket to look at. Used if LookAtBone is empty. - You can use  LookAtLocation if you need offset from this point. That location will be used in their local space. *" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSocketDragonReference, SocketName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewProp_SocketName_MetaData), Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewProp_SocketName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSocketDragonReference_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewProp_SocketName,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSocketDragonReference_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"SocketDragonReference",
		Z_Construct_UScriptStruct_FSocketDragonReference_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketDragonReference_Statics::PropPointers),
		sizeof(FSocketDragonReference),
		alignof(FSocketDragonReference),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketDragonReference_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSocketDragonReference_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSocketDragonReference_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FSocketDragonReference()
	{
		if (!Z_Registration_Info_UScriptStruct_SocketDragonReference.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SocketDragonReference.InnerSingleton, Z_Construct_UScriptStruct_FSocketDragonReference_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SocketDragonReference.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget;
class UScriptStruct* FBoneDragonSocketTarget::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBoneDragonSocketTarget, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("BoneDragonSocketTarget"));
	}
	return Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FBoneDragonSocketTarget>()
{
	return FBoneDragonSocketTarget::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseSocket_MetaData[];
#endif
		static void NewProp_bUseSocket_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSocket;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneReference_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoneReference;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SocketReference_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SocketReference;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBoneDragonSocketTarget>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket_MetaData[] = {
		{ "Category", "FBoneDragonSocketTarget" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket_SetBit(void* Obj)
	{
		((FBoneDragonSocketTarget*)Obj)->bUseSocket = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket = { "bUseSocket", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FBoneDragonSocketTarget), &Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket_MetaData), Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_BoneReference_MetaData[] = {
		{ "Category", "FBoneDragonSocketTarget" },
		{ "EditCondition", "!bUseSocket" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_BoneReference = { "BoneReference", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBoneDragonSocketTarget, BoneReference), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_BoneReference_MetaData), Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_BoneReference_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_SocketReference_MetaData[] = {
		{ "Category", "FBoneDragonSocketTarget" },
		{ "EditCondition", "bUseSocket" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_SocketReference = { "SocketReference", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBoneDragonSocketTarget, SocketReference), Z_Construct_UScriptStruct_FSocketDragonReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_SocketReference_MetaData), Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_SocketReference_MetaData) }; // 2799666830
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_bUseSocket,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_BoneReference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewProp_SocketReference,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"BoneDragonSocketTarget",
		Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::PropPointers),
		sizeof(FBoneDragonSocketTarget),
		alignof(FBoneDragonSocketTarget),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FBoneDragonSocketTarget()
	{
		if (!Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.InnerSingleton, Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget.InnerSingleton;
	}

static_assert(std::is_polymorphic<FAnimNode_DragonControlBase>() == std::is_polymorphic<FAnimNode_Base>(), "USTRUCT FAnimNode_DragonControlBase cannot be polymorphic unless super FAnimNode_Base is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase;
class UScriptStruct* FAnimNode_DragonControlBase::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonControlBase"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonControlBase>()
{
	return FAnimNode_DragonControlBase::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComponentPose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ComponentPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LODThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LODThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActualAlpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ActualAlpha;
		static const UECodeGen_Private::FBytePropertyParams NewProp_AlphaInputType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlphaInputType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_AlphaInputType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAlphaBoolEnabled_MetaData[];
#endif
		static void NewProp_bAlphaBoolEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlphaBoolEnabled;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlphaScaleBias_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlphaScaleBias;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlphaBoolBlend_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlphaBoolBlend;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlphaCurveName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_AlphaCurveName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlphaScaleBiasClamp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlphaScaleBiasClamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonControlBase>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ComponentPose_MetaData[] = {
		{ "Category", "Links" },
		{ "Comment", "// Input link\n" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "ToolTip", "Input link" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ComponentPose = { "ComponentPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, ComponentPose), Z_Construct_UScriptStruct_FComponentSpacePoseLink, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ComponentPose_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ComponentPose_MetaData) }; // 3609499842
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_LODThreshold_MetaData[] = {
		{ "Category", "Performance" },
		{ "Comment", "/*\n\x09* Max LOD that this node is allowed to run\n\x09* For example if you have LODThreadhold to be 2, it will run until LOD 2 (based on 0 index)\n\x09* when the component LOD becomes 3, it will stop update/evaluate\n\x09* currently transition would be issue and that has to be re-visited\n\x09*/" },
		{ "DisplayName", "LOD Threshold" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "ToolTip", "* Max LOD that this node is allowed to run\n* For example if you have LODThreadhold to be 2, it will run until LOD 2 (based on 0 index)\n* when the component LOD becomes 3, it will stop update/evaluate\n* currently transition would be issue and that has to be re-visited" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_LODThreshold = { "LODThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, LODThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_LODThreshold_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_LODThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ActualAlpha_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ActualAlpha = { "ActualAlpha", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, ActualAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ActualAlpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ActualAlpha_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType_MetaData[] = {
		{ "Category", "Alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType = { "AlphaInputType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, AlphaInputType), Z_Construct_UEnum_Engine_EAnimAlphaInputType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType_MetaData) }; // 1731027530
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled_MetaData[] = {
		{ "Category", "Alpha" },
		{ "DisplayName", "bEnabled (Blend)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled_SetBit(void* Obj)
	{
		((FAnimNode_DragonControlBase*)Obj)->bAlphaBoolEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled = { "bAlphaBoolEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonControlBase), &Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_Alpha_MetaData[] = {
		{ "Category", "Alpha" },
		{ "Comment", "// Current strength of the skeletal control\n" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "Current strength of the skeletal control" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBias_MetaData[] = {
		{ "Category", "Alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBias = { "AlphaScaleBias", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, AlphaScaleBias), Z_Construct_UScriptStruct_FInputScaleBias, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBias_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBias_MetaData) }; // 3365344614
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaBoolBlend_MetaData[] = {
		{ "Category", "Alpha" },
		{ "DisplayName", "Blend Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaBoolBlend = { "AlphaBoolBlend", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, AlphaBoolBlend), Z_Construct_UScriptStruct_FInputAlphaBoolBlend, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaBoolBlend_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaBoolBlend_MetaData) }; // 2453606702
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaCurveName_MetaData[] = {
		{ "Category", "Alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaCurveName = { "AlphaCurveName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, AlphaCurveName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaCurveName_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaCurveName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBiasClamp_MetaData[] = {
		{ "Category", "Alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonControlBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBiasClamp = { "AlphaScaleBiasClamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonControlBase, AlphaScaleBiasClamp), Z_Construct_UScriptStruct_FInputScaleBiasClamp, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBiasClamp_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBiasClamp_MetaData) }; // 233997992
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ComponentPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_LODThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_ActualAlpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaInputType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_bAlphaBoolEnabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBias,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaBoolBlend,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaCurveName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewProp_AlphaScaleBiasClamp,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_Base,
		&NewStructOps,
		"AnimNode_DragonControlBase",
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::PropPointers),
		sizeof(FAnimNode_DragonControlBase),
		alignof(FAnimNode_DragonControlBase),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonControlBase_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonControlBase_h_Statics::ScriptStructInfo[] = {
		{ FSocketDragonReference::StaticStruct, Z_Construct_UScriptStruct_FSocketDragonReference_Statics::NewStructOps, TEXT("SocketDragonReference"), &Z_Registration_Info_UScriptStruct_SocketDragonReference, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSocketDragonReference), 2799666830U) },
		{ FBoneDragonSocketTarget::StaticStruct, Z_Construct_UScriptStruct_FBoneDragonSocketTarget_Statics::NewStructOps, TEXT("BoneDragonSocketTarget"), &Z_Registration_Info_UScriptStruct_BoneDragonSocketTarget, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBoneDragonSocketTarget), 1010858793U) },
		{ FAnimNode_DragonControlBase::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonControlBase_Statics::NewStructOps, TEXT("AnimNode_DragonControlBase"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonControlBase, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonControlBase), 3277243593U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonControlBase_h_3747728148(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonControlBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonControlBase_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
