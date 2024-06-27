// Fill out your copyright notice in the Description page of Project Settings.


#include "DPAnimNotify_ShotEnd.h"

#include <Components/SkeletalMeshComponent.h>
#include "../DPAnimInstance.h"

void UDPAnimNotify_ShotEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(MeshComp->GetAnimInstance()))
	{
		animInst->AttackEndSign();
	}
}
