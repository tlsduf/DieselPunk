// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DragonIKPhysicsComponent.h"
#include "../../Source/Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKPhysicsComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_ADragonIKPhysicsHolder_NoRegister();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKPhysicsComponent();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKPhysicsComponent_NoRegister();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier();
	DRAGONIKPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship;
class UScriptStruct* FDragonData_PhysicsParentRelationship::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonData_PhysicsParentRelationship"));
	}
	return Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonData_PhysicsParentRelationship>()
{
	return FDragonData_PhysicsParentRelationship::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_child_bone_name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_child_bone_name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_parent_bone_name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_parent_bone_name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonData_PhysicsParentRelationship>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_child_bone_name_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Child Bone Name" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_child_bone_name = { "child_bone_name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsParentRelationship, child_bone_name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_child_bone_name_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_child_bone_name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_parent_bone_name_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Parent Bone Name" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_parent_bone_name = { "parent_bone_name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsParentRelationship, parent_bone_name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_parent_bone_name_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_parent_bone_name_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_child_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewProp_parent_bone_name,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonData_PhysicsParentRelationship",
		Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::PropPointers),
		sizeof(FDragonData_PhysicsParentRelationship),
		alignof(FDragonData_PhysicsParentRelationship),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.InnerSingleton, Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier;
