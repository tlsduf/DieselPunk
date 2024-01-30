// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "Components/SplineComponent.h"

struct DIESELPUNK_API FSplinePath
{
public:
	FTransform Transform;	// 중심이 될 Transform
	FSplineCurves Path;		// Path Data
	
	int32 s_ReparamStepsPerSegment = 10;	// Spline path options

public:
	// 생성자
	FSplinePath();

	// Path 유효성 검사
	bool IsValid() const;

	// Spline 에 포인트를 추가합니다.
	void AddSplinePoint(const FVector& InPosition, ESplineCoordinateSpace::Type InCoordinateSpace, ESplinePointType::Type InCurveMode);

	// Spline 의 포인트를 모두 지웁니다.
	void ClearSplinePoints();

	// Spline의 변경사항을 업데이트합니다.
	void UpdateSpline();

	float GetSplineLength();
	FVector GetLocationAtDistanceAlongSpline(float Distance);
	FRotator GetRotationAtDistanceAlongSpline(float Distance);

	// 주어진 월드 위치(InWorldLocation)로부터 가장 가까운 Spline Distance 리턴
	float GetDistanceClosestToWorldLocation(const FVector& InWorldLocation) const;
};