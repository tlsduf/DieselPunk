// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableInterface.h"

#include "Components/CapsuleComponent.h"

// Add default functionality here for any IPlayerInputInterface functions that are not pure virtual.
void IThrowableInterface::ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner)
{
	TWeakObjectPtr<AActor> thisPtr = Cast<AActor>(this);
	if(!thisPtr.IsValid() || !InThrowingOwner.IsValid())
		return;

	ThrowingOwner = InThrowingOwner;
	
	UShapeComponent* capsuleComp = Cast<UShapeComponent>(thisPtr->GetComponentByClass(UShapeComponent::StaticClass()));
	capsuleComp->OnComponentHit.AddDynamic(this, &IThrowableInterface::OnHit);
}

void IThrowableInterface::ThrowComplete()
{
	TWeakObjectPtr<AActor> thisPtr = Cast<AActor>(this);
	if(!thisPtr.IsValid())
		return;
	
	UShapeComponent* capsuleComp = Cast<UShapeComponent>(thisPtr->GetComponentByClass(UShapeComponent::StaticClass()));
	if(capsuleComp->OnComponentBeginOverlap.IsBound())
		capsuleComp->OnComponentBeginOverlap.Clear();
}

void IThrowableInterface::OnHit(UPrimitiveComponent* InHitComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHit)
{
	if(InOtherActor == ThrowingOwner)
		return;

	ThrowComplete();
}
