// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DragonIKTraceManagerComponent.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKTraceManagerComponent() {}
// Cross Module References
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKTraceManagerComponent();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKTraceManagerComponent_NoRegister();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType();
	DRAGONIKPLUGIN_API UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceMParams();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDragonIKTraceMType;
	static UEnum* EDragonIKTraceMType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EDragonIKTraceMType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EDragonIKTraceMType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("EDragonIKTraceMType"));
		}
		return Z_Registration_Info_UEnum_EDragonIKTraceMType.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<EDragonIKTraceMType>()
	{
		return EDragonIKTraceMType_StaticEnum();
	}
	struct Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enumerators[] = {
		{ "EDragonIKTraceMType::LineTrace", (int64)EDragonIKTraceMType::LineTrace },
		{ "EDragonIKTraceMType::SphereTrace", (int64)EDragonIKTraceMType::SphereTrace },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDragonIKSpineData,const TArray<FDragonIKTraceParamKeyValuePair>,data);\n" },
#endif
		{ "LineTrace.DisplayName", "Line Trace" },
		{ "LineTrace.Name", "EDragonIKTraceMType::LineTrace" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
		{ "SphereTrace.DisplayName", "Sphere Trace" },
		{ "SphereTrace.Name", "EDragonIKTraceMType::SphereTrace" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDragonIKSpineData,const TArray<FDragonIKTraceParamKeyValuePair>,data);" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		"EDragonIKTraceMType",
		"EDragonIKTraceMType",
		Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType()
	{
		if (!Z_Registration_Info_UEnum_EDragonIKTraceMType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDragonIKTraceMType.InnerSingleton, Z_Construct_UEnum_DragonIKPlugin_EDragonIKTraceMType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EDragonIKTraceMType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair;
class UScriptStruct* FDragonIKTraceKeyValuePair::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonIKTraceKeyValuePair"));
	}
	return Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonIKTraceKeyValuePair>()
{
	return FDragonIKTraceKeyValuePair::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Key;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_result_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_result;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\nUSTRUCT(BlueprintType)\nstruct FDragonIKTraceHandlerStruct\n{\n\x09GENERATED_BODY()\n\n\x09""bool is_activated = false;\n\x09""bool bWantsTrace = false;\n\x09""FTraceHandle LastTraceHandle;\n\x09""FTraceDelegate TraceDelegate;\n};\n*/" },
#endif
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USTRUCT(BlueprintType)\nstruct FDragonIKTraceHandlerStruct\n{\n       GENERATED_BODY()\n\n       bool is_activated = false;\n       bool bWantsTrace = false;\n       FTraceHandle LastTraceHandle;\n       FTraceDelegate TraceDelegate;\n};" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonIKTraceKeyValuePair>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonIKTraceKeyValuePair, Key), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_Key_MetaData), Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_Key_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_BoneName_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonIKTraceKeyValuePair, BoneName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_BoneName_MetaData), Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_BoneName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_hit_result_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_hit_result = { "hit_result", nullptr, (EPropertyFlags)0x0010008000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonIKTraceKeyValuePair, hit_result), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_hit_result_MetaData), Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_hit_result_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_BoneName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewProp_hit_result,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonIKTraceKeyValuePair",
		Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::PropPointers),
		sizeof(FDragonIKTraceKeyValuePair),
		alignof(FDragonIKTraceKeyValuePair),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000005),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.InnerSingleton, Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonIKTraceMParams;
class UScriptStruct* FDragonIKTraceMParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonIKTraceMParams, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonIKTraceMParams"));
	}
	return Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonIKTraceMParams>()
{
	return FDragonIKTraceMParams::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonIKTraceMParams>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonIKTraceMParams",
		nullptr,
		0,
		sizeof(FDragonIKTraceMParams),
		alignof(FDragonIKTraceMParams),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceMParams()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.InnerSingleton, Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonIKTraceMParams.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair;
class UScriptStruct* FDragonIKTraceParamKeyValuePair::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonIKTraceParamKeyValuePair"));
	}
	return Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonIKTraceParamKeyValuePair>()
{
	return FDragonIKTraceParamKeyValuePair::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Key;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trace_params_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_trace_params;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonIKTraceParamKeyValuePair>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_Key_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonIKTraceParamKeyValuePair, Key), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_Key_MetaData), Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_Key_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_trace_params_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_trace_params = { "trace_params", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonIKTraceParamKeyValuePair, trace_params), Z_Construct_UScriptStruct_FDragonIKTraceMParams, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_trace_params_MetaData), Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_trace_params_MetaData) }; // 4041424791
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewProp_trace_params,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonIKTraceParamKeyValuePair",
		Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::PropPointers),
		sizeof(FDragonIKTraceParamKeyValuePair),
		alignof(FDragonIKTraceParamKeyValuePair),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.InnerSingleton, Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics
	{
		struct _Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms
		{
			TArray<FDragonIKTraceKeyValuePair> hit_data_pair;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_data_pair_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_data_pair_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_hit_data_pair;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair_Inner = { "hit_data_pair", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair, METADATA_PARAMS(0, nullptr) }; // 2132537031
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair = { "hit_data_pair", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms, hit_data_pair), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair_MetaData), Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair_MetaData) }; // 2132537031
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::NewProp_hit_data_pair,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin, nullptr, "DragonIKFootSolverTraceData__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::_Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::_Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FDragonIKFootSolverTraceData_DelegateWrapper(const FMulticastScriptDelegate& DragonIKFootSolverTraceData, TArray<FDragonIKTraceKeyValuePair> const& hit_data_pair)
{
	struct _Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms
	{
		TArray<FDragonIKTraceKeyValuePair> hit_data_pair;
	};
	_Script_DragonIKPlugin_eventDragonIKFootSolverTraceData_Parms Parms;
	Parms.hit_data_pair=hit_data_pair;
	DragonIKFootSolverTraceData.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct DragonIKTraceManagerComponent_eventSpineSolverTraceData_Parms
	{
		TArray<FDragonIKTraceKeyValuePair> hit_data_pair;
	};
	static FName NAME_UDragonIKTraceManagerComponent_SpineSolverTraceData = FName(TEXT("SpineSolverTraceData"));
	void UDragonIKTraceManagerComponent::SpineSolverTraceData(TArray<FDragonIKTraceKeyValuePair> const& hit_data_pair)
	{
		DragonIKTraceManagerComponent_eventSpineSolverTraceData_Parms Parms;
		Parms.hit_data_pair=hit_data_pair;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKTraceManagerComponent_SpineSolverTraceData),&Parms);
	}
	void UDragonIKTraceManagerComponent::StaticRegisterNativesUDragonIKTraceManagerComponent()
	{
	}
	struct Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_data_pair_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_data_pair_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_hit_data_pair;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair_Inner = { "hit_data_pair", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair, METADATA_PARAMS(0, nullptr) }; // 2132537031
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair = { "hit_data_pair", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKTraceManagerComponent_eventSpineSolverTraceData_Parms, hit_data_pair), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair_MetaData), Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair_MetaData) }; // 2132537031
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::NewProp_hit_data_pair,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKTraceManagerComponent, nullptr, "SpineSolverTraceData", nullptr, nullptr, Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::PropPointers), sizeof(DragonIKTraceManagerComponent_eventSpineSolverTraceData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKTraceManagerComponent_eventSpineSolverTraceData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDragonIKTraceManagerComponent);
	UClass* Z_Construct_UClass_UDragonIKTraceManagerComponent_NoRegister()
	{
		return UDragonIKTraceManagerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_read_this_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_read_this;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Is_Enabled_MetaData[];
#endif
		static void NewProp_Is_Enabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Is_Enabled;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShow_Spine_Trace_Lines_InGame_MetaData[];
#endif
		static void NewProp_bShow_Spine_Trace_Lines_InGame_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShow_Spine_Trace_Lines_InGame;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShow_Foot_Trace_Lines_InGame_MetaData[];
#endif
		static void NewProp_bShow_Foot_Trace_Lines_InGame_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShow_Foot_Trace_Lines_InGame;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnDragonikFootHitData_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDragonikFootHitData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDragonIKTraceManagerComponent_SpineSolverTraceData, "SpineSolverTraceData" }, // 2974996363
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DragonIK" },
		{ "DisplayName", "Dragonik Trace Manager" },
		{ "IncludePath", "DragonIKTraceManagerComponent.h" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_read_this_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n*\n* This is a new optional feature which centrally manages the trace firing logic, of the spine and foot solvers of your character's animation blueprint.\n* Enable \"Use External Trace Management Component\" boolean parameter in the dragonik foot solver and spine solver.\n* Using this could potentially improve editor stability and avoid certain rare niche crashes such as during multithreading.\n* This lets the spine and foot solvers to do it's calculations without the burden of firing traces from it's internal update thread.\n* You also get access to the trace hit info from the \"On Dragonik Foot Hit Data\" callback event.\n*/" },
#endif
		{ "DisplayName", "HOVER MOUSE HERE FOR TIPS!" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is a new optional feature which centrally manages the trace firing logic, of the spine and foot solvers of your character's animation blueprint.\n* Enable \"Use External Trace Management Component\" boolean parameter in the dragonik foot solver and spine solver.\n* Using this could potentially improve editor stability and avoid certain rare niche crashes such as during multithreading.\n* This lets the spine and foot solvers to do it's calculations without the burden of firing traces from it's internal update thread.\n* You also get access to the trace hit info from the \"On Dragonik Foot Hit Data\" callback event." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_read_this = { "read_this", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKTraceManagerComponent, read_this), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_read_this_MetaData), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_read_this_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "DisplayName", "Is Enabled ?" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled_SetBit(void* Obj)
	{
		((UDragonIKTraceManagerComponent*)Obj)->Is_Enabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled = { "Is_Enabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKTraceManagerComponent), &Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled_MetaData), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "DisplayName", "Show Spine Solver Traces" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame_SetBit(void* Obj)
	{
		((UDragonIKTraceManagerComponent*)Obj)->bShow_Spine_Trace_Lines_InGame = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame = { "bShow_Spine_Trace_Lines_InGame", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKTraceManagerComponent), &Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame_MetaData), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame_MetaData[] = {
		{ "Category", "DragonIKTraceManager" },
		{ "DisplayName", "Show Foot Solver Traces" },
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame_SetBit(void* Obj)
	{
		((UDragonIKTraceManagerComponent*)Obj)->bShow_Foot_Trace_Lines_InGame = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame = { "bShow_Foot_Trace_Lines_InGame", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKTraceManagerComponent), &Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame_MetaData), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_OnDragonikFootHitData_MetaData[] = {
		{ "ModuleRelativePath", "Public/DragonIKTraceManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_OnDragonikFootHitData = { "OnDragonikFootHitData", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKTraceManagerComponent, OnDragonikFootHitData), Z_Construct_UDelegateFunction_DragonIKPlugin_DragonIKFootSolverTraceData__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_OnDragonikFootHitData_MetaData), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_OnDragonikFootHitData_MetaData) }; // 196537750
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_read_this,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_Is_Enabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Spine_Trace_Lines_InGame,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_bShow_Foot_Trace_Lines_InGame,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::NewProp_OnDragonikFootHitData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDragonIKTraceManagerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::ClassParams = {
		&UDragonIKTraceManagerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDragonIKTraceManagerComponent()
	{
		if (!Z_Registration_Info_UClass_UDragonIKTraceManagerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDragonIKTraceManagerComponent.OuterSingleton, Z_Construct_UClass_UDragonIKTraceManagerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDragonIKTraceManagerComponent.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UClass* StaticClass<UDragonIKTraceManagerComponent>()
	{
		return UDragonIKTraceManagerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDragonIKTraceManagerComponent);
	UDragonIKTraceManagerComponent::~UDragonIKTraceManagerComponent() {}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::EnumInfo[] = {
		{ EDragonIKTraceMType_StaticEnum, TEXT("EDragonIKTraceMType"), &Z_Registration_Info_UEnum_EDragonIKTraceMType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4045379752U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ScriptStructInfo[] = {
		{ FDragonIKTraceKeyValuePair::StaticStruct, Z_Construct_UScriptStruct_FDragonIKTraceKeyValuePair_Statics::NewStructOps, TEXT("DragonIKTraceKeyValuePair"), &Z_Registration_Info_UScriptStruct_DragonIKTraceKeyValuePair, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonIKTraceKeyValuePair), 2132537031U) },
		{ FDragonIKTraceMParams::StaticStruct, Z_Construct_UScriptStruct_FDragonIKTraceMParams_Statics::NewStructOps, TEXT("DragonIKTraceMParams"), &Z_Registration_Info_UScriptStruct_DragonIKTraceMParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonIKTraceMParams), 4041424791U) },
		{ FDragonIKTraceParamKeyValuePair::StaticStruct, Z_Construct_UScriptStruct_FDragonIKTraceParamKeyValuePair_Statics::NewStructOps, TEXT("DragonIKTraceParamKeyValuePair"), &Z_Registration_Info_UScriptStruct_DragonIKTraceParamKeyValuePair, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonIKTraceParamKeyValuePair), 2886753567U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDragonIKTraceManagerComponent, UDragonIKTraceManagerComponent::StaticClass, TEXT("UDragonIKTraceManagerComponent"), &Z_Registration_Info_UClass_UDragonIKTraceManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDragonIKTraceManagerComponent), 1480597723U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_3454653894(TEXT("/Script/DragonIKPlugin"),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKTraceManagerComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
