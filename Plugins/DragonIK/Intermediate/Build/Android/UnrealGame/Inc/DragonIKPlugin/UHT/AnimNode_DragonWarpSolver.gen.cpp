// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonWarpSolver.h"
#include "../../Source/Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "DragonIK_Library.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonWarpSolver() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_WarpLimbsData();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ETraceTypeQuery();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_DragonWarpSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonWarpSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver;
class UScriptStruct* FAnimNode_DragonWarpSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonWarpSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonWarpSolver>()
{
	return FAnimNode_DragonWarpSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_dragon_limb_input_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dragon_limb_input_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_dragon_limb_input;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hip_Bone_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Hip_Bone_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_enable_solver_MetaData[];
#endif
		static void NewProp_enable_solver_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable_solver;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_character_direction_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_character_direction_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_forward_vector_CS_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_forward_vector_CS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_warping_const_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed_warping_const;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_enable_slope_warp_MetaData[];
#endif
		static void NewProp_enable_slope_warp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable_slope_warp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_automatic_speed_warping_const_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_automatic_speed_warping_const;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_slope_detection_tolerance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_slope_detection_tolerance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Warp_Slope_Interpolation_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Warp_Slope_Interpolation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_Channel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Trace_Channel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_downward_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_downward_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_line_trace_upper_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_line_trace_upper_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_virtual_leg_width_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_virtual_leg_width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_virtual_scale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_virtual_scale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayLineTrace_MetaData[];
#endif
		static void NewProp_DisplayLineTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DisplayLineTrace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Limb_Compression_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Limb_Compression_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Limb_Lifting_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Limb_Lifting_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hip_Change_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Hip_Change_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hip_Lifting_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hip_Lifting_Curve;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//USTRUCT(BlueprintInternalUseOnly)\n" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "ToolTip", "USTRUCT(BlueprintInternalUseOnly)" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonWarpSolver>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input_Inner = { "dragon_limb_input", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDragonData_WarpLimbsData, METADATA_PARAMS(0, nullptr) }; // 3298322812
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input_MetaData[] = {
		{ "Category", "InputData" },
		{ "Comment", "/*\n\x09\x09* Type the legs/arm bone inputs.\n  */" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Type the legs/arm bone inputs." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input = { "dragon_limb_input", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, dragon_limb_input), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input_MetaData) }; // 3298322812
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Bone_Name_MetaData[] = {
		{ "Category", "InputData" },
		{ "Comment", "/*\n\x09\x09* Choose either the pelvis/hip bone or the root bone.\n\x09\x09* Used for offseting the location using the warp constants and warp curve datas.\n\x09\x09*/" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Choose either the pelvis/hip bone or the root bone.\n* Used for offseting the location using the warp constants and warp curve datas." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Bone_Name = { "Hip_Bone_Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Hip_Bone_Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Bone_Name_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Bone_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n* Toggle this parameter to turn on/off ik.\n* Example use case : Disable it when character is jumping or flying in the air.\n*/" },
		{ "DisplayName", "Enable Solver (Instant)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "* Toggle this parameter to turn on/off ik.\n* Example use case : Disable it when character is jumping or flying in the air." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver_SetBit(void* Obj)
	{
		((FAnimNode_DragonWarpSolver*)Obj)->enable_solver = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver = { "enable_solver", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWarpSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_character_direction_vector_CS_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations.\n*/" },
		{ "DisplayName", "Character Up Direction Vector (Local space)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "*The up direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_character_direction_vector_CS = { "character_direction_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, character_direction_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_character_direction_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_character_direction_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_forward_vector_CS_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n*The forward direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations.\n*/" },
		{ "DisplayName", "Character Forward Vector (Local space)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "*The forward direction vector of the character in component space.\n* 99% cases, this should not be altered.\n* Only needed to alter on characters that do not follow the standard unreal character orientations." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_forward_vector_CS = { "forward_vector_CS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, forward_vector_CS), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_forward_vector_CS_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_forward_vector_CS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_speed_warping_const_MetaData[] = {
		{ "Category", "ManualWarpSettings" },
		{ "Comment", "/*\n\x09* Tweak this to warp your character arms/legs so they become exaggerated and de-exaggerated.\n\x09* 1 means the default non-warped result. \n\x09* Lower than a 1 value will warp inwards. Values above 1 will warp outwards.\n\x09* This input does nothing if automatic slope warping is enabled. The automatic slope warp speed warping constant will be used instead.\n\x09*/" },
		{ "DisplayName", "Manual Speed warping parameter" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "* Tweak this to warp your character arms/legs so they become exaggerated and de-exaggerated.\n* 1 means the default non-warped result.\n* Lower than a 1 value will warp inwards. Values above 1 will warp outwards.\n* This input does nothing if automatic slope warping is enabled. The automatic slope warp speed warping constant will be used instead." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_speed_warping_const = { "speed_warping_const", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, speed_warping_const), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_speed_warping_const_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_speed_warping_const_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n* This will enable slope warping and disable manual warping.\n* If enabled, the manual speed warping parameter will not affect anything.\n* If enabled, the automatic speed warping constant will be used along with the respective curve datas.\n*/" },
		{ "DisplayName", "Use Automatic Slope Warp ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* This will enable slope warping and disable manual warping.\n* If enabled, the manual speed warping parameter will not affect anything.\n* If enabled, the automatic speed warping constant will be used along with the respective curve datas." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp_SetBit(void* Obj)
	{
		((FAnimNode_DragonWarpSolver*)Obj)->enable_slope_warp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp = { "enable_slope_warp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWarpSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_automatic_speed_warping_const_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n\x09* Tweak this to warp your character arms/legs so they become exaggerated and de-exaggerated on slopes. \n\x09* This value is used for the curve datas.\n\x09* This parameter is disabled if automatic slope warping is disabled.\n\x09*/" },
		{ "DisplayName", "Automatic Speed warping constant" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Tweak this to warp your character arms/legs so they become exaggerated and de-exaggerated on slopes.\n* This value is used for the curve datas.\n* This parameter is disabled if automatic slope warping is disabled." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_automatic_speed_warping_const = { "automatic_speed_warping_const", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, automatic_speed_warping_const), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_automatic_speed_warping_const_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_automatic_speed_warping_const_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_slope_detection_tolerance_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n\x09* Increase this value to warp more on slopes.\n\x09* Decrease this value to warp less on slopes.\n\x09*/" },
		{ "DisplayName", "Slope Detection Tolerance" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Increase this value to warp more on slopes.\n* Decrease this value to warp less on slopes." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_slope_detection_tolerance = { "slope_detection_tolerance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, slope_detection_tolerance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_slope_detection_tolerance_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_slope_detection_tolerance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Warp_Slope_Interpolation_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n\x09* The interpolation speed of the slope detection and related warping process.\n\x09*/" },
		{ "DisplayName", "Warp Slope Interpolation Speed" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The interpolation speed of the slope detection and related warping process." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Warp_Slope_Interpolation = { "Warp_Slope_Interpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Warp_Slope_Interpolation), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Warp_Slope_Interpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Warp_Slope_Interpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Trace_Channel_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings.*/" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "ToolTip", "* Trace channel used by the solver traces. Recommended to create a new dedicated trace channel for the ik through project settings." },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Trace_Channel = { "Trace_Channel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Trace_Channel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Trace_Channel_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Trace_Channel_MetaData) }; // 2725057287
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_downward_height_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n* The size of the line traces below the hips */" },
		{ "DisplayName", "Trace Downward Height" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The size of the line traces below the hips" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_downward_height = { "line_trace_downward_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, line_trace_downward_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_downward_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_downward_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_upper_height_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n\x09* The size of the line traces above the hips */" },
		{ "DisplayName", "Trace Upward Height" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The size of the line traces above the hips" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_upper_height = { "line_trace_upper_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, line_trace_upper_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_upper_height_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_upper_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_leg_width_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "Comment", "/*\n* The spacing width of the two line traces responsible for detecting slopes.\n*/" },
		{ "DisplayName", "Trace Gap Size" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The spacing width of the two line traces responsible for detecting slopes." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_leg_width = { "virtual_leg_width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, virtual_leg_width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_leg_width_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_leg_width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_scale_MetaData[] = {
		{ "Category", "BasicSettings" },
		{ "Comment", "/*\n* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters.\n*/" },
		{ "DisplayName", "Global trace scale multiplier" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Virtual scale multiplier of the ik\n* Increase this value if your mesh is super big by default and you are too lazy to increase all parameters one by one.\n* Uniformly increases all trace related parameters." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_scale = { "virtual_scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, virtual_scale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_scale_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_scale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace_MetaData[] = {
		{ "Category", "AutomaticSlopeWarpSettings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace_SetBit(void* Obj)
	{
		((FAnimNode_DragonWarpSolver*)Obj)->DisplayLineTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace = { "DisplayLineTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWarpSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Compression_Intensity_MetaData[] = {
		{ "Category", "CommonWarpSettings" },
		{ "Comment", "/*\n\x09* The intensity of the extra limb compression when warping.\n\x09* Used as a multiplier for the extra limb compression curve.\n\x09* 0 means no extra compression.\n\x09* The blue disc widgets in the viewport below the feets is responsible for determining the reference point for compression.\n\x09* The blue discs need to be tweaked accordingly to avoid offsets.\n\x09*/" },
		{ "DisplayName", "Extra limb compression multiplier with respect to warp" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The intensity of the extra limb compression when warping.\n* Used as a multiplier for the extra limb compression curve.\n* 0 means no extra compression.\n* The blue disc widgets in the viewport below the feets is responsible for determining the reference point for compression.\n* The blue discs need to be tweaked accordingly to avoid offsets." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Compression_Intensity = { "Limb_Compression_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Limb_Compression_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Compression_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Compression_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Lifting_Curve_MetaData[] = {
		{ "Category", "CommonWarpSettings" },
		{ "Comment", "/*\n\x09* The extra compression of the arms/legs when changing warp value.\n\x09* The X-axis is the warp value that goes from 0 to n-value.\n\x09* The Y-axis is the intensity of the compression. This multiplies with the extra limb compression intensity parameter.\n\x09*/" },
		{ "DisplayName", "Extra limb Compression Curve. X-axis is speed warp parameter." },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The extra compression of the arms/legs when changing warp value.\n* The X-axis is the warp value that goes from 0 to n-value.\n* The Y-axis is the intensity of the compression. This multiplies with the extra limb compression intensity parameter." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Lifting_Curve = { "Limb_Lifting_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Limb_Lifting_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Lifting_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Lifting_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Change_Intensity_MetaData[] = {
		{ "Category", "CommonWarpSettings" },
		{ "Comment", "/*\n\x09* A multiplier value that is used for offseting the hips when changing warp value.\n\x09*/" },
		{ "DisplayName", "Hip Lift multiplier. Multiplies with the hip lift curve." },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* A multiplier value that is used for offseting the hips when changing warp value." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Change_Intensity = { "Hip_Change_Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Hip_Change_Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Change_Intensity_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Change_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Lifting_Curve_MetaData[] = {
		{ "Category", "CommonWarpSettings" },
		{ "Comment", "/*\n\x09* The curve input that multiplies with the hip lift constant.\n\x09* The X-axis is the warp value that goes from 0 to n-value\n\x09* The Y-axis is the intensity of the extra lift of the hips and limbs.\n\x09* Example use case is pushing the character down when at high warp values.\n\x09*/" },
		{ "DisplayName", "Hip Lifting Curve. X-axis is speed warp parameter." },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWarpSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The curve input that multiplies with the hip lift constant.\n* The X-axis is the warp value that goes from 0 to n-value\n* The Y-axis is the intensity of the extra lift of the hips and limbs.\n* Example use case is pushing the character down when at high warp values." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Lifting_Curve = { "Hip_Lifting_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWarpSolver, Hip_Lifting_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Lifting_Curve_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Lifting_Curve_MetaData) }; // 3321759441
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_dragon_limb_input,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Bone_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_solver,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_character_direction_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_forward_vector_CS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_speed_warping_const,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_enable_slope_warp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_automatic_speed_warping_const,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_slope_detection_tolerance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Warp_Slope_Interpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Trace_Channel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_downward_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_line_trace_upper_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_leg_width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_virtual_scale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_DisplayLineTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Compression_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Limb_Lifting_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Change_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewProp_Hip_Lifting_Curve,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonWarpSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonWarpSolver),
		alignof(FAnimNode_DragonWarpSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonWarpSolver_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonWarpSolver_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_DragonWarpSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonWarpSolver_Statics::NewStructOps, TEXT("AnimNode_DragonWarpSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonWarpSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonWarpSolver), 1714228084U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonWarpSolver_h_715677897(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonWarpSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonWarpSolver_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
