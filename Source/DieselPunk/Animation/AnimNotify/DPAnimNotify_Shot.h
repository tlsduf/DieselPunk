// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DPAnimNotify_Shot.generated.h"

USTRUCT(BlueprintType)
struct FSoundInfo
{
	GENERATED_BODY()

	//재생할 사운드 에셋 이름
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	FString SoundAssetName = TEXT("");

	//로케이션은 기본적으로 Mesh의 Grenade_socket위치를 기반으로 합니다. 오프셋 로케이션입니다.
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	FVector OffsetLocation = FVector::ZeroVector;

	//로테이션은 기본적으로 Mesh의 Grenade_socket회전을 기반으로 합니다. 오프셋 로테이션입니다.
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	FRotator OffsetRotation = FRotator::ZeroRotator;

	//볼륨 곱연산
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	float VolumeMultiplier = 1.f;

	//피치 곱연산
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	float PitchMultiplier = 1.f;
};

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UDPAnimNotify_Shot : public UAnimNotify
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="MYDP_AnimNotify")
	FSoundInfo SoundInfo;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
