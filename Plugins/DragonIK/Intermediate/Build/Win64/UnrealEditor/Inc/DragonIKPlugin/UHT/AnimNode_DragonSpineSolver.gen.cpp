// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonSpineSolver.h"
#include "../../Source/Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "../../Source/Runtime/Engine/Public/Animation/BoneReference.h"
#include "DragonIK_Library.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonSpineSolver() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EIKTrace_Type_Plugin();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_MultiInput();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_Type2MultiInput();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ETraceTypeQuery();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBoneReference();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERefPosePluginEnum;
	static UEnum* ERefPosePluginEnum_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERefPosePluginEnum.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERefPosePluginEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("ERefPosePluginEnum"));
		}
		return Z_Registration_Info_UEnum_ERefPosePluginEnum.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<ERefPosePluginEnum>()
	{
		return ERefPosePluginEnum_StaticEnum();
	}
	struct Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enumerators[] = {
		{ "ERefPosePluginEnum::VE_Animated", (int64)ERefPosePluginEnum::VE_Animated },
		{ "ERefPosePluginEnum::VE_Rest", (int64)ERefPosePluginEnum::VE_Rest },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\"BlueprintType\" is essential to include\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\"BlueprintType\" is essential to include" },
#endif
		{ "VE_Animated.DisplayName", "Animated Pose" },
		{ "VE_Animated.Name", "ERefPosePluginEnum::VE_Animated" },
		{ "VE_Rest.DisplayName", "Rest Pose" },
		{ "VE_Rest.Name", "ERefPosePluginEnum::VE_Rest" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		"ERefPosePluginEnum",
		"ERefPosePluginEnum",
		Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum()
	{
		if (!Z_Registration_Info_UEnum_ERefPosePluginEnum.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERefPosePluginEnum.InnerSingleton, Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERefPosePluginEnum.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESolverComplexityPluginEnum;
	static UEnum* ESolverComplexityPluginEnum_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("ESolverComplexityPluginEnum"));
		}
		return Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<ESolverComplexityPluginEnum>()
	{
		return ESolverComplexityPluginEnum_StaticEnum();
	}
	struct Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enumerators[] = {
		{ "ESolverComplexityPluginEnum::VE_Simple", (int64)ESolverComplexityPluginEnum::VE_Simple },
		{ "ESolverComplexityPluginEnum::VE_Complex", (int64)ESolverComplexityPluginEnum::VE_Complex },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\"BlueprintType\" is essential to include\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\"BlueprintType\" is essential to include" },
#endif
		{ "VE_Complex.Comment", "/*\n\x09* Legacy fabrik method is the original previous method of solving.\n\x09* Fabrik ensures all bones are transformed, but its pitfalls is that it might cause undesired deformations.\n\x09*/" },
		{ "VE_Complex.DisplayName", "Legacy Fabrik Method" },
		{ "VE_Complex.Name", "ESolverComplexityPluginEnum::VE_Complex" },
		{ "VE_Complex.ToolTip", "* Legacy fabrik method is the original previous method of solving.\n* Fabrik ensures all bones are transformed, but its pitfalls is that it might cause undesired deformations." },
		{ "VE_Simple.Comment", "/*\n\x09* This is the newer method of solving that provides a more simpler and more stable body solving.\n\x09* Ensures all bones between the pelvis and chest remain the same.\n\x09*/" },
		{ "VE_Simple.DisplayName", "Simpler Solving Method" },
		{ "VE_Simple.Name", "ESolverComplexityPluginEnum::VE_Simple" },
		{ "VE_Simple.ToolTip", "* This is the newer method of solving that provides a more simpler and more stable body solving.\n* Ensures all bones between the pelvis and chest remain the same." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		"ESolverComplexityPluginEnum",
		"ESolverComplexityPluginEnum",
		Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum()
	{
		if (!Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.InnerSingleton, Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESolverComplexityPluginEnum.InnerSingleton;
	}

static_assert(std::is_polymorphic<FAnimNode_DragonSpineSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonSpineSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver;
class UScriptStruct* FAnimNode_DragonSpineSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonSpineSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonSpineSolver>()
{
	return FAnimNode_DragonSpineSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_use_trace_manager_component_MetaData[];
#endif
		static void NewProp_use_trace_manager_component_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_trace_manager_component;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_solver_identifier_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_solver_identifier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dragon_input_data_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_dragon_input_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_use_type2_input_MetaData[];
#endif
		static void NewProp_use_type2_input_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_type2_input;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dragon_input_type2_data_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_dragon_input_type2_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Precision_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Precision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotationLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxIterations_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxIterations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Shift_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Shift_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Trace_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anti_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Anti_Trace_Channel;
		static const UECodeGen_Private::FBytePropertyParams NewProp_trace_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trace_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_trace_type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Trace_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_hit_complex_MetaData[];
#endif
		static void NewProp_line_trace_hit_complex_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_line_trace_hit_complex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trace_interval_duration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_trace_interval_duration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_LOD_Specific_Intervals_MetaData[];
#endif
		static void NewProp_Use_LOD_Specific_Intervals_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_LOD_Specific_Intervals;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LOD0_Interval_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LOD0_Interval;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LOD1_Interval_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LOD1_Interval;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LOD2_Interval_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LOD2_Interval;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Trace_Distance_Adapting_MetaData[];
#endif
		static void NewProp_Use_Trace_Distance_Adapting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Trace_Distance_Adapting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Max_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Trace_Max_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Interval_Velocity_Curve_MetaData[];
#endif
		static void NewProp_Use_Interval_Velocity_Curve_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Interval_Velocity_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interval_Velocity_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Interval_Velocity_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Override_Curve_Velocity_MetaData[];
#endif
		static void NewProp_Override_Curve_Velocity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Override_Curve_Velocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_custom_velocity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_custom_velocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rotate_Around_Translate_MetaData[];
#endif
		static void NewProp_Rotate_Around_Translate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Rotate_Around_Translate;
		static const UECodeGen_Private::FBytePropertyParams NewProp_complexity_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_complexity_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_complexity_type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ignore_Lerping_MetaData[];
#endif
		static void NewProp_Ignore_Lerping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Ignore_Lerping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_virtual_scale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_virtual_scale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_downward_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_downward_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_upper_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_upper_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Anti_Channel_MetaData[];
#endif
		static void NewProp_Use_Anti_Channel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Anti_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_stabilize_pelvis_legs_MetaData[];
#endif
		static void NewProp_stabilize_pelvis_legs_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_stabilize_pelvis_legs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_UpSlopeStabilization_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_UpSlopeStabilization_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_DownSlopeStabilization_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_DownSlopeStabilization_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_stabilize_chest_legs_MetaData[];
#endif
		static void NewProp_stabilize_chest_legs_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_stabilize_chest_legs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_UpSlopeStabilization_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_UpSlopeStabilization_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_DownslopeStabilization_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_DownslopeStabilization_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Stabilization_Head_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Stabilization_Head_Bone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Stabilization_Tail_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Stabilization_Tail_Bone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Ducking_Feature_MetaData[];
#endif
		static void NewProp_Use_Ducking_Feature_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Ducking_Feature;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ducking_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Ducking_Trace_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ducking_Limit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Ducking_Limit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_Crouch_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_Crouch_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_Crouch_Rotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_Crouch_Rotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Duck_Pelvis_Trace_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Duck_Pelvis_Trace_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Crouch_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Crouch_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Crouch_Rotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Crouch_Rotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Duck_Chest_Trace_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Duck_Chest_Trace_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slanted_Height_Up_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Slanted_Height_Up_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Slanted_Height_Down_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Slanted_Height_Down_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dip_multiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dip_multiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pelvis_adaptive_gravity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pelvis_adaptive_gravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_reverse_fabrik_MetaData[];
#endif
		static void NewProp_reverse_fabrik_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_reverse_fabrik;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Calculation_To_RefPose_MetaData[];
#endif
		static void NewProp_Calculation_To_RefPose_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Calculation_To_RefPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Slanted_Height_Up_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Slanted_Height_Up_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Slanted_Height_Down_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Slanted_Height_Down_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_chest_side_dip_multiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_chest_side_dip_multiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_chest_adaptive_gravity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_chest_adaptive_gravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Base_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Base_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_Base_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_Base_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_virtual_leg_width_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_virtual_leg_width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Maximum_Dip_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Maximum_Dip_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_Height_Multiplier_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Pelvis_Height_Multiplier_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Maximum_Dip_Height_Chest_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Maximum_Dip_Height_Chest;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Height_Multiplier_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Chest_Height_Multiplier_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_power_between_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_rotation_power_between;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Automatic_Fabrik_Selection_MetaData[];
#endif
		static void NewProp_Use_Automatic_Fabrik_Selection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Automatic_Fabrik_Selection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Lerp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Trace_Lerp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_Lerp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Location_Lerp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_Lerp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_Lerp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interpolation_Multiplier_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Interpolation_Multiplier_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Influence_Alpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_Influence_Alpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_ForwardRotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_ForwardRotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_UpwardForwardRotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pelvis_UpwardForwardRotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Body_Rotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Body_Rotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pelvis_Rotation_Offset_Rotator_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Pelvis_Rotation_Offset_Rotator;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_ForwardRotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_ForwardRotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_UpwardForwardRotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_UpwardForwardRotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_SidewardRotation_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Chest_SidewardRotation_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chest_Rotation_Offset_Rotator_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Chest_Rotation_Offset_Rotator;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Full_Extended_Spine_MetaData[];
#endif
		static void NewProp_Full_Extended_Spine_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Full_Extended_Spine;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_max_extension_ratio_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_max_extension_ratio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_min_extension_ratio_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_min_extension_ratio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_extension_switch_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_extension_switch_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Solver_MetaData[];
#endif
		static void NewProp_Enable_Solver_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Solver;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Work_Outside_PIE_MetaData[];
#endif
		static void NewProp_Work_Outside_PIE_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Work_Outside_PIE;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Fake_Chest_Rotations_MetaData[];
#endif
		static void NewProp_Use_Fake_Chest_Rotations_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Fake_Chest_Rotations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Fake_Pelvis_Rotations_MetaData[];
#endif
		static void NewProp_Use_Fake_Pelvis_Rotations_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Fake_Pelvis_Rotations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Force_Activation_MetaData[];
#endif
		static void NewProp_Force_Activation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Force_Activation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_accurate_feet_placement_MetaData[];
#endif
		static void NewProp_accurate_feet_placement_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_accurate_feet_placement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Accurate_Foot_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Accurate_Foot_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_use_crosshair_trace_also_for_fail_distance_MetaData[];
#endif
		static void NewProp_use_crosshair_trace_also_for_fail_distance_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_crosshair_trace_also_for_fail_distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Only_Root_Solve_MetaData[];
#endif
		static void NewProp_Only_Root_Solve_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Only_Root_Solve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ignore_Chest_Solve_MetaData[];
#endif
		static void NewProp_Ignore_Chest_Solve_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Ignore_Chest_Solve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Overall_PostSolved_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Overall_PostSolved_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_character_direction_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_character_direction_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Forward_Direction_Vector_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Forward_Direction_Vector;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_flip_forward_and_right_MetaData[];
#endif
		static void NewProp_flip_forward_and_right_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_flip_forward_and_right;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SolverReferencePose_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SolverReferencePose_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SolverReferencePose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Spine_Feet_Connect_MetaData[];
#endif
		static void NewProp_Spine_Feet_Connect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Spine_Feet_Connect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Snake_Joint_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Snake_Joint_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Snake_Interpolation_MetaData[];
#endif
		static void NewProp_Enable_Snake_Interpolation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Snake_Interpolation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_is_snake_MetaData[];
#endif
		static void NewProp_is_snake_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_is_snake;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ignore_End_Points_MetaData[];
#endif
		static void NewProp_Ignore_End_Points_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Ignore_End_Points;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Maximum_Feet_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Maximum_Feet_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Minimum_Feet_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Minimum_Feet_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayLineTrace_MetaData[];
#endif
		static void NewProp_DisplayLineTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DisplayLineTrace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//USTRUCT(BlueprintInternalUseOnly)\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USTRUCT(BlueprintInternalUseOnly)" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonSpineSolver>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component_MetaData[] = {
		{ "Category", "OptionalTraceManagerComponentSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * This is a new optional experimental feature.\n\x09 * Enable this to let the trace manager component to do the heavy lifting of the trace firing logic. The trace manager component runs in your Pawn blueprint.\n\x09 * Trace fire is independently centralized in an orderly fashion instead of the default decentralized approach.\n\x09 * By default this is disabled, and trace firing is directly handled within each solver.\n\x09 * Enabling this can potentially fix stability issues in rare scenarios in the use of this solver along with overall engine stability.\n\x09 */" },
#endif
		{ "DisplayName", "Use External Trace Manager Component ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is a new optional experimental feature.\n* Enable this to let the trace manager component to do the heavy lifting of the trace firing logic. The trace manager component runs in your Pawn blueprint.\n* Trace fire is independently centralized in an orderly fashion instead of the default decentralized approach.\n* By default this is disabled, and trace firing is directly handled within each solver.\n* Enabling this can potentially fix stability issues in rare scenarios in the use of this solver along with overall engine stability." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->use_trace_manager_component = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component = { "use_trace_manager_component", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_solver_identifier_MetaData[] = {
		{ "Category", "OptionalTraceManagerComponentSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Only relevant if using the optional \"DragonIK Trace Manager component\".\n\x09 * If this animbp only has one spine solver only, you can leave it unchanged.\n\x09 * If there is more than one foot solver, make sure they have any unique number here.\n\x09 */" },
#endif
		{ "DisplayName", "Unique Solver Identifier" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Only relevant if using the optional \"DragonIK Trace Manager component\".\n* If this animbp only has one spine solver only, you can leave it unchanged.\n* If there is more than one foot solver, make sure they have any unique number here." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_solver_identifier = { "solver_identifier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, solver_identifier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_solver_identifier_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_solver_identifier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_data_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Type the input bones used by the solver - pelvis,spine-start and feets\n* Pull this pin to create a \"make struct\" and easily type out the bones.\n* Optionally you can type the bones directly inside the solver. Doing so is slightly more recommended because it activates fast path.\n*/" },
#endif
		{ "EditCondition", "!use_type2_input" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Type the input bones used by the solver - pelvis,spine-start and feets\n* Pull this pin to create a \"make struct\" and easily type out the bones.\n* Optionally you can type the bones directly inside the solver. Doing so is slightly more recommended because it activates fast path." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_data = { "dragon_input_data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, dragon_input_data), Z_Construct_UScriptStruct_FDragonData_MultiInput, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_data_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_data_MetaData) }; // 1496037613
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If you have a more \"complicated\" skeleton on your character, you can make use of the second input method which gives you more control.\n\x09 * This input method is very flexible and lets you make use of characters with a lot of unnatural parallel bone structures on an character/creature\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If you have a more \"complicated\" skeleton on your character, you can make use of the second input method which gives you more control.\n* This input method is very flexible and lets you make use of characters with a lot of unnatural parallel bone structures on an character/creature" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->use_type2_input = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input = { "use_type2_input", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_type2_data_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If you have a more \"complicated\" skeleton on your character, you can make use of the second input method which gives you more control.\n\x09 * This input method is very flexible and lets you make use of characters with a lot of unnatural parallel bone structures on an character/creature.\n\x09 * \n\x09 */" },
#endif
		{ "EditCondition", "use_type2_input" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If you have a more \"complicated\" skeleton on your character, you can make use of the second input method which gives you more control.\n* This input method is very flexible and lets you make use of characters with a lot of unnatural parallel bone structures on an character/creature." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_type2_data = { "dragon_input_type2_data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, dragon_input_type2_data), Z_Construct_UScriptStruct_FDragonData_Type2MultiInput, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_type2_data_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_type2_data_MetaData) }; // 3093450381
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Precision_MetaData[] = {
		{ "Category", "Solver" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tolerance for final tip location delta from EffectorLocation*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tolerance for final tip location delta from EffectorLocation" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Precision = { "Precision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Precision), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Precision_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Precision_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_RotationLimit_MetaData[] = {
		{ "Category", "Solver" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n     * The rotation limit of each bones for spine solving.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The rotation limit of each bones for spine solving." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_RotationLimit = { "RotationLimit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, RotationLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_RotationLimit_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_RotationLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_MaxIterations_MetaData[] = {
		{ "Category", "Solver" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09  * Maximum number of iterations allowed.\n\x09  * Best left untouched. Higher values can be more costly. */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Maximum number of iterations allowed.\n* Best left untouched. Higher values can be more costly." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_MaxIterations = { "MaxIterations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, MaxIterations), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_MaxIterations_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_MaxIterations_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Shift_Speed_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09 * The transistion speed between solve and unsolve state (eg:- when character jumps and falls back to ground).\n\x09\x09 * Lower values means slower but smoother transition.\n\x09\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinShownByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The transistion speed between solve and unsolve state (eg:- when character jumps and falls back to ground).\n* Lower values means slower but smoother transition." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Shift_Speed = { "Shift_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Shift_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Shift_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Shift_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Channel_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings.*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings." },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Channel = { "Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Channel_MetaData) }; // 2725057287
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Anti_Trace_Channel_MetaData[] = {
		{ "Category", "BasicSettings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Anti_Trace_Channel = { "Anti_Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Anti_Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Anti_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Anti_Trace_Channel_MetaData) }; // 2725057287
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Choose Trace type - Line,Sphere and Box.*/" },
#endif
		{ "DisplayName", "Trace Type" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Choose Trace type - Line,Sphere and Box." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type = { "trace_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, trace_type), Z_Construct_UEnum_DragonIKPlugin_EIKTrace_Type_Plugin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type_MetaData) }; // 1628889231
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Radius_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* If trace type is box or sphere, its radius is controlled using the Trace Radius */" },
#endif
		{ "DisplayName", "Trace Radius" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If trace type is box or sphere, its radius is controlled using the Trace Radius" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Radius = { "Trace_Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Trace_Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Radius_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex_MetaData[] = {
		{ "Category", "BasicSettings" },
		{ "DisplayName", "Trace Hit Complex ? (True for complex, False for simple)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->line_trace_hit_complex = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex = { "line_trace_hit_complex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_interval_duration_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Trace Firing Interval Constant (Performance)" },
		{ "EditCondition", "!Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_interval_duration = { "trace_interval_duration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, trace_interval_duration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_interval_duration_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_interval_duration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Use LOD specific intervals ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_LOD_Specific_Intervals = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals = { "Use_LOD_Specific_Intervals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD0_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD0 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD0_Interval = { "LOD0_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, LOD0_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD0_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD0_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD1_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD1 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD1_Interval = { "LOD1_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, LOD1_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD1_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD1_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD2_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD2 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD2_Interval = { "LOD2_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, LOD2_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD2_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD2_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Turn off traces after a distance from the camera ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Trace_Distance_Adapting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting = { "Use_Trace_Distance_Adapting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Max_Distance_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Max distance until traces are turned off" },
		{ "EditCondition", "Use_Trace_Distance_Adapting" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Max_Distance = { "Trace_Max_Distance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Trace_Max_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Max_Distance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Max_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Use trace interval-velocity multiplier curve function ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Interval_Velocity_Curve = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve = { "Use_Interval_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData[] = {
		{ "Category", "TracePerformance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The value from this curve at the proportional velocity is multiplied with the trace interval constant or the LOD intervals\n\x09*/" },
#endif
		{ "DisplayName", "Trace interval-velocity multiplier curve" },
		{ "EditCondition", "Use_Interval_Velocity_Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The value from this curve at the proportional velocity is multiplied with the trace interval constant or the LOD intervals" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interval_Velocity_Curve = { "Interval_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Interval_Velocity_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity_MetaData[] = {
		{ "Category", "MasterCurveSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* If enabled, the velocity that drives the curves is the custom velocity parameter instead of calculating from the character blueprint movement component.\n*/" },
#endif
		{ "DisplayName", "Use custom velocity instead of automatic character blueprint velocity for curves ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If enabled, the velocity that drives the curves is the custom velocity parameter instead of calculating from the character blueprint movement component." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Override_Curve_Velocity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity = { "Override_Curve_Velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_custom_velocity_MetaData[] = {
		{ "Category", "MasterCurveSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Used as the velocity for curves if enabled.\n\x09* Overrides the automatic velocity calculation, useful for non-Character blueprints that doesn't have a movement component.\n\x09*/" },
#endif
		{ "DisplayName", "Custom Curve Velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Used as the velocity for curves if enabled.\n* Overrides the automatic velocity calculation, useful for non-Character blueprints that doesn't have a movement component." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_custom_velocity = { "custom_velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, custom_velocity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_custom_velocity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_custom_velocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Internally disabled if using simple solving method.\n\x09* Enable this to rotate the pelvis and chest in perfect perpendicular fashion.\n\x09* Good for general purpose, but can cause extreme rotation and translations in wild,sharp and uneven surfaces.\n\x09* Recommended to experiment between this enabled and disabled.\n\x09*/" },
#endif
		{ "DisplayName", "Rotate and move bone around terrain ? (Disabling gives more stable but slightly inaccurate solving)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Internally disabled if using simple solving method.\n* Enable this to rotate the pelvis and chest in perfect perpendicular fashion.\n* Good for general purpose, but can cause extreme rotation and translations in wild,sharp and uneven surfaces.\n* Recommended to experiment between this enabled and disabled." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Rotate_Around_Translate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate = { "Rotate_Around_Translate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* \"Simple Solving Method\" is the newer method of solving only the bones that matter.\n* SSM Ensures all bones between the pelvis and chest remain the same.\n* \"Legacy fabrik method\" is the original previous method of solving until 2.2.6.\n* LFM ensures all bones are transformed and solved, but it might cause undesired deformations on complex rigs.\n*/" },
#endif
		{ "DisplayName", "Solving Method for bones between pelvis and chest" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \"Simple Solving Method\" is the newer method of solving only the bones that matter.\n* SSM Ensures all bones between the pelvis and chest remain the same.\n* \"Legacy fabrik method\" is the original previous method of solving until 2.2.6.\n* LFM ensures all bones are transformed and solved, but it might cause undesired deformations on complex rigs." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type = { "complexity_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, complexity_type), Z_Construct_UEnum_DragonIKPlugin_ESolverComplexityPluginEnum, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type_MetaData) }; // 3253964227
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to bypass interpolation and use instant solving data! */" },
#endif
		{ "DisplayName", "Ignore Lerping" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to bypass interpolation and use instant solving data!" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Ignore_Lerping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping = { "Ignore_Lerping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_scale_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters.\n*/" },
#endif
		{ "DisplayName", "Global trace scale multiplier" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_scale = { "virtual_scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, virtual_scale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_scale_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_downward_height_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Line trace height below the spines/feets */" },
#endif
		{ "DisplayName", "Trace Downward Height" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Line trace height below the spines/feets" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_downward_height = { "line_trace_downward_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, line_trace_downward_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_downward_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_downward_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_upper_height_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Line trace height above the spines/feets */" },
#endif
		{ "DisplayName", "Trace Upward Height" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Line trace height above the spines/feets" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_upper_height = { "line_trace_upper_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, line_trace_upper_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_upper_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_upper_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Use the anti-channel in the solving logic. Use meshes with the anti-channel set to \"block\" to repel the traces from touching ceilings and closed spaces.\n* Also useful when under stairs or narrow multi-storied buildings. Cover the ceilings and under stairs with anti-channel blocked meshes.\n*/" },
#endif
		{ "DisplayName", "Use Anti-Channel Functionality" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Use the anti-channel in the solving logic. Use meshes with the anti-channel set to \"block\" to repel the traces from touching ceilings and closed spaces.\n* Also useful when under stairs or narrow multi-storied buildings. Cover the ceilings and under stairs with anti-channel blocked meshes." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Anti_Channel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel = { "Use_Anti_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs_MetaData[] = {
		{ "Category", "LegStabilization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enabling this will make the legs connected to the pelvis to avoid any deformations and be independent.\n\x09*/" },
#endif
		{ "DisplayName", "Stabilize legs connected to pelvis during body bending ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enabling this will make the legs connected to the pelvis to avoid any deformations and be independent." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->stabilize_pelvis_legs = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs = { "stabilize_pelvis_legs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpSlopeStabilization_Alpha_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Stabilization alpha of pelvis legs in an upward facing slope\n\x09* 1 = Full leg stabilization.\n\x09* 0 = No leg stabilization\n\x09*/" },
#endif
		{ "DisplayName", "(Upslope) Pelvic legs stabilization alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Stabilization alpha of pelvis legs in an upward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization" },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpSlopeStabilization_Alpha = { "Pelvis_UpSlopeStabilization_Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_UpSlopeStabilization_Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpSlopeStabilization_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpSlopeStabilization_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_DownSlopeStabilization_Alpha_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Stabilization alpha of pelvis legs in an downward facing slope\n\x09* 1 = Full leg stabilization.\n\x09* 0 = No leg stabilization\n\x09*/" },
#endif
		{ "DisplayName", "(Downslope) Pelvic legs stabilization alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Stabilization alpha of pelvis legs in an downward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization" },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_DownSlopeStabilization_Alpha = { "Pelvis_DownSlopeStabilization_Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_DownSlopeStabilization_Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_DownSlopeStabilization_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_DownSlopeStabilization_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs_MetaData[] = {
		{ "Category", "LegStabilization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enabling this will make the legs connected to the chest/spine-start to avoid any deformations and be independent.\n\x09*/" },
#endif
		{ "DisplayName", "Stabilize legs connected to chest during body bending ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enabling this will make the legs connected to the chest/spine-start to avoid any deformations and be independent." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->stabilize_chest_legs = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs = { "stabilize_chest_legs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpSlopeStabilization_Alpha_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Stabilization alpha of chest legs in an upward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization\n*/" },
#endif
		{ "DisplayName", "(Upslope) Chest legs stabilization alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Stabilization alpha of chest legs in an upward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization" },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpSlopeStabilization_Alpha = { "Chest_UpSlopeStabilization_Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_UpSlopeStabilization_Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpSlopeStabilization_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpSlopeStabilization_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_DownslopeStabilization_Alpha_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Stabilization alpha of chest legs in an downward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization\n*/" },
#endif
		{ "DisplayName", "(Downslope) Chest legs stabilization alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Stabilization alpha of chest legs in an downward facing slope\n* 1 = Full leg stabilization.\n* 0 = No leg stabilization" },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_DownslopeStabilization_Alpha = { "Chest_DownslopeStabilization_Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_DownslopeStabilization_Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_DownslopeStabilization_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_DownslopeStabilization_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Head_Bone_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "DisplayName", "(optional) Head bone to be stabilized" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Head_Bone = { "Stabilization_Head_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Stabilization_Head_Bone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Head_Bone_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Head_Bone_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Tail_Bone_MetaData[] = {
		{ "Category", "LegStabilization" },
		{ "DisplayName", "(optional) Tail bone to be stabilized" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Tail_Bone = { "Stabilization_Tail_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Stabilization_Tail_Bone), Z_Construct_UScriptStruct_FBoneReference, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Tail_Bone_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Tail_Bone_MetaData) }; // 1286936164
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is completely enable/disable the ducking functionality.\n\x09*/" },
#endif
		{ "DisplayName", "(optional) Use Ducking/Crouching feature ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is completely enable/disable the ducking functionality." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Ducking_Feature = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature = { "Use_Ducking_Feature", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Trace_Channel_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Trace channel only used for the ducking/crouching logic.\n\x09*/" },
#endif
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Trace channel only used for the ducking/crouching logic." },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Trace_Channel = { "Ducking_Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Ducking_Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Trace_Channel_MetaData) }; // 2725057287
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Limit_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Height of ducking trace starting from the pelvis bone position.\n*/" },
#endif
		{ "DisplayName", "Max Ducking Height Limit" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Height of ducking trace starting from the pelvis bone position." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Limit = { "Ducking_Limit", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Ducking_Limit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Limit_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Limit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Height_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Height of ducking trace starting from the pelvis bone position.\n\x09*/" },
#endif
		{ "DisplayName", "Pelvis Ducking Trace Height" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Height of ducking trace starting from the pelvis bone position." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Height = { "Pelvis_Crouch_Height", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_Crouch_Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Rotation_Intensity_MetaData[] = {
		{ "Category", "DuckingSettings" },
		{ "DisplayName", "Pelvis Ducking Rotation Intensity" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Rotation_Intensity = { "Pelvis_Crouch_Rotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_Crouch_Rotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Rotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Rotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Pelvis_Trace_Offset_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Vertical offset of the pelvis ducking trace.\n\x09*/" },
#endif
		{ "DisplayName", "Pelvis Ducking Trace Offset" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Vertical offset of the pelvis ducking trace." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Pelvis_Trace_Offset = { "Duck_Pelvis_Trace_Offset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Duck_Pelvis_Trace_Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Pelvis_Trace_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Pelvis_Trace_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Height_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Height of ducking trace starting from the chest bone position.\n\x09* Not used on bipeds and single body spiders.\n\x09*/" },
#endif
		{ "DisplayName", "Chest Ducking Trace Height" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Height of ducking trace starting from the chest bone position.\n* Not used on bipeds and single body spiders." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Height = { "Chest_Crouch_Height", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Crouch_Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Rotation_Intensity_MetaData[] = {
		{ "Category", "DuckingSettings" },
		{ "DisplayName", "Chest Ducking Rotation Intensity" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Rotation_Intensity = { "Chest_Crouch_Rotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Crouch_Rotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Rotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Rotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Chest_Trace_Offset_MetaData[] = {
		{ "Category", "DuckingSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Vertical offset of the chest ducking trace\n\x09* Not used on bipeds and single body spiders.\n\x09*/" },
#endif
		{ "DisplayName", "Chest Ducking Trace Offset" },
		{ "EditCondition", "Use_Ducking_Feature" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Vertical offset of the chest ducking trace\n* Not used on bipeds and single body spiders." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Chest_Trace_Offset = { "Duck_Chest_Trace_Offset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Duck_Chest_Trace_Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Chest_Trace_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Chest_Trace_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Up_Offset_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Extra dip when pelvis is on an upward slope*/" },
#endif
		{ "DisplayName", "Extra dip When going up slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Extra dip when pelvis is on an upward slope" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Up_Offset = { "Slanted_Height_Up_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Slanted_Height_Up_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Up_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Up_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Down_Offset_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Extra dip when pelvis is on a downward slope*/" },
#endif
		{ "DisplayName", "Extra dip When going down slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Extra dip when pelvis is on a downward slope" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Down_Offset = { "Slanted_Height_Down_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Slanted_Height_Down_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Down_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Down_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dip_multiplier_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* If your character isn't dipping enough to touch the ground during slopes, slightly increase this value.\n* Only handles dipping based on the pairs of feet and the difference between their respective trace hit location.\n* Will not dip on flat surfaces.\n*/" },
#endif
		{ "DisplayName", "Extra dip multiplier relative to feet lift difference" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If your character isn't dipping enough to touch the ground during slopes, slightly increase this value.\n* Only handles dipping based on the pairs of feet and the difference between their respective trace hit location.\n* Will not dip on flat surfaces." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dip_multiplier = { "dip_multiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, dip_multiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dip_multiplier_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dip_multiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_pelvis_adaptive_gravity_MetaData[] = {
		{ "Category", "PelvisControl" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "-1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Blend between a low elevation priority (-1) to a high elevation priority (1) when calculating the dip.\n\x09* -1 means dipping the body to the lowest leg.\n\x09* +1 means rising the body to the highest leg.\n\x09* Any value in between is a blend between the highest and lowest point.\n\x09* Useful to control over-dipping of creatures on challenging terrains. Such as dragons with small limbs but giant body on a steep slope.\n\x09*/" },
#endif
		{ "DisplayName", "Pelvis gravity priority" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Blend between a low elevation priority (-1) to a high elevation priority (1) when calculating the dip.\n* -1 means dipping the body to the lowest leg.\n* +1 means rising the body to the highest leg.\n* Any value in between is a blend between the highest and lowest point.\n* Useful to control over-dipping of creatures on challenging terrains. Such as dragons with small limbs but giant body on a steep slope." },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "-1.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_pelvis_adaptive_gravity = { "pelvis_adaptive_gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, pelvis_adaptive_gravity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_pelvis_adaptive_gravity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_pelvis_adaptive_gravity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to prioritise chest over the pelvis.\n\x09* The normal fabrik mode prioritises the pelvis transformation location when on extreme terrains.\n\x09* The reverse fabrik mode ensures chest is given priority.\n\x09*/" },
#endif
		{ "DisplayName", "Reverse Fabrik" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to prioritise chest over the pelvis.\n* The normal fabrik mode prioritises the pelvis transformation location when on extreme terrains.\n* The reverse fabrik mode ensures chest is given priority." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->reverse_fabrik = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik = { "reverse_fabrik", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Should solver calculation be based on the default reference pose or the current animated pose ?*/" },
#endif
		{ "DisplayName", "Calculation Relative To Ref Pose" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Should solver calculation be based on the default reference pose or the current animated pose ?" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Calculation_To_RefPose = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose = { "Calculation_To_RefPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Up_Offset_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Extra dip when chest is on an upward slope*/" },
#endif
		{ "DisplayName", "Extra dip When going up slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Extra dip when chest is on an upward slope" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Up_Offset = { "Chest_Slanted_Height_Up_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Slanted_Height_Up_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Up_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Up_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Down_Offset_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09* Extra dip when chest is on a downward slope*/" },
#endif
		{ "DisplayName", "Extra dip When going down slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Extra dip when chest is on a downward slope" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Down_Offset = { "Chest_Slanted_Height_Down_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Slanted_Height_Down_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Down_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Down_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_side_dip_multiplier_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* If your character isn't dipping enough to touch the ground during slopes, slightly increase this value.\n* Only handles dipping based on the pairs of feet and the difference between their respective trace hit location.\n* Will not dip on flat surfaces.\n*/" },
#endif
		{ "DisplayName", "Extra chest dip multiplier relative to feet lift difference" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If your character isn't dipping enough to touch the ground during slopes, slightly increase this value.\n* Only handles dipping based on the pairs of feet and the difference between their respective trace hit location.\n* Will not dip on flat surfaces." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_side_dip_multiplier = { "chest_side_dip_multiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, chest_side_dip_multiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_side_dip_multiplier_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_side_dip_multiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_adaptive_gravity_MetaData[] = {
		{ "Category", "ChestControl" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "-1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Blend between a low elevation priority (-1) to a high elevation priority (1) when calculating the dip.\n* -1 means dipping the body to the lowest leg.\n* +1 means rising the body to the highest leg.\n* Any value in between is a blend between the highest and lowest point.\n* Useful to control over-dipping of creatures on challenging terrains. Such as dragons with small limbs but giant body on a steep slope.\n*/" },
#endif
		{ "DisplayName", "Chest gravity priority" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Blend between a low elevation priority (-1) to a high elevation priority (1) when calculating the dip.\n* -1 means dipping the body to the lowest leg.\n* +1 means rising the body to the highest leg.\n* Any value in between is a blend between the highest and lowest point.\n* Useful to control over-dipping of creatures on challenging terrains. Such as dragons with small limbs but giant body on a steep slope." },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "-1.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_adaptive_gravity = { "chest_adaptive_gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, chest_adaptive_gravity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_adaptive_gravity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_adaptive_gravity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Base_Offset_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Optional additional Z offset for the chest*/" },
#endif
		{ "DisplayName", "Chest Z Offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Optional additional Z offset for the chest" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Base_Offset = { "Chest_Base_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Base_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Base_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Base_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Base_Offset_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Optional additional Z offset for the pelvis*/" },
#endif
		{ "DisplayName", "Pelvis Z Offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Optional additional Z offset for the pelvis" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Base_Offset = { "Pelvis_Base_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_Base_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Base_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Base_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_leg_width_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the spacing width of the 4 green trace lines arranged in a cross pattern, around both pelvis and chest bones\n\x09*  Ensure the spacing radius is tweaked to the spacing of the feet\n\x09*  This is used for important subtle calculations, such as detecting slopes/flat surfaces.\n\x09*  Used for rotation calculation for pelvis and chest if \"Alternate cross based rotation\" is enabled.\n\x09*/" },
#endif
		{ "DisplayName", "Alternate Cross Radius (4 green trace lines)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the spacing width of the 4 green trace lines arranged in a cross pattern, around both pelvis and chest bones\n*  Ensure the spacing radius is tweaked to the spacing of the feet\n*  This is used for important subtle calculations, such as detecting slopes/flat surfaces.\n*  Used for rotation calculation for pelvis and chest if \"Alternate cross based rotation\" is enabled." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_leg_width = { "virtual_leg_width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, virtual_leg_width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_leg_width_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_leg_width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Maximum height the pelvis can dip below the base pose. Lower values means pelvis will dip less.\n\x09* For biped (2 feet) characters, this is only used.\n\x09*/" },
#endif
		{ "DisplayName", "Maximum Dip Height - Pelvis" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Maximum height the pelvis can dip below the base pose. Lower values means pelvis will dip less.\n* For biped (2 feet) characters, this is only used." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height = { "Maximum_Dip_Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Maximum_Dip_Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Height_Multiplier_Curve_MetaData[] = {
		{ "Category", "PelvisControl" },
		{ "DisplayName", "(Pelvis) Dip height multiplier relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Height_Multiplier_Curve = { "Pelvis_Height_Multiplier_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_Height_Multiplier_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Height_Multiplier_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Height_Multiplier_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_Chest_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Maximum height the chest can dip below the base pose. Lower value means chest will dip less.\n\x09* Not applicable for biped (2 feet) characters.\n\x09*/" },
#endif
		{ "DisplayName", "Maximum Dip Height - Chest" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Maximum height the chest can dip below the base pose. Lower value means chest will dip less.\n* Not applicable for biped (2 feet) characters." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_Chest = { "Maximum_Dip_Height_Chest", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Maximum_Dip_Height_Chest), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_Chest_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_Chest_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Height_Multiplier_Curve_MetaData[] = {
		{ "Category", "ChestControl" },
		{ "DisplayName", "(Chest) Dip height multiplier relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Height_Multiplier_Curve = { "Chest_Height_Multiplier_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Height_Multiplier_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Height_Multiplier_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Height_Multiplier_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_rotation_power_between_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the rotation alpha value of all the bones between the pelvis and chest.\n\x09* 1 value means full solved state, while 0 means 0 solved state.\n\x09*/" },
#endif
		{ "DisplayName", "Rotation alpha between end points" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the rotation alpha value of all the bones between the pelvis and chest.\n* 1 value means full solved state, while 0 means 0 solved state." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_rotation_power_between = { "rotation_power_between", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, rotation_power_between), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_rotation_power_between_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_rotation_power_between_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection_MetaData[] = {
		{ "Category", "Experimental" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* An experimental feature, where the solver automatically switch between fabrik and reverse fabrik mode depending on the slope.\n\x09*/" },
#endif
		{ "DisplayName", "Automatic Fabrik Selection (Development)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* An experimental feature, where the solver automatically switch between fabrik and reverse fabrik mode depending on the slope." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Automatic_Fabrik_Selection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection = { "Use_Automatic_Fabrik_Selection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Lerp_Speed_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* A new parameter.\n\x09* Responsible for interpolating the trace hit data.\n\x09* Tweaking this affects the entire ik speed and smoothness.\n\x09* Works along with the location lerp speed.\n\x09* Doesn't work on snake mode. Snake mode uses the snake speed.\n\x09*/" },
#endif
		{ "DisplayName", "Trace Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* A new parameter.\n* Responsible for interpolating the trace hit data.\n* Tweaking this affects the entire ik speed and smoothness.\n* Works along with the location lerp speed.\n* Doesn't work on snake mode. Snake mode uses the snake speed." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Lerp_Speed = { "Trace_Lerp_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Trace_Lerp_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Lerp_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Lerp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Location_Lerp_Speed_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Controls the location interpolation speed of the body.\n\x09*   Higher values means faster interpolation.\n\x09*   Slower values means slower but also smoother interpolation.\n\x09*/" },
#endif
		{ "DisplayName", "Body Location Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the location interpolation speed of the body.\n*   Higher values means faster interpolation.\n*   Slower values means slower but also smoother interpolation." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Location_Lerp_Speed = { "Location_Lerp_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Location_Lerp_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Location_Lerp_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Location_Lerp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotation_Lerp_Speed_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Controls the rotation interpolation speed of the body.\n\x09*   Higher values means faster interpolation.\n\x09*   Slower values means slower but also smoother interpolation.\n\x09*/" },
#endif
		{ "DisplayName", "Body Rotation Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the rotation interpolation speed of the body.\n*   Higher values means faster interpolation.\n*   Slower values means slower but also smoother interpolation." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotation_Lerp_Speed = { "Rotation_Lerp_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Rotation_Lerp_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotation_Lerp_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotation_Lerp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interpolation_Multiplier_Curve_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The existing interpolations (location and rotation) gets multiplied with respect to the speed of your character.\n\x09*/" },
#endif
		{ "DisplayName", "Interpolation multiplier relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The existing interpolations (location and rotation) gets multiplied with respect to the speed of your character." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interpolation_Multiplier_Curve = { "Interpolation_Multiplier_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Interpolation_Multiplier_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interpolation_Multiplier_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interpolation_Multiplier_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Influence_Alpha_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The location alpha value for the chest.\n\x09*   1 means full solving of the chest transformation.\n\x09*   0 means no solving of the chest transformation.\n\x09*   Chest rotation still works regardless.\n\x09*/" },
#endif
		{ "DisplayName", "Chest Influence Alpha" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The location alpha value for the chest.\n*   1 means full solving of the chest transformation.\n*   0 means no solving of the chest transformation.\n*   Chest rotation still works regardless." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Influence_Alpha = { "Chest_Influence_Alpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Influence_Alpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Influence_Alpha_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Influence_Alpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_ForwardRotation_Intensity_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Controls the intensity of the pelvis forward rotation with respect to the downward slopes.\n\x09* 0 means no rotation applied.\n\x09*/" },
#endif
		{ "DisplayName", "Down slope pelvis Forward Rotation Intensity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the pelvis forward rotation with respect to the downward slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_ForwardRotation_Intensity = { "Pelvis_ForwardRotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_ForwardRotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_ForwardRotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_ForwardRotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpwardForwardRotation_Intensity_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Controls the intensity of the pelvis forward rotation with respect to upward slopes.\n* 0 means no rotation applied.\n*/" },
#endif
		{ "DisplayName", "Up slope Pelvis Forward Rotation Intensity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the pelvis forward rotation with respect to upward slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpwardForwardRotation_Intensity = { "Pelvis_UpwardForwardRotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_UpwardForwardRotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpwardForwardRotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpwardForwardRotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Body_Rotation_Intensity_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Controls the intensity of the pelvis sideward rotation with respect to the slopes.\n\x09* 0 means no rotation applied.\n\x09*/" },
#endif
		{ "DisplayName", "Pelvis Sideward Rotation Intensity on slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the pelvis sideward rotation with respect to the slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Body_Rotation_Intensity = { "Body_Rotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Body_Rotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Body_Rotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Body_Rotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Rotation_Offset_Rotator_MetaData[] = {
		{ "Category", "PelvisControl" },
		{ "DisplayName", "Pelvis Post Rotation Offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Rotation_Offset_Rotator = { "Pelvis_Rotation_Offset_Rotator", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Pelvis_Rotation_Offset_Rotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Rotation_Offset_Rotator_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Rotation_Offset_Rotator_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_ForwardRotation_Intensity_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Controls the intensity of the chest forward rotation with respect to the downward slopes.\n\x09* 0 means no rotation applied.\n\x09*/" },
#endif
		{ "DisplayName", "Down slope chest Forward Rotation Intensity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the chest forward rotation with respect to the downward slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_ForwardRotation_Intensity = { "Chest_ForwardRotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_ForwardRotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_ForwardRotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_ForwardRotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpwardForwardRotation_Intensity_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Controls the intensity of the chest forward rotation with respect to the upward slopes.\n* 0 means no rotation applied.\n*/" },
#endif
		{ "DisplayName", "Up slope chest Forward Rotation Intensity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the chest forward rotation with respect to the upward slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpwardForwardRotation_Intensity = { "Chest_UpwardForwardRotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_UpwardForwardRotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpwardForwardRotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpwardForwardRotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_SidewardRotation_Intensity_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Controls the intensity of the chest sideward rotation with respect to the slopes.\n\x09 * 0 means no rotation applied.\n\x09*/" },
#endif
		{ "DisplayName", "Chest Sideward Rotation Intensity on slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the intensity of the chest sideward rotation with respect to the slopes.\n* 0 means no rotation applied." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_SidewardRotation_Intensity = { "Chest_SidewardRotation_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_SidewardRotation_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_SidewardRotation_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_SidewardRotation_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Rotation_Offset_Rotator_MetaData[] = {
		{ "Category", "ChestControl" },
		{ "DisplayName", "Chest Post Rotation Offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Rotation_Offset_Rotator = { "Chest_Rotation_Offset_Rotator", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Chest_Rotation_Offset_Rotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Rotation_Offset_Rotator_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Rotation_Offset_Rotator_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine_MetaData[] = {
		{ "Category", "SpineAdvancedTweaks" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\x09UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedSettings, meta = (PinHiddenByDefault))\n//\x09""FTransform DebugEffectorTransformTwo;\n" },
#endif
		{ "DisplayName", "Is spine always fully extended ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedSettings, meta = (PinHiddenByDefault))\nFTransform DebugEffectorTransformTwo;" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Full_Extended_Spine = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine = { "Full_Extended_Spine", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_max_extension_ratio_MetaData[] = {
		{ "Category", "SpineAdvancedTweaks" },
		{ "DisplayName", "Fully extended ratio" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_max_extension_ratio = { "max_extension_ratio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, max_extension_ratio), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_max_extension_ratio_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_max_extension_ratio_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_min_extension_ratio_MetaData[] = {
		{ "Category", "SpineAdvancedTweaks" },
		{ "DisplayName", "Non extended ratio" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_min_extension_ratio = { "min_extension_ratio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, min_extension_ratio), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_min_extension_ratio_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_min_extension_ratio_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_extension_switch_speed_MetaData[] = {
		{ "Category", "SpineAdvancedTweaks" },
		{ "DisplayName", "Extension Switch Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_extension_switch_speed = { "extension_switch_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, extension_switch_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_extension_switch_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_extension_switch_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Toggle this parameter to turn on/off ik.\n\x09* Example use case : Disable it when character is jumping or flying in the air.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinShownByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Toggle this parameter to turn on/off ik.\n* Example use case : Disable it when character is jumping or flying in the air." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Enable_Solver = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver = { "Enable_Solver", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n*/" },
#endif
		{ "DisplayName", "Work outside gameplay (For Sequencer)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Work_Outside_PIE = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE = { "Work_Outside_PIE", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations_MetaData[] = {
		{ "Category", "ChestControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to use the 4 cross-based trace lines to determine the rotation of the chest instead of the default normal method\n\x09*/" },
#endif
		{ "DisplayName", "Use Alternate Cross-Based Chest Rotation (for bipeds and spiders)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to use the 4 cross-based trace lines to determine the rotation of the chest instead of the default normal method" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Fake_Chest_Rotations = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations = { "Use_Fake_Chest_Rotations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations_MetaData[] = {
		{ "Category", "PelvisControl" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to use the 4 cross-based trace lines to determine the rotation of the pelvis instead of the default normal method\n\x09*/" },
#endif
		{ "DisplayName", "Use Alternate Cross-Based Pelvis Rotation (for bipeds and spiders)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to use the 4 cross-based trace lines to determine the rotation of the pelvis instead of the default normal method" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Use_Fake_Pelvis_Rotations = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations = { "Use_Fake_Pelvis_Rotations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*This will force the ik to work at all times. Animals will not be able to jump if this is enabled.\n\x09*Only recommended for testing and debugging purposes.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*This will force the ik to work at all times. Animals will not be able to jump if this is enabled.\n*Only recommended for testing and debugging purposes." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Force_Activation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation = { "Force_Activation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Enable this to use proper accurate feet placement logic. But it might provide jumpy nature for certain quadrupeds like horses when they are moving on slopes.\n\x09*Recommended use case is to disable this when a quadruped animal is moving, but enable it when it is idle.\n\x09*Recommended to always turn it on for bipeds like humans.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Enable this to use proper accurate feet placement logic. But it might provide jumpy nature for certain quadrupeds like horses when they are moving on slopes.\n*Recommended use case is to disable this when a quadruped animal is moving, but enable it when it is idle.\n*Recommended to always turn it on for bipeds like humans." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->accurate_feet_placement = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement = { "accurate_feet_placement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Accurate_Foot_Curve_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Control the alpha between \"Accurate but maybe jumpy\" and \"Simple but stable\" solving.\n\x09*/" },
#endif
		{ "DisplayName", "Accurate-Simple foot placement curve relative to velocity. 0 = Simple. 1 = Accurate." },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Control the alpha between \"Accurate but maybe jumpy\" and \"Simple but stable\" solving." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Accurate_Foot_Curve = { "Accurate_Foot_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Accurate_Foot_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Accurate_Foot_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Accurate_Foot_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 *Enable this to use the 4 cross based traces to turn off the ik, if any of the trace hits are too far.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Enable this to use the 4 cross based traces to turn off the ik, if any of the trace hits are too far." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->use_crosshair_trace_also_for_fail_distance = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance = { "use_crosshair_trace_also_for_fail_distance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Enable this to only solve the pelvis bone, while the remaining bones remain unchanged.\n\x09*Recommended to enable it for bipeds like humans and raptors.\n\x09* Also recommended for single root spiders.\n\x09*/" },
#endif
		{ "DisplayName", "Solve only pelvis bone (useful for bipeds and spiders)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Enable this to only solve the pelvis bone, while the remaining bones remain unchanged.\n*Recommended to enable it for bipeds like humans and raptors.\n* Also recommended for single root spiders." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Only_Root_Solve = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve = { "Only_Root_Solve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This can be used to ignore the custom chest bone modifications, while retaining all other bone modifications.\n\x09* Helps avoid deformations but ignores the chest rotation controls.\n\x09* Forward and sideward rotation intensities will be completely ignored and the bone rotates naturally with respect to the rest of the body.\n\x09*/" },
#endif
		{ "DisplayName", "Avoid solving chest bone (useful when custom rotation controls aren't needed)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This can be used to ignore the custom chest bone modifications, while retaining all other bone modifications.\n* Helps avoid deformations but ignores the chest rotation controls.\n* Forward and sideward rotation intensities will be completely ignored and the bone rotates naturally with respect to the rest of the body." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Ignore_Chest_Solve = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve = { "Ignore_Chest_Solve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Overall_PostSolved_Offset_MetaData[] = {
		{ "Category", "AdvancedSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Additional offset parameters to the overall bones\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Additional offset parameters to the overall bones" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Overall_PostSolved_Offset = { "Overall_PostSolved_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Overall_PostSolved_Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Overall_PostSolved_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Overall_PostSolved_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_character_direction_vector_CS_MetaData[] = {
		{ "Category", "ComponentDirectionSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*The up direction vector of the character in component space.\n\x09* 99% cases, this should not be altered.\n\x09* Only needed to alter on characters that do not follow the standard unreal character orientations.\n\x09*/" },
#endif
		{ "DisplayName", "Up Direction Vector" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_character_direction_vector_CS = { "character_direction_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, character_direction_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_character_direction_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_character_direction_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Forward_Direction_Vector_MetaData[] = {
		{ "Category", "ComponentDirectionSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*The forward direction vector of the character in component space.\n\x09* 99% cases, this should not be altered.\n\x09* Only needed to alter on characters that do not follow the standard unreal character orientations.\n\x09*/" },
#endif
		{ "DisplayName", "Forward Direction Vector" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*The forward direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Forward_Direction_Vector = { "Forward_Direction_Vector", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Forward_Direction_Vector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Forward_Direction_Vector_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Forward_Direction_Vector_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right_MetaData[] = {
		{ "Category", "ComponentDirectionSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*If character is rigged and animated in the opposite direction to the standard unreal forward/right directions, then enable this.\n\x09* 99% cases, this should not be altered.\n\x09*/" },
#endif
		{ "DisplayName", "Flip forward and right rotation" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*If character is rigged and animated in the opposite direction to the standard unreal forward/right directions, then enable this.\n* 99% cases, this should not be altered." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->flip_forward_and_right = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right = { "flip_forward_and_right", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose_MetaData[] = {
		{ "Category", "Miscellaneous" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Whether to use the reference pose or animated pose for calculations.\n\x09*/" },
#endif
		{ "DisplayName", "Solver Reference Pose" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Whether to use the reference pose or animated pose for calculations." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose = { "SolverReferencePose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, SolverReferencePose), Z_Construct_UEnum_DragonIKPlugin_ERefPosePluginEnum, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose_MetaData) }; // 429068342
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect_MetaData[] = {
		{ "Category", "Miscellaneous" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Automatically correct the spine and feet bone pairing with respect to the typed bone names in the input settings.\n\x09*  If correct bone names are typed, it makes no difference in the end.\n\x09*/" },
#endif
		{ "DisplayName", "Strict Spine-Feet pair finding" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Automatically correct the spine and feet bone pairing with respect to the typed bone names in the input settings.\n*  If correct bone names are typed, it makes no difference in the end." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Spine_Feet_Connect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect = { "Spine_Feet_Connect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Snake_Joint_Speed_MetaData[] = {
		{ "Category", "SnakeSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**Spine interpolation speed if snake mode is enabled.\n\x09*/" },
#endif
		{ "DisplayName", "Snake Joint Speed (If snake true)" },
		{ "EditCondition", "is_snake" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spine interpolation speed if snake mode is enabled." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Snake_Joint_Speed = { "Snake_Joint_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Snake_Joint_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Snake_Joint_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Snake_Joint_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation_MetaData[] = {
		{ "Category", "SnakeSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Toggle this parameter to turn on/off snake ik interpolation.\n*/" },
#endif
		{ "EditCondition", "is_snake" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Toggle this parameter to turn on/off snake ik interpolation." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Enable_Snake_Interpolation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation = { "Enable_Snake_Interpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake_MetaData[] = {
		{ "Category", "SnakeSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable snake mode.\n\x09* If character is either a snake or a worm, enable this.\n\x09* Can also be turned on for biped characters sleeping or laying on the ground.\n\x09*/" },
#endif
		{ "DisplayName", "Is it a snake ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable snake mode.\n* If character is either a snake or a worm, enable this.\n* Can also be turned on for biped characters sleeping or laying on the ground." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->is_snake = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake = { "is_snake", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points_MetaData[] = {
		{ "Category", "SnakeSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Useful for snake tails.\n*/" },
#endif
		{ "DisplayName", "Ignore tip bone modification." },
		{ "EditCondition", "is_snake" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Useful for snake tails." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->Ignore_End_Points = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points = { "Ignore_End_Points", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Feet_Distance_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Maximum distance from feet to terrain to allow the solving to happen.\n\x09 * Higher value makes the ik to solve even on terrains far below the character.\n\x09*/" },
#endif
		{ "DisplayName", "Maximum Feet-Terrain Fail Distance" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Maximum distance from feet to terrain to allow the solving to happen.\n* Higher value makes the ik to solve even on terrains far below the character." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Feet_Distance = { "Maximum_Feet_Distance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Maximum_Feet_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Feet_Distance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Feet_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Minimum_Feet_Distance_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The minimum distance between feet and terrain to allow solving to happen.\n\x09* Increase this value if ik is turning off easilly on slopes.\n\x09* Too high of a value can make the ik to \"stick\" to the ground more, which can be undesirable.\n\x09* Recommended to tweak this value until it feels right\n\x09*/" },
#endif
		{ "DisplayName", "Minimum Terrain-Capsule Activation Distance" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The minimum distance between feet and terrain to allow solving to happen.\n* Increase this value if ik is turning off easilly on slopes.\n* Too high of a value can make the ik to \"stick\" to the ground more, which can be undesirable.\n* Recommended to tweak this value until it feels right" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Minimum_Feet_Distance = { "Minimum_Feet_Distance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonSpineSolver, Minimum_Feet_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Minimum_Feet_Distance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Minimum_Feet_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace_MetaData[] = {
		{ "Category", "BasicSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to render the traces in the animgraph viewports.\n\x09*/" },
#endif
		{ "DisplayName", "Display LineTracing" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonSpineSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to render the traces in the animgraph viewports." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace_SetBit(void* Obj)
	{
		((FAnimNode_DragonSpineSolver*)Obj)->DisplayLineTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace = { "DisplayLineTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonSpineSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_trace_manager_component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_solver_identifier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_type2_input,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dragon_input_type2_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Precision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_RotationLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_MaxIterations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Shift_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Anti_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_hit_complex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_trace_interval_duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_LOD_Specific_Intervals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD0_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD1_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_LOD2_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Trace_Distance_Adapting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Max_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Interval_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interval_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Override_Curve_Velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_custom_velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotate_Around_Translate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_complexity_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Lerping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_downward_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_line_trace_upper_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Anti_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_pelvis_legs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpSlopeStabilization_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_DownSlopeStabilization_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_stabilize_chest_legs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpSlopeStabilization_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_DownslopeStabilization_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Head_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Stabilization_Tail_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Ducking_Feature,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ducking_Limit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Crouch_Rotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Pelvis_Trace_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Crouch_Rotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Duck_Chest_Trace_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Up_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Slanted_Height_Down_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_dip_multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_pelvis_adaptive_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_reverse_fabrik,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Calculation_To_RefPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Up_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Slanted_Height_Down_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_side_dip_multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_chest_adaptive_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Base_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Base_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_virtual_leg_width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Height_Multiplier_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Dip_Height_Chest,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Height_Multiplier_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_rotation_power_between,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Automatic_Fabrik_Selection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Trace_Lerp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Location_Lerp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Rotation_Lerp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Interpolation_Multiplier_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Influence_Alpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_ForwardRotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_UpwardForwardRotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Body_Rotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Pelvis_Rotation_Offset_Rotator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_ForwardRotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_UpwardForwardRotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_SidewardRotation_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Chest_Rotation_Offset_Rotator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Full_Extended_Spine,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_max_extension_ratio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_min_extension_ratio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_extension_switch_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Solver,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Work_Outside_PIE,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Chest_Rotations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Use_Fake_Pelvis_Rotations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Force_Activation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_accurate_feet_placement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Accurate_Foot_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_use_crosshair_trace_also_for_fail_distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Only_Root_Solve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_Chest_Solve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Overall_PostSolved_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_character_direction_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Forward_Direction_Vector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_flip_forward_and_right,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_SolverReferencePose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Spine_Feet_Connect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Snake_Joint_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Enable_Snake_Interpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_is_snake,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Ignore_End_Points,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Maximum_Feet_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_Minimum_Feet_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewProp_DisplayLineTrace,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonSpineSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonSpineSolver),
		alignof(FAnimNode_DragonSpineSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::EnumInfo[] = {
		{ ERefPosePluginEnum_StaticEnum, TEXT("ERefPosePluginEnum"), &Z_Registration_Info_UEnum_ERefPosePluginEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 429068342U) },
		{ ESolverComplexityPluginEnum_StaticEnum, TEXT("ESolverComplexityPluginEnum"), &Z_Registration_Info_UEnum_ESolverComplexityPluginEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3253964227U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_DragonSpineSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics::NewStructOps, TEXT("AnimNode_DragonSpineSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonSpineSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonSpineSolver), 2893600308U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_808463692(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
