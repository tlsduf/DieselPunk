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
	EEffectPlayType EffectPlayType;
	
	//나이아가라 이펙트
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* N_Effect;

	//파티클시스템 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* Effect;

	//사운드
	UPROPERTY(EditAnywhere)
	USoundBase* Sound;
};