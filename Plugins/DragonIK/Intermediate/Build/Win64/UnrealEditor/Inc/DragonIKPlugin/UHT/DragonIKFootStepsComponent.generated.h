// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DragonIKFootStepsComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
#ifdef DRAGONIKPLUGIN_DragonIKFootStepsComponent_generated_h
#error "DragonIKFootStepsComponent.generated.h already included, missing '#pragma once' in DragonIKFootStepsComponent.h"
#endif
#define DRAGONIKPLUGIN_DragonIKFootStepsComponent_generated_h

#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_16_DELEGATE \
DRAGONIKPLUGIN_API void FCharacterFootStep_DelegateWrapper(const FMulticastScriptDelegate& CharacterFootStep, FName bone_name, FTransform foot_transform, float height_difference, FHitResult hit_info);


#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_SPARSE_DATA
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_ACCESSORS
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_CALLBACK_WRAPPERS
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDragonIKFootStepsComponent(); \
	friend struct Z_Construct_UClass_UDragonIKFootStepsComponent_Statics; \
public: \
	DECLARE_CLASS(UDragonIKFootStepsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DragonIKPlugin"), NO_API) \
	DECLARE_SERIALIZER(UDragonIKFootStepsComponent)


#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDragonIKFootStepsComponent(UDragonIKFootStepsComponent&&); \
	NO_API UDragonIKFootStepsComponent(const UDragonIKFootStepsComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDragonIKFootStepsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDragonIKFootStepsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDragonIKFootStepsComponent) \
	NO_API virtual ~UDragonIKFootStepsComponent();


#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_19_PROLOG
#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_SPARSE_DATA \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_ACCESSORS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_CALLBACK_WRAPPERS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_INCLASS_NO_PURE_DECLS \
	FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DRAGONIKPLUGIN_API UClass* StaticClass<class UDragonIKFootStepsComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKFootStepsComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
