// Fill out your copyright notice in the Description page of Project Settings.


#include "DPAnimNotify_Shot.h"

#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/GameInstanceSubSystem/SoundManagementGss.h"

void UDPAnimNotify_Shot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UWorld* world = MeshComp->GetWorld();
	if(world == nullptr)
		return;

	UGameInstance* instance = world->GetGameInstance();
	if(instance == nullptr)
		return;

	USoundManagementGss* gss = instance->GetSubsystem<USoundManagementGss>();
	if(gss)
	{
		FVector location = MeshComp->GetSocketLocation(FName(TEXT("Grenade_socket")));
		FRotator rotation = MeshComp->GetSocketRotation(FName(TEXT("Grenade_socket")));
		gss->PlaySoundAtLocation(SoundInfo.SoundAssetName, location + SoundInfo.OffsetLocation, rotation + SoundInfo.OffsetRotation,
			SoundInfo.VolumeMultiplier, SoundInfo.PitchMultiplier);
	}
}
