// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DragonIKPhysicsComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USkeletalMeshComponent;
struct FHitResult;
#ifdef DRAGONIKPLUGIN_DragonIKPhysicsComponent_generated_h
#error "DragonIKPhysicsComponent.generated.h already included, missing '#pragma once' in DragonIKPhysicsComponent.h"
#endif
#define DRAGONIKPLUGIN_DragonIKPhysicsComponent_generated_h

#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDragonData_PhysicsParentRelationship_Statics; \
	DRAGONIKPLUGIN_API static class UScriptStruct* StaticStruct();


template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<struct FDragonData_PhysicsParentRelationship>();

#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_48_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDragonData_PhysicsHandleMultiplier_Statics; \
	DRAGONIKPLUGIN_API static class UScriptStruct* StaticStruct();


template<> DRAGONIKPLUGIN_API UScriptStruct* StaticStruct<struct FDragonData_PhysicsHandleMultiplier>();

#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_SPARSE_DATA
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool Multicast_PerformActiveRagdoll_Validate(float ); \
	virtual void Multicast_PerformActiveRagdoll_Implementation(float pelvis_mass_override); \
	virtual bool Server_PerformActiveRagdoll_Validate(float ); \
	virtual void Server_PerformActiveRagdoll_Implementation(float pelvis_mass_override); \
	virtual bool Multicast_Modify_Reset_Bone_Info_Validate(TArray<FName> const& ); \
	virtual void Multicast_Modify_Reset_Bone_Info_Implementation(TArray<FName> const& bone_list); \
	virtual bool Server_Modify_Reset_Bone_Info_Validate(TArray<FName> const& ); \
	virtual void Server_Modify_Reset_Bone_Info_Implementation(TArray<FName> const& bone_list); \
	virtual bool Multicast_Control_Bone_Handle_Validate(FName , FTransform , bool ); \
	virtual void Multicast_Control_Bone_Handle_Implementation(FName bone_name, FTransform override_transform, bool enable); \
	virtual bool Server_Control_Bone_Handle_Validate(FName , FTransform , bool ); \
	virtual void Server_Control_Bone_Handle_Implementation(FName bone_name, FTransform override_transform, bool enable); \
	virtual bool Multicast_SetInterpolation_Validate(int32 ); \
	virtual void Multicast_SetInterpolation_Implementation(int32 inter_value); \
	virtual bool Server_SetInterpolation_Validate(int32 ); \
	virtual void Server_SetInterpolation_Implementation(int32 inter_value); \
	virtual bool Multicast_UpdatePhysanimData_Validate(int32 , int32 , int32 , int32 ); \
	virtual void Multicast_UpdatePhysanimData_Implementation(int32 LinearStrength, int32 AngularStrength, int32 LinearDamp, int32 AngularDamp); \
	virtual bool Server_UpdatePhysanimData_Validate(int32 , int32 , int32 , int32 ); \
	virtual void Server_UpdatePhysanimData_Implementation(int32 LinearStrength, int32 AngularStrength, int32 LinearDamp, int32 AngularDamp); \
	virtual bool Multicast_ReleaseAllHandles_Validate(bool ); \
	virtual void Multicast_ReleaseAllHandles_Implementation(bool go_ragdoll); \
	virtual bool Server_ReleaseAllHandles_Validate(bool ); \
	virtual void Server_ReleaseAllHandles_Implementation(bool go_ragdoll); \
	virtual bool Multicast_CacheSimulationStates_Validate(); \
	virtual void Multicast_CacheSimulationStates_Implementation(); \
	virtual bool Server_CacheSimulationStates_Validate(); \
	virtual void Server_CacheSimulationStates_Implementation(); \
	virtual bool Multicast_DragonIKSimulatePhysics_Validate(USkeletalMeshComponent* , FName , bool ); \
	virtual void Multicast_DragonIKSimulatePhysics_Implementation(USkeletalMeshComponent* skmesh, FName BoneName, bool IncludeSelf); \
	virtual bool Server_DragonIKSimulatePhysics_Validate(USkeletalMeshComponent* , FName , bool ); \
	virtual void Server_DragonIKSimulatePhysics_Implementation(USkeletalMeshComponent* skmesh, FName BoneName, bool IncludeSelf); \
	virtual bool Multicast_OnHitCallback_Validate(FHitResult const& , const FName , FVector const& , FVector const& , FName const& ); \
	virtual void Multicast_OnHitCallback_Implementation(FHitResult const& Hit, const FName Optional_Override_Hit_Bone_Name, FVector const& hit_location, FVector const& hit_impulse_direction, FName const& hit_bone_name); \
	virtual bool Server_OnHitCallback_Validate(FHitResult const& , const FName , FVector const& , FVector const& , FName const& ); \
	virtual void Server_OnHitCallback_Implementation(FHitResult const& Hit, const FName Optional_Override_Hit_Bone_Name, FVector const& hit_location, FVector const& hit_impulse_direction, FName const& hit_bone_name); \
	virtual bool Multicast_ReGrabAllHandles_Validate(bool ); \
	virtual void Multicast_ReGrabAllHandles_Implementation(bool exit_ragdoll); \
	virtual bool Server_ReGrabAllHandles_Validate(bool ); \
	virtual void Server_ReGrabAllHandles_Implementation(bool exit_ragdoll); \
	virtual bool Multicast_FirstTimeInitialization_Validate(USkeletalMeshComponent* ); \
	virtual void Multicast_FirstTimeInitialization_Implementation(USkeletalMeshComponent* skeleton_input); \
	virtual bool Server_FirstTimeInitialization_Validate(USkeletalMeshComponent* ); \
	virtual void Server_FirstTimeInitialization_Implementation(USkeletalMeshComponent* skeleton_input); \
 \
	DECLARE_FUNCTION(execMulticast_PerformActiveRagdoll); \
	DECLARE_FUNCTION(execServer_PerformActiveRagdoll); \
	DECLARE_FUNCTION(execPerformActiveRagdoll); \
	DECLARE_FUNCTION(execMulticast_Modify_Reset_Bone_Info); \
	DECLARE_FUNCTION(execServer_Modify_Reset_Bone_Info); \
	DECLARE_FUNCTION(execModify_Reset_Bone_Info); \
	DECLARE_FUNCTION(execMulticast_Control_Bone_Handle); \
	DECLARE_FUNCTION(execServer_Control_Bone_Handle); \
	DECLARE_FUNCTION(execControl_Bone_Handle); \
	DECLARE_FUNCTION(execMulticast_SetInterpolation); \
	DECLARE_FUNCTION(execServer_SetInterpolation); \
	DECLARE_FUNCTION(execSetInterpolation); \
	DECLARE_FUNCTION(execMulticast_UpdatePhysanimData); \
	DECLARE_FUNCTION(execServer_UpdatePhysanimData); \
	DECLARE_FUNCTION(execUpdateSpecificPhysanimData); \
	DECLARE_FUNCTION(execUpdatePhysanimData); \
	DECLARE_FUNCTION(execMulticast_ReleaseAllHandles); \
	DECLARE_FUNCTION(execServer_ReleaseAllHandles); \
	DECLARE_FUNCTION(execReleaseAllHandles); \
	DECLARE_FUNCTION(execMulticast_CacheSimulationStates); \
	DECLARE_FUNCTION(execServer_CacheSimulationStates); \
	DECLARE_FUNCTION(execCacheSimulationStates); \
	DECLARE_FUNCTION(execMulticast_DragonIKSimulatePhysics); \
	DECLARE_FUNCTION(execServer_DragonIKSimulatePhysics); \
	DECLARE_FUNCTION(execMulticast_OnHitCallback); \
	DECLARE_FUNCTION(execServer_OnHitCallback); \
	DECLARE_FUNCTION(execOnHitCallback); \
	DECLARE_FUNCTION(execMulticast_ReGrabAllHandles); \
	DECLARE_FUNCTION(execServer_ReGrabAllHandles); \
	DECLARE_FUNCTION(execReGrabAllHandles); \
	DECLARE_FUNCTION(execMulticast_FirstTimeInitialization); \
	DECLARE_FUNCTION(execServer_FirstTimeInitialization); \
	DECLARE_FUNCTION(execFirstTimeInitialization);


#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_CALLBACK_WRAPPERS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDragonIKPhysicsComponent(); \
	friend struct Z_Construct_UClass_UDragonIKPhysicsComponent_Statics; \
public: \
	DECLARE_CLASS(UDragonIKPhysicsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DragonIKPlugin"), NO_API) \
	DECLARE_SERIALIZER(UDragonIKPhysicsComponent) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		handler_holder=NETFIELD_REP_START, \
		individual_bone_selection, \
		NETFIELD_REP_END=individual_bone_selection	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDragonIKPhysicsComponent(UDragonIKPhysicsComponent&&); \
	NO_API UDragonIKPhysicsComponent(const UDragonIKPhysicsComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDragonIKPhysicsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDragonIKPhysicsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDragonIKPhysicsComponent) \
	NO_API virtual ~UDragonIKPhysicsComponent();


#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_61_PROLOG
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_SPARSE_DATA \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_CALLBACK_WRAPPERS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_INCLASS_NO_PURE_DECLS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h_64_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DRAGONIKPLUGIN_API UClass* StaticClass<class UDragonIKPhysicsComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_DragonIKPlugin_Source_DragonIKPlugin_Public_DragonIKPhysicsComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
