// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <Components/SplineComponent.h>
#include <GameFramework/Actor.h>
#include "ProjectilePathingSpline.generated.h"


class USplineComponent;

UCLASS()
class DIESELPUNK_API AProjectilePathingSpline : public AActor
{
	GENERATED_BODY()
protected:
	//배치할 스플라인입니다.
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> SplineComponent = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AProjectilePathingSpline();

	// SplineComponent 의 GetSplineLength 함수호출
	float _GetSplineLength();

	// SplineComponent 의 GetLocationAtDistanceAlongSpline 함수호출
	FVector _GetLocationAtDistanceAlongSpline(float Distance, ESplineCoordinateSpace::Type CoordinateSpace);

	// SplineComponent 의 GetRotationAtDistanceAlongSpline 함수호출
	FRotator _GetRotationAtDistanceAlongSpline(float Distance, ESplineCoordinateSpace::Type CoordinateSpace);

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;

	
};
