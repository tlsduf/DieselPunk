// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DragonIKFootStepsComponent.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKFootStepsComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKFootStepsComponent();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKFootStepsComponent_NoRegister();
	DRAGONIKPLUGIN_API UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics
	{
		struct _Script_DragonIKPlugin_eventCharacterFootStep_Parms
		{
			FName bone_name;
			FTransform foot_transform;
			float height_difference;
			FHitResult hit_info;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_foot_transform;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_height_difference;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_info;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DragonIKPlugin_eventCharacterFootStep_Parms, bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_foot_transform = { "foot_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DragonIKPlugin_eventCharacterFootStep_Parms, foot_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_height_difference = { "height_difference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DragonIKPlugin_eventCharacterFootStep_Parms, height_difference), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_hit_info = { "hit_info", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DragonIKPlugin_eventCharacterFootStep_Parms, hit_info), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_foot_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_height_difference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::NewProp_hit_info,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_DragonIKPlugin, nullptr, "CharacterFootStep__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::_Script_DragonIKPlugin_eventCharacterFootStep_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::_Script_DragonIKPlugin_eventCharacterFootStep_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FCharacterFootStep_DelegateWrapper(const FMulticastScriptDelegate& CharacterFootStep, FName bone_name, FTransform foot_transform, float height_difference, FHitResult hit_info)
{
	struct _Script_DragonIKPlugin_eventCharacterFootStep_Parms
	{
		FName bone_name;
		FTransform foot_transform;
		float height_difference;
		FHitResult hit_info;
	};
	_Script_DragonIKPlugin_eventCharacterFootStep_Parms Parms;
	Parms.bone_name=bone_name;
	Parms.foot_transform=foot_transform;
	Parms.height_difference=height_difference;
	Parms.hit_info=hit_info;
	CharacterFootStep.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct DragonIKFootStepsComponent_eventCallFootSteps_Parms
	{
		FName bone_name;
		FTransform foot_transform;
		float height_difference;
		FHitResult hit_info;
	};
	static FName NAME_UDragonIKFootStepsComponent_CallFootSteps = FName(TEXT("CallFootSteps"));
	void UDragonIKFootStepsComponent::CallFootSteps(FName bone_name, FTransform foot_transform, float height_difference, FHitResult hit_info)
	{
		DragonIKFootStepsComponent_eventCallFootSteps_Parms Parms;
		Parms.bone_name=bone_name;
		Parms.foot_transform=foot_transform;
		Parms.height_difference=height_difference;
		Parms.hit_info=hit_info;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKFootStepsComponent_CallFootSteps),&Parms);
	}
	void UDragonIKFootStepsComponent::StaticRegisterNativesUDragonIKFootStepsComponent()
	{
	}
	struct Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_bone_name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_foot_transform;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_height_difference;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hit_info;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_bone_name = { "bone_name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKFootStepsComponent_eventCallFootSteps_Parms, bone_name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_foot_transform = { "foot_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKFootStepsComponent_eventCallFootSteps_Parms, foot_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_height_difference = { "height_difference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKFootStepsComponent_eventCallFootSteps_Parms, height_difference), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_hit_info = { "hit_info", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKFootStepsComponent_eventCallFootSteps_Parms, hit_info), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_bone_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_foot_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_height_difference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::NewProp_hit_info,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKFootStepsComponent, nullptr, "CallFootSteps", nullptr, nullptr, Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::PropPointers), sizeof(DragonIKFootStepsComponent_eventCallFootSteps_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKFootStepsComponent_eventCallFootSteps_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDragonIKFootStepsComponent);
	UClass* Z_Construct_UClass_UDragonIKFootStepsComponent_NoRegister()
	{
		return UDragonIKFootStepsComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDragonIKFootStepsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterFootStep_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterFootStep;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_read_this_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_read_this;
		static const UECodeGen_Private::FNamePropertyParams NewProp_foot_socket_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_foot_socket_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_foot_socket;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_foot_enter_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_foot_enter_height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_foot_exit_height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_foot_exit_height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDragonIKFootStepsComponent_CallFootSteps, "CallFootSteps" }, // 1694316212
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DragonIK" },
		{ "DisplayName", "Dragonik Footsteps Component" },
		{ "IncludePath", "DragonIKFootStepsComponent.h" },
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_OnCharacterFootStep_MetaData[] = {
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_OnCharacterFootStep = { "OnCharacterFootStep", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKFootStepsComponent, OnCharacterFootStep), Z_Construct_UDelegateFunction_DragonIKPlugin_CharacterFootStep__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_OnCharacterFootStep_MetaData), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_OnCharacterFootStep_MetaData) }; // 350745202
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_read_this_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/*\n\x09*\n\x09* This is a brand new mini feature that provides foot steps based on whenever the feets touch the ground. This can be used for foot sounds,VFX etc.\n\x09* IMPORTAINT REQUIREMENT : The dragonik foot solver is needed to be connected and used in your character's animation blueprint. This component recycles the trace information already setup in the foot solver.\n\x09* Enable \"listen for foot steps\" boolean parameter in the dragonik foot solver. That's it! Foot steps callback will start working\n\x09* In this foot steps component, use the \"On Character Foot Step\" callback event for all your foot step needs.\n\x09*/" },
		{ "DisplayName", "HOVER MOUSE HERE FOR TIPS!" },
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* This is a brand new mini feature that provides foot steps based on whenever the feets touch the ground. This can be used for foot sounds,VFX etc.\n* IMPORTAINT REQUIREMENT : The dragonik foot solver is needed to be connected and used in your character's animation blueprint. This component recycles the trace information already setup in the foot solver.\n* Enable \"listen for foot steps\" boolean parameter in the dragonik foot solver. That's it! Foot steps callback will start working\n* In this foot steps component, use the \"On Character Foot Step\" callback event for all your foot step needs." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_read_this = { "read_this", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKFootStepsComponent, read_this), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_read_this_MetaData), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_read_this_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket_Inner = { "foot_socket", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/*\n\x09* Choose the appropriate foot socket/bone names here.\n\x09* Order is important! The order should be in the same order used in the feet array of the foot solver.\n\x09*/" },
		{ "DisplayName", "Foot Socket Array" },
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Choose the appropriate foot socket/bone names here.\n* Order is important! The order should be in the same order used in the feet array of the foot solver." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket = { "foot_socket", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKFootStepsComponent, foot_socket), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket_MetaData), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_enter_height_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/*\n\x09* Foot steps is invoked when the feet bone/socket enters this height in component space.\n\x09*/" },
		{ "DisplayName", "Foot Step Enter Height" },
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Foot steps is invoked when the feet bone/socket enters this height in component space." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_enter_height = { "foot_enter_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKFootStepsComponent, foot_enter_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_enter_height_MetaData), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_enter_height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_exit_height_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/*\n\x09* Foot steps is reseted when the feet bone/socket exits this height in component space. This should always be a higher number than the foot enter height.\n\x09*/" },
		{ "DisplayName", "Foot Step Exit Height" },
		{ "ModuleRelativePath", "Public/DragonIKFootStepsComponent.h" },
		{ "PinHiddenByDefault", "" },
		{ "ToolTip", "* Foot steps is reseted when the feet bone/socket exits this height in component space. This should always be a higher number than the foot enter height." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_exit_height = { "foot_exit_height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKFootStepsComponent, foot_exit_height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_exit_height_MetaData), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_exit_height_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_OnCharacterFootStep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_read_this,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_socket,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_enter_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::NewProp_foot_exit_height,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDragonIKFootStepsComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::ClassParams = {
		&UDragonIKFootStepsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDragonIKFootStepsComponent()
	{
		if (!Z_Registration_Info_UClass_UDragonIKFootStepsComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDragonIKFootStepsComponent.OuterSingleton, Z_Construct_UClass_UDragonIKFootStepsComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDragonIKFootStepsComponent.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UClass* StaticClass<UDragonIKFootStepsComponent>()
	{
		return UDragonIKFootStepsComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDragonIKFootStepsComponent);
	UDragonIKFootStepsComponent::~UDragonIKFootStepsComponent() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDragonIKFootStepsComponent, UDragonIKFootStepsComponent::StaticClass, TEXT("UDragonIKFootStepsComponent"), &Z_Registration_Info_UClass_UDragonIKFootStepsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDragonIKFootStepsComponent), 2087393525U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_2281979049(TEXT("/Script/DragonIKPlugin"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
