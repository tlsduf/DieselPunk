// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonFeetSolver.h"
#include "../../Source/Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "../../Source/Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "DragonIK_Library.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonFeetSolver() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EIKTrace_Type_Plugin();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EInterpoLocation_Type_Plugin();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EInterpoRotation_Type_Plugin();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_FeetAlpha_Struct();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_FeetOffset_Struct();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_MultiInput();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_StickyFeetStruct();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_StickySocketStruct();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ETraceTypeQuery();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FComponentSpacePoseLink();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EIK_Type_Plugin;
	static UEnum* EIK_Type_Plugin_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EIK_Type_Plugin.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EIK_Type_Plugin.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("EIK_Type_Plugin"));
		}
		return Z_Registration_Info_UEnum_EIK_Type_Plugin.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<EIK_Type_Plugin>()
	{
		return EIK_Type_Plugin_StaticEnum();
	}
	struct Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enumerators[] = {
		{ "EIK_Type_Plugin::ENUM_Two_Bone_Ik", (int64)EIK_Type_Plugin::ENUM_Two_Bone_Ik },
		{ "EIK_Type_Plugin::ENUM_Single_Bone_Ik", (int64)EIK_Type_Plugin::ENUM_Single_Bone_Ik },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//class APlayerController;\n//\"BlueprintType\" is essential to include\n" },
#endif
		{ "ENUM_Single_Bone_Ik.DisplayName", "Single Bone IK" },
		{ "ENUM_Single_Bone_Ik.Name", "EIK_Type_Plugin::ENUM_Single_Bone_Ik" },
		{ "ENUM_Two_Bone_Ik.DisplayName", "Two Bone IK" },
		{ "ENUM_Two_Bone_Ik.Name", "EIK_Type_Plugin::ENUM_Two_Bone_Ik" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "class APlayerController;\n\"BlueprintType\" is essential to include" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		"EIK_Type_Plugin",
		"EIK_Type_Plugin",
		Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin()
	{
		if (!Z_Registration_Info_UEnum_EIK_Type_Plugin.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EIK_Type_Plugin.InnerSingleton, Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EIK_Type_Plugin.InnerSingleton;
	}

static_assert(std::is_polymorphic<FAnimNode_DragonFeetSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonFeetSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver;
class UScriptStruct* FAnimNode_DragonFeetSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonFeetSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonFeetSolver>()
{
	return FAnimNode_DragonFeetSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics
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
		static const UECodeGen_Private::FBytePropertyParams NewProp_ik_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ik_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ik_type;
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
		static const UECodeGen_Private::FBytePropertyParams NewProp_loc_interp_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_loc_interp_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_loc_interp_type;
		static const UECodeGen_Private::FBytePropertyParams NewProp_rot_interp_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rot_interp_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_rot_interp_type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_virtual_scale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_virtual_scale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_feet_alpha_multiplier_array_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_feet_alpha_multiplier_array;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_feet_extra_offset_array_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_feet_extra_offset_array;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_automatic_leg_make_MetaData[];
#endif
		static void NewProp_automatic_leg_make_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_automatic_leg_make;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_OptionalRef_Feet_As_Ref_MetaData[];
#endif
		static void NewProp_Use_OptionalRef_Feet_As_Ref_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_OptionalRef_Feet_As_Ref;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_enable_solver_MetaData[];
#endif
		static void NewProp_enable_solver_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable_solver;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Work_Outside_PIE_MetaData[];
#endif
		static void NewProp_Work_Outside_PIE_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Work_Outside_PIE;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OptionalRefPose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OptionalRefPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_interpolate_only_z_MetaData[];
#endif
		static void NewProp_interpolate_only_z_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_interpolate_only_z;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_shift_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_shift_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_Lerp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Location_Lerp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_feet_rotation_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_feet_rotation_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ignore_shift_speed_MetaData[];
#endif
		static void NewProp_ignore_shift_speed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ignore_shift_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ignore_Lerping_MetaData[];
#endif
		static void NewProp_Ignore_Lerping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Ignore_Lerping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ignore_Location_Lerping_MetaData[];
#endif
		static void NewProp_Ignore_Location_Lerping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Ignore_Location_Lerping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interpolation_Velocity_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Interpolation_Velocity_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Complex_Rotation_Method_MetaData[];
#endif
		static void NewProp_Enable_Complex_Rotation_Method_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Complex_Rotation_Method;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComplexSimpleFoot_Velocity_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ComplexSimpleFoot_Velocity_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Trace_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anti_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Anti_Trace_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FPS_Lerp_Treshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FPS_Lerp_Treshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_upper_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_upper_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_down_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_down_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Down_Multiplier_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Trace_Down_Multiplier_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Anti_Channel_MetaData[];
#endif
		static void NewProp_Use_Anti_Channel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Anti_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_use_footstep_listening_MetaData[];
#endif
		static void NewProp_use_footstep_listening_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_footstep_listening;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Should_Rotate_Feet_MetaData[];
#endif
		static void NewProp_Should_Rotate_Feet_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Should_Rotate_Feet;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_show_trace_in_game_MetaData[];
#endif
		static void NewProp_show_trace_in_game_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_show_trace_in_game;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_execute_in_preview_MetaData[];
#endif
		static void NewProp_execute_in_preview_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_execute_in_preview;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Pitch_MetaData[];
#endif
		static void NewProp_Enable_Pitch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Pitch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Roll_MetaData[];
#endif
		static void NewProp_Enable_Roll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Roll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_character_direction_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_character_direction_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_character_forward_direction_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_character_forward_direction_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_poles_forward_direction_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_poles_forward_direction_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Four_Point_Feets_MetaData[];
#endif
		static void NewProp_Use_Four_Point_Feets_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Four_Point_Feets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Foot_Lift_Limit_MetaData[];
#endif
		static void NewProp_Enable_Foot_Lift_Limit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Foot_Lift_Limit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Affect_Toes_Always_MetaData[];
#endif
		static void NewProp_Affect_Toes_Always_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Affect_Toes_Always;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Finger_Alpha_Velocity_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Finger_Alpha_Velocity_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Max_Limb_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Max_Limb_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Feet_Lift_Warping_MetaData[];
#endif
		static void NewProp_Feet_Lift_Warping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Feet_Lift_Warping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Feet_Lift_Warp_Multiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Feet_Lift_Warp_Multiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_feet_vertical_size_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_feet_vertical_size;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Feet_Lift_Limit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Feet_Lift_Limit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_feet_mode_MetaData[];
#endif
		static void NewProp_sticky_feet_mode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_sticky_feet_mode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_feet_on_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_sticky_feet_on_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_feet_off_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_sticky_feet_off_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sticky_Feet_Range_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Sticky_Feet_Range;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_feets_data_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_sticky_feets_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_floor_detection_MetaData[];
#endif
		static void NewProp_sticky_floor_detection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_sticky_floor_detection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_floor_value_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_floor_value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Auto_Sticky_Toggle_MetaData[];
#endif
		static void NewProp_Auto_Sticky_Toggle_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Auto_Sticky_Toggle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sticky_sockets_data_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_sticky_sockets_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Foot_01_Height_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Foot_01_Height_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Foot_02_Height_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Foot_02_Height_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Foot_03_Height_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Foot_03_Height_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Foot_04_Height_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Foot_04_Height_Offset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//USTRUCT(BlueprintInternalUseOnly)\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USTRUCT(BlueprintInternalUseOnly)" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonFeetSolver>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component_MetaData[] = {
		{ "Category", "OptionalTraceManagerComponentSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09 * This is a new optional experimental feature.\n\x09\x09 * Enable this to let the trace manager component to do the heavy lifting of the trace firing logic. The trace manager component runs in your Pawn blueprint.\n\x09\x09 * Trace logic is centralized in an orderly fashion instead of the default decentralized approach.\n\x09\x09 * By default this is disabled, and trace firing is directly handled within each solver.\n\x09\x09 * Enabling this can potentially fix stability issues in rare scenarios in the use of this solver along with overall engine stability.\n\x09\x09 * The trace info of this solver will become available in the pawn blueprint as well, in case you need it for gameplay purposes.\n\x09\x09 */" },
#endif
		{ "DisplayName", "Use External Trace Manager Component ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is a new optional experimental feature.\n* Enable this to let the trace manager component to do the heavy lifting of the trace firing logic. The trace manager component runs in your Pawn blueprint.\n* Trace logic is centralized in an orderly fashion instead of the default decentralized approach.\n* By default this is disabled, and trace firing is directly handled within each solver.\n* Enabling this can potentially fix stability issues in rare scenarios in the use of this solver along with overall engine stability.\n* The trace info of this solver will become available in the pawn blueprint as well, in case you need it for gameplay purposes." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->use_trace_manager_component = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component = { "use_trace_manager_component", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_solver_identifier_MetaData[] = {
		{ "Category", "OptionalTraceManagerComponentSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Only relevant if using the optional \"DragonIK Trace Manager component\".\n\x09 * If this animbp only has one foot solver only, you can leave it unchanged.\n\x09 * If there is more than one foot solver, make sure they have any unique number here.\n\x09 */" },
#endif
		{ "DisplayName", "Unique Solver Identifier" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Only relevant if using the optional \"DragonIK Trace Manager component\".\n* If this animbp only has one foot solver only, you can leave it unchanged.\n* If there is more than one foot solver, make sure they have any unique number here." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_solver_identifier = { "solver_identifier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, solver_identifier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_solver_identifier_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_solver_identifier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_dragon_input_data_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09\x09* Type the input bones used by the solver - pelvis,spine-start and feets\n  * Pull this pin to create a \"make struct\" and easily type out the bones.\n  * Optionally you can type the bones directly inside the solver. Doing so is slightly more recommended because it activates fast path.\n  */" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Type the input bones used by the solver - pelvis,spine-start and feets\n* Pull this pin to create a \"make struct\" and easily type out the bones.\n* Optionally you can type the bones directly inside the solver. Doing so is slightly more recommended because it activates fast path." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_dragon_input_data = { "dragon_input_data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, dragon_input_data), Z_Construct_UScriptStruct_FDragonData_MultiInput, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_dragon_input_data_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_dragon_input_data_MetaData) }; // 1496037613
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Select foot ik type - two bone ik and one bone ik.\n\x09* 99.9% best to use the default two bone ik.\n\x09* One bone ik is only useful in case the animal has no knee bones, such as the infinity blade spiders.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Select foot ik type - two bone ik and one bone ik.\n* 99.9% best to use the default two bone ik.\n* One bone ik is only useful in case the animal has no knee bones, such as the infinity blade spiders." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type = { "ik_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, ik_type), Z_Construct_UEnum_DragonIKPlugin_EIK_Type_Plugin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type_MetaData) }; // 1115181697
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Choose Trace type - Line,Sphere and Box.*/" },
#endif
		{ "DisplayName", "Trace Type" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Choose Trace type - Line,Sphere and Box." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type = { "trace_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, trace_type), Z_Construct_UEnum_DragonIKPlugin_EIKTrace_Type_Plugin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type_MetaData) }; // 1628889231
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Radius_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* If trace type is box or sphere, its radius is controlled using the Trace Radius */" },
#endif
		{ "DisplayName", "Trace Radius" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If trace type is box or sphere, its radius is controlled using the Trace Radius" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Radius = { "Trace_Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Trace_Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Radius_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex_MetaData[] = {
		{ "Category", "TraceSettings" },
		{ "DisplayName", "Trace Hit Complex ? (True for complex, False for simple)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->line_trace_hit_complex = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex = { "line_trace_hit_complex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_interval_duration_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Trace Firing Interval (Performance)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_interval_duration = { "trace_interval_duration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, trace_interval_duration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_interval_duration_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_interval_duration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Use LOD specific intervals ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_LOD_Specific_Intervals = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals = { "Use_LOD_Specific_Intervals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD0_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD0 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD0_Interval = { "LOD0_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, LOD0_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD0_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD0_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD1_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD1 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD1_Interval = { "LOD1_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, LOD1_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD1_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD1_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD2_Interval_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "LOD2 Interval" },
		{ "EditCondition", "Use_LOD_Specific_Intervals" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD2_Interval = { "LOD2_Interval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, LOD2_Interval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD2_Interval_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD2_Interval_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Turn off traces after a distance from the camera ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_Trace_Distance_Adapting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting = { "Use_Trace_Distance_Adapting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Max_Distance_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Max distance until traces are turned off" },
		{ "EditCondition", "Use_Trace_Distance_Adapting" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Max_Distance = { "Trace_Max_Distance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Trace_Max_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Max_Distance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Max_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData[] = {
		{ "Category", "TracePerformance" },
		{ "DisplayName", "Use trace interval-velocity multiplier curve function ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_Interval_Velocity_Curve = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve = { "Use_Interval_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData[] = {
		{ "Category", "TracePerformance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The value from this curve at the proportional velocity is multiplied with the trace interval constant or the LOD intervals\n\x09*/" },
#endif
		{ "DisplayName", "Trace interval-velocity multiplier curve" },
		{ "EditCondition", "Use_Interval_Velocity_Curve" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The value from this curve at the proportional velocity is multiplied with the trace interval constant or the LOD intervals" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interval_Velocity_Curve = { "Interval_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Interval_Velocity_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interval_Velocity_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity_MetaData[] = {
		{ "Category", "MasterCurveSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* If enabled, the velocity that drives the curves is the custom velocity parameter instead of calculating from the character blueprint movement component.\n*/" },
#endif
		{ "DisplayName", "Use custom velocity instead of automatic character blueprint velocity for curves ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If enabled, the velocity that drives the curves is the custom velocity parameter instead of calculating from the character blueprint movement component." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Override_Curve_Velocity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity = { "Override_Curve_Velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_custom_velocity_MetaData[] = {
		{ "Category", "MasterCurveSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Used as the velocity for curves if enabled.\n\x09* Overrides the automatic velocity calculation, useful for non-Character blueprints that doesn't have a movement component.\n\x09*/" },
#endif
		{ "DisplayName", "Custom Curve Velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Used as the velocity for curves if enabled.\n* Overrides the automatic velocity calculation, useful for non-Character blueprints that doesn't have a movement component." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_custom_velocity = { "custom_velocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, custom_velocity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_custom_velocity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_custom_velocity_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Select the feet location interpolation method.\n\x09* Default uses the divisive location interpolation method, which provides optimal smoothness and speed of solving.\n\x09* Optionally can use the legacy method of interpolation.\n\x09*/" },
#endif
		{ "DisplayName", "Location Interpolation Type" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Select the feet location interpolation method.\n* Default uses the divisive location interpolation method, which provides optimal smoothness and speed of solving.\n* Optionally can use the legacy method of interpolation." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type = { "loc_interp_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, loc_interp_type), Z_Construct_UEnum_DragonIKPlugin_EInterpoLocation_Type_Plugin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type_MetaData) }; // 430350942
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Select the feet rotation interpolation method.\n\x09* Default uses the divisive location interpolation method, which provides optimal smoothness and speed of solving.\n\x09* Optionally can use the legacy method of interpolation.\n\x09*/" },
#endif
		{ "DisplayName", "Rotation Interpolation Type" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Select the feet rotation interpolation method.\n* Default uses the divisive location interpolation method, which provides optimal smoothness and speed of solving.\n* Optionally can use the legacy method of interpolation." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type = { "rot_interp_type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, rot_interp_type), Z_Construct_UEnum_DragonIKPlugin_EInterpoRotation_Type_Plugin, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type_MetaData) }; // 1166717702
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_virtual_scale_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters.\n*/" },
#endif
		{ "DisplayName", "Global trace scale multiplier" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_virtual_scale = { "virtual_scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, virtual_scale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_virtual_scale_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_virtual_scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_alpha_multiplier_array_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * You can dynamically control the alpha of each limbs using a float alpha.\n * The index of the array corresponds to the index of the feet array info.\n */" },
#endif
		{ "DisplayName", "(optional) Feet Alpha Multiplier Array" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* You can dynamically control the alpha of each limbs using a float alpha.\n* The index of the array corresponds to the index of the feet array info." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_alpha_multiplier_array = { "feet_alpha_multiplier_array", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, feet_alpha_multiplier_array), Z_Construct_UScriptStruct_FDragonData_FeetAlpha_Struct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_alpha_multiplier_array_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_alpha_multiplier_array_MetaData) }; // 3464803677
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_extra_offset_array_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * You can dynamically offset the position of each limbs and the trace position.\n\x09 * The index of the array corresponds to the index of the feet array info.\n\x09 * The offset works in component space.\n\x09 */" },
#endif
		{ "DisplayName", "(optional) Feet Position Offset Array" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* You can dynamically offset the position of each limbs and the trace position.\n* The index of the array corresponds to the index of the feet array info.\n* The offset works in component space." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_extra_offset_array = { "feet_extra_offset_array", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, feet_extra_offset_array), Z_Construct_UScriptStruct_FDragonData_FeetOffset_Struct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_extra_offset_array_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_extra_offset_array_MetaData) }; // 3446151862
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Parameter to choose between automatic feet bone detection or manual method.\n\x09* If enabled, solvers only uses the feet bones, and automatically assumes the next 2 parent bones as knees and thighs.\n\x09* If disabled, solvers uses the feet bones, knee bones and thigh bones typed in the feet array.\n\x09* If disabled, all bones need to be valid. Any invalid bones will not activate the ik.\n\x09* Very useful to keep it disabled on DAZ rigs and certain animal characters, where the thigh-knee-foot are not in a straight linear hierarchy.\n\x09*/" },
#endif
		{ "DisplayName", "Automatic Foot-Knee-Thigh detection" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Parameter to choose between automatic feet bone detection or manual method.\n* If enabled, solvers only uses the feet bones, and automatically assumes the next 2 parent bones as knees and thighs.\n* If disabled, solvers uses the feet bones, knee bones and thigh bones typed in the feet array.\n* If disabled, all bones need to be valid. Any invalid bones will not activate the ik.\n* Very useful to keep it disabled on DAZ rigs and certain animal characters, where the thigh-knee-foot are not in a straight linear hierarchy." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->automatic_leg_make = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make = { "automatic_leg_make", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* If enabled, the rotation of the feet will be relative to its current animation.\n\x09* If disabled, the absolute reference rotation of the feet will be used instead, ensuring always aligned feets.\n\x09*/" },
#endif
		{ "DisplayName", "Use (optional ref pose) as reference for foot rotation ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If enabled, the rotation of the feet will be relative to its current animation.\n* If disabled, the absolute reference rotation of the feet will be used instead, ensuring always aligned feets." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_OptionalRef_Feet_As_Ref = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref = { "Use_OptionalRef_Feet_As_Ref", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Toggle this parameter to turn on/off ik.\n* Example use case : Disable it when character is jumping or flying in the air.\n*/" },
#endif
		{ "DisplayName", "Enable Solver (Instant)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinShownByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Toggle this parameter to turn on/off ik.\n* Example use case : Disable it when character is jumping or flying in the air." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->enable_solver = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver = { "enable_solver", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n*/" },
#endif
		{ "DisplayName", "Work outside gameplay (For Sequencer)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinShownByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Work_Outside_PIE = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE = { "Work_Outside_PIE", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_OptionalRefPose_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Supply a cached pose copy before the spine solver to serve as a proper reference for calculating feet rotations on slopes.\n\x09* Only used if its boolean is enabled.\n\x09*/" },
#endif
		{ "DisplayName", "(optional) Ref pose for foot rotation on slopes" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Supply a cached pose copy before the spine solver to serve as a proper reference for calculating feet rotations on slopes.\n* Only used if its boolean is enabled." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_OptionalRefPose = { "OptionalRefPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, OptionalRefPose), Z_Construct_UScriptStruct_FComponentSpacePoseLink, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_OptionalRefPose_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_OptionalRefPose_MetaData) }; // 3609499842
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* If enabled, interpolation is strictly on the vertical axis of the feets. (Recommended)\n\x09* If disabled, interpolation is in all directions. Might create a delayed feet response in low frame rates.\n\x09*///\n" },
#endif
		{ "DisplayName", "Interpolate only on legs Z axis ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If enabled, interpolation is strictly on the vertical axis of the feets. (Recommended)\n* If disabled, interpolation is in all directions. Might create a delayed feet response in low frame rates.\n//" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->interpolate_only_z = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z = { "interpolate_only_z", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_shift_speed_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * The transistion speed between solve and unsolve state of the leg ik (eg:- when character jumps and falls back to ground).\n * Lower values means slower but smoother transition.\n */" },
#endif
		{ "DisplayName", "Shift Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The transistion speed between solve and unsolve state of the leg ik (eg:- when character jumps and falls back to ground).\n* Lower values means slower but smoother transition." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_shift_speed = { "shift_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, shift_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_shift_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_shift_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Location_Lerp_Speed_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Controls the feet interpolation location speed.\n* Lower values means smoother but slower results.\n* Is ignored if \"Ignore location lerping\" is enabled.\n*/" },
#endif
		{ "DisplayName", "Feet Position Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the feet interpolation location speed.\n* Lower values means smoother but slower results.\n* Is ignored if \"Ignore location lerping\" is enabled." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Location_Lerp_Speed = { "Location_Lerp_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Location_Lerp_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Location_Lerp_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Location_Lerp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_rotation_speed_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Controls the feet interpolation rotation speed.\n* Lower values means smoother but slower results.\n* Is ignored if \"Ignore rotation lerping\" is enabled.\n*/" },
#endif
		{ "DisplayName", "Feet Rotation Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Controls the feet interpolation rotation speed.\n* Lower values means smoother but slower results.\n* Is ignored if \"Ignore rotation lerping\" is enabled." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_rotation_speed = { "feet_rotation_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, feet_rotation_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_rotation_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_rotation_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Shift Logic : The smooth transition between touching and non-touching state.\n* Ignoring this will make transitions instant.\n*/" },
#endif
		{ "DisplayName", "Ignore Shift Logic" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Shift Logic : The smooth transition between touching and non-touching state.\n* Ignoring this will make transitions instant." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->ignore_shift_speed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed = { "ignore_shift_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to completely bypass rotation interpolation and use default values!\n\x09*/" },
#endif
		{ "DisplayName", "Ignore Rotation Interpolation" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to completely bypass rotation interpolation and use default values!" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Ignore_Lerping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping = { "Ignore_Lerping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Enable this to completely bypass location interpolation and use default values!\n\x09*/" },
#endif
		{ "DisplayName", "Ignore Location Interpolation" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to completely bypass location interpolation and use default values!" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Ignore_Location_Lerping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping = { "Ignore_Location_Lerping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interpolation_Velocity_Curve_MetaData[] = {
		{ "Category", "InterpolationSettings" },
		{ "DisplayName", "Interpolation multiplier relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interpolation_Velocity_Curve = { "Interpolation_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Interpolation_Velocity_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interpolation_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interpolation_Velocity_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method_MetaData[] = {
		{ "Category", "InterpolationSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Uses a rotation method of rotating and moving the feets to perfectly align themselves to the terrain.\n\x09* If disabled, only the feets get rotated. Might produce slight gaps on steep terrains.\n\x09*/" },
#endif
		{ "DisplayName", "Enable complex but accurate foot placement method ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Uses a rotation method of rotating and moving the feets to perfectly align themselves to the terrain.\n* If disabled, only the feets get rotated. Might produce slight gaps on steep terrains." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Enable_Complex_Rotation_Method = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method = { "Enable_Complex_Rotation_Method", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ComplexSimpleFoot_Velocity_Curve_MetaData[] = {
		{ "Category", "InterpolationSettings" },
		{ "DisplayName", "Complex to simple foot placement transition relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ComplexSimpleFoot_Velocity_Curve = { "ComplexSimpleFoot_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, ComplexSimpleFoot_Velocity_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ComplexSimpleFoot_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ComplexSimpleFoot_Velocity_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Channel_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings.*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings." },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Channel = { "Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Channel_MetaData) }; // 2725057287
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Anti_Trace_Channel_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Channel used for the trace repelling anti-channel process.*/" },
#endif
		{ "DisplayName", "Trace Anti-Channel" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Channel used for the trace repelling anti-channel process." },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Anti_Trace_Channel = { "Anti_Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Anti_Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Anti_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Anti_Trace_Channel_MetaData) }; // 2725057287
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_FPS_Lerp_Treshold_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disable interpolation of the foot solver if the game frame rate falls beyond this value.\n\x09* Useful to avoid the flying and inconsistent feet problem at lower frame rates.\n\x09*/" },
#endif
		{ "DisplayName", "Fps treshold for interpolation" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disable interpolation of the foot solver if the game frame rate falls beyond this value.\n* Useful to avoid the flying and inconsistent feet problem at lower frame rates." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_FPS_Lerp_Treshold = { "FPS_Lerp_Treshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, FPS_Lerp_Treshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_FPS_Lerp_Treshold_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_FPS_Lerp_Treshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_upper_height_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Line trace height above the feet bones.\n\x09* Too high values will cause legs to react to ceilings and trees.\n\x09* Too low values will cause ik to not work on extreme slopes and steps.*/" },
#endif
		{ "DisplayName", "Trace Height above feet" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Line trace height above the feet bones.\n* Too high values will cause legs to react to ceilings and trees.\n* Too low values will cause ik to not work on extreme slopes and steps." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_upper_height = { "line_trace_upper_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, line_trace_upper_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_upper_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_upper_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_down_height_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Line trace height below the feet bones. Usually best kept 0.\n* Too high values can lead to sticky IK which might be undesirable.*/" },
#endif
		{ "DisplayName", "Trace Height below feet" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Line trace height below the feet bones. Usually best kept 0.\n* Too high values can lead to sticky IK which might be undesirable." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_down_height = { "line_trace_down_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, line_trace_down_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_down_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_down_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Down_Multiplier_Curve_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* \n*/" },
#endif
		{ "DisplayName", "Trace down height multiplier relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Down_Multiplier_Curve = { "Trace_Down_Multiplier_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Trace_Down_Multiplier_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Down_Multiplier_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Down_Multiplier_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel_MetaData[] = {
		{ "Category", "TraceSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Use the anti-channel in the solving logic. Use meshes with the anti-channel set to \"block\" to repel the traces from touching ceilings and closed spaces.\n\x09* Also useful when under stairs or narrow multi-storied buildings. Cover the ceilings and under stairs with anti-channel blocked meshes.\n\x09*/" },
#endif
		{ "DisplayName", "Use Anti-Channel Functionality" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Use the anti-channel in the solving logic. Use meshes with the anti-channel set to \"block\" to repel the traces from touching ceilings and closed spaces.\n* Also useful when under stairs or narrow multi-storied buildings. Cover the ceilings and under stairs with anti-channel blocked meshes." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_Anti_Channel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel = { "Use_Anti_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening_MetaData[] = {
		{ "Category", "TraceSettings" },
		{ "DisplayName", "Listen for foot steps ? (for the DragonIK footstep component)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->use_footstep_listening = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening = { "use_footstep_listening", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disable this to ignore feet rotaion and use default animated rotation.\n\x09*/" },
#endif
		{ "DisplayName", "Should Solving Rotate Feet ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disable this to ignore feet rotaion and use default animated rotation." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Should_Rotate_Feet = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet = { "Should_Rotate_Feet", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this to render the line traces in the animgraph viewport.\n*/" },
#endif
		{ "DisplayName", "Display Line Trace ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to render the line traces in the animgraph viewport." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->show_trace_in_game = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game = { "show_trace_in_game", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Execute in Animbp preview ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->execute_in_preview = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview = { "execute_in_preview", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disable this to zero out the pitch of the feet.\n\x09*/" },
#endif
		{ "DisplayName", "Enable Foot Pitch" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disable this to zero out the pitch of the feet." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Enable_Pitch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch = { "Enable_Pitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disable this to zero out the roll of the feet.\n\x09*/" },
#endif
		{ "DisplayName", "Enable Foot Roll" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disable this to zero out the roll of the feet." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Enable_Roll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll = { "Enable_Roll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_direction_vector_CS_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations.\n*/" },
#endif
		{ "DisplayName", "Character Up Direction Vector (Local space)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_direction_vector_CS = { "character_direction_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, character_direction_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_direction_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_direction_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_forward_direction_vector_CS_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations.\n*/" },
#endif
		{ "DisplayName", "Dynamic Forward Direction Vector (Local space)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_forward_direction_vector_CS = { "character_forward_direction_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, character_forward_direction_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_forward_direction_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_forward_direction_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_poles_forward_direction_vector_CS_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This parameter is mainly useful when using mocap animations that involves the character rotating its root bone in multiple directions.\n\x09* It is the default forward vector of your character in component space. The dynamic forward vector is compared with the default forward vector to appropriately alter\n\x09* the knee poles and avoid knee bending in the wrong directions.\n\x09* If your character is setup in standard unreal forward axis, then there is no need to alter this.\n\x09*/" },
#endif
		{ "DisplayName", "Reference Forward Direction Vector (Local space)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This parameter is mainly useful when using mocap animations that involves the character rotating its root bone in multiple directions.\n* It is the default forward vector of your character in component space. The dynamic forward vector is compared with the default forward vector to appropriately alter\n* the knee poles and avoid knee bending in the wrong directions.\n* If your character is setup in standard unreal forward axis, then there is no need to alter this." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_poles_forward_direction_vector_CS = { "poles_forward_direction_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, poles_forward_direction_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_poles_forward_direction_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_poles_forward_direction_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disabling this uses the default foot rotation calculation, using the terrain normal data.\n\x09* Enabling this uses a slightly more complex but more stable and accurate rotation calculation. Uses 4 traces per feet instead of 1.\n\x09* Provides greater control of rotation control in the foot array. Have the ability to control the frontal and sideway spacing per feet.\n\x09*/" },
#endif
		{ "DisplayName", "Use advanced 4-point feet rotation ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disabling this uses the default foot rotation calculation, using the terrain normal data.\n* Enabling this uses a slightly more complex but more stable and accurate rotation calculation. Uses 4 traces per feet instead of 1.\n* Provides greater control of rotation control in the foot array. Have the ability to control the frontal and sideway spacing per feet." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Use_Four_Point_Feets = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets = { "Use_Four_Point_Feets", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Enable foot lift limit ? (uses the foot extension ratios in foot array)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Enable_Foot_Lift_Limit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit = { "Enable_Foot_Lift_Limit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Disable this to completely disable finger ik if finger data is written.\n\x09*/" },
#endif
		{ "DisplayName", "Calculate toe/finger rotations ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Disable this to completely disable finger ik if finger data is written." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Affect_Toes_Always = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always = { "Affect_Toes_Always", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Finger_Alpha_Velocity_Curve_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This will gradually turn off finger ik when in locomotion to give smoother and stable results during gameplay.\n\x09* Default values make finger ik only available when idle. Tweak it to enable it during gameplay.\n\x09* \n\x09*/" },
#endif
		{ "DisplayName", "Finger IK Alpha relative to velocity" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This will gradually turn off finger ik when in locomotion to give smoother and stable results during gameplay.\n* Default values make finger ik only available when idle. Tweak it to enable it during gameplay." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Finger_Alpha_Velocity_Curve = { "Finger_Alpha_Velocity_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Finger_Alpha_Velocity_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Finger_Alpha_Velocity_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Finger_Alpha_Velocity_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Max_Limb_Radius_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Decrease this to clamp the leg ik within the angle.\n\x09* Can help decrease jarring knee bending on extreme terrain conditions.\n\x09*/" },
#endif
		{ "DisplayName", "Maximum allowed leg ik angle" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Decrease this to clamp the leg ik within the angle.\n* Can help decrease jarring knee bending on extreme terrain conditions." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Max_Limb_Radius = { "Max_Limb_Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Max_Limb_Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Max_Limb_Radius_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Max_Limb_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping_MetaData[] = {
		{ "Category", "FeetLiftWarping" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this to use the feet lift warping feature.\n* This will let the limb animations to be exaggerarted in a verticaly manner, increasing/decreasing the feet lift intensity depending on the animation.\n*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to use the feet lift warping feature.\n* This will let the limb animations to be exaggerarted in a verticaly manner, increasing/decreasing the feet lift intensity depending on the animation." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Feet_Lift_Warping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping = { "Feet_Lift_Warping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warp_Multiplier_MetaData[] = {
		{ "Category", "FeetLiftWarping" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the warp value.\n\x09* * A value of 1 means the default animated result. This works like a multiplier.\n\x09* * A value above 1 means there is an increased exaggeration in the feet lifting of the current animation\n\x09* * A value below 1 means there is a decrease in the intensity of the feet lifting of the current animation\n\x09* * The warping effect works linearly based on the position of the feet at a given moment of an animated pose relative to the ground.\n\n\x09*/" },
#endif
		{ "DisplayName", "Feet Lift Warp Multiplier" },
		{ "EditCondition", "Feet_Lift_Warping" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the warp value.\n* * A value of 1 means the default animated result. This works like a multiplier.\n* * A value above 1 means there is an increased exaggeration in the feet lifting of the current animation\n* * A value below 1 means there is a decrease in the intensity of the feet lifting of the current animation\n* * The warping effect works linearly based on the position of the feet at a given moment of an animated pose relative to the ground." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warp_Multiplier = { "Feet_Lift_Warp_Multiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Feet_Lift_Warp_Multiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warp_Multiplier_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warp_Multiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_vertical_size_MetaData[] = {
		{ "Category", "FeetLiftWarping" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the approx size of a single feet vertically in cm\n\x09*/" },
#endif
		{ "DisplayName", "Approx Feet Height" },
		{ "EditCondition", "Feet_Lift_Warping" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the approx size of a single feet vertically in cm" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_vertical_size = { "feet_vertical_size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, feet_vertical_size), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_vertical_size_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_vertical_size_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Limit_MetaData[] = {
		{ "Category", "FeetLiftWarping" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the maximum height the feet can be lifted through vertical warping\n\x09*/" },
#endif
		{ "DisplayName", "Feet Lift-Up Limit" },
		{ "EditCondition", "Feet_Lift_Warping" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the maximum height the feet can be lifted through vertical warping" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Limit = { "Feet_Lift_Limit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Feet_Lift_Limit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Limit_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Limit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this to use the sticky feets feature.\n* This will instantly enable/disable the entire sticky feets functionality without any interpolation.\n*/" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to use the sticky feets feature.\n* This will instantly enable/disable the entire sticky feets functionality without any interpolation." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->sticky_feet_mode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode = { "sticky_feet_mode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_on_speed_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Interpolation speed of the feets when going from normal to sticky state. */" },
#endif
		{ "EditCondition", "sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interpolation speed of the feets when going from normal to sticky state." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_on_speed = { "sticky_feet_on_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, sticky_feet_on_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_on_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_on_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_off_speed_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Interpolation speed of the feets when going from sticky to normal state. */" },
#endif
		{ "EditCondition", "sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interpolation speed of the feets when going from sticky to normal state." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_off_speed = { "sticky_feet_off_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, sticky_feet_off_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_off_speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_off_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Sticky_Feet_Range_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* How far can a feet stick from it's original position before it gets released ?\n* Really useful to get stick feets to get released if the leg over stretches during movement.\n* Eg:- If value is 30, then the feet will stop getting stuck if the distance between the stick position and original feet position crosses a distance of 30 units.\n* The default 0 value means the feet will never get unstuck depending on distance between stick position and original feet position. The feet stick tolerance logic is essentially ignored in 0.\n*/" },
#endif
		{ "DisplayName", "Feet stick tolerance ? (0 means tolerance logic ignored)" },
		{ "EditCondition", "sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* How far can a feet stick from it's original position before it gets released ?\n* Really useful to get stick feets to get released if the leg over stretches during movement.\n* Eg:- If value is 30, then the feet will stop getting stuck if the distance between the stick position and original feet position crosses a distance of 30 units.\n* The default 0 value means the feet will never get unstuck depending on distance between stick position and original feet position. The feet stick tolerance logic is essentially ignored in 0." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Sticky_Feet_Range = { "Sticky_Feet_Range", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Sticky_Feet_Range), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Sticky_Feet_Range_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Sticky_Feet_Range_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feets_data_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Used if sticky feet mode is enabled and automatic floor sticking is set to false.\n\x09* A boolean array that corresponds to stick state of each legs. True means that limb is sticked to the ground. False is the unsticked normal mode.\n\x09* Dynamically enabling/disabling this could help remove the slippery leg problem when character is moving.\n\x09*/" },
#endif
		{ "DisplayName", "Manual Sticky Feets Array" },
		{ "EditCondition", "!sticky_floor_detection && sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Used if sticky feet mode is enabled and automatic floor sticking is set to false.\n* A boolean array that corresponds to stick state of each legs. True means that limb is sticked to the ground. False is the unsticked normal mode.\n* Dynamically enabling/disabling this could help remove the slippery leg problem when character is moving." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feets_data = { "sticky_feets_data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, sticky_feets_data), Z_Construct_UScriptStruct_FDragonData_StickyFeetStruct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feets_data_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feets_data_MetaData) }; // 2374290724
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09*Enable this to use auto floor sticking. The feets of the character stick if it goes below the floor value.\n\x09* Optionally, you can use the sticky sockets data to stick based on the bone socket location rather than the feet locations.\n\x09* Eg:- If your feet/socket goes below 2.2f value in Z direction, then feets are frozen in place until the animated feet goes above 2.2f Z value again.\n\x09* Enabling this disables\n\x09*/" },
#endif
		{ "DisplayName", "Use automatic floor sticking ?" },
		{ "EditCondition", "sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*Enable this to use auto floor sticking. The feets of the character stick if it goes below the floor value.\n* Optionally, you can use the sticky sockets data to stick based on the bone socket location rather than the feet locations.\n* Eg:- If your feet/socket goes below 2.2f value in Z direction, then feets are frozen in place until the animated feet goes above 2.2f Z value again.\n* Enabling this disables" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->sticky_floor_detection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection = { "sticky_floor_detection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_floor_value_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the floor value in component space used for auto feet sticking. It's not used for manual sticking.\n\x09* Tweak this value slightly until the feets stick at the right height. Usually this value could be an approx height of the feet.\n\x09* If the foot/socket reaches below this value during any frame of the animation, it will be turned into a stick state. Vice versa for un-stick state.\n\x09*/" },
#endif
		{ "DisplayName", "Sticky floor height" },
		{ "EditCondition", "sticky_floor_detection && sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the floor value in component space used for auto feet sticking. It's not used for manual sticking.\n* Tweak this value slightly until the feets stick at the right height. Usually this value could be an approx height of the feet.\n* If the foot/socket reaches below this value during any frame of the animation, it will be turned into a stick state. Vice versa for un-stick state." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_floor_value = { "floor_value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, floor_value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_floor_value_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_floor_value_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Toggle this to smoothly turn on/off the feet sticking during automatic-sticking mode.\n\x09*/" },
#endif
		{ "EditCondition", "sticky_floor_detection && sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Toggle this to smoothly turn on/off the feet sticking during automatic-sticking mode." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle_SetBit(void* Obj)
	{
		((FAnimNode_DragonFeetSolver*)Obj)->Auto_Sticky_Toggle = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle = { "Auto_Sticky_Toggle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonFeetSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_sockets_data_MetaData[] = {
		{ "Category", "StickyFeetFunctions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Used only if automatic floor detection logic is used instead of the manual bool method.\n*/" },
#endif
		{ "EditCondition", "sticky_floor_detection && sticky_feet_mode" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Used only if automatic floor detection logic is used instead of the manual bool method." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_sockets_data = { "sticky_sockets_data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, sticky_sockets_data), Z_Construct_UScriptStruct_FDragonData_StickySocketStruct, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_sockets_data_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_sockets_data_MetaData) }; // 3233476475
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_01_Height_Offset_MetaData[] = {
		{ "Category", "DynamicFootOffset" },
		{ "DisplayName", "(optional) Foot 1 Height offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_01_Height_Offset = { "Foot_01_Height_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Foot_01_Height_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_01_Height_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_01_Height_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_02_Height_Offset_MetaData[] = {
		{ "Category", "DynamicFootOffset" },
		{ "DisplayName", "(optional) Foot 2 Height offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_02_Height_Offset = { "Foot_02_Height_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Foot_02_Height_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_02_Height_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_02_Height_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_03_Height_Offset_MetaData[] = {
		{ "Category", "DynamicFootOffset" },
		{ "DisplayName", "(optional) Foot 3 Height offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_03_Height_Offset = { "Foot_03_Height_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Foot_03_Height_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_03_Height_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_03_Height_Offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_04_Height_Offset_MetaData[] = {
		{ "Category", "DynamicFootOffset" },
		{ "DisplayName", "(optional) Foot 4 Height offset" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonFeetSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_04_Height_Offset = { "Foot_04_Height_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonFeetSolver, Foot_04_Height_Offset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_04_Height_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_04_Height_Offset_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_trace_manager_component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_solver_identifier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_dragon_input_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ik_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_hit_complex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_trace_interval_duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_LOD_Specific_Intervals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD0_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD1_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_LOD2_Interval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Trace_Distance_Adapting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Max_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Interval_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interval_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Override_Curve_Velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_custom_velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_loc_interp_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_rot_interp_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_virtual_scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_alpha_multiplier_array,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_extra_offset_array,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_automatic_leg_make,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_OptionalRef_Feet_As_Ref,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_enable_solver,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Work_Outside_PIE,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_OptionalRefPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_interpolate_only_z,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_shift_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Location_Lerp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_rotation_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ignore_shift_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Lerping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Ignore_Location_Lerping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Interpolation_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Complex_Rotation_Method,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_ComplexSimpleFoot_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Anti_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_FPS_Lerp_Treshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_upper_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_line_trace_down_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Trace_Down_Multiplier_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Anti_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_use_footstep_listening,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Should_Rotate_Feet,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_show_trace_in_game,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_execute_in_preview,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Pitch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Roll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_direction_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_character_forward_direction_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_poles_forward_direction_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Use_Four_Point_Feets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Enable_Foot_Lift_Limit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Affect_Toes_Always,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Finger_Alpha_Velocity_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Max_Limb_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Warp_Multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_feet_vertical_size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Feet_Lift_Limit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_mode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_on_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feet_off_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Sticky_Feet_Range,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_feets_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_floor_detection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_floor_value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Auto_Sticky_Toggle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_sticky_sockets_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_01_Height_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_02_Height_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_03_Height_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewProp_Foot_04_Height_Offset,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonFeetSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonFeetSolver),
		alignof(FAnimNode_DragonFeetSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::EnumInfo[] = {
		{ EIK_Type_Plugin_StaticEnum, TEXT("EIK_Type_Plugin"), &Z_Registration_Info_UEnum_EIK_Type_Plugin, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1115181697U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_DragonFeetSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics::NewStructOps, TEXT("AnimNode_DragonFeetSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonFeetSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonFeetSolver), 463085226U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_2573860877(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
