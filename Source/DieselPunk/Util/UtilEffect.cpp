// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilEffect.h"
#include <Kismet/GameplayStatics.h>
#include <NiagaraFunctionLibrary.h>
#include <NiagaraComponent.h>


// =============================================================
// 파티클 이펙트를 생성한다.
// =============================================================
UParticleSystemComponent* UtilEffect::SpawnParticleEffect(UWorld* InWorld, UParticleSystem* InParticleSystem, const FEffectTransform& InEffectTransform)
{
	UParticleSystemComponent* particleComp = UGameplayStatics::SpawnEmitterAtLocation(InWorld,InParticleSystem, InEffectTransform.Location, InEffectTransform.Rotation, InEffectTransform.Scale);

	return particleComp;
}

// =============================================================
// 파티클 이펙트를 생성한다.(Attached)
// =============================================================
UParticleSystemComponent* UtilEffect::SpawnParticleEffectAttached(UParticleSystem* InParticleSystem, USceneComponent* InAttachComp, FName InSocketName, const FEffectTransform& InEffectTransform)
{
	UParticleSystemComponent* particleComp = UGameplayStatics::SpawnEmitterAttached(InParticleSystem, InAttachComp, InSocketName, InEffectTransform.Location, InEffectTransform.Rotation, InEffectTransform.Scale, EAttachLocation::KeepRelativeOffset, true);

	return particleComp;
}

// =============================================================
// 나이아가라 이펙트를 생성한다.
// =============================================================
UNiagaraComponent* UtilEffect::SpawnNiagaraEffect(UWorld* InWorld, UNiagaraSystem* InNiagaraSystem, const FEffectTransform& InEffectTransform)
{
	UNiagaraComponent* niagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation( InWorld, InNiagaraSystem, InEffectTransform.Location, InEffectTransform.Rotation );
	niagaraComp->SetWorldScale3D(InEffectTransform.Scale);

	return niagaraComp;
}

// =============================================================
// 나이아가라 이펙트를 생성한다.(Attached)
// =============================================================
UNiagaraComponent* UtilEffect::SpawnNiagaraEffectAttached(UNiagaraSystem* InNiagaraSystem, USceneComponent* InAttachComp, FName InSocketName, const FEffectTransform& InEffectTransform)
{
	UNiagaraComponent* niagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached( InNiagaraSystem, InAttachComp, InSocketName, InEffectTransform.Location, InEffectTransform.Rotation, EAttachLocation::KeepRelativeOffset, true );
	niagaraComp->SetWorldScale3D(InEffectTransform.Scale);

	return niagaraComp;
}