// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilEffect.h"
#include "../Component/DecorateActorComponent.h"
#include <NiagaraFunctionLibrary.h>
#include <NiagaraComponent.h>


// =============================================================
// 실제 파티클 생성이 이루어지는 곳
// =============================================================
UNiagaraComponent* _SpawnParticleComponent( const FString& InPath, const FVector& InLocation, const FRotator& InRotation, const FVector& InScale, UWorld* InWorld )
{
	UNiagaraSystem* niagaraSystem = LoadObject<UNiagaraSystem>( nullptr, *InPath );
	if ( !niagaraSystem )
		return nullptr;

	UWorld* world = InWorld ? InWorld : DpGetWorld();
	UNiagaraComponent* niagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation( world, niagaraSystem, InLocation, InRotation );
	if ( !niagaraComp )
		return nullptr;

	if ( InScale != FVector::OneVector )
		niagaraComp->SetWorldScale3D(InScale);

	return niagaraComp;
}

// =============================================================
// 실제 파티클 생성이 이루어지는 곳 ( 소켓 부착 )
// =============================================================
UNiagaraComponent* _SpawnParticleComponentAttached( const FString& InPath, USceneComponent* InAttachComp, FName InSocketName, const FVector& InLocation, const FRotator& InRotation, const FVector& InScale )
{
	UNiagaraSystem* niagaraSystem = LoadObject<UNiagaraSystem>( nullptr, *InPath );
	if ( !niagaraSystem )
		return nullptr;

	UNiagaraComponent* niagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached( niagaraSystem, InAttachComp, InSocketName, InLocation, InRotation, EAttachLocation::KeepRelativeOffset, true );
	if ( !niagaraComp )
		return nullptr;

	if ( InScale != FVector::OneVector )
		niagaraComp->SetWorldScale3D( InScale );

	return niagaraComp;
}

// =============================================================
// 데코레이터를 발동한다.
// =============================================================
void UtilEffect::ActivateDecorator( AActor* InActor, EDecorateUseType InUseType )
{
	if ( !InActor )
		return;

	TArray< UDecorateActorComponent* > DecoComps;
	InActor->GetComponents< UDecorateActorComponent >( DecoComps );

	for ( UDecorateActorComponent*& decoComp : DecoComps )
	{
		decoComp->StartDeco( InUseType );
	}
}

// =============================================================
// 파티클을 생성한다.
// =============================================================
UNiagaraComponent* UtilEffect::SpawnParticleComponent( TSoftObjectPtr<UNiagaraSystem> InNiagaraSystem, const FVector& InLocation, const FRotator& InRotation, const FVector& InScale, UWorld* InWorld )
{
	const FSoftObjectPath& objPath = InNiagaraSystem.ToSoftObjectPath();
	if ( !objPath.IsValid() ) return nullptr;

	return _SpawnParticleComponent( objPath.ToString(), InLocation, InRotation, InScale, InWorld );
}

// =============================================================
// 파티클을 생성한다.
// =============================================================
UNiagaraComponent* UtilEffect::SpawnParticleComponentAttached( TSoftObjectPtr<UNiagaraSystem> InNiagaraSystem, USceneComponent* InAttachComp, FName InSocketName, const FVector& InLocation, const FRotator& InRotation, const FVector& InScale )
{
	const FSoftObjectPath& objPath = InNiagaraSystem.ToSoftObjectPath();
	if ( !objPath.IsValid() ) return nullptr;

	return _SpawnParticleComponentAttached( objPath.ToString(), InAttachComp, InSocketName, InLocation, InRotation, InScale );
}