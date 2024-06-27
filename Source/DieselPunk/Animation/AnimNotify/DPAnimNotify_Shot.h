// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"

#include "../../Common/EffectStruct.h"
#include "DPAnimNotify_Shot.generated.h"

/**
 * 발사체를 발사할 때 이펙트 및 스킬을 처리합니다.
 */
UCLASS()
class DIESELPUNK_API UDPAnimNotify_Shot : public UAnimNotify
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	double DamageCoefficient = 1.0;
public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
