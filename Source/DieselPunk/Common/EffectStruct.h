// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "EffectStruct.generated.h"

class UNiagaraSystem;
class UParticleSystem;
class USoundBase;

USTRUCT()
struct FEffectData
{
	GENERATED_BODY()
	
	//이펙트 재생 타입
	UPROPERTY(EditAnywhere)
	EEffectPlayType EffectPlayType = EEffectPlayType::None;
	
	//나이아가라 이펙트
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* N_Effect;

	//파티클시스템 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* Effect;

	//사운드
	UPROPERTY(EditAnywhere)
	USoundBase* Sound;
	
	//볼륨 곱연산
	UPROPERTY(EditAnywhere)
	float VolumeMultiplier = 1.f;

	//피치 곱연산
	UPROPERTY(EditAnywhere)
	float PitchMultiplier = 1.f;

	//어태치 할것인가
	UPROPERTY(EditAnywhere)
	bool bAttach = false;

	//어태치 할 본 이름
	UPROPERTY(EditAnywhere)
	FName AttachBoneName = "";

	//오프셋
	UPROPERTY(EditAnywhere)
	FTransform Offset = FTransform::Identity;
};