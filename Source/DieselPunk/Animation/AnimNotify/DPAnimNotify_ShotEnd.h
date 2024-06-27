// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DPAnimNotify_ShotEnd.generated.h"

/**
 * 샷 애니메이션이 끝날 때 처리를 합니다.
 */
UCLASS()
class DIESELPUNK_API UDPAnimNotify_ShotEnd : public UAnimNotify
{
	GENERATED_BODY()
public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
