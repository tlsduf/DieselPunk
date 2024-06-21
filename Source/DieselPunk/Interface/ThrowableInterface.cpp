// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableInterface.h"

#include "Components/CapsuleComponent.h"

void IThrowableInterface::ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner)
{
	ThrowingOwner = InThrowingOwner;
}

// Add default functionality here for any IPlayerInputInterface functions that are not pure virtual.
void IThrowableInterface::ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner)
{
	TWeakObjectPtr<AActor> thisPtr = Cast<AActor>(this);
	if(!thisPtr.IsValid() || !InThrowingOwner.IsValid())
		return;

	if(ThrowingOwner != InThrowingOwner)
	{
		//이런 경우는 일어날 수 없음
		return;
	}
		
	ThrowingOwner = InThrowingOwner;
	
	UShapeComponent* shapeComp = Cast<UShapeComponent>(thisPtr->GetComponentByClass(UShapeComponent::StaticClass()));
	if(!shapeComp)
		return;
	
	shapeComp->OnComponentHit.AddDynamic(this, &IThrowableInterface::OnHit);
	shapeComp->OnComponentBeginOverlap.AddDynamic(this, &IThrowableInterface::OnBeginOverlap);
}

void IThrowableInterface::ThrowComplete()
{
	TWeakObjectPtr<AActor> thisPtr = Cast<AActor>(this);
	if(!thisPtr.IsValid())
		return;
	
	UShapeComponent* capsuleComp = Cast<UShapeComponent>(thisPtr->GetComponentByClass(UShapeComponent::StaticClass()));
	if(capsuleComp->OnComponentHit.IsBound())
		capsuleComp->OnComponentHit.Clear();
	if(capsuleComp->OnComponentBeginOverlap.IsBound())
		capsuleComp->OnComponentBeginOverlap.Clear();
}

void IThrowableInterface::OnBeginOverlap(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult& InSweepResult)
{
	if(InOtherActor == ThrowingOwner)
		return;

	ThrowComplete();
}

void IThrowableInterface::OnHit(UPrimitiveComponent* InHitComponent, AActor* InOtherActor,
                                UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHit)
{
	if(InOtherActor == ThrowingOwner)
		return;

	ThrowComplete();
}
