// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DragonIKWeaponPhysicsComponent.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragonIKWeaponPhysicsComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKWeaponPhysicsComponent();
	DRAGONIKPLUGIN_API UClass* Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_DragonIKPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Unfreeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Unfreeze_Elbows_Function_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Multicast_Unfreeze_Elbows_Function_Validate"));
			return;
		}
		P_THIS->Multicast_Unfreeze_Elbows_Function_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Unfreeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Unfreeze_Elbows_Function_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Server_Unfreeze_Elbows_Function_Validate"));
			return;
		}
		P_THIS->Server_Unfreeze_Elbows_Function_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execUnfreeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Unfreeze_Elbows_Function(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Freeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Freeze_Elbows_Function_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Multicast_Freeze_Elbows_Function_Validate"));
			return;
		}
		P_THIS->Multicast_Freeze_Elbows_Function_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Freeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Freeze_Elbows_Function_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Server_Freeze_Elbows_Function_Validate"));
			return;
		}
		P_THIS->Server_Freeze_Elbows_Function_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execFreeze_Elbows_Function)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Freeze_Elbows_Function(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Attach_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_UBOOL(Z_Param_arm_position_recalibrate);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Attach_Hand_Only_Validate(Z_Param_hand_bone,Z_Param_arm_position_recalibrate))
		{
			RPC_ValidateFailed(TEXT("Multicast_Attach_Hand_Only_Validate"));
			return;
		}
		P_THIS->Multicast_Attach_Hand_Only_Implementation(Z_Param_hand_bone,Z_Param_arm_position_recalibrate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Attach_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_UBOOL(Z_Param_arm_position_recalibrate);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Attach_Hand_Only_Validate(Z_Param_hand_bone,Z_Param_arm_position_recalibrate))
		{
			RPC_ValidateFailed(TEXT("Server_Attach_Hand_Only_Validate"));
			return;
		}
		P_THIS->Server_Attach_Hand_Only_Implementation(Z_Param_hand_bone,Z_Param_arm_position_recalibrate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execAttach_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_UBOOL(Z_Param_arm_position_recalibrate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attach_Hand_Only(Z_Param_hand_bone,Z_Param_arm_position_recalibrate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Weapon_Transform_Override)
	{
		P_GET_STRUCT(FTransform,Z_Param_Weapon_Transform);
		P_GET_UBOOL(Z_Param_bShould_Override_Weapon_Transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Weapon_Transform_Override_Validate(Z_Param_Weapon_Transform,Z_Param_bShould_Override_Weapon_Transform))
		{
			RPC_ValidateFailed(TEXT("Multicast_Weapon_Transform_Override_Validate"));
			return;
		}
		P_THIS->Multicast_Weapon_Transform_Override_Implementation(Z_Param_Weapon_Transform,Z_Param_bShould_Override_Weapon_Transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Weapon_Transform_Override)
	{
		P_GET_STRUCT(FTransform,Z_Param_Weapon_Transform);
		P_GET_UBOOL(Z_Param_bShould_Override_Weapon_Transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Weapon_Transform_Override_Validate(Z_Param_Weapon_Transform,Z_Param_bShould_Override_Weapon_Transform))
		{
			RPC_ValidateFailed(TEXT("Server_Weapon_Transform_Override_Validate"));
			return;
		}
		P_THIS->Server_Weapon_Transform_Override_Implementation(Z_Param_Weapon_Transform,Z_Param_bShould_Override_Weapon_Transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execWeapon_Transform_Override)
	{
		P_GET_STRUCT(FTransform,Z_Param_Weapon_Transform);
		P_GET_UBOOL(Z_Param_bShould_Override_Weapon_Transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Weapon_Transform_Override(Z_Param_Weapon_Transform,Z_Param_bShould_Override_Weapon_Transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Release_Hand_Plus_Override)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_STRUCT(FTransform,Z_Param_hand_transform);
		P_GET_UBOOL(Z_Param_override_hand_location);
		P_GET_UBOOL(Z_Param_override_hand_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Release_Hand_Plus_Override_Validate(Z_Param_hand_bone,Z_Param_hand_transform,Z_Param_override_hand_location,Z_Param_override_hand_rotation))
		{
			RPC_ValidateFailed(TEXT("Multicast_Release_Hand_Plus_Override_Validate"));
			return;
		}
		P_THIS->Multicast_Release_Hand_Plus_Override_Implementation(Z_Param_hand_bone,Z_Param_hand_transform,Z_Param_override_hand_location,Z_Param_override_hand_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Release_Hand_Plus_Override)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_STRUCT(FTransform,Z_Param_hand_transform);
		P_GET_UBOOL(Z_Param_override_hand_location);
		P_GET_UBOOL(Z_Param_override_hand_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Release_Hand_Plus_Override_Validate(Z_Param_hand_bone,Z_Param_hand_transform,Z_Param_override_hand_location,Z_Param_override_hand_rotation))
		{
			RPC_ValidateFailed(TEXT("Server_Release_Hand_Plus_Override_Validate"));
			return;
		}
		P_THIS->Server_Release_Hand_Plus_Override_Implementation(Z_Param_hand_bone,Z_Param_hand_transform,Z_Param_override_hand_location,Z_Param_override_hand_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execRelease_Hand_Plus_Override)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_GET_STRUCT(FTransform,Z_Param_hand_transform);
		P_GET_UBOOL(Z_Param_override_hand_location);
		P_GET_UBOOL(Z_Param_override_hand_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Release_Hand_Plus_Override(Z_Param_hand_bone,Z_Param_hand_transform,Z_Param_override_hand_location,Z_Param_override_hand_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Release_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Release_Hand_Only_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Multicast_Release_Hand_Only_Validate"));
			return;
		}
		P_THIS->Multicast_Release_Hand_Only_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Release_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Release_Hand_Only_Validate(Z_Param_hand_bone))
		{
			RPC_ValidateFailed(TEXT("Server_Release_Hand_Only_Validate"));
			return;
		}
		P_THIS->Server_Release_Hand_Only_Implementation(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execRelease_Hand_Only)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_hand_bone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Release_Hand_Only(Z_Param_hand_bone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_EnableWeaponsArms)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_EnableWeaponsArms_Validate())
		{
			RPC_ValidateFailed(TEXT("Multicast_EnableWeaponsArms_Validate"));
			return;
		}
		P_THIS->Multicast_EnableWeaponsArms_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_EnableWeaponsArms)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_EnableWeaponsArms_Validate())
		{
			RPC_ValidateFailed(TEXT("Server_EnableWeaponsArms_Validate"));
			return;
		}
		P_THIS->Server_EnableWeaponsArms_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execEnableWeaponsArms)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableWeaponsArms();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_DisableWeaponsArms)
	{
		P_GET_UBOOL(Z_Param_reset_weapon_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_DisableWeaponsArms_Validate(Z_Param_reset_weapon_transform))
		{
			RPC_ValidateFailed(TEXT("Multicast_DisableWeaponsArms_Validate"));
			return;
		}
		P_THIS->Multicast_DisableWeaponsArms_Implementation(Z_Param_reset_weapon_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_DisableWeaponsArms)
	{
		P_GET_UBOOL(Z_Param_reset_weapon_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_DisableWeaponsArms_Validate(Z_Param_reset_weapon_transform))
		{
			RPC_ValidateFailed(TEXT("Server_DisableWeaponsArms_Validate"));
			return;
		}
		P_THIS->Server_DisableWeaponsArms_Implementation(Z_Param_reset_weapon_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execDisableWeaponsArms)
	{
		P_GET_UBOOL(Z_Param_reset_weapon_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisableWeaponsArms(Z_Param_reset_weapon_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Release_Weapon)
	{
		P_GET_UBOOL(Z_Param_should_simulatephysics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_UBOOL(Z_Param_bKeep_Attachment);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Release_Weapon_Validate(Z_Param_should_simulatephysics,Z_Param_use_gravity,Z_Param_bKeep_Attachment))
		{
			RPC_ValidateFailed(TEXT("Multicast_Release_Weapon_Validate"));
			return;
		}
		P_THIS->Multicast_Release_Weapon_Implementation(Z_Param_should_simulatephysics,Z_Param_use_gravity,Z_Param_bKeep_Attachment);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Release_Weapon)
	{
		P_GET_UBOOL(Z_Param_should_simulatephysics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_UBOOL(Z_Param_bKeep_Attachment);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Release_Weapon_Validate(Z_Param_should_simulatephysics,Z_Param_use_gravity,Z_Param_bKeep_Attachment))
		{
			RPC_ValidateFailed(TEXT("Server_Release_Weapon_Validate"));
			return;
		}
		P_THIS->Server_Release_Weapon_Implementation(Z_Param_should_simulatephysics,Z_Param_use_gravity,Z_Param_bKeep_Attachment);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execRelease_Weapon)
	{
		P_GET_UBOOL(Z_Param_should_simulatephysics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_UBOOL(Z_Param_bKeep_Attachment);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Release_Weapon(Z_Param_should_simulatephysics,Z_Param_use_gravity,Z_Param_bKeep_Attachment);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Destroy_Weapon)
	{
		P_GET_OBJECT(AActor,Z_Param_weapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Destroy_Weapon_Validate(Z_Param_weapon))
		{
			RPC_ValidateFailed(TEXT("Multicast_Destroy_Weapon_Validate"));
			return;
		}
		P_THIS->Multicast_Destroy_Weapon_Implementation(Z_Param_weapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Destroy_Weapon)
	{
		P_GET_OBJECT(AActor,Z_Param_weapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Destroy_Weapon_Validate(Z_Param_weapon))
		{
			RPC_ValidateFailed(TEXT("Server_Destroy_Weapon_Validate"));
			return;
		}
		P_THIS->Server_Destroy_Weapon_Implementation(Z_Param_weapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execDestroy_Weapon)
	{
		P_GET_OBJECT(AActor,Z_Param_weapon);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Destroy_Weapon(Z_Param_weapon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_Grab_Weapon)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_grabbed_bone);
		P_GET_UBOOL(Z_Param_simulate_physics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_PROPERTY(FNameProperty,Z_Param_WeaponBoneName);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Multicast_Grab_Weapon_Validate(Z_Param_grabbed_bone,Z_Param_simulate_physics,Z_Param_use_gravity,Z_Param_WeaponBoneName))
		{
			RPC_ValidateFailed(TEXT("Multicast_Grab_Weapon_Validate"));
			return;
		}
		P_THIS->Multicast_Grab_Weapon_Implementation(Z_Param_grabbed_bone,Z_Param_simulate_physics,Z_Param_use_gravity,Z_Param_WeaponBoneName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_Grab_Weapon)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_grabbed_bone);
		P_GET_UBOOL(Z_Param_simulate_physics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_PROPERTY(FNameProperty,Z_Param_WeaponBoneName);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_Grab_Weapon_Validate(Z_Param_grabbed_bone,Z_Param_simulate_physics,Z_Param_use_gravity,Z_Param_WeaponBoneName))
		{
			RPC_ValidateFailed(TEXT("Server_Grab_Weapon_Validate"));
			return;
		}
		P_THIS->Server_Grab_Weapon_Implementation(Z_Param_grabbed_bone,Z_Param_simulate_physics,Z_Param_use_gravity,Z_Param_WeaponBoneName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execGrab_Weapon)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_grabbed_bone);
		P_GET_UBOOL(Z_Param_simulate_physics);
		P_GET_UBOOL(Z_Param_use_gravity);
		P_GET_PROPERTY(FNameProperty,Z_Param_WeaponBoneName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Grab_Weapon(Z_Param_grabbed_bone,Z_Param_simulate_physics,Z_Param_use_gravity,Z_Param_WeaponBoneName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execMulticast_FirstTimeInitialization)
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
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execServer_FirstTimeInitialization)
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
	DEFINE_FUNCTION(UDragonIKWeaponPhysicsComponent::execFirstTimeInitialization)
	{
		P_GET_OBJECT(USkeletalMeshComponent,Z_Param_skeleton_input);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FirstTimeInitialization(Z_Param_skeleton_input);
		P_NATIVE_END;
	}
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms
	{
		FName hand_bone;
		bool arm_position_recalibrate;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Destroy_Weapon_Parms
	{
		AActor* weapon;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms
	{
		bool reset_weapon_transform;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms
	{
		USkeletalMeshComponent* skeleton_input;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Freeze_Elbows_Function_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms
	{
		FName grabbed_bone;
		bool simulate_physics;
		bool use_gravity;
		FName WeaponBoneName;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Only_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms
	{
		FName hand_bone;
		FTransform hand_transform;
		bool override_hand_location;
		bool override_hand_rotation;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms
	{
		bool should_simulatephysics;
		bool use_gravity;
		bool bKeep_Attachment;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Unfreeze_Elbows_Function_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms
	{
		FTransform Weapon_Transform;
		bool bShould_Override_Weapon_Transform;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms
	{
		FName hand_bone;
		bool arm_position_recalibrate;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Destroy_Weapon_Parms
	{
		AActor* weapon;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms
	{
		bool reset_weapon_transform;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_FirstTimeInitialization_Parms
	{
		USkeletalMeshComponent* skeleton_input;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Freeze_Elbows_Function_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms
	{
		FName grabbed_bone;
		bool simulate_physics;
		bool use_gravity;
		FName WeaponBoneName;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Only_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms
	{
		FName hand_bone;
		FTransform hand_transform;
		bool override_hand_location;
		bool override_hand_rotation;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms
	{
		bool should_simulatephysics;
		bool use_gravity;
		bool bKeep_Attachment;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Unfreeze_Elbows_Function_Parms
	{
		FName hand_bone;
	};
	struct DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms
	{
		FTransform Weapon_Transform;
		bool bShould_Override_Weapon_Transform;
	};
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only = FName(TEXT("Multicast_Attach_Hand_Only"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Attach_Hand_Only(FName hand_bone, bool arm_position_recalibrate)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms Parms;
		Parms.hand_bone=hand_bone;
		Parms.arm_position_recalibrate=arm_position_recalibrate ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon = FName(TEXT("Multicast_Destroy_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Destroy_Weapon(AActor* weapon)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Destroy_Weapon_Parms Parms;
		Parms.weapon=weapon;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms = FName(TEXT("Multicast_DisableWeaponsArms"));
	void UDragonIKWeaponPhysicsComponent::Multicast_DisableWeaponsArms(bool reset_weapon_transform)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms Parms;
		Parms.reset_weapon_transform=reset_weapon_transform ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms = FName(TEXT("Multicast_EnableWeaponsArms"));
	void UDragonIKWeaponPhysicsComponent::Multicast_EnableWeaponsArms()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms),NULL);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization = FName(TEXT("Multicast_FirstTimeInitialization"));
	void UDragonIKWeaponPhysicsComponent::Multicast_FirstTimeInitialization(USkeletalMeshComponent* skeleton_input)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms Parms;
		Parms.skeleton_input=skeleton_input;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function = FName(TEXT("Multicast_Freeze_Elbows_Function"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Freeze_Elbows_Function(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Freeze_Elbows_Function_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon = FName(TEXT("Multicast_Grab_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Grab_Weapon(FName grabbed_bone, bool simulate_physics, bool use_gravity, FName WeaponBoneName)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms Parms;
		Parms.grabbed_bone=grabbed_bone;
		Parms.simulate_physics=simulate_physics ? true : false;
		Parms.use_gravity=use_gravity ? true : false;
		Parms.WeaponBoneName=WeaponBoneName;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only = FName(TEXT("Multicast_Release_Hand_Only"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Release_Hand_Only(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Only_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override = FName(TEXT("Multicast_Release_Hand_Plus_Override"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Release_Hand_Plus_Override(FName hand_bone, FTransform hand_transform, bool override_hand_location, bool override_hand_rotation)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms Parms;
		Parms.hand_bone=hand_bone;
		Parms.hand_transform=hand_transform;
		Parms.override_hand_location=override_hand_location ? true : false;
		Parms.override_hand_rotation=override_hand_rotation ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon = FName(TEXT("Multicast_Release_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Release_Weapon(bool should_simulatephysics, bool use_gravity, bool bKeep_Attachment)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms Parms;
		Parms.should_simulatephysics=should_simulatephysics ? true : false;
		Parms.use_gravity=use_gravity ? true : false;
		Parms.bKeep_Attachment=bKeep_Attachment ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function = FName(TEXT("Multicast_Unfreeze_Elbows_Function"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Unfreeze_Elbows_Function(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Unfreeze_Elbows_Function_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override = FName(TEXT("Multicast_Weapon_Transform_Override"));
	void UDragonIKWeaponPhysicsComponent::Multicast_Weapon_Transform_Override(FTransform Weapon_Transform, bool bShould_Override_Weapon_Transform)
	{
		DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms Parms;
		Parms.Weapon_Transform=Weapon_Transform;
		Parms.bShould_Override_Weapon_Transform=bShould_Override_Weapon_Transform ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only = FName(TEXT("Server_Attach_Hand_Only"));
	void UDragonIKWeaponPhysicsComponent::Server_Attach_Hand_Only(FName hand_bone, bool arm_position_recalibrate)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms Parms;
		Parms.hand_bone=hand_bone;
		Parms.arm_position_recalibrate=arm_position_recalibrate ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon = FName(TEXT("Server_Destroy_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Server_Destroy_Weapon(AActor* weapon)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Destroy_Weapon_Parms Parms;
		Parms.weapon=weapon;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms = FName(TEXT("Server_DisableWeaponsArms"));
	void UDragonIKWeaponPhysicsComponent::Server_DisableWeaponsArms(bool reset_weapon_transform)
	{
		DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms Parms;
		Parms.reset_weapon_transform=reset_weapon_transform ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms = FName(TEXT("Server_EnableWeaponsArms"));
	void UDragonIKWeaponPhysicsComponent::Server_EnableWeaponsArms()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms),NULL);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization = FName(TEXT("Server_FirstTimeInitialization"));
	void UDragonIKWeaponPhysicsComponent::Server_FirstTimeInitialization(USkeletalMeshComponent* skeleton_input)
	{
		DragonIKWeaponPhysicsComponent_eventServer_FirstTimeInitialization_Parms Parms;
		Parms.skeleton_input=skeleton_input;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function = FName(TEXT("Server_Freeze_Elbows_Function"));
	void UDragonIKWeaponPhysicsComponent::Server_Freeze_Elbows_Function(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Freeze_Elbows_Function_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon = FName(TEXT("Server_Grab_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Server_Grab_Weapon(FName grabbed_bone, bool simulate_physics, bool use_gravity, FName WeaponBoneName)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms Parms;
		Parms.grabbed_bone=grabbed_bone;
		Parms.simulate_physics=simulate_physics ? true : false;
		Parms.use_gravity=use_gravity ? true : false;
		Parms.WeaponBoneName=WeaponBoneName;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only = FName(TEXT("Server_Release_Hand_Only"));
	void UDragonIKWeaponPhysicsComponent::Server_Release_Hand_Only(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Only_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override = FName(TEXT("Server_Release_Hand_Plus_Override"));
	void UDragonIKWeaponPhysicsComponent::Server_Release_Hand_Plus_Override(FName hand_bone, FTransform hand_transform, bool override_hand_location, bool override_hand_rotation)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms Parms;
		Parms.hand_bone=hand_bone;
		Parms.hand_transform=hand_transform;
		Parms.override_hand_location=override_hand_location ? true : false;
		Parms.override_hand_rotation=override_hand_rotation ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon = FName(TEXT("Server_Release_Weapon"));
	void UDragonIKWeaponPhysicsComponent::Server_Release_Weapon(bool should_simulatephysics, bool use_gravity, bool bKeep_Attachment)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms Parms;
		Parms.should_simulatephysics=should_simulatephysics ? true : false;
		Parms.use_gravity=use_gravity ? true : false;
		Parms.bKeep_Attachment=bKeep_Attachment ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function = FName(TEXT("Server_Unfreeze_Elbows_Function"));
	void UDragonIKWeaponPhysicsComponent::Server_Unfreeze_Elbows_Function(FName hand_bone)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Unfreeze_Elbows_Function_Parms Parms;
		Parms.hand_bone=hand_bone;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function),&Parms);
	}
	static FName NAME_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override = FName(TEXT("Server_Weapon_Transform_Override"));
	void UDragonIKWeaponPhysicsComponent::Server_Weapon_Transform_Override(FTransform Weapon_Transform, bool bShould_Override_Weapon_Transform)
	{
		DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms Parms;
		Parms.Weapon_Transform=Weapon_Transform;
		Parms.bShould_Override_Weapon_Transform=bShould_Override_Weapon_Transform ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override),&Parms);
	}
	void UDragonIKWeaponPhysicsComponent::StaticRegisterNativesUDragonIKWeaponPhysicsComponent()
	{
		UClass* Class = UDragonIKWeaponPhysicsComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Attach_Hand_Only", &UDragonIKWeaponPhysicsComponent::execAttach_Hand_Only },
			{ "Destroy_Weapon", &UDragonIKWeaponPhysicsComponent::execDestroy_Weapon },
			{ "DisableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execDisableWeaponsArms },
			{ "EnableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execEnableWeaponsArms },
			{ "FirstTimeInitialization", &UDragonIKWeaponPhysicsComponent::execFirstTimeInitialization },
			{ "Freeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execFreeze_Elbows_Function },
			{ "Grab_Weapon", &UDragonIKWeaponPhysicsComponent::execGrab_Weapon },
			{ "Multicast_Attach_Hand_Only", &UDragonIKWeaponPhysicsComponent::execMulticast_Attach_Hand_Only },
			{ "Multicast_Destroy_Weapon", &UDragonIKWeaponPhysicsComponent::execMulticast_Destroy_Weapon },
			{ "Multicast_DisableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execMulticast_DisableWeaponsArms },
			{ "Multicast_EnableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execMulticast_EnableWeaponsArms },
			{ "Multicast_FirstTimeInitialization", &UDragonIKWeaponPhysicsComponent::execMulticast_FirstTimeInitialization },
			{ "Multicast_Freeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execMulticast_Freeze_Elbows_Function },
			{ "Multicast_Grab_Weapon", &UDragonIKWeaponPhysicsComponent::execMulticast_Grab_Weapon },
			{ "Multicast_Release_Hand_Only", &UDragonIKWeaponPhysicsComponent::execMulticast_Release_Hand_Only },
			{ "Multicast_Release_Hand_Plus_Override", &UDragonIKWeaponPhysicsComponent::execMulticast_Release_Hand_Plus_Override },
			{ "Multicast_Release_Weapon", &UDragonIKWeaponPhysicsComponent::execMulticast_Release_Weapon },
			{ "Multicast_Unfreeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execMulticast_Unfreeze_Elbows_Function },
			{ "Multicast_Weapon_Transform_Override", &UDragonIKWeaponPhysicsComponent::execMulticast_Weapon_Transform_Override },
			{ "Release_Hand_Only", &UDragonIKWeaponPhysicsComponent::execRelease_Hand_Only },
			{ "Release_Hand_Plus_Override", &UDragonIKWeaponPhysicsComponent::execRelease_Hand_Plus_Override },
			{ "Release_Weapon", &UDragonIKWeaponPhysicsComponent::execRelease_Weapon },
			{ "Server_Attach_Hand_Only", &UDragonIKWeaponPhysicsComponent::execServer_Attach_Hand_Only },
			{ "Server_Destroy_Weapon", &UDragonIKWeaponPhysicsComponent::execServer_Destroy_Weapon },
			{ "Server_DisableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execServer_DisableWeaponsArms },
			{ "Server_EnableWeaponsArms", &UDragonIKWeaponPhysicsComponent::execServer_EnableWeaponsArms },
			{ "Server_FirstTimeInitialization", &UDragonIKWeaponPhysicsComponent::execServer_FirstTimeInitialization },
			{ "Server_Freeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execServer_Freeze_Elbows_Function },
			{ "Server_Grab_Weapon", &UDragonIKWeaponPhysicsComponent::execServer_Grab_Weapon },
			{ "Server_Release_Hand_Only", &UDragonIKWeaponPhysicsComponent::execServer_Release_Hand_Only },
			{ "Server_Release_Hand_Plus_Override", &UDragonIKWeaponPhysicsComponent::execServer_Release_Hand_Plus_Override },
			{ "Server_Release_Weapon", &UDragonIKWeaponPhysicsComponent::execServer_Release_Weapon },
			{ "Server_Unfreeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execServer_Unfreeze_Elbows_Function },
			{ "Server_Weapon_Transform_Override", &UDragonIKWeaponPhysicsComponent::execServer_Weapon_Transform_Override },
			{ "Unfreeze_Elbows_Function", &UDragonIKWeaponPhysicsComponent::execUnfreeze_Elbows_Function },
			{ "Weapon_Transform_Override", &UDragonIKWeaponPhysicsComponent::execWeapon_Transform_Override },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms
		{
			FName hand_bone;
			bool arm_position_recalibrate;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static void NewProp_arm_position_recalibrate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_arm_position_recalibrate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms*)Obj)->arm_position_recalibrate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate = { "arm_position_recalibrate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Attach the hand back to the weapon\n * Call the arm position recalibrate if you want the hand to go back to the last grabbed position or use the existing position as the new grab position\n */" },
#endif
		{ "DisplayName", "Attach Hand Only" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Attach the hand back to the weapon\n* Call the arm position recalibrate if you want the hand to go back to the last grabbed position or use the existing position as the new grab position" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Attach_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::DragonIKWeaponPhysicsComponent_eventAttach_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventDestroy_Weapon_Parms
		{
			AActor* weapon;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_weapon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::NewProp_weapon = { "weapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventDestroy_Weapon_Parms, weapon), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::NewProp_weapon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Destroy Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Destroy_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventDestroy_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventDestroy_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventDisableWeaponsArms_Parms
		{
			bool reset_weapon_transform;
		};
		static void NewProp_reset_weapon_transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_reset_weapon_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventDisableWeaponsArms_Parms*)Obj)->reset_weapon_transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform = { "reset_weapon_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventDisableWeaponsArms_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Disable Weapon+Arms Without Release" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "DisableWeaponsArms", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::DragonIKWeaponPhysicsComponent_eventDisableWeaponsArms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::DragonIKWeaponPhysicsComponent_eventDisableWeaponsArms_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Enable Weapon+Arms Without Release" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "EnableWeaponsArms", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventFirstTimeInitialization_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventFirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Only needed to be called once.\n\x09* The very first function to be called before anything else can work!\n\x09*/" },
#endif
		{ "DisplayName", "First Time Initialization (WeaponComp)" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Only needed to be called once.\n* The very first function to be called before anything else can work!" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::DragonIKWeaponPhysicsComponent_eventFirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::DragonIKWeaponPhysicsComponent_eventFirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventFreeze_Elbows_Function_Parms
		{
			FName hand_bone;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventFreeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Freeze Weapon & Elbow Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Freeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::DragonIKWeaponPhysicsComponent_eventFreeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::DragonIKWeaponPhysicsComponent_eventFreeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms
		{
			FName grabbed_bone;
			bool simulate_physics;
			bool use_gravity;
			FName WeaponBoneName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_grabbed_bone;
		static void NewProp_simulate_physics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_simulate_physics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponBoneName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_grabbed_bone = { "grabbed_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms, grabbed_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms*)Obj)->simulate_physics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_simulate_physics = { "simulate_physics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_WeaponBoneName = { "WeaponBoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms, WeaponBoneName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_grabbed_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_simulate_physics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::NewProp_WeaponBoneName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Grab the weapon and activate the corresponding arms IK\n\x09*/" },
#endif
		{ "CPP_Default_simulate_physics", "true" },
		{ "CPP_Default_use_gravity", "false" },
		{ "CPP_Default_WeaponBoneName", "None" },
		{ "DisplayName", "Grab Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Grab the weapon and activate the corresponding arms IK" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Grab_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventGrab_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static void NewProp_arm_position_recalibrate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_arm_position_recalibrate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms*)Obj)->arm_position_recalibrate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate = { "arm_position_recalibrate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Attach_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Attach_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_weapon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::NewProp_weapon = { "weapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Destroy_Weapon_Parms, weapon), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::NewProp_weapon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Destroy_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Destroy_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Destroy_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics
	{
		static void NewProp_reset_weapon_transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_reset_weapon_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms*)Obj)->reset_weapon_transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform = { "reset_weapon_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_DisableWeaponsArms", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_DisableWeaponsArms_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_EnableWeaponsArms", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_FirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Freeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Freeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Freeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Freeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_grabbed_bone;
		static void NewProp_simulate_physics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_simulate_physics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponBoneName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_grabbed_bone = { "grabbed_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms, grabbed_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms*)Obj)->simulate_physics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_simulate_physics = { "simulate_physics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_WeaponBoneName = { "WeaponBoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms, WeaponBoneName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_grabbed_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_simulate_physics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::NewProp_WeaponBoneName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Grab_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Grab_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Release_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hand_transform;
		static void NewProp_override_hand_location_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_location;
		static void NewProp_override_hand_rotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_hand_transform = { "hand_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms, hand_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms*)Obj)->override_hand_location = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location = { "override_hand_location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms*)Obj)->override_hand_rotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation = { "override_hand_rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_hand_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Release_Hand_Plus_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Hand_Plus_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics
	{
		static void NewProp_should_simulatephysics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_should_simulatephysics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static void NewProp_bKeep_Attachment_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeep_Attachment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms*)Obj)->should_simulatephysics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_should_simulatephysics = { "should_simulatephysics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms*)Obj)->bKeep_Attachment = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_bKeep_Attachment = { "bKeep_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_should_simulatephysics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::NewProp_bKeep_Attachment,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Release_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Release_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Unfreeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Unfreeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Unfreeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Unfreeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Weapon_Transform;
		static void NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShould_Override_Weapon_Transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform = { "Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms, Weapon_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms*)Obj)->bShould_Override_Weapon_Transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform = { "bShould_Override_Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Multicast_Weapon_Transform_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventMulticast_Weapon_Transform_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventRelease_Hand_Only_Parms
		{
			FName hand_bone;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventRelease_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Keep the weapon holding still held and active, but virtually release the hand\n\x09* Use the hand array index corresponding to the hand array from the WeaponArmSolver in your animbp\n\x09*/" },
#endif
		{ "DisplayName", "Release Hand Only" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Keep the weapon holding still held and active, but virtually release the hand\n* Use the hand array index corresponding to the hand array from the WeaponArmSolver in your animbp" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Release_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms
		{
			FName hand_bone;
			FTransform hand_transform;
			bool override_hand_location;
			bool override_hand_rotation;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hand_transform;
		static void NewProp_override_hand_location_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_location;
		static void NewProp_override_hand_rotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_hand_transform = { "hand_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms, hand_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms*)Obj)->override_hand_location = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location = { "override_hand_location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms*)Obj)->override_hand_rotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation = { "override_hand_rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_hand_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Along with virtually releasing the had, position the transform of the hand and control it.\n * The weapon physics and it's position stays the same until release weapon is called.\n */" },
#endif
		{ "DisplayName", "Override Hand Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Along with virtually releasing the had, position the transform of the hand and control it.\n* The weapon physics and it's position stays the same until release weapon is called." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Release_Hand_Plus_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Hand_Plus_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms
		{
			bool should_simulatephysics;
			bool use_gravity;
			bool bKeep_Attachment;
		};
		static void NewProp_should_simulatephysics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_should_simulatephysics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static void NewProp_bKeep_Attachment_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeep_Attachment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms*)Obj)->should_simulatephysics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_should_simulatephysics = { "should_simulatephysics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms*)Obj)->bKeep_Attachment = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_bKeep_Attachment = { "bKeep_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_should_simulatephysics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::NewProp_bKeep_Attachment,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Release the weapon and deactivate the corresponding arms IK\n\x09*/" },
#endif
		{ "CPP_Default_bKeep_Attachment", "true" },
		{ "CPP_Default_use_gravity", "true" },
		{ "DisplayName", "Release Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Release the weapon and deactivate the corresponding arms IK" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Release_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::DragonIKWeaponPhysicsComponent_eventRelease_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static void NewProp_arm_position_recalibrate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_arm_position_recalibrate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms*)Obj)->arm_position_recalibrate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate = { "arm_position_recalibrate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::NewProp_arm_position_recalibrate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Attach Hand Only" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Attach_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Attach_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_weapon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::NewProp_weapon = { "weapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Destroy_Weapon_Parms, weapon), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::NewProp_weapon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Destroy Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Destroy_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Destroy_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Destroy_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics
	{
		static void NewProp_reset_weapon_transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_reset_weapon_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms*)Obj)->reset_weapon_transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform = { "reset_weapon_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::NewProp_reset_weapon_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Disable Weapon+Arms Without Release" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_DisableWeaponsArms", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_DisableWeaponsArms_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Enable Weapon+Arms Without Release" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_EnableWeaponsArms", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input = { "skeleton_input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_FirstTimeInitialization_Parms, skeleton_input), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::NewProp_skeleton_input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] First Time Initialization (WeaponComp)" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_FirstTimeInitialization", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_FirstTimeInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_FirstTimeInitialization_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Freeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Freeze Weapon Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Freeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Freeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Freeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_grabbed_bone;
		static void NewProp_simulate_physics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_simulate_physics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static const UECodeGen_Private::FNamePropertyParams NewProp_WeaponBoneName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_grabbed_bone = { "grabbed_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms, grabbed_bone), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms*)Obj)->simulate_physics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_simulate_physics = { "simulate_physics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_simulate_physics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_WeaponBoneName = { "WeaponBoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms, WeaponBoneName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_grabbed_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_simulate_physics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::NewProp_WeaponBoneName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "CPP_Default_simulate_physics", "true" },
		{ "CPP_Default_use_gravity", "false" },
		{ "CPP_Default_WeaponBoneName", "None" },
		{ "DisplayName", "z[Server] Grab Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Grab_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Grab_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Only_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Release Hand Only" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Release_Hand_Only", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Only_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Only_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hand_transform;
		static void NewProp_override_hand_location_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_location;
		static void NewProp_override_hand_rotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_override_hand_rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_hand_transform = { "hand_transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms, hand_transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms*)Obj)->override_hand_location = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location = { "override_hand_location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms*)Obj)->override_hand_rotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation = { "override_hand_rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_hand_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_hand_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::NewProp_override_hand_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Override Hand Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Release_Hand_Plus_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84A20C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Hand_Plus_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics
	{
		static void NewProp_should_simulatephysics_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_should_simulatephysics;
		static void NewProp_use_gravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_use_gravity;
		static void NewProp_bKeep_Attachment_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeep_Attachment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms*)Obj)->should_simulatephysics = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_should_simulatephysics = { "should_simulatephysics", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_should_simulatephysics_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_use_gravity_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms*)Obj)->use_gravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_use_gravity = { "use_gravity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_use_gravity_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms*)Obj)->bKeep_Attachment = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_bKeep_Attachment = { "bKeep_Attachment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_bKeep_Attachment_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_should_simulatephysics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_use_gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::NewProp_bKeep_Attachment,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "CPP_Default_bKeep_Attachment", "true" },
		{ "CPP_Default_use_gravity", "true" },
		{ "DisplayName", "z[Server] Release Weapon" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Release_Weapon", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Release_Weapon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Unfreeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Un-Freeze Weapon Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Unfreeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Unfreeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Unfreeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Weapon_Transform;
		static void NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShould_Override_Weapon_Transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform = { "Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms, Weapon_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms*)Obj)->bShould_Override_Weapon_Transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform = { "bShould_Override_Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "z[Server] Override Weapon Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Server_Weapon_Transform_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::PropPointers), sizeof(DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84A20C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(DragonIKWeaponPhysicsComponent_eventServer_Weapon_Transform_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventUnfreeze_Elbows_Function_Parms
		{
			FName hand_bone;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_hand_bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone = { "hand_bone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventUnfreeze_Elbows_Function_Parms, hand_bone), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::NewProp_hand_bone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Un-Freeze Weapon Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Unfreeze_Elbows_Function", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::DragonIKWeaponPhysicsComponent_eventUnfreeze_Elbows_Function_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::DragonIKWeaponPhysicsComponent_eventUnfreeze_Elbows_Function_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics
	{
		struct DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms
		{
			FTransform Weapon_Transform;
			bool bShould_Override_Weapon_Transform;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Weapon_Transform;
		static void NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShould_Override_Weapon_Transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform = { "Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms, Weapon_Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit(void* Obj)
	{
		((DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms*)Obj)->bShould_Override_Weapon_Transform = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform = { "bShould_Override_Weapon_Transform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms), &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_Weapon_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::NewProp_bShould_Override_Weapon_Transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::Function_MetaDataParams[] = {
		{ "Category", "DragonIK" },
		{ "DisplayName", "Override Weapon Transform" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, nullptr, "Weapon_Transform_Override", nullptr, nullptr, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::DragonIKWeaponPhysicsComponent_eventWeapon_Transform_Override_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDragonIKWeaponPhysicsComponent);
	UClass* Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_NoRegister()
	{
		return UDragonIKWeaponPhysicsComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_weapon_input_component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_weapon_input_component;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_read_this_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_read_this;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Max_Arm_Length_Percent_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Max_Arm_Length_Percent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_physanim_tag_index_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_physanim_tag_index;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unfreeze_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_unfreeze_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_is_grabbing_MetaData[];
#endif
		static void NewProp_is_grabbing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_is_grabbing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Teleport_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Teleport_Distance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DragonIKPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Attach_Hand_Only, "Attach_Hand_Only" }, // 2818912106
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Destroy_Weapon, "Destroy_Weapon" }, // 864406103
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_DisableWeaponsArms, "DisableWeaponsArms" }, // 2481510858
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_EnableWeaponsArms, "EnableWeaponsArms" }, // 442875547
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_FirstTimeInitialization, "FirstTimeInitialization" }, // 399082867
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Freeze_Elbows_Function, "Freeze_Elbows_Function" }, // 4242573924
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Grab_Weapon, "Grab_Weapon" }, // 2937390355
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Attach_Hand_Only, "Multicast_Attach_Hand_Only" }, // 2485558892
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Destroy_Weapon, "Multicast_Destroy_Weapon" }, // 3580796737
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_DisableWeaponsArms, "Multicast_DisableWeaponsArms" }, // 64550501
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_EnableWeaponsArms, "Multicast_EnableWeaponsArms" }, // 73682147
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_FirstTimeInitialization, "Multicast_FirstTimeInitialization" }, // 3823962166
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Freeze_Elbows_Function, "Multicast_Freeze_Elbows_Function" }, // 3905238434
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Grab_Weapon, "Multicast_Grab_Weapon" }, // 226110097
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Only, "Multicast_Release_Hand_Only" }, // 3062036270
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Hand_Plus_Override, "Multicast_Release_Hand_Plus_Override" }, // 602711952
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Release_Weapon, "Multicast_Release_Weapon" }, // 3749412371
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Unfreeze_Elbows_Function, "Multicast_Unfreeze_Elbows_Function" }, // 3734986686
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Multicast_Weapon_Transform_Override, "Multicast_Weapon_Transform_Override" }, // 639064047
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Only, "Release_Hand_Only" }, // 373995440
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Hand_Plus_Override, "Release_Hand_Plus_Override" }, // 1440047213
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Release_Weapon, "Release_Weapon" }, // 3649044305
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Attach_Hand_Only, "Server_Attach_Hand_Only" }, // 1804655280
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Destroy_Weapon, "Server_Destroy_Weapon" }, // 993635986
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_DisableWeaponsArms, "Server_DisableWeaponsArms" }, // 913464411
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_EnableWeaponsArms, "Server_EnableWeaponsArms" }, // 4116835794
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_FirstTimeInitialization, "Server_FirstTimeInitialization" }, // 468832843
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Freeze_Elbows_Function, "Server_Freeze_Elbows_Function" }, // 225558378
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Grab_Weapon, "Server_Grab_Weapon" }, // 3210587275
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Only, "Server_Release_Hand_Only" }, // 2972643384
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Hand_Plus_Override, "Server_Release_Hand_Plus_Override" }, // 1153329893
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Release_Weapon, "Server_Release_Weapon" }, // 3976530105
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Unfreeze_Elbows_Function, "Server_Unfreeze_Elbows_Function" }, // 3505716689
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Server_Weapon_Transform_Override, "Server_Weapon_Transform_Override" }, // 1800689646
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Unfreeze_Elbows_Function, "Unfreeze_Elbows_Function" }, // 3136272556
		{ &Z_Construct_UFunction_UDragonIKWeaponPhysicsComponent_Weapon_Transform_Override, "Weapon_Transform_Override" }, // 2760818795
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "DragonIK" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\nUENUM(BlueprintType)\x09\x09//\"BlueprintType\" is essential to include\nenum class EOrigin_Grab_DragonIK : uint8\n{\n\x09""ENUM_Origin_Zero \x09UMETA(DisplayName = \"Grab origin is world origin\"),\n\x09""ENUM_Origin_Hand \x09UMETA(DisplayName = \"Grab origin at dominant hand\")\n\n};\n*/" },
#endif
		{ "DisplayName", "Dragonik Weapon Handler Component" },
		{ "IncludePath", "DragonIKWeaponPhysicsComponent.h" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UENUM(BlueprintType)           //\"BlueprintType\" is essential to include\nenum class EOrigin_Grab_DragonIK : uint8\n{\n       ENUM_Origin_Zero        UMETA(DisplayName = \"Grab origin is world origin\"),\n       ENUM_Origin_Hand        UMETA(DisplayName = \"Grab origin at dominant hand\")\n\n};" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_weapon_input_component_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_weapon_input_component = { "weapon_input_component", nullptr, (EPropertyFlags)0x001000000008002d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, weapon_input_component), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_weapon_input_component_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_weapon_input_component_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_read_this_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n*\n* This is a brand new feature that makes your weapon (gun,sword,apple,books etc) be physics driven but also make the arms to adapt to the collision reactions of the weapon using IK in the animation blueprint.\n* There are two important elements to use this feature :-\n* 1. The DragonIK Weapon handler component you add in your pawn BP\n* 2. The DragonIK Weapon Arm IK Solver you add in your skeletal mesh's animation blueprint.\n* Set up just your arm bone names in the hand array of your weapon arm IK solver\n* Call the \"first time initialization\" function, then call the \"grab weapon\" function.\n* Call the \"Release weapon\" to disconnect the feature.\n* Physics is only applied on the weapon. The arms are purely driven by IK.\n*/" },
#endif
		{ "DisplayName", "HOVER MOUSE HERE FOR TIPS!" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This is a brand new feature that makes your weapon (gun,sword,apple,books etc) be physics driven but also make the arms to adapt to the collision reactions of the weapon using IK in the animation blueprint.\n* There are two important elements to use this feature :-\n* 1. The DragonIK Weapon handler component you add in your pawn BP\n* 2. The DragonIK Weapon Arm IK Solver you add in your skeletal mesh's animation blueprint.\n* Set up just your arm bone names in the hand array of your weapon arm IK solver\n* Call the \"first time initialization\" function, then call the \"grab weapon\" function.\n* Call the \"Release weapon\" to disconnect the feature.\n* Physics is only applied on the weapon. The arms are purely driven by IK." },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_read_this = { "read_this", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, read_this), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_read_this_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_read_this_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Max_Arm_Length_Percent_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Keeping this 0 makes the weapon to only move within the maximum length of the arm from the shoulder to the hand.\n\x09* A higher value makes the weapon to move even outside of the arm range.\n\x09* A negative value makes the weapon movement range to be even smaller, and move inwards.\n\x09*/" },
#endif
		{ "DisplayName", "Max Arm Length Percent" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Keeping this 0 makes the weapon to only move within the maximum length of the arm from the shoulder to the hand.\n* A higher value makes the weapon to move even outside of the arm range.\n* A negative value makes the weapon movement range to be even smaller, and move inwards." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Max_Arm_Length_Percent = { "Max_Arm_Length_Percent", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Max_Arm_Length_Percent), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Max_Arm_Length_Percent_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Max_Arm_Length_Percent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Make sure this tag is of the same value as the tag value in the physanim info relayer.\n\x09* This tag info is used to help make the physanim relayer determine the correct component to relay the animation data into.\n\x09*/" },
#endif
		{ "DisplayName", "PhysWeapon component tag" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Make sure this tag is of the same value as the tag value in the physanim info relayer.\n* This tag info is used to help make the physanim relayer determine the correct component to relay the animation data into." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_physanim_tag_index = { "physanim_tag_index", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, physanim_tag_index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_physanim_tag_index_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* This value will only be affected after the first initialization or after each new \"grab\".\n\x09*/" },
#endif
		{ "DisplayName", "Linear Strength" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Strength = { "Linear_Strength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Linear_Strength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Strength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Angular Strength" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Strength = { "Angular_Strength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Angular_Strength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Strength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Linear Damp" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Damp = { "Linear_Damp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Linear_Damp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Damp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* This value will only be affected after the first initialization or after each new \"grab\".\n*/" },
#endif
		{ "DisplayName", "Angular Damp" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This value will only be affected after the first initialization or after each new \"grab\"." },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Damp = { "Angular_Damp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Angular_Damp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Damp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Interpolation Speed" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Interpolation_Speed = { "Interpolation_Speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Interpolation_Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Interpolation_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_unfreeze_speed_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Unfreeze Interpolation Speed" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_unfreeze_speed = { "unfreeze_speed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, unfreeze_speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_unfreeze_speed_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_unfreeze_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing_MetaData[] = {
		{ "Category", "CoreInput" },
		{ "DisplayName", "Is Weapon Grabbed ?" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing_SetBit(void* Obj)
	{
		((UDragonIKWeaponPhysicsComponent*)Obj)->is_grabbing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing = { "is_grabbing", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDragonIKWeaponPhysicsComponent), &Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData[] = {
		{ "Category", "CoreInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * If the distance between the target weapon position and current weapon position is beyond this distance, then temporarily teleport the weapon along with the character.\n\x09 */" },
#endif
		{ "DisplayName", "Teleport Distance" },
		{ "ModuleRelativePath", "Public/DragonIKWeaponPhysicsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* If the distance between the target weapon position and current weapon position is beyond this distance, then temporarily teleport the weapon along with the character." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Teleport_Distance = { "Teleport_Distance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDragonIKWeaponPhysicsComponent, Teleport_Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Teleport_Distance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_weapon_input_component,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_read_this,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Max_Arm_Length_Percent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_physanim_tag_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Linear_Damp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Angular_Damp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Interpolation_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_unfreeze_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_is_grabbing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::NewProp_Teleport_Distance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDragonIKWeaponPhysicsComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::ClassParams = {
		&UDragonIKWeaponPhysicsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDragonIKWeaponPhysicsComponent()
	{
		if (!Z_Registration_Info_UClass_UDragonIKWeaponPhysicsComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDragonIKWeaponPhysicsComponent.OuterSingleton, Z_Construct_UClass_UDragonIKWeaponPhysicsComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDragonIKWeaponPhysicsComponent.OuterSingleton;
	}
	template<> DRAGONIKPLUGIN_API UClass* StaticClass<UDragonIKWeaponPhysicsComponent>()
	{
		return UDragonIKWeaponPhysicsComponent::StaticClass();
	}

	void UDragonIKWeaponPhysicsComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_weapon_input_component(TEXT("weapon_input_component"));

		const bool bIsValid = true
			&& Name_weapon_input_component == ClassReps[(int32)ENetFields_Private::weapon_input_component].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UDragonIKWeaponPhysicsComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDragonIKWeaponPhysicsComponent);
	UDragonIKWeaponPhysicsComponent::~UDragonIKWeaponPhysicsComponent() {}
	struct Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDragonIKWeaponPhysicsComponent, UDragonIKWeaponPhysicsComponent::StaticClass, TEXT("UDragonIKWeaponPhysicsComponent"), &Z_Registration_Info_UClass_UDragonIKWeaponPhysicsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDragonIKWeaponPhysicsComponent), 910848864U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_2533538726(TEXT("/Script/DragonIKPlugin"),
		Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DieselPunk_Plugins_DragonIK_Source_DragonIKPlugin_Public_DragonIKWeaponPhysicsComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
