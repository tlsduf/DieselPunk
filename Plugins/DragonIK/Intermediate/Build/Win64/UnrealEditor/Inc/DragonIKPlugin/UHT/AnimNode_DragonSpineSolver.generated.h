// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AnimNode_DragonSpineSolver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DRAGONIKPLUGIN_AnimNode_DragonSpineSolver_generated_h
#error "AnimNode_DragonSpineSolver.generated.h already included, missing '#pragma once' in AnimNode_DragonSpineSolver.h"
#endif
#define DRAGONIKPLUGIN_AnimNode_DragonSpineSolver_generated_h

#define FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h_74_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAnimNode_DragonSpineSolver_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FAnimNode_DragonControlBase Super;


template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<struct FAnimNode_DragonSpineSolver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_AnimNode_DragonSpineSolver_h


#define FOREACH_ENUM_EREFPOSEPLUGINENUM(op) \
	op(ERefPosePluginEnum::VE_Animated) \
	op(ERefPosePluginEnum::VE_Rest) 

enum class ERefPosePluginEnum : uint8;
template<> struct TIsUEnumClass<ERefPosePluginEnum> { enum { Value = true }; };
template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<ERefPosePluginEnum>();

#define FOREACH_ENUM_ESOLVERCOMPLEXITYPLUGINENUM(op) \
	op(ESolverComplexityPluginEnum::VE_Simple) \
	op(ESolverComplexityPluginEnum::VE_Complex) 

enum class ESolverComplexityPluginEnum : uint8;
template<> struct TIsUEnumClass<ESolverComplexityPluginEnum> { enum { Value = true }; };
template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<ESolverComplexityPluginEnum>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
