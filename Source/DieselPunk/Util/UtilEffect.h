// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "NiagaraSystem.h"
#include "UtilEffect.generated.h"


class USceneComponent;
class UNiagaraComponent;
class UNiagaraSystem;


USTRUCT( BlueprintType )
struct FEffectTransform
{
	GENERATED_BODY()

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FVector Location = FVector::ZeroVector;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FRotator Rotation = FRotator::ZeroRotator;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FVector Scale = FVector(1);
};

namespace UtilEffect
{
	// 파티클 이펙트를 생성한다.
	UParticleSystemComponent* SpawnParticleEffect(UWorld* InWorld, UParticleSystem* InParticleSystem, const FEffectTransform& InEffectTransform);

	// 파티클 이펙트를 생성한다.(Attached)
	UParticleSystemComponent* SpawnParticleEffectAttached(UParticleSystem* InParticleSystem, USceneComponent* InAttachComp, FName InSocketName = NAME_None, const FEffectTransform& InEffectTransform = FEffectTransform());
	
	// 나이아가라 이펙트를 생성한다.
	UNiagaraComponent* SpawnNiagaraEffect(UWorld* InWorld, UNiagaraSystem* InNiagaraSystem, const FEffectTransform& InEffectTransform);

	// 나이아가라 이펙트를 생성한다.(Attached)
	UNiagaraComponent* SpawnNiagaraEffectAttached( UNiagaraSystem* InNiagaraSystem, USceneComponent* InAttachComp, FName InSocketName = NAME_None, const FEffectTransform& InEffectTransform = FEffectTransform());
}
