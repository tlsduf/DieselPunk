// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AnimNode_DragonFeetSolver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DRAGONIKPLUGIN_AnimNode_DragonFeetSolver_generated_h
#error "AnimNode_DragonFeetSolver.generated.h already included, missing '#pragma once' in AnimNode_DragonFeetSolver.h"
#endif
#define DRAGONIKPLUGIN_AnimNode_DragonFeetSolver_generated_h

#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h_54_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAnimNode_DragonFeetSolver_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FAnimNode_DragonControlBase Super;


template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<struct FAnimNode_DragonFeetSolver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_AnimNode_DragonFeetSolver_h


#define FOREACH_ENUM_EIK_TYPE_PLUGIN(op) \
	op(EIK_Type_Plugin::ENUM_Two_Bone_Ik) \
	op(EIK_Type_Plugin::ENUM_Single_Bone_Ik) 

enum class EIK_Type_Plugin : uint8;
template<> struct TIsUEnumClass<EIK_Type_Plugin> { enum { Value = true }; };
template<> DRAGONIKPLUGIN_API UEnum* StaticEnum<EIK_Type_Plugin>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
