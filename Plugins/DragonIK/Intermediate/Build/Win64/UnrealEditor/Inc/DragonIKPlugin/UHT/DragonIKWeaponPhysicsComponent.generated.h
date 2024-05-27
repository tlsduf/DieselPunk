// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DragonIKWeaponPhysicsComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class USkeletalMeshComponent;
#ifdef DRAGONIKPLUGIN_DragonIKWeaponPhysicsComponent_generated_h
#error "DragonIKWeaponPhysicsComponent.generated.h already included, missing '#pragma once' in DragonIKWeaponPhysicsComponent.h"
#endif
#define DRAGONIKPLUGIN_DragonIKWeaponPhysicsComponent_generated_h

#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_SPARSE_DATA
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool Multicast_Unfreeze_Elbows_Function_Validate(FName ); \
	virtual void Multicast_Unfreeze_Elbows_Function_Implementation(FName hand_bone); \
	virtual bool Server_Unfreeze_Elbows_Function_Validate(FName ); \
	virtual void Server_Unfreeze_Elbows_Function_Implementation(FName hand_bone); \
	virtual bool Multicast_Freeze_Elbows_Function_Validate(FName ); \
	virtual void Multicast_Freeze_Elbows_Function_Implementation(FName hand_bone); \
	virtual bool Server_Freeze_Elbows_Function_Validate(FName ); \
	virtual void Server_Freeze_Elbows_Function_Implementation(FName hand_bone); \
	virtual bool Multicast_Attach_Hand_Only_Validate(FName , bool ); \
	virtual void Multicast_Attach_Hand_Only_Implementation(FName hand_bone, bool arm_position_recalibrate); \
	virtual bool Server_Attach_Hand_Only_Validate(FName , bool ); \
	virtual void Server_Attach_Hand_Only_Implementation(FName hand_bone, bool arm_position_recalibrate); \
	virtual bool Multicast_Weapon_Transform_Override_Validate(FTransform , bool ); \
	virtual void Multicast_Weapon_Transform_Override_Implementation(FTransform Weapon_Transform, bool bShould_Override_Weapon_Transform); \
	virtual bool Server_Weapon_Transform_Override_Validate(FTransform , bool ); \
	virtual void Server_Weapon_Transform_Override_Implementation(FTransform Weapon_Transform, bool bShould_Override_Weapon_Transform); \
	virtual bool Multicast_Release_Hand_Plus_Override_Validate(FName , FTransform , bool , bool ); \
	virtual void Multicast_Release_Hand_Plus_Override_Implementation(FName hand_bone, FTransform hand_transform, bool override_hand_location, bool override_hand_rotation); \
	virtual bool Server_Release_Hand_Plus_Override_Validate(FName , FTransform , bool , bool ); \
	virtual void Server_Release_Hand_Plus_Override_Implementation(FName hand_bone, FTransform hand_transform, bool override_hand_location, bool override_hand_rotation); \
	virtual bool Multicast_Release_Hand_Only_Validate(FName ); \
	virtual void Multicast_Release_Hand_Only_Implementation(FName hand_bone); \
	virtual bool Server_Release_Hand_Only_Validate(FName ); \
	virtual void Server_Release_Hand_Only_Implementation(FName hand_bone); \
	virtual bool Multicast_EnableWeaponsArms_Validate(); \
	virtual void Multicast_EnableWeaponsArms_Implementation(); \
	virtual bool Server_EnableWeaponsArms_Validate(); \
	virtual void Server_EnableWeaponsArms_Implementation(); \
	virtual bool Multicast_DisableWeaponsArms_Validate(bool ); \
	virtual void Multicast_DisableWeaponsArms_Implementation(bool reset_weapon_transform); \
	virtual bool Server_DisableWeaponsArms_Validate(bool ); \
	virtual void Server_DisableWeaponsArms_Implementation(bool reset_weapon_transform); \
	virtual bool Multicast_Release_Weapon_Validate(bool , bool , bool ); \
	virtual void Multicast_Release_Weapon_Implementation(bool should_simulatephysics, bool use_gravity, bool bKeep_Attachment); \
	virtual bool Server_Release_Weapon_Validate(bool , bool , bool ); \
	virtual void Server_Release_Weapon_Implementation(bool should_simulatephysics, bool use_gravity, bool bKeep_Attachment); \
	virtual bool Multicast_Destroy_Weapon_Validate(AActor* ); \
	virtual void Multicast_Destroy_Weapon_Implementation(AActor* weapon); \
	virtual bool Server_Destroy_Weapon_Validate(AActor* ); \
	virtual void Server_Destroy_Weapon_Implementation(AActor* weapon); \
	virtual bool Multicast_Grab_Weapon_Validate(FName , bool , bool , FName ); \
	virtual void Multicast_Grab_Weapon_Implementation(FName grabbed_bone, bool simulate_physics, bool use_gravity, FName WeaponBoneName); \
	virtual bool Server_Grab_Weapon_Validate(FName , bool , bool , FName ); \
	virtual void Server_Grab_Weapon_Implementation(FName grabbed_bone, bool simulate_physics, bool use_gravity, FName WeaponBoneName); \
	virtual bool Multicast_FirstTimeInitialization_Validate(USkeletalMeshComponent* ); \
	virtual void Multicast_FirstTimeInitialization_Implementation(USkeletalMeshComponent* skeleton_input); \
	virtual bool Server_FirstTimeInitialization_Validate(USkeletalMeshComponent* ); \
	virtual void Server_FirstTimeInitialization_Implementation(USkeletalMeshComponent* skeleton_input); \
 \
	DECLARE_FUNCTION(execMulticast_Unfreeze_Elbows_Function); \
	DECLARE_FUNCTION(execServer_Unfreeze_Elbows_Function); \
	DECLARE_FUNCTION(execUnfreeze_Elbows_Function); \
	DECLARE_FUNCTION(execMulticast_Freeze_Elbows_Function); \
	DECLARE_FUNCTION(execServer_Freeze_Elbows_Function); \
	DECLARE_FUNCTION(execFreeze_Elbows_Function); \
	DECLARE_FUNCTION(execMulticast_Attach_Hand_Only); \
	DECLARE_FUNCTION(execServer_Attach_Hand_Only); \
	DECLARE_FUNCTION(execAttach_Hand_Only); \
	DECLARE_FUNCTION(execMulticast_Weapon_Transform_Override); \
	DECLARE_FUNCTION(execServer_Weapon_Transform_Override); \
	DECLARE_FUNCTION(execWeapon_Transform_Override); \
	DECLARE_FUNCTION(execMulticast_Release_Hand_Plus_Override); \
	DECLARE_FUNCTION(execServer_Release_Hand_Plus_Override); \
	DECLARE_FUNCTION(execRelease_Hand_Plus_Override); \
	DECLARE_FUNCTION(execMulticast_Release_Hand_Only); \
	DECLARE_FUNCTION(execServer_Release_Hand_Only); \
	DECLARE_FUNCTION(execRelease_Hand_Only); \
	DECLARE_FUNCTION(execMulticast_EnableWeaponsArms); \
	DECLARE_FUNCTION(execServer_EnableWeaponsArms); \
	DECLARE_FUNCTION(execEnableWeaponsArms); \
	DECLARE_FUNCTION(execMulticast_DisableWeaponsArms); \
	DECLARE_FUNCTION(execServer_DisableWeaponsArms); \
	DECLARE_FUNCTION(execDisableWeaponsArms); \
	DECLARE_FUNCTION(execMulticast_Release_Weapon); \
	DECLARE_FUNCTION(execServer_Release_Weapon); \
	DECLARE_FUNCTION(execRelease_Weapon); \
	DECLARE_FUNCTION(execMulticast_Destroy_Weapon); \
	DECLARE_FUNCTION(execServer_Destroy_Weapon); \
	DECLARE_FUNCTION(execDestroy_Weapon); \
	DECLARE_FUNCTION(execMulticast_Grab_Weapon); \
	DECLARE_FUNCTION(execServer_Grab_Weapon); \
	DECLARE_FUNCTION(execGrab_Weapon); \
	DECLARE_FUNCTION(execMulticast_FirstTimeInitialization); \
	DECLARE_FUNCTION(execServer_FirstTimeInitialization); \
	DECLARE_FUNCTION(execFirstTimeInitialization);


#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_ACCESSORS
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_CALLBACK_WRAPPERS
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDragonIKWeaponPhysicsComponent(); \
	friend struct Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics; \
public: \
	DECLARE_CLASS(UDragonIKWeaponPhysicsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DragonIKPlugin"), NO_API) \
	DECLARE_SERIALIZER(UDragonIKWeaponPhysicsComponent) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		weapon_input_component=NETFIELD_REP_START, \
		NETFIELD_REP_END=weapon_input_component	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDragonIKWeaponPhysicsComponent(UDragonIKWeaponPhysicsComponent&&); \
	NO_API UDragonIKWeaponPhysicsComponent(const UDragonIKWeaponPhysicsComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDragonIKWeaponPhysicsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDragonIKWeaponPhysicsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDragonIKWeaponPhysicsComponent) \
	NO_API virtual ~UDragonIKWeaponPhysicsComponent();


#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_41_PROLOG
#define FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_SPARSE_DATA \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_ACCESSORS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_CALLBACK_WRAPPERS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DRAGONIKPLUGIN_API UClass* StaticClass<class UDragonIKWeaponPhysicsComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Desktop_Unreal_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