class UScriptStruct* FDragonData_PhysicsHandleMultiplier::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier, (UObject*)Z_Construct_UPackage__Script_DragonIKPlugin(), TEXT("DragonData_PhysicsHandleMultiplier"));
	}
	return Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.OuterSingleton;
}
template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<FDragonData_PhysicsHandleMultiplier>()
{
	return FDragonData_PhysicsHandleMultiplier::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bone_name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bone_strength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_bone_strength;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDragonData_PhysicsHandleMultiplier>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_name_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Bone Name" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsHandleMultiplier, bone_name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_name_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_strength_MetaData[] = {
		{ "Category", "SkeletalControl" },
		{ "DisplayName", "Bone Handle Strength Multiplier" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_strength = { "bone_strength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDragonData_PhysicsHandleMultiplier, bone_strength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_strength_MetaData), Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_strength_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewProp_bone_strength,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
		nullptr,
		&NewStructOps,
		"DragonData_PhysicsHandleMultiplier",
		Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::PropPointers),
		sizeof(FDragonData_PhysicsHandleMultiplier),
		alignof(FDragonData_PhysicsHandleMultiplier),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier()
	{
		if (!Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.InnerSingleton, Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier.InnerSingleton;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_PerformActiveRagdoll)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pelvis_mass_override);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_PerformActiveRagdoll_Validate(Z_Param_pelvis_mass_override))
		{
			RPC_ValidateFailed(TEXT("Multicast_PerformActiveRagdoll_Validate"));
			return;
		}
		P_THIS->Multicast_PerformActiveRagdoll_Implementation(Z_Param_pelvis_mass_override);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_PerformActiveRagdoll)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pelvis_mass_override);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_PerformActiveRagdoll_Validate(Z_Param_pelvis_mass_override))
		{
			RPC_ValidateFailed(TEXT("Server_PerformActiveRagdoll_Validate"));
			return;
		}
		P_THIS->Server_PerformActiveRagdoll_Implementation(Z_Param_pelvis_mass_override);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execPerformActiveRagdoll)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pelvis_mass_override);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PerformActiveRagdoll(Z_Param_pelvis_mass_override);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_Modify_Reset_Bone_Info)
	{
		P_GET_TARRAY(FName,Z_Param_bone_list);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Modify_Reset_Bone_Info_Validate(Z_Param_bone_list))
		{
			RPC_ValidateFailed(TEXT("Multicast_Modify_Reset_Bone_Info_Validate"));
			return;
		}
		P_THIS->Multicast_Modify_Reset_Bone_Info_Implementation(Z_Param_bone_list);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_Modify_Reset_Bone_Info)
	{
		P_GET_TARRAY(FName,Z_Param_bone_list);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Modify_Reset_Bone_Info_Validate(Z_Param_bone_list))
		{
			RPC_ValidateFailed(TEXT("Server_Modify_Reset_Bone_Info_Validate"));
			return;
		}
		P_THIS->Server_Modify_Reset_Bone_Info_Implementation(Z_Param_bone_list);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execModify_Reset_Bone_Info)
	{
		P_GET_TARRAY(FName,Z_Param_bone_list);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Modify_Reset_Bone_Info(Z_Param_bone_list);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_Control_Bone_Handle)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_bone_name);
		P_GET_STRUCT(FTransform,Z_Param_override_transform);
		P_GET_UBOOL(Z_Param_enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Control_Bone_Handle_Validate(Z_Param_bone_name,Z_Param_override_transform,Z_Param_enable))
		{
			RPC_ValidateFailed(TEXT("Multicast_Control_Bone_Handle_Validate"));
			return;
		}
		P_THIS->Multicast_Control_Bone_Handle_Implementation(Z_Param_bone_name,Z_Param_override_transform,Z_Param_enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_Control_Bone_Handle)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_bone_name);
		P_GET_STRUCT(FTransform,Z_Param_override_transform);
		P_GET_UBOOL(Z_Param_enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Control_Bone_Handle_Validate(Z_Param_bone_name,Z_Param_override_transform,Z_Param_enable))
		{
			RPC_ValidateFailed(TEXT("Server_Control_Bone_Handle_Validate"));
			return;
		}
		P_THIS->Server_Control_Bone_Handle_Implementation(Z_Param_bone_name,Z_Param_override_transform,Z_Param_enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execControl_Bone_Handle)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_bone_name);
		P_GET_STRUCT(FTransform,Z_Param_override_transform);
		P_GET_UBOOL(Z_Param_enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Control_Bone_Handle(Z_Param_bone_name,Z_Param_override_transform,Z_Param_enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_SetInterpolation)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_inter_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_SetInterpolation_Validate(Z_Param_inter_value))
		{
			RPC_ValidateFailed(TEXT("Multicast_SetInterpolation_Validate"));
			return;
		}
		P_THIS->Multicast_SetInterpolation_Implementation(Z_Param_inter_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_SetInterpolation)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_inter_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_SetInterpolation_Validate(Z_Param_inter_value))
		{
			RPC_ValidateFailed(TEXT("Server_SetInterpolation_Validate"));
			return;
		}
		P_THIS->Server_SetInterpolation_Implementation(Z_Param_inter_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execSetInterpolation)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_inter_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInterpolation(Z_Param_inter_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_UpdatePhysanimData)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearDamp);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularDamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_UpdatePhysanimData_Validate(Z_Param_LinearStrength,Z_Param_AngularStrength,Z_Param_LinearDamp,Z_Param_AngularDamp))
		{
			RPC_ValidateFailed(TEXT("Multicast_UpdatePhysanimData_Validate"));
			return;
		}
		P_THIS->Multicast_UpdatePhysanimData_Implementation(Z_Param_LinearStrength,Z_Param_AngularStrength,Z_Param_LinearDamp,Z_Param_AngularDamp);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_UpdatePhysanimData)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearDamp);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularDamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_UpdatePhysanimData_Validate(Z_Param_LinearStrength,Z_Param_AngularStrength,Z_Param_LinearDamp,Z_Param_AngularDamp))
		{
			RPC_ValidateFailed(TEXT("Server_UpdatePhysanimData_Validate"));
			return;
		}
		P_THIS->Server_UpdatePhysanimData_Implementation(Z_Param_LinearStrength,Z_Param_AngularStrength,Z_Param_LinearDamp,Z_Param_AngularDamp);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execUpdateSpecificPhysanimData)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_BoneName);
		P_GET_PROPERTY(FIntProperty,Z_Param_linear_strength_var);
		P_GET_PROPERTY(FIntProperty,Z_Param_angular_strength_var);
		P_GET_PROPERTY(FIntProperty,Z_Param_linear_damp_var);
		P_GET_PROPERTY(FIntProperty,Z_Param_angular_damp_var);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSpecificPhysanimData(Z_Param_BoneName,Z_Param_linear_strength_var,Z_Param_angular_strength_var,Z_Param_linear_damp_var,Z_Param_angular_damp_var);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execUpdatePhysanimData)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularStrength);
		P_GET_PROPERTY(FIntProperty,Z_Param_LinearDamp);
		P_GET_PROPERTY(FIntProperty,Z_Param_AngularDamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdatePhysanimData(Z_Param_LinearStrength,Z_Param_AngularStrength,Z_Param_LinearDamp,Z_Param_AngularDamp);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_ReleaseAllHandles)
	{
		P_GET_UBOOL(Z_Param_go_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_ReleaseAllHandles_Validate(Z_Param_go_ragdoll))
		{
			RPC_ValidateFailed(TEXT("Multicast_ReleaseAllHandles_Validate"));
			return;
		}
		P_THIS->Multicast_ReleaseAllHandles_Implementation(Z_Param_go_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_ReleaseAllHandles)
	{
		P_GET_UBOOL(Z_Param_go_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_ReleaseAllHandles_Validate(Z_Param_go_ragdoll))
		{
			RPC_ValidateFailed(TEXT("Server_ReleaseAllHandles_Validate"));
			return;
		}
		P_THIS->Server_ReleaseAllHandles_Implementation(Z_Param_go_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execReleaseAllHandles)
	{
		P_GET_UBOOL(Z_Param_go_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReleaseAllHandles(Z_Param_go_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_CacheSimulationStates)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_CacheSimulationStates_Validate())
		{
			RPC_ValidateFailed(TEXT("Multicast_CacheSimulationStates_Validate"));
			return;
		}
		P_THIS->Multicast_CacheSimulationStates_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_CacheSimulationStates)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_CacheSimulationStates_Validate())
		{
			RPC_ValidateFailed(TEXT("Server_CacheSimulationStates_Validate"));
			return;
		}
		P_THIS->Server_CacheSimulationStates_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execCacheSimulationStates)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CacheSimulationStates();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_DragonIKSimulatePhysics)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skmesh);
		P_GET_PROPERTY(FNameProperty,Z_Param_BoneName);
		P_GET_UBOOL(Z_Param_IncludeSelf);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_DragonIKSimulatePhysics_Validate(Z_Param_skmesh,Z_Param_BoneName,Z_Param_IncludeSelf))
		{
			RPC_ValidateFailed(TEXT("Multicast_DragonIKSimulatePhysics_Validate"));
			return;
		}
		P_THIS->Multicast_DragonIKSimulatePhysics_Implementation(Z_Param_skmesh,Z_Param_BoneName,Z_Param_IncludeSelf);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_DragonIKSimulatePhysics)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skmesh);
		P_GET_PROPERTY(FNameProperty,Z_Param_BoneName);
		P_GET_UBOOL(Z_Param_IncludeSelf);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_DragonIKSimulatePhysics_Validate(Z_Param_skmesh,Z_Param_BoneName,Z_Param_IncludeSelf))
		{
			RPC_ValidateFailed(TEXT("Server_DragonIKSimulatePhysics_Validate"));
			return;
		}
		P_THIS->Server_DragonIKSimulatePhysics_Implementation(Z_Param_skmesh,Z_Param_BoneName,Z_Param_IncludeSelf);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_OnHitCallback)
	{
		P_GET_STRUCT(FHitResult,Z_Param_Hit);
		P_GET_PROPERTY(FNameProperty,Z_Param_Optional_Override_Hit_Bone_Name);
		P_GET_STRUCT(FVector,Z_Param_hit_location);
		P_GET_STRUCT(FVector,Z_Param_hit_impulse_direction);
		P_GET_PROPERTY(FNameProperty,Z_Param_hit_bone_name);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_OnHitCallback_Validate(Z_Param_Hit,Z_Param_Optional_Override_Hit_Bone_Name,Z_Param_hit_location,Z_Param_hit_impulse_direction,Z_Param_hit_bone_name))
		{
			RPC_ValidateFailed(TEXT("Multicast_OnHitCallback_Validate"));
			return;
		}
		P_THIS->Multicast_OnHitCallback_Implementation(Z_Param_Hit,Z_Param_Optional_Override_Hit_Bone_Name,Z_Param_hit_location,Z_Param_hit_impulse_direction,Z_Param_hit_bone_name);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_OnHitCallback)
	{
		P_GET_STRUCT(FHitResult,Z_Param_Hit);
		P_GET_PROPERTY(FNameProperty,Z_Param_Optional_Override_Hit_Bone_Name);
		P_GET_STRUCT(FVector,Z_Param_hit_location);
		P_GET_STRUCT(FVector,Z_Param_hit_impulse_direction);
		P_GET_PROPERTY(FNameProperty,Z_Param_hit_bone_name);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_OnHitCallback_Validate(Z_Param_Hit,Z_Param_Optional_Override_Hit_Bone_Name,Z_Param_hit_location,Z_Param_hit_impulse_direction,Z_Param_hit_bone_name))
		{
			RPC_ValidateFailed(TEXT("Server_OnHitCallback_Validate"));
			return;
		}
		P_THIS->Server_OnHitCallback_Implementation(Z_Param_Hit,Z_Param_Optional_Override_Hit_Bone_Name,Z_Param_hit_location,Z_Param_hit_impulse_direction,Z_Param_hit_bone_name);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execOnHitCallback)
	{
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_GET_PROPERTY(FNameProperty,Z_Param_Optional_Override_Hit_Bone_Name);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_hit_location);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_hit_impulse_direction);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_hit_bone_name);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHitCallback(Z_Param_Out_Hit,Z_Param_Optional_Override_Hit_Bone_Name,Z_Param_Out_hit_location,Z_Param_Out_hit_impulse_direction,Z_Param_Out_hit_bone_name);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_ReGrabAllHandles)
	{
		P_GET_UBOOL(Z_Param_exit_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_ReGrabAllHandles_Validate(Z_Param_exit_ragdoll))
		{
			RPC_ValidateFailed(TEXT("Multicast_ReGrabAllHandles_Validate"));
			return;
		}
		P_THIS->Multicast_ReGrabAllHandles_Implementation(Z_Param_exit_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_ReGrabAllHandles)
	{
		P_GET_UBOOL(Z_Param_exit_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_ReGrabAllHandles_Validate(Z_Param_exit_ragdoll))
		{
			RPC_ValidateFailed(TEXT("Server_ReGrabAllHandles_Validate"));
			return;
		}
		P_THIS->Server_ReGrabAllHandles_Implementation(Z_Param_exit_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execReGrabAllHandles)
	{
		P_GET_UBOOL(Z_Param_exit_ragdoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReGrabAllHandles(Z_Param_exit_ragdoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execMulticast_FirstTimeInitialization)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skeleton_input);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_FirstTimeInitialization_Validate(Z_Param_skeleton_input))
		{
			RPC_ValidateFailed(TEXT("Multicast_FirstTimeInitialization_Validate"));
			return;
		}
		P_THIS->Multicast_FirstTimeInitialization_Implementation(Z_Param_skeleton_input);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execServer_FirstTimeInitialization)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skeleton_input);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_FirstTimeInitialization_Validate(Z_Param_skeleton_input))
		{
			RPC_ValidateFailed(TEXT("Server_FirstTimeInitialization_Validate"));
			return;
		}
		P_THIS->Server_FirstTimeInitialization_Implementation(Z_Param_skeleton_input);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKPhysicsComponent::execFirstTimeInitialization)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skeleton_input);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FirstTimeInitialization(Z_Param_skeleton_input);
		P_NATIVE_END;
	}
	struct DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms
	{
		FName bone_name;
		FTransform override_transform;
		bool enable;
	};
	struct DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms
	{
		USkeletalMeshComponent* skmesh;
		FName BoneName;
		bool IncludeSelf;
	};
	struct DragonIKPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms
	{
		USkeletalMeshComponent* skeleton_input;
	};
	struct DragonIKPhysicsComponent_eventMulticast_Modify_Reset_Bone_Info_Parms
	{
		TArray<FName> bone_list;
	};
	struct DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms
	{
		FHitResult Hit;
		FName Optional_Override_Hit_Bone_Name;
		FVector hit_location;
		FVector hit_impulse_direction;
		FName hit_bone_name;
	};
	struct DragonIKPhysicsComponent_eventMulticast_PerformActiveRagdoll_Parms
	{
		float pelvis_mass_override;
	};
	struct DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms
	{
		bool exit_ragdoll;
	};
	struct DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms
	{
		bool go_ragdoll;
	};
	struct DragonIKPhysicsComponent_eventMulticast_SetInterpolation_Parms
	{
		int32 inter_value;
	};
	struct DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms
	{
		int32 LinearStrength;
		int32 AngularStrength;
		int32 LinearDamp;
		int32 AngularDamp;
	};
	struct DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms
	{
		FName bone_name;
		FTransform override_transform;
		bool enable;
	};
	struct DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms
	{
		USkeletalMeshComponent* skmesh;
		FName BoneName;
		bool IncludeSelf;
	};
	struct DragonIKPhysicsComponent_eventServer_FirstTimeInitialization_Parms
	{
		USkeletalMeshComponent* skeleton_input;
	};
	struct DragonIKPhysicsComponent_eventServer_Modify_Reset_Bone_Info_Parms
	{
		TArray<FName> bone_list;
	};
	struct DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms
	{
		FHitResult Hit;
		FName Optional_Override_Hit_Bone_Name;
		FVector hit_location;
		FVector hit_impulse_direction;
		FName hit_bone_name;
	};
	struct DragonIKPhysicsComponent_eventServer_PerformActiveRagdoll_Parms
	{
		float pelvis_mass_override;
	};
	struct DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms
	{
		bool exit_ragdoll;
	};
	struct DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms
	{
		bool go_ragdoll;
	};
	struct DragonIKPhysicsComponent_eventServer_SetInterpolation_Parms
	{
		int32 inter_value;
	};
	struct DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms
	{
		int32 LinearStrength;
		int32 AngularStrength;
		int32 LinearDamp;
		int32 AngularDamp;
	};
	static FName NAME_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates = FName(TEXT("Multicast_CacheSimulationStates"));
	void UDragonIKPhysicsComponent::Multicast_CacheSimulationStates()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates),NULL);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle = FName(TEXT("Multicast_Control_Bone_Handle"));
	void UDragonIKPhysicsComponent::Multicast_Control_Bone_Handle(FName bone_name, FTransform override_transform, bool enable)
	{
		DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms Parms;
		Parms.bone_name=bone_name;
		Parms.override_transform=override_transform;
		Parms.enable=enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics = FName(TEXT("Multicast_DragonIKSimulatePhysics"));
	void UDragonIKPhysicsComponent::Multicast_DragonIKSimulatePhysics(USkeletalMeshComponent* skmesh, FName BoneName, bool IncludeSelf)
	{
		DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms Parms;
		Parms.skmesh=skmesh;
		Parms.BoneName=BoneName;
		Parms.IncludeSelf=IncludeSelf ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization = FName(TEXT("Multicast_FirstTimeInitialization"));
	void UDragonIKPhysicsComponent::Multicast_FirstTimeInitialization(USkeletalMeshComponent* skeleton_input)
	{
		DragonIKPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms Parms;
		Parms.skeleton_input=skeleton_input;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info = FName(TEXT("Multicast_Modify_Reset_Bone_Info"));
	void UDragonIKPhysicsComponent::Multicast_Modify_Reset_Bone_Info(TArray<FName> const& bone_list)
	{
		DragonIKPhysicsComponent_eventMulticast_Modify_Reset_Bone_Info_Parms Parms;
		Parms.bone_list=bone_list;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_OnHitCallback = FName(TEXT("Multicast_OnHitCallback"));
	void UDragonIKPhysicsComponent::Multicast_OnHitCallback(FHitResult const& Hit, const FName Optional_Override_Hit_Bone_Name, FVector const& hit_location, FVector const& hit_impulse_direction, FName const& hit_bone_name)
	{
		DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms Parms;
		Parms.Hit=Hit;
		Parms.Optional_Override_Hit_Bone_Name=Optional_Override_Hit_Bone_Name;
		Parms.hit_location=hit_location;
		Parms.hit_impulse_direction=hit_impulse_direction;
		Parms.hit_bone_name=hit_bone_name;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_OnHitCallback),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll = FName(TEXT("Multicast_PerformActiveRagdoll"));
	void UDragonIKPhysicsComponent::Multicast_PerformActiveRagdoll(float pelvis_mass_override)
	{
		DragonIKPhysicsComponent_eventMulticast_PerformActiveRagdoll_Parms Parms;
		Parms.pelvis_mass_override=pelvis_mass_override;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles = FName(TEXT("Multicast_ReGrabAllHandles"));
	void UDragonIKPhysicsComponent::Multicast_ReGrabAllHandles(bool exit_ragdoll)
	{
		DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms Parms;
		Parms.exit_ragdoll=exit_ragdoll ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles = FName(TEXT("Multicast_ReleaseAllHandles"));
	void UDragonIKPhysicsComponent::Multicast_ReleaseAllHandles(bool go_ragdoll)
	{
		DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms Parms;
		Parms.go_ragdoll=go_ragdoll ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_SetInterpolation = FName(TEXT("Multicast_SetInterpolation"));
	void UDragonIKPhysicsComponent::Multicast_SetInterpolation(int32 inter_value)
	{
		DragonIKPhysicsComponent_eventMulticast_SetInterpolation_Parms Parms;
		Parms.inter_value=inter_value;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_SetInterpolation),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData = FName(TEXT("Multicast_UpdatePhysanimData"));
	void UDragonIKPhysicsComponent::Multicast_UpdatePhysanimData(int32 LinearStrength, int32 AngularStrength, int32 LinearDamp, int32 AngularDamp)
	{
		DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms Parms;
		Parms.LinearStrength=LinearStrength;
		Parms.AngularStrength=AngularStrength;
		Parms.LinearDamp=LinearDamp;
		Parms.AngularDamp=AngularDamp;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_CacheSimulationStates = FName(TEXT("Server_CacheSimulationStates"));
	void UDragonIKPhysicsComponent::Server_CacheSimulationStates()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_CacheSimulationStates),NULL);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_Control_Bone_Handle = FName(TEXT("Server_Control_Bone_Handle"));
	void UDragonIKPhysicsComponent::Server_Control_Bone_Handle(FName bone_name, FTransform override_transform, bool enable)
	{
		DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms Parms;
		Parms.bone_name=bone_name;
		Parms.override_transform=override_transform;
		Parms.enable=enable ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_Control_Bone_Handle),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics = FName(TEXT("Server_DragonIKSimulatePhysics"));
	void UDragonIKPhysicsComponent::Server_DragonIKSimulatePhysics(USkeletalMeshComponent* skmesh, FName BoneName, bool IncludeSelf)
	{
		DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms Parms;
		Parms.skmesh=skmesh;
		Parms.BoneName=BoneName;
		Parms.IncludeSelf=IncludeSelf ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_FirstTimeInitialization = FName(TEXT("Server_FirstTimeInitialization"));
	void UDragonIKPhysicsComponent::Server_FirstTimeInitialization(USkeletalMeshComponent* skeleton_input)
	{
		DragonIKPhysicsComponent_eventServer_FirstTimeInitialization_Parms Parms;
		Parms.skeleton_input=skeleton_input;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_FirstTimeInitialization),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info = FName(TEXT("Server_Modify_Reset_Bone_Info"));
	void UDragonIKPhysicsComponent::Server_Modify_Reset_Bone_Info(TArray<FName> const& bone_list)
	{
		DragonIKPhysicsComponent_eventServer_Modify_Reset_Bone_Info_Parms Parms;
		Parms.bone_list=bone_list;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_OnHitCallback = FName(TEXT("Server_OnHitCallback"));
	void UDragonIKPhysicsComponent::Server_OnHitCallback(FHitResult const& Hit, const FName Optional_Override_Hit_Bone_Name, FVector const& hit_location, FVector const& hit_impulse_direction, FName const& hit_bone_name)
	{
		DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms Parms;
		Parms.Hit=Hit;
		Parms.Optional_Override_Hit_Bone_Name=Optional_Override_Hit_Bone_Name;
		Parms.hit_location=hit_location;
		Parms.hit_impulse_direction=hit_impulse_direction;
		Parms.hit_bone_name=hit_bone_name;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_OnHitCallback),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll = FName(TEXT("Server_PerformActiveRagdoll"));
	void UDragonIKPhysicsComponent::Server_PerformActiveRagdoll(float pelvis_mass_override)
	{
		DragonIKPhysicsComponent_eventServer_PerformActiveRagdoll_Parms Parms;
		Parms.pelvis_mass_override=pelvis_mass_override;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_ReGrabAllHandles = FName(TEXT("Server_ReGrabAllHandles"));
	void UDragonIKPhysicsComponent::Server_ReGrabAllHandles(bool exit_ragdoll)
	{
		DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms Parms;
		Parms.exit_ragdoll=exit_ragdoll ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_ReGrabAllHandles),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_ReleaseAllHandles = FName(TEXT("Server_ReleaseAllHandles"));
	void UDragonIKPhysicsComponent::Server_ReleaseAllHandles(bool go_ragdoll)
	{
		DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms Parms;
		Parms.go_ragdoll=go_ragdoll ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_ReleaseAllHandles),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_SetInterpolation = FName(TEXT("Server_SetInterpolation"));
	void UDragonIKPhysicsComponent::Server_SetInterpolation(int32 inter_value)
	{
		DragonIKPhysicsComponent_eventServer_SetInterpolation_Parms Parms;
		Parms.inter_value=inter_value;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_SetInterpolation),&Parms);
	}
	static FName NAME_UDragonIKPhysicsComponent_Server_UpdatePhysanimData = FName(TEXT("Server_UpdatePhysanimData"));
	void UDragonIKPhysicsComponent::Server_UpdatePhysanimData(int32 LinearStrength, int32 AngularStrength, int32 LinearDamp, int32 AngularDamp)
	{
		DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms Parms;
		Parms.LinearStrength=LinearStrength;
		Parms.AngularStrength=AngularStrength;
		Parms.LinearDamp=LinearDamp;
		Parms.AngularDamp=AngularDamp;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKPhysicsComponent_Server_UpdatePhysanimData),&Parms);
	}
	void UDragonIKPhysicsComponent::StaticRegisterNativesUDragonIKPhysicsComponent()
	{
		UClass* Class = UDragonIKPhysicsComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CacheSimulationStates", &UDragonIKPhysicsComponent::execCacheSimulationStates },
			{ "Control_Bone_Handle", &UDragonIKPhysicsComponent::execControl_Bone_Handle },
			{ "FirstTimeInitialization", &UDragonIKPhysicsComponent::execFirstTimeInitialization },
			{ "Modify_Reset_Bone_Info", &UDragonIKPhysicsComponent::execModify_Reset_Bone_Info },
			{ "Multicast_CacheSimulationStates", &UDragonIKPhysicsComponent::execMulticast_CacheSimulationStates },
			{ "Multicast_Control_Bone_Handle", &UDragonIKPhysicsComponent::execMulticast_Control_Bone_Handle },
			{ "Multicast_DragonIKSimulatePhysics", &UDragonIKPhysicsComponent::execMulticast_DragonIKSimulatePhysics },
			{ "Multicast_FirstTimeInitialization", &UDragonIKPhysicsComponent::execMulticast_FirstTimeInitialization },
			{ "Multicast_Modify_Reset_Bone_Info", &UDragonIKPhysicsComponent::execMulticast_Modify_Reset_Bone_Info },
			{ "Multicast_OnHitCallback", &UDragonIKPhysicsComponent::execMulticast_OnHitCallback },
			{ "Multicast_PerformActiveRagdoll", &UDragonIKPhysicsComponent::execMulticast_PerformActiveRagdoll },
			{ "Multicast_ReGrabAllHandles", &UDragonIKPhysicsComponent::execMulticast_ReGrabAllHandles },
			{ "Multicast_ReleaseAllHandles", &UDragonIKPhysicsComponent::execMulticast_ReleaseAllHandles },
			{ "Multicast_SetInterpolation", &UDragonIKPhysicsComponent::execMulticast_SetInterpolation },
			{ "Multicast_UpdatePhysanimData", &UDragonIKPhysicsComponent::execMulticast_UpdatePhysanimData },
			{ "OnHitCallback", &UDragonIKPhysicsComponent::execOnHitCallback },
			{ "PerformActiveRagdoll", &UDragonIKPhysicsComponent::execPerformActiveRagdoll },
			{ "ReGrabAllHandles", &UDragonIKPhysicsComponent::execReGrabAllHandles },
			{ "ReleaseAllHandles", &UDragonIKPhysicsComponent::execReleaseAllHandles },
			{ "Server_CacheSimulationStates", &UDragonIKPhysicsComponent::execServer_CacheSimulationStates },
			{ "Server_Control_Bone_Handle", &UDragonIKPhysicsComponent::execServer_Control_Bone_Handle },
			{ "Server_DragonIKSimulatePhysics", &UDragonIKPhysicsComponent::execServer_DragonIKSimulatePhysics },
			{ "Server_FirstTimeInitialization", &UDragonIKPhysicsComponent::execServer_FirstTimeInitialization },
			{ "Server_Modify_Reset_Bone_Info", &UDragonIKPhysicsComponent::execServer_Modify_Reset_Bone_Info },
			{ "Server_OnHitCallback", &UDragonIKPhysicsComponent::execServer_OnHitCallback },
			{ "Server_PerformActiveRagdoll", &UDragonIKPhysicsComponent::execServer_PerformActiveRagdoll },
			{ "Server_ReGrabAllHandles", &UDragonIKPhysicsComponent::execServer_ReGrabAllHandles },
			{ "Server_ReleaseAllHandles", &UDragonIKPhysicsComponent::execServer_ReleaseAllHandles },
			{ "Server_SetInterpolation", &UDragonIKPhysicsComponent::execServer_SetInterpolation },
			{ "Server_UpdatePhysanimData", &UDragonIKPhysicsComponent::execServer_UpdatePhysanimData },
			{ "SetInterpolation", &UDragonIKPhysicsComponent::execSetInterpolation },
			{ "UpdatePhysanimData", &UDragonIKPhysicsComponent::execUpdatePhysanimData },
			{ "UpdateSpecificPhysanimData", &UDragonIKPhysicsComponent::execUpdateSpecificPhysanimData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This need to be called after you simualte your physics.\n\x09* This is to cache the details of the bodies that is under physics simulation.\n\x09* This cached data is needed for calculating the auto-blending and auto-toggling of physics simulation.\n\x09*/" },
#endif
		{ "DisplayName", "Cache Simulation State (Call this after simulating physics)" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This need to be called after you simualte your physics.\n* This is to cache the details of the bodies that is under physics simulation.\n* This cached data is needed for calculating the auto-blending and auto-toggling of physics simulation." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "CacheSimulationStates", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics
	{
		struct DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms
		{
			FName bone_name;
			FTransform override_transform;
			bool enable;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_override_transform;
		static void NewProp_enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms, bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_override_transform = { "override_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms, override_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_enable_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms*)Obj)->enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_enable = { "enable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_enable_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_override_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::NewProp_enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Call this to override the transform of an individual physics handle driving a specific bone.\n\x09*/" },
#endif
		{ "DisplayName", "Override Bone Handle Transform" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Call this to override the transform of an individual physics handle driving a specific bone." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Control_Bone_Handle", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::DragonIKPhysicsComponent_eventControl_Bone_Handle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics
	{
		struct DragonIKPhysicsComponent_eventFirstTimeInitialization_Parms
		{
			USkeletalMeshComponent* skeleton_input;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skeleton_input_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_skeleton_input;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventFirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "First Time Initialization" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::DragonIKPhysicsComponent_eventFirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::DragonIKPhysicsComponent_eventFirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics
	{
		struct DragonIKPhysicsComponent_eventModify_Reset_Bone_Info_Parms
		{
			TArray<FName> bone_list;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_list_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_bone_list;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner = { "bone_list", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::NewProp_bone_list = { "bone_list", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventModify_Reset_Bone_Info_Parms, bone_list), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::NewProp_bone_list,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Call this if you want to dynamically alter and reset the core bone inputs anytime during gameplay.\n\x09*/" },
#endif
		{ "DisplayName", "Modify & Reset Bone Settings" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Call this if you want to dynamically alter and reset the core bone inputs anytime during gameplay." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Modify_Reset_Bone_Info", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::DragonIKPhysicsComponent_eventModify_Reset_Bone_Info_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::DragonIKPhysicsComponent_eventModify_Reset_Bone_Info_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_CacheSimulationStates", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_override_transform;
		static void NewProp_enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms, bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_override_transform = { "override_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms, override_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_enable_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms*)Obj)->enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_enable = { "enable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_enable_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_override_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::NewProp_enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_Control_Bone_Handle", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_Control_Bone_Handle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skmesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_skmesh;
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
		static void NewProp_IncludeSelf_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IncludeSelf;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_skmesh = { "skmesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms, skmesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms, BoneName), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms*)Obj)->IncludeSelf = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf = { "IncludeSelf", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_skmesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_BoneName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_DragonIKSimulatePhysics", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_DragonIKSimulatePhysics_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skeleton_input_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_skeleton_input;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_list_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bone_list_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_bone_list;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner = { "bone_list", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list = { "bone_list", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_Modify_Reset_Bone_Info_Parms, bone_list), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::NewProp_bone_list,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_Modify_Reset_Bone_Info", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_Modify_Reset_Bone_Info_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_Modify_Reset_Bone_Info_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Optional_Override_Hit_Bone_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Optional_Override_Hit_Bone_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_impulse_direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_impulse_direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_bone_name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_hit_bone_name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Hit_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Hit_MetaData) }; // 1891709922
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name = { "Optional_Override_Hit_Bone_Name", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms, Optional_Override_Hit_Bone_Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_location = { "hit_location", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms, hit_location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_location_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_location_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_impulse_direction = { "hit_impulse_direction", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms, hit_impulse_direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_bone_name = { "hit_bone_name", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms, hit_bone_name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Hit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_impulse_direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::NewProp_hit_bone_name,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_OnHitCallback", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_OnHitCallback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pelvis_mass_override;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override = { "pelvis_mass_override", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_PerformActiveRagdoll_Parms, pelvis_mass_override), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_PerformActiveRagdoll", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_PerformActiveRagdoll_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_PerformActiveRagdoll_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics
	{
		static void NewProp_exit_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_exit_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms*)Obj)->exit_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::NewProp_exit_ragdoll = { "exit_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::NewProp_exit_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_ReGrabAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_ReGrabAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics
	{
		static void NewProp_go_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_go_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms*)Obj)->go_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::NewProp_go_ragdoll = { "go_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::NewProp_go_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_ReleaseAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_ReleaseAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_inter_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::NewProp_inter_value = { "inter_value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_SetInterpolation_Parms, inter_value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::NewProp_inter_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_SetInterpolation", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_SetInterpolation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_SetInterpolation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearDamp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularDamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_LinearStrength = { "LinearStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms, LinearStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_AngularStrength = { "AngularStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms, AngularStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_LinearDamp = { "LinearDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms, LinearDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_AngularDamp = { "AngularDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms, AngularDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_LinearStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_AngularStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_LinearDamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::NewProp_AngularDamp,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Multicast_UpdatePhysanimData", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventMulticast_UpdatePhysanimData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics
	{
		struct DragonIKPhysicsComponent_eventOnHitCallback_Parms
		{
			FHitResult Hit;
			FName Optional_Override_Hit_Bone_Name;
			FVector hit_location;
			FVector hit_impulse_direction;
			FName hit_bone_name;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UECodeGen_Private::FNamePropertyParams NewProp_Optional_Override_Hit_Bone_Name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_impulse_direction;
		static const UECodeGen_Private::FNamePropertyParams NewProp_hit_bone_name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventOnHitCallback_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Hit_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Hit_MetaData) }; // 1891709922
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name = { "Optional_Override_Hit_Bone_Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventOnHitCallback_Parms, Optional_Override_Hit_Bone_Name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_location = { "hit_location", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventOnHitCallback_Parms, hit_location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_impulse_direction = { "hit_impulse_direction", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventOnHitCallback_Parms, hit_impulse_direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_bone_name = { "hit_bone_name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventOnHitCallback_Parms, hit_bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Hit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_impulse_direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::NewProp_hit_bone_name,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Call this whenever the character detects a hit.\n\x09* It can be called anywhere, typically its called at the end of the onComponentHit or a line trace hits.\n\x09* The optional override hit bone name is only used if the \"Bone Name\" value of the hit struct is an invalid value.This is useful\n\x09* in UE 4.27 because \"Bone Name\" is not editable in the hit struct at the blueprint level. This parameter is ignored otherwise.\n\x09*\n\x09*/" },
#endif
		{ "DisplayName", "DragonIK PhysAnims onHitCallback" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Call this whenever the character detects a hit.\n* It can be called anywhere, typically its called at the end of the onComponentHit or a line trace hits.\n* The optional override hit bone name is only used if the \"Bone Name\" value of the hit struct is an invalid value.This is useful\n* in UE 4.27 because \"Bone Name\" is not editable in the hit struct at the blueprint level. This parameter is ignored otherwise." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "OnHitCallback", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::DragonIKPhysicsComponent_eventOnHitCallback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::DragonIKPhysicsComponent_eventOnHitCallback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics
	{
		struct DragonIKPhysicsComponent_eventPerformActiveRagdoll_Parms
		{
			float pelvis_mass_override;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pelvis_mass_override;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override = { "pelvis_mass_override", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventPerformActiveRagdoll_Parms, pelvis_mass_override), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Character will ragdoll with physical animation attribute by simply calling this function.\n\x09* The pelvis mass override needs to be a high number to ensure the character doesn't slow fall due to the physanim handles from the arms/legs slowing down the pelvis.\n\x09*/" },
#endif
		{ "CPP_Default_pelvis_mass_override", "1000.000000" },
		{ "DisplayName", "Perform Active Ragdoll" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Character will ragdoll with physical animation attribute by simply calling this function.\n* The pelvis mass override needs to be a high number to ensure the character doesn't slow fall due to the physanim handles from the arms/legs slowing down the pelvis." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "PerformActiveRagdoll", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::DragonIKPhysicsComponent_eventPerformActiveRagdoll_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::DragonIKPhysicsComponent_eventPerformActiveRagdoll_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics
	{
		struct DragonIKPhysicsComponent_eventReGrabAllHandles_Parms
		{
			bool exit_ragdoll;
		};
		static void NewProp_exit_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_exit_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventReGrabAllHandles_Parms*)Obj)->exit_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::NewProp_exit_ragdoll = { "exit_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventReGrabAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::NewProp_exit_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is for re-grabbing all the physics handles managed by the physanim component.\n\x09* Only needed to be called if the physanim was ever released.\n\x09* Enable exit ragdoll to true only if you are doing get up animations after a ragdoll. Exit ragdoll parameter can be ignored otherwise.\n\x09*/" },
#endif
		{ "DisplayName", "Re-Grab all handles" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is for re-grabbing all the physics handles managed by the physanim component.\n* Only needed to be called if the physanim was ever released.\n* Enable exit ragdoll to true only if you are doing get up animations after a ragdoll. Exit ragdoll parameter can be ignored otherwise." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "ReGrabAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::DragonIKPhysicsComponent_eventReGrabAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::DragonIKPhysicsComponent_eventReGrabAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics
	{
		struct DragonIKPhysicsComponent_eventReleaseAllHandles_Parms
		{
			bool go_ragdoll;
		};
		static void NewProp_go_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_go_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventReleaseAllHandles_Parms*)Obj)->go_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::NewProp_go_ragdoll = { "go_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventReleaseAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::NewProp_go_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Call this when you want to turn off physical animations.\n\x09* Enable the go ragdoll parameter if you also want to safely go into ragdoll state.\n\x09*/" },
#endif
		{ "DisplayName", "Release all handles" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Call this when you want to turn off physical animations.\n* Enable the go ragdoll parameter if you also want to safely go into ragdoll state." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "ReleaseAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::DragonIKPhysicsComponent_eventReleaseAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::DragonIKPhysicsComponent_eventReleaseAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Cache Simulation State" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_CacheSimulationStates", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_override_transform;
		static void NewProp_enable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms, bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_override_transform = { "override_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms, override_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_enable_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms*)Obj)->enable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_enable = { "enable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_enable_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_override_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::NewProp_enable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Override Bone Handle Transform" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_Control_Bone_Handle", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84A20C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_Control_Bone_Handle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skmesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_skmesh;
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
		static void NewProp_IncludeSelf_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IncludeSelf;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_skmesh = { "skmesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms, skmesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_skmesh_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms, BoneName), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms*)Obj)->IncludeSelf = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf = { "IncludeSelf", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_skmesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_BoneName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::NewProp_IncludeSelf,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] SetAllBodiesBelowSimulatePhysics" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_DragonIKSimulatePhysics", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_DragonIKSimulatePhysics_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skeleton_input_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_skeleton_input;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_FirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] First Time Initialization" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_FirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_FirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_list_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bone_list_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_bone_list;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner = { "bone_list", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list = { "bone_list", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_Modify_Reset_Bone_Info_Parms, bone_list), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::NewProp_bone_list,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Modify & Reset Bone Settings" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_Modify_Reset_Bone_Info", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_Modify_Reset_Bone_Info_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_Modify_Reset_Bone_Info_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Optional_Override_Hit_Bone_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Optional_Override_Hit_Bone_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_impulse_direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_impulse_direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_bone_name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_hit_bone_name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Hit_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Hit_MetaData) }; // 1891709922
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name = { "Optional_Override_Hit_Bone_Name", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms, Optional_Override_Hit_Bone_Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_location = { "hit_location", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms, hit_location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_location_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_location_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_impulse_direction = { "hit_impulse_direction", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms, hit_impulse_direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_impulse_direction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_bone_name = { "hit_bone_name", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms, hit_bone_name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_bone_name_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Hit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_Optional_Override_Hit_Bone_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_impulse_direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::NewProp_hit_bone_name,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "-z[Server] DragonIK PhysAnims onHitCallback" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_OnHitCallback", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_OnHitCallback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pelvis_mass_override;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override = { "pelvis_mass_override", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_PerformActiveRagdoll_Parms, pelvis_mass_override), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::NewProp_pelvis_mass_override,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "CPP_Default_pelvis_mass_override", "1000.000000" },
		{ "DisplayName", "z[Server] Perform Active Ragdoll" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_PerformActiveRagdoll", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_PerformActiveRagdoll_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_PerformActiveRagdoll_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics
	{
		static void NewProp_exit_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_exit_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms*)Obj)->exit_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::NewProp_exit_ragdoll = { "exit_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::NewProp_exit_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::NewProp_exit_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Re-Grab all handles" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_ReGrabAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_ReGrabAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics
	{
		static void NewProp_go_ragdoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_go_ragdoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit(void* Obj)
	{
		((DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms*)Obj)->go_ragdoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::NewProp_go_ragdoll = { "go_ragdoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms), &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::NewProp_go_ragdoll_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::NewProp_go_ragdoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Release all handles" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_ReleaseAllHandles", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_ReleaseAllHandles_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_inter_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::NewProp_inter_value = { "inter_value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_SetInterpolation_Parms, inter_value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::NewProp_inter_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Set Interpolation" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_SetInterpolation", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_SetInterpolation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_SetInterpolation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearDamp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularDamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_LinearStrength = { "LinearStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms, LinearStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_AngularStrength = { "AngularStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms, AngularStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_LinearDamp = { "LinearDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms, LinearDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_AngularDamp = { "AngularDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms, AngularDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_LinearStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_AngularStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_LinearDamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::NewProp_AngularDamp,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Update Physanim Data" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "Server_UpdatePhysanimData", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::PropPointers), sizeof(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKPhysicsComponent_eventServer_UpdatePhysanimData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics
	{
		struct DragonIKPhysicsComponent_eventSetInterpolation_Parms
		{
			int32 inter_value;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_inter_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::NewProp_inter_value = { "inter_value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventSetInterpolation_Parms, inter_value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::NewProp_inter_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Set Interpolation" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "SetInterpolation", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::DragonIKPhysicsComponent_eventSetInterpolation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::DragonIKPhysicsComponent_eventSetInterpolation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics
	{
		struct DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms
		{
			int32 LinearStrength;
			int32 AngularStrength;
			int32 LinearDamp;
			int32 AngularDamp;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularStrength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LinearDamp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AngularDamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_LinearStrength = { "LinearStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms, LinearStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_AngularStrength = { "AngularStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms, AngularStrength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_LinearDamp = { "LinearDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms, LinearDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_AngularDamp = { "AngularDamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms, AngularDamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_LinearStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_AngularStrength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_LinearDamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::NewProp_AngularDamp,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Call this to safely alter the linear strength,angular strength and damping of the physanim.\n\x09*/" },
#endif
		{ "DisplayName", "Update Overall Physanim Data" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Call this to safely alter the linear strength,angular strength and damping of the physanim." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "UpdatePhysanimData", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::DragonIKPhysicsComponent_eventUpdatePhysanimData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics
	{
		struct DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms
		{
			FName BoneName;
			int32 linear_strength_var;
			int32 angular_strength_var;
			int32 linear_damp_var;
			int32 angular_damp_var;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_linear_strength_var;
		static const UECodeGen_Private::FIntPropertyParams NewProp_angular_strength_var;
		static const UECodeGen_Private::FIntPropertyParams NewProp_linear_damp_var;
		static const UECodeGen_Private::FIntPropertyParams NewProp_angular_damp_var;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms, BoneName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_linear_strength_var = { "linear_strength_var", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms, linear_strength_var), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_angular_strength_var = { "angular_strength_var", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms, angular_strength_var), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_linear_damp_var = { "linear_damp_var", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms, linear_damp_var), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_angular_damp_var = { "angular_damp_var", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms, angular_damp_var), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_BoneName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_linear_strength_var,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_angular_strength_var,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_linear_damp_var,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::NewProp_angular_damp_var,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Update Singular Physanim Data" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKPhysicsComponent, nullptr, "UpdateSpecificPhysanimData", nullptr, nullptr, Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::DragonIKPhysicsComponent_eventUpdateSpecificPhysanimData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDragonIKPhysicsComponent);
	UClass* Z_Construct_UClass_UDragonIKPhysicsComponent_NoRegister()
	{
		return UDragonIKPhysicsComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDragonIKPhysicsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_handler_holder_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_handler_holder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_physanim_tag_index_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_physanim_tag_index;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Custom_Root_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Custom_Root_Bone;
		static const UECodeGen_Private::FNamePropertyParams NewProp_individual_bone_selection_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_individual_bone_selection_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_individual_bone_selection;
		static const UECodeGen_Private::FNamePropertyParams NewProp_Influence_Stopping_Bones_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Influence_Stopping_Bones_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Influence_Stopping_Bones;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Override_Handle_Strength_Multiplier_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Override_Handle_Strength_Multiplier_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Override_Handle_Strength_Multiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Linear_Strength_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Linear_Strength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Angular_Strength_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Angular_Strength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Linear_Damp_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Linear_Damp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Angular_Damp_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Angular_Damp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interpolation_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Interpolation_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Teleport_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Teleport_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_parent_child_ragdoll_state_MetaData[];
#endif
		static void NewProp_parent_child_ragdoll_state_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_parent_child_ragdoll_state;
		static const UECodeGen_Private::FNamePropertyParams NewProp_Parent_Child_Connection_Array_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_Parent_Child_Connection_Array_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Parent_Child_Connection_Array_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Parent_Child_Connection_Array;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_use_auto_blending_logic_MetaData[];
#endif
		static void NewProp_use_auto_blending_logic_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_auto_blending_logic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Autoblendalpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Autoblendalpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_modify_physics_states_MetaData[];
#endif
		static void NewProp_modify_physics_states_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_modify_physics_states;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_Enable_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Hit_Enable_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_Disable_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Hit_Disable_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hit_delay_time_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_hit_delay_time;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Physanim_Enter_Curve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Physanim_Enter_Curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_blend_to_zero_MetaData[];
#endif
		static void NewProp_blend_to_zero_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_blend_to_zero;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_CacheSimulationStates, "CacheSimulationStates" }, // 4155076275
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Control_Bone_Handle, "Control_Bone_Handle" }, // 1461211168
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_FirstTimeInitialization, "FirstTimeInitialization" }, // 22521109
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Modify_Reset_Bone_Info, "Modify_Reset_Bone_Info" }, // 3555776985
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_CacheSimulationStates, "Multicast_CacheSimulationStates" }, // 2625543485
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Control_Bone_Handle, "Multicast_Control_Bone_Handle" }, // 1585603262
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_DragonIKSimulatePhysics, "Multicast_DragonIKSimulatePhysics" }, // 2557763902
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_FirstTimeInitialization, "Multicast_FirstTimeInitialization" }, // 2214311998
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_Modify_Reset_Bone_Info, "Multicast_Modify_Reset_Bone_Info" }, // 2092388711
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_OnHitCallback, "Multicast_OnHitCallback" }, // 724511585
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_PerformActiveRagdoll, "Multicast_PerformActiveRagdoll" }, // 293180953
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReGrabAllHandles, "Multicast_ReGrabAllHandles" }, // 522161141
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_ReleaseAllHandles, "Multicast_ReleaseAllHandles" }, // 4035146020
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_SetInterpolation, "Multicast_SetInterpolation" }, // 1057432398
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Multicast_UpdatePhysanimData, "Multicast_UpdatePhysanimData" }, // 3496026996
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_OnHitCallback, "OnHitCallback" }, // 4133730102
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_PerformActiveRagdoll, "PerformActiveRagdoll" }, // 2731678839
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_ReGrabAllHandles, "ReGrabAllHandles" }, // 3136864141
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_ReleaseAllHandles, "ReleaseAllHandles" }, // 3222418615
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_CacheSimulationStates, "Server_CacheSimulationStates" }, // 4233768103
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Control_Bone_Handle, "Server_Control_Bone_Handle" }, // 3185782059
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_DragonIKSimulatePhysics, "Server_DragonIKSimulatePhysics" }, // 2366852184
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_FirstTimeInitialization, "Server_FirstTimeInitialization" }, // 1912906430
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_Modify_Reset_Bone_Info, "Server_Modify_Reset_Bone_Info" }, // 1887828672
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_OnHitCallback, "Server_OnHitCallback" }, // 1644425329
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_PerformActiveRagdoll, "Server_PerformActiveRagdoll" }, // 3258047933
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReGrabAllHandles, "Server_ReGrabAllHandles" }, // 1778864028
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_ReleaseAllHandles, "Server_ReleaseAllHandles" }, // 3127459907
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_SetInterpolation, "Server_SetInterpolation" }, // 591322329
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_Server_UpdatePhysanimData, "Server_UpdatePhysanimData" }, // 834250028
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_SetInterpolation, "SetInterpolation" }, // 1317793420
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdatePhysanimData, "UpdatePhysanimData" }, // 2475640043
		{ &Z_Construct_UFunction_UDragonIKPhysicsComponent_UpdateSpecificPhysanimData, "UpdateSpecificPhysanimData" }, // 1971179687
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DragonIK" },
		{ "DisplayName", "Dragonik Physanim Component" },
		{ "IncludePath", "DragonIKPhysicsComponent.h" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_handler_holder_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Physanim Handle Holder Reference" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_handler_holder = { "handler_holder", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, handler_holder), Z_Construct_UClass_ADragonIKPhysicsHolder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_handler_holder_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_handler_holder_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Make sure this tag is of the same value as the tag value in the physanim info relayer.\n\x09* This tag info is used to help make the physanim relayer determine the correct component to relay the animation data into.\n\x09*/" },
#endif
		{ "DisplayName", "Physanim component tag" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Make sure this tag is of the same value as the tag value in the physanim info relayer.\n* This tag info is used to help make the physanim relayer determine the correct component to relay the animation data into." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_physanim_tag_index = { "physanim_tag_index", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, physanim_tag_index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Custom_Root_Bone_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the common parent physics body/bone that holds all other physics bodies together.\n\x09* This is typically the \"pelvis\" body when it comes to humans. Same goes for most animals.\n\x09*/" },
#endif
		{ "DisplayName", "Common Root Physics Bone (Eg:- Pelvis bone for Mannequin)" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the common parent physics body/bone that holds all other physics bodies together.\n* This is typically the \"pelvis\" body when it comes to humans. Same goes for most animals." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Custom_Root_Bone = { "Custom_Root_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Custom_Root_Bone), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Custom_Root_Bone_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Custom_Root_Bone_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection_Inner = { "individual_bone_selection", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* - This is the most important input. All the bones typed here will have physical animation working.\n\x09* - For best performance, only the core bones of a character needed physical animation influence.\n\x09* - These core bones could be the tips of the limb bones such as the hands,head,legs,tails etc along with the bones that holds other limbs together\n\x09* such as pelvis,chest etc.\n\x09*/" },
#endif
		{ "DisplayName", "Individual Bone Selection" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* - This is the most important input. All the bones typed here will have physical animation working.\n* - For best performance, only the core bones of a character needed physical animation influence.\n* - These core bones could be the tips of the limb bones such as the hands,head,legs,tails etc along with the bones that holds other limbs together\n* such as pelvis,chest etc." },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection = { "individual_bone_selection", nullptr, (EPropertyFlags)0x0010000000000021, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, individual_bone_selection), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones_Inner = { "Influence_Stopping_Bones", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is an optional bone input.\n\x09* When the body of a character faces collision, then physical animation is usually enabled for the entire body during those collisions.\n\x09* This input lets the character only use physical animation for a limited chain of bones, a chain stopped by any of the influence stopping bones.\n\x09* Eg:- If you use spine_03 here, and when the mannequin touches an object using the hands, then physics and physical animation is only influenced for all the bones between the hand bone and the spine_03 bone.\n\x09*/" },
#endif
		{ "DisplayName", "Influence Stopping Bones" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is an optional bone input.\n* When the body of a character faces collision, then physical animation is usually enabled for the entire body during those collisions.\n* This input lets the character only use physical animation for a limited chain of bones, a chain stopped by any of the influence stopping bones.\n* Eg:- If you use spine_03 here, and when the mannequin touches an object using the hands, then physics and physical animation is only influenced for all the bones between the hand bone and the spine_03 bone." },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones = { "Influence_Stopping_Bones", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Influence_Stopping_Bones), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier_Inner = { "Override_Handle_Strength_Multiplier", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier, METADATA_PARAMS(0, nullptr) }; // 1488502214
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is an optional input.\n\x09* If any body parts need stronger or weaker physical animation compared to the rest of the body, you can list them here.\n\x09* The bone strength value proportionaly multiplies the linear strength and angular strength of that particular body.\n\x09*/" },
#endif
		{ "DisplayName", "Override Handle Strength Multiplier (Per bone)" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is an optional input.\n* If any body parts need stronger or weaker physical animation compared to the rest of the body, you can list them here.\n* The bone strength value proportionaly multiplies the linear strength and angular strength of that particular body." },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier = { "Override_Handle_Strength_Multiplier", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Override_Handle_Strength_Multiplier), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier_MetaData) }; // 1488502214
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This value will only be affected after the first initialization or after each new \"grab\".\n\x09*/" },
#endif
		{ "DisplayName", "Linear Strength" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Strength = { "Linear_Strength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Linear_Strength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Angular Strength" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Strength = { "Angular_Strength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Angular_Strength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Linear Damp" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Damp = { "Linear_Damp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Linear_Damp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Angular Damp" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Damp = { "Angular_Damp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Angular_Damp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Interpolation Speed" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Interpolation_Speed = { "Interpolation_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Interpolation_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If the distance between the current character position and character position in previous frame is beyond this distance, then temporarily teleport and reset the physics state along with the character.\n\x09 */" },
#endif
		{ "DisplayName", "Teleport Distance" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If the distance between the current character position and character position in previous frame is beyond this distance, then temporarily teleport and reset the physics state along with the character." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Teleport_Distance = { "Teleport_Distance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Teleport_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state_MetaData[] = {
		{ "Category", "ParentChildCustomLinking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is a special optional additional feature.\n\x09* You can make one physics body get affected by the positional/rotational change of another physics body. Such as a parent child relationship.\n\x09*/" },
#endif
		{ "DisplayName", "(optional) Use custom Parent-Child body mapping ?" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is a special optional additional feature.\n* You can make one physics body get affected by the positional/rotational change of another physics body. Such as a parent child relationship." },
#endif
	};
#endif
	void Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state_SetBit(void* Obj)
	{
		((UDragonIKPhysicsComponent*)Obj)->parent_child_ragdoll_state = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state = { "parent_child_ragdoll_state", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKPhysicsComponent), &Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_ValueProp = { "Parent_Child_Connection_Array", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_Key_KeyProp = { "Parent_Child_Connection_Array_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_MetaData[] = {
		{ "Category", "ParentChildCustomLinking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Set the child-parent relationship between physics bodies here.\n\x09* Eg:- If you set the child as the head bone and the parent as the spine_03 bone in the mannequin, then any pushback of the spine_03 body will proportionally\n\x09* alter the transforms of the head bone.\n\x09*/" },
#endif
		{ "DisplayName", "(optional) Child-Parent physics relationship" },
		{ "EditCondition", "parent_child_ragdoll_state" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Set the child-parent relationship between physics bodies here.\n* Eg:- If you set the child as the head bone and the parent as the spine_03 bone in the mannequin, then any pushback of the spine_03 body will proportionally\n* alter the transforms of the head bone." },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array = { "Parent_Child_Connection_Array", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Parent_Child_Connection_Array), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Let the component auto handle the physics blending whether the body is in a hit state or an non-hit state.\n\x09*/" },
#endif
		{ "DisplayName", "Use Auto Blending and Hit Logic ?" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Let the component auto handle the physics blending whether the body is in a hit state or an non-hit state." },
#endif
	};
#endif
	void Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic_SetBit(void* Obj)
	{
		((UDragonIKPhysicsComponent*)Obj)->use_auto_blending_logic = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic = { "use_auto_blending_logic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKPhysicsComponent), &Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Autoblendalpha_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* You can optionally modify this during runtime \n\x09* This is an alpha value that multiplies with the physics blending alpha during the auto blending logic\n\x09* Ignored when in ragdoll or active-ragdoll mode\n\x09*/" },
#endif
		{ "DisplayName", "Auto blend alpha multiplier" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "You can optionally modify this during runtime\n      * This is an alpha value that multiplies with the physics blending alpha during the auto blending logic\n      * Ignored when in ragdoll or active-ragdoll mode" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Autoblendalpha = { "Autoblendalpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Autoblendalpha), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Autoblendalpha_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Autoblendalpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* An additional optional function that works in tandem with the auto blending logic\n\x09* Let the component also turn off/on physics simulation whenever it is not hitting any physics object.\n\x09* This will preserve performance, but can make physics turned off all the time if the onHit() doesnt register any hits from the mesh.\n\x09*/" },
#endif
		{ "DisplayName", "Modify physics simulation during gameplay for saving performance ?" },
		{ "EditCondition", "use_auto_blending_logic" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* An additional optional function that works in tandem with the auto blending logic\n* Let the component also turn off/on physics simulation whenever it is not hitting any physics object.\n* This will preserve performance, but can make physics turned off all the time if the onHit() doesnt register any hits from the mesh." },
#endif
	};
#endif
	void Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states_SetBit(void* Obj)
	{
		((UDragonIKPhysicsComponent*)Obj)->modify_physics_states = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states = { "modify_physics_states", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKPhysicsComponent), &Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Enable_Speed_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
		{ "DisplayName", "Hit Enable Speed" },
		{ "EditCondition", "use_auto_blending_logic" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Enable_Speed = { "Hit_Enable_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Hit_Enable_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Enable_Speed_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Enable_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Disable_Speed_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
		{ "DisplayName", "Hit Disable Speed" },
		{ "EditCondition", "use_auto_blending_logic" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Disable_Speed = { "Hit_Disable_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Hit_Disable_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Disable_Speed_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Disable_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_hit_delay_time_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* After a collision, how long should physical animation persist until it goes back to the animated state ? \n\x09*/" },
#endif
		{ "DisplayName", "Delay in secs until blending starts going down ?" },
		{ "EditCondition", "use_auto_blending_logic" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* After a collision, how long should physical animation persist until it goes back to the animated state ?" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_hit_delay_time = { "hit_delay_time", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, hit_delay_time), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_hit_delay_time_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_hit_delay_time_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Physanim_Enter_Curve_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This is the physics body alpha over time whenever the character tries to transition from ragdoll to physanim animations.\n\x09* Useful for getup animations.\n\x09*/" },
#endif
		{ "DisplayName", "Ragdoll to Physanim alpha blend curve over time" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is the physics body alpha over time whenever the character tries to transition from ragdoll to physanim animations.\n* Useful for getup animations." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Physanim_Enter_Curve = { "Physanim_Enter_Curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKPhysicsComponent, Physanim_Enter_Curve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Physanim_Enter_Curve_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Physanim_Enter_Curve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero_MetaData[] = {
		{ "Category", "AlphaAndPhysicsManagement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This can be ticked to on/off depending on whether partial blending of a physics body leads to strange results.\n\x09* This input was made because of one particular instance where a character's head and hands were flying so far out of it's position whenever it reacts to a hit, while using a strict influence stopping bones input\n\x09* Blending to absolute zero can have some minor performance boost compared to blending to a value near zero.\n\x09* But you will likely not feel any difference at all for most types of rigs. Only toggle this if you feel something is obviously off!\n\x09*/" },
#endif
		{ "DisplayName", "Allow physics auto blend to reach absolute zero value ?" },
		{ "ModuleRelativePath", "Public/DragonIKPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This can be ticked to on/off depending on whether partial blending of a physics body leads to strange results.\n* This input was made because of one particular instance where a character's head and hands were flying so far out of it's position whenever it reacts to a hit, while using a strict influence stopping bones input\n* Blending to absolute zero can have some minor performance boost compared to blending to a value near zero.\n* But you will likely not feel any difference at all for most types of rigs. Only toggle this if you feel something is obviously off!" },
#endif
	};
#endif
	void Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero_SetBit(void* Obj)
	{
		((UDragonIKPhysicsComponent*)Obj)->blend_to_zero = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero = { "blend_to_zero", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKPhysicsComponent), &Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero_MetaData), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_handler_holder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_physanim_tag_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Custom_Root_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_individual_bone_selection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Influence_Stopping_Bones,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Override_Handle_Strength_Multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Linear_Damp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Angular_Damp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Interpolation_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Teleport_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_parent_child_ragdoll_state,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Parent_Child_Connection_Array,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_use_auto_blending_logic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Autoblendalpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_modify_physics_states,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Enable_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Hit_Disable_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_hit_delay_time,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_Physanim_Enter_Curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::NewProp_blend_to_zero,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDragonIKPhysicsComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::ClassParams = {
		&UDragonIKPhysicsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDragonIKPhysicsComponent()
	{
		if (!Z_Registration_Info_UClass_UDragonIKPhysicsComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDragonIKPhysicsComponent.OuterSingleton, Z_Construct_UClass_UDragonIKPhysicsComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDragonIKPhysicsComponent.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UClass* StaticClass<UDragonIKPhysicsComponent>()
	{
		return UDragonIKPhysicsComponent::StaticClass();
	}

	void UDragonIKPhysicsComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_handler_holder(TEXT("handler_holder"));
		static const FName Name_individual_bone_selection(TEXT("individual_bone_selection"));

		const bool bIsValid = true
			&& Name_handler_holder == ClassReps[(int32)ENetFields_Private::handler_holder].Property->GetFName()
			&& Name_individual_bone_selection == ClassReps[(int32)ENetFields_Private::individual_bone_selection].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UDragonIKPhysicsComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDragonIKPhysicsComponent);
	UDragonIKPhysicsComponent::~UDragonIKPhysicsComponent() {}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ScriptStructInfo[] = {
		{ FDragonData_PhysicsParentRelationship::StaticStruct, Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics::NewStructOps, TEXT("DragonData_PhysicsParentRelationship"), &Z_Registration_Info_UScriptStruct_DragonData_PhysicsParentRelationship, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonData_PhysicsParentRelationship), 2026152435U) },
		{ FDragonData_PhysicsHandleMultiplier::StaticStruct, Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics::NewStructOps, TEXT("DragonData_PhysicsHandleMultiplier"), &Z_Registration_Info_UScriptStruct_DragonData_PhysicsHandleMultiplier, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDragonData_PhysicsHandleMultiplier), 1488502214U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDragonIKPhysicsComponent, UDragonIKPhysicsComponent::StaticClass, TEXT("UDragonIKPhysicsComponent"), &Z_Registration_Info_UClass_UDragonIKPhysicsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDragonIKPhysicsComponent), 1206523301U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_1528141036(TEXT("/Script/DragonIKPlugin"),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
