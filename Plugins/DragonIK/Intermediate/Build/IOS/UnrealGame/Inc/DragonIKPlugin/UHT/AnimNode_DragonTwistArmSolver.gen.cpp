// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonTwistArmSolver.h"
#include "DragonIK_Library.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonTwistArmSolver() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_EPole_System_DragonIK();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_ERotation_Type_DragonIK();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_ETwist_Type_DragonIK();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_ArmsData();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_DragonTwistArmSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonTwistArmSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver;
class UScriptStruct* FAnimNode_DragonTwistArmSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonTwistArmSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonTwistArmSolver>()
{
	return FAnimNode_DragonTwistArmSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hand_Input_Info_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hand_Input_Info;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_target_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_target_transform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extra_Elbow_Pole_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extra_Elbow_Pole_Offset;
		static const UECodeGen_Private::FBytePropertyParams NewProp_pole_system_input_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pole_system_input_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_pole_system_input;
		static const UECodeGen_Private::FBytePropertyParams NewProp_arm_twist_axis_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_arm_twist_axis_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_arm_twist_axis;
		static const UECodeGen_Private::FBytePropertyParams NewProp_hand_rotation_method_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hand_rotation_method_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_hand_rotation_method;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Let_Arm_Twist_With_Hand_MetaData[];
#endif
		static void NewProp_Let_Arm_Twist_With_Hand_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Let_Arm_Twist_With_Hand;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_allow_arm_stretch_MetaData[];
#endif
		static void NewProp_allow_arm_stretch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_allow_arm_stretch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enable_Interpolation_MetaData[];
#endif
		static void NewProp_Enable_Interpolation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enable_Interpolation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interpolation_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Interpolation_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAt_Axis_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LookAt_Axis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Upward_Axis_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Upward_Axis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Use_Physics_Adaptation_MetaData[];
#endif
		static void NewProp_Use_Physics_Adaptation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_Physics_Adaptation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_physics_root_reference_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_physics_root_reference;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayLineTrace_MetaData[];
#endif
		static void NewProp_DisplayLineTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DisplayLineTrace;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Debug_Hand_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Debug_Hand_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Debug_Hand_Locations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//USTRUCT(BlueprintInternalUseOnly)\n" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "ToolTip", "USTRUCT(BlueprintInternalUseOnly)" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonTwistArmSolver>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Hand_Input_Info_MetaData[] = {
		{ "Category", "InputData" },
		{ "Comment", "//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputData, meta = (DisplayName = \"Hands Input (optional)\", PinHiddenByDefault))\n//\x09TArray<FDragonData_ArmsData> Aiming_Hand_Limbs;\n" },
		{ "DisplayName", "Hands Input Info" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputData, meta = (DisplayName = \"Hands Input (optional)\", PinHiddenByDefault))\n       TArray<FDragonData_ArmsData> Aiming_Hand_Limbs;" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Hand_Input_Info = { "Hand_Input_Info", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, Hand_Input_Info), Z_Construct_UScriptStruct_FDragonData_ArmsData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Hand_Input_Info_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Hand_Input_Info_MetaData) }; // 2305217581
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_target_transform_MetaData[] = {
		{ "Category", "InputData" },
		{ "Comment", "/*\n\x09\x09* Separate aim targets for hands.\n\x09\x09* Break this parameter after exposing to expose the array for dynamic modification.\n\x09\x09*///UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputData, meta = (DisplayName = \"Overrided Arm Aim Target Array\", PinHiddenByDefault))\n//\x09""FDragonData_Overrided_Location_Data Arm_TargetLocation_Overrides;\n" },
		{ "DisplayName", "Target Transform" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "* Separate aim targets for hands.\n* Break this parameter after exposing to expose the array for dynamic modification.\n//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputData, meta = (DisplayName = \"Overrided Arm Aim Target Array\", PinHiddenByDefault))\n//     FDragonData_Overrided_Location_Data Arm_TargetLocation_Overrides;" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_target_transform = { "target_transform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, target_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_target_transform_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_target_transform_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Extra_Elbow_Pole_Offset_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n\x09* You can use this to easily offset your auto-calculated elbow pole offset.\n\x09* Eg:- If you want to make the elbow poles an bit up during gameplay at certain points, then make this (0,0,X) where X is a positive number.\n\x09* The offset is done in component space and not in world space.\n\x09*/" },
		{ "DisplayName", "(optional) Extra Offset on the elbow poles" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* You can use this to easily offset your auto-calculated elbow pole offset.\n* Eg:- If you want to make the elbow poles an bit up during gameplay at certain points, then make this (0,0,X) where X is a positive number.\n* The offset is done in component space and not in world space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Extra_Elbow_Pole_Offset = { "Extra_Elbow_Pole_Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, Extra_Elbow_Pole_Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Extra_Elbow_Pole_Offset_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Extra_Elbow_Pole_Offset_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n* Select the pole system for the arms.\n* Only used if reaching mode is used. It's ignored for aiming mode.\n*/" },
		{ "DisplayName", "Arm Pole System Method" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "ToolTip", "* Select the pole system for the arms.\n* Only used if reaching mode is used. It's ignored for aiming mode." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input = { "pole_system_input", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, pole_system_input), Z_Construct_UEnum_DragonIKPlugin_EPole_System_DragonIK, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input_MetaData) }; // 2340247924
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n* Choose the axis of your arm twisting.\n* Only used if reaching mode is used. It's ignored for aiming mode.\n*/" },
		{ "DisplayName", "Arm Twist Axis Technique" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "ToolTip", "* Choose the axis of your arm twisting.\n* Only used if reaching mode is used. It's ignored for aiming mode." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis = { "arm_twist_axis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, arm_twist_axis), Z_Construct_UEnum_DragonIKPlugin_ETwist_Type_DragonIK, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis_MetaData) }; // 2021683273
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method_MetaData[] = {
		{ "Category", "ReachingAndSeparateAim" },
		{ "Comment", "/*\n\x09* Decide if the hand rotation is additively calculated or directly replaced by the hand transforms.\n\x09*/" },
		{ "DisplayName", "Hand Rotation Method" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "ToolTip", "* Decide if the hand rotation is additively calculated or directly replaced by the hand transforms." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method = { "hand_rotation_method", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, hand_rotation_method), Z_Construct_UEnum_DragonIKPlugin_ERotation_Type_DragonIK, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method_MetaData) }; // 1884170530
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n*///\x09UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (DisplayName = \"Work outside gameplay (For Sequencer)\", PinShownByDefault))\n//\x09\x09""bool Work_Outside_PIE = true;\n" },
		{ "DisplayName", "Should arm twist with hand ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n//     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (DisplayName = \"Work outside gameplay (For Sequencer)\", PinShownByDefault))\n//             bool Work_Outside_PIE = true;" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_SetBit(void* Obj)
	{
		((FAnimNode_DragonTwistArmSolver*)Obj)->Let_Arm_Twist_With_Hand = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand = { "Let_Arm_Twist_With_Hand", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonTwistArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Should arm stretch ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch_SetBit(void* Obj)
	{
		((FAnimNode_DragonTwistArmSolver*)Obj)->allow_arm_stretch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch = { "allow_arm_stretch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonTwistArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation_SetBit(void* Obj)
	{
		((FAnimNode_DragonTwistArmSolver*)Obj)->Enable_Interpolation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation = { "Enable_Interpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonTwistArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Interpolation_Speed_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Interpolation_Speed = { "Interpolation_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, Interpolation_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Interpolation_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Interpolation_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_LookAt_Axis_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/*\n\x09* The forward direction axis of the character.\n\x09* Characters using the standard unreal directions use the default value.\n\x09*/" },
		{ "DisplayName", "Forward Axis" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* The forward direction axis of the character.\n* Characters using the standard unreal directions use the default value." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_LookAt_Axis = { "LookAt_Axis", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, LookAt_Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_LookAt_Axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_LookAt_Axis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Upward_Axis_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Upward Axis" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Upward_Axis = { "Upward_Axis", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, Upward_Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Upward_Axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Upward_Axis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation_MetaData[] = {
		{ "Category", "AdvancedSettings" },
		{ "Comment", "/*\n * If using physical animation or in ragdoll state, if you want the aim solver to adapt to it and still target the correct targets, enable this.\n */" },
		{ "DisplayName", "Should solver adapt to physical animations ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* If using physical animation or in ragdoll state, if you want the aim solver to adapt to it and still target the correct targets, enable this." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation_SetBit(void* Obj)
	{
		((FAnimNode_DragonTwistArmSolver*)Obj)->Use_Physics_Adaptation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation = { "Use_Physics_Adaptation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonTwistArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_physics_root_reference_MetaData[] = {
		{ "Category", "AdvancedSettings" },
		{ "DisplayName", "Physics root reference bone (eg:- pelvis)" },
		{ "EditCondition", "Use_Physics_Adaptation" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_physics_root_reference = { "physics_root_reference", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, physics_root_reference), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_physics_root_reference_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_physics_root_reference_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace_MetaData[] = {
		{ "Category", "DebuggingOnly" },
		{ "Comment", "/*\n* Enable this to render the traces in the animgraph viewports.\n* Animbp viewport will be unaltered.\n*/" },
		{ "DisplayName", "Display Lines & Widgets" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Enable this to render the traces in the animgraph viewports.\n* Animbp viewport will be unaltered." },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace_SetBit(void* Obj)
	{
		((FAnimNode_DragonTwistArmSolver*)Obj)->DisplayLineTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace = { "DisplayLineTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonTwistArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations_Inner = { "Debug_Hand_Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData[] = {
		{ "Category", "DebuggingOnly" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonTwistArmSolver.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations = { "Debug_Hand_Locations", nullptr, (EPropertyFlags)0x0010000000000041, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonTwistArmSolver, Debug_Hand_Locations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Hand_Input_Info,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_target_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Extra_Elbow_Pole_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_pole_system_input,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_arm_twist_axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_hand_rotation_method,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_allow_arm_stretch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Enable_Interpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Interpolation_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_LookAt_Axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Upward_Axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Use_Physics_Adaptation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_physics_root_reference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_DisplayLineTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewProp_Debug_Hand_Locations,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonTwistArmSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonTwistArmSolver),
		alignof(FAnimNode_DragonTwistArmSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonTwistArmSolver_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonTwistArmSolver_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_DragonTwistArmSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonTwistArmSolver_Statics::NewStructOps, TEXT("AnimNode_DragonTwistArmSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonTwistArmSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonTwistArmSolver), 2000453650U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonTwistArmSolver_h_2810986187(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonTwistArmSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonTwistArmSolver_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
