// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <UObject/Interface.h>
#include "ThrowableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UThrowableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 던질 수 있는 액터에 달립니다.
 */
class DIESELPUNK_API IThrowableInterface
{
	GENERATED_BODY()
	TWeakObjectPtr<AActor> ThrowingOwner = nullptr;
public:
	virtual void ThrowReady(){}
	virtual void ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner);
	virtual void ThrowComplete();
public:
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* InHitComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHit);
};
