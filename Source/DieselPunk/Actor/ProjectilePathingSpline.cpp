// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectilePathingSpline.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(ProjectilePathingSpline)

// Sets default values
AProjectilePathingSpline::AProjectilePathingSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	if(!SplineComponent)
	{
		return;
	}
	SplineComponent->SetupAttachment(RootComponent);
	SplineComponent->PrimaryComponentTick.bCanEverTick = false;
}

float AProjectilePathingSpline::_GetSplineLength()
{
	return SplineComponent->GetSplineLength();
}

FVector AProjectilePathingSpline::_GetLocationAtDistanceAlongSpline(float Distance, ESplineCoordinateSpace::Type CoordinateSpace)
{
	return SplineComponent->GetLocationAtDistanceAlongSpline(Distance,CoordinateSpace);
}

FRotator AProjectilePathingSpline::_GetRotationAtDistanceAlongSpline(float Distance, ESplineCoordinateSpace::Type CoordinateSpace)
{
	return SplineComponent->GetRotationAtDistanceAlongSpline(Distance,CoordinateSpace);
}

/** Overridable native event for when play begins for this actor. */
void AProjectilePathingSpline::BeginPlay()
{
	Super::BeginPlay();
}
