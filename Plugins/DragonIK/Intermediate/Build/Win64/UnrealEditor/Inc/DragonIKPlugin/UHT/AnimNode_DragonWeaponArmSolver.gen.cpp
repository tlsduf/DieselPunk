// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimNode_DragonWeaponArmSolver.h"
#include "DragonIK_Library.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_DragonWeaponArmSolver() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_NoRegister();
	DRAGONIKPLUGIN_API UEnum* Z_Construct_UEnum_DragonIKPlugin_ETwist_Type_DragonIK();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonControlBase();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_ArmsData();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_DragonWeaponArmSolver>() == std::is_polymorphic<FAnimNode_DragonControlBase>(), "USTRUCT FAnimNode_DragonWeaponArmSolver cannot be polymorphic unless super FAnimNode_DragonControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver;
class UScriptStruct* FAnimNode_DragonWeaponArmSolver::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("AnimNode_DragonWeaponArmSolver"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FAnimNode_DragonWeaponArmSolver>()
{
	return FAnimNode_DragonWeaponArmSolver::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_weapon_handler_component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_weapon_handler_component;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Physweapon_Component_Tag_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Physweapon_Component_Tag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Aiming_Hand_Limbs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Aiming_Hand_Limbs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Aiming_Hand_Limbs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_primary_hand_index_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_primary_hand_index;
		static const UECodeGen_Private::FBytePropertyParams NewProp_arm_twist_axis_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_arm_twist_axis_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_arm_twist_axis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Let_Arm_Twist_With_Hand_MetaData[];
#endif
		static void NewProp_Let_Arm_Twist_With_Hand_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Let_Arm_Twist_With_Hand;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//USTRUCT(BlueprintInternalUseOnly)\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "USTRUCT(BlueprintInternalUseOnly)" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_DragonWeaponArmSolver>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_weapon_handler_component_MetaData[] = {
		{ "Category", "InputData" },
		{ "DisplayName", "Physweapon Component Ref" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_weapon_handler_component = { "weapon_handler_component", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, weapon_handler_component), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_weapon_handler_component_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_weapon_handler_component_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Physweapon_Component_Tag_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\x09/** Target socket to look at. Used if LookAtBone is empty. - You can use  LookAtLocation if you need offset from this point. That location will be used in their local space. **/\n//\x09UPROPERTY(EditAnywhere, Category = LookAtSettings)\n//\x09\x09""FBoneSocketTarget LookAtTarget;\n" },
#endif
		{ "DisplayName", "Physweapon Component Tag" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target socket to look at. Used if LookAtBone is empty. - You can use  LookAtLocation if you need offset from this point. That location will be used in their local space. *\nUPROPERTY(EditAnywhere, Category = LookAtSettings)\n      FBoneSocketTarget LookAtTarget;" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Physweapon_Component_Tag = { "Physweapon_Component_Tag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, Physweapon_Component_Tag), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Physweapon_Component_Tag_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Physweapon_Component_Tag_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs_Inner = { "Aiming_Hand_Limbs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDragonData_ArmsData, METADATA_PARAMS(0, nullptr) }; // 648727300
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs_MetaData[] = {
		{ "Category", "InputData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The hand inputs. Used for seperate clamping and restricting of limb movements during body aiming.\n\x09* Uses : Weapon aiming, hand restriction while extreme body bending, wings stability etc\n\x09*/" },
#endif
		{ "DisplayName", "Hands Input (optional)" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The hand inputs. Used for seperate clamping and restricting of limb movements during body aiming.\n* Uses : Weapon aiming, hand restriction while extreme body bending, wings stability etc" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs = { "Aiming_Hand_Limbs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, Aiming_Hand_Limbs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs_MetaData) }; // 648727300
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_primary_hand_index_MetaData[] = {
		{ "Category", "InputData" },
		{ "DisplayName", "Primary Hand Index" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_primary_hand_index = { "primary_hand_index", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, primary_hand_index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_primary_hand_index_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_primary_hand_index_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Choose the axis of your arm twisting.\n* Only used if reaching mode is used. It's ignored for aiming mode.\n*/" },
#endif
		{ "DisplayName", "Arm Twist Axis Technique" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Choose the axis of your arm twisting.\n* Only used if reaching mode is used. It's ignored for aiming mode." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis = { "arm_twist_axis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, arm_twist_axis), Z_Construct_UEnum_DragonIKPlugin_ETwist_Type_DragonIK, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis_MetaData) }; // 1584971014
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n*///\x09UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (DisplayName = \"Work outside gameplay (For Sequencer)\", PinShownByDefault))\n//\x09\x09""bool Work_Outside_PIE = true;\n" },
#endif
		{ "DisplayName", "Should arm twist with hand ?" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this parameter to make IK work even when not playing in PIE mode\n* Useful for recording in sequencer.\n//     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (DisplayName = \"Work outside gameplay (For Sequencer)\", PinShownByDefault))\n//             bool Work_Outside_PIE = true;" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_SetBit(void* Obj)
	{
		((FAnimNode_DragonWeaponArmSolver*)Obj)->Let_Arm_Twist_With_Hand = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand = { "Let_Arm_Twist_With_Hand", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWeaponArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation_SetBit(void* Obj)
	{
		((FAnimNode_DragonWeaponArmSolver*)Obj)->Enable_Interpolation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation = { "Enable_Interpolation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWeaponArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Interpolation_Speed_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Interpolation_Speed = { "Interpolation_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, Interpolation_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Interpolation_Speed_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Interpolation_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_LookAt_Axis_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* The forward direction axis of the character.\n\x09* Characters using the standard unreal directions use the default value.\n\x09*/" },
#endif
		{ "DisplayName", "Forward Axis" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* The forward direction axis of the character.\n* Characters using the standard unreal directions use the default value." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_LookAt_Axis = { "LookAt_Axis", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, LookAt_Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_LookAt_Axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_LookAt_Axis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Upward_Axis_MetaData[] = {
		{ "Category", "Settings" },
		{ "DisplayName", "Upward Axis" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Upward_Axis = { "Upward_Axis", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, Upward_Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Upward_Axis_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Upward_Axis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace_MetaData[] = {
		{ "Category", "DebuggingOnly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* Enable this to render the traces in the animgraph viewports.\n* Animbp viewport will be unaltered.\n*/" },
#endif
		{ "DisplayName", "Display Lines & Widgets" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Enable this to render the traces in the animgraph viewports.\n* Animbp viewport will be unaltered." },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace_SetBit(void* Obj)
	{
		((FAnimNode_DragonWeaponArmSolver*)Obj)->DisplayLineTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace = { "DisplayLineTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAnimNode_DragonWeaponArmSolver), &Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations_Inner = { "Debug_Hand_Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData[] = {
		{ "Category", "DebuggingOnly" },
		{ "ModuleRelativePath", "Public/AnimNode_DragonWeaponArmSolver.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations = { "Debug_Hand_Locations", nullptr, (EPropertyFlags)0x0010000000000041, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_DragonWeaponArmSolver, Debug_Hand_Locations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_weapon_handler_component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Physweapon_Component_Tag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Aiming_Hand_Limbs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_primary_hand_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_arm_twist_axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Let_Arm_Twist_With_Hand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Enable_Interpolation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Interpolation_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_LookAt_Axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Upward_Axis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_DisplayLineTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewProp_Debug_Hand_Locations,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		Z_Construct_UScriptStruct_FAnimNode_DragonControlBase,
		&NewStructOps,
		"AnimNode_DragonWeaponArmSolver",
		Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::PropPointers),
		sizeof(FAnimNode_DragonWeaponArmSolver),
		alignof(FAnimNode_DragonWeaponArmSolver),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000205),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonWeaponArmSolver_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonWeaponArmSolver_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_DragonWeaponArmSolver::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_DragonWeaponArmSolver_Statics::NewStructOps, TEXT("AnimNode_DragonWeaponArmSolver"), &Z_Registration_Info_UScriptStruct_AnimNode_DragonWeaponArmSolver, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_DragonWeaponArmSolver), 3060369949U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonWeaponArmSolver_h_810114099(TEXT("/Script/DragonIKPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonWeaponArmSolver_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonWeaponArmSolver_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
