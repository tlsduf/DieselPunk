// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NavigationData.h"
#include "Components/SplineComponent.h"
#include "Components/ActorComponent.h"
#include "PathFindingComponent.generated.h"


struct DIESELPUNK_API FSplinePath
{
public:
	FTransform Transform;	// 중심이 될 Transform
	FSplineCurves Path;		// Path Data
	
	static int32 s_ReparamStepsPerSegment;	// Spline path options

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
	
	FVector GetLocationAtDistanceAlongSpline(float Distance);
	FRotator GetRotationAtDistanceAlongSpline(float Distance);
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UPathFindingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(transient)
	TObjectPtr<ANavigationData> MyNavData;	// 경로탐색에 활용되는 NavigationData

	TArray<FVector> MyPathPoints;	// 몬스터의 PathPoint를 담을 배열
	
	FSplinePath SplinePath;			// MyPathPoints를 기반으로 생성된 Curve Spline
	
	// inStartLoc to inEndLoc 경로탐색 // 기존의 경로탐색 로직을 그대로 따라합니다.(아마도)
	FNavPathSharedPtr SearchPathTo(const FVector inStartLoc, const FVector inEndLoc);
	
	// FPathFindingQuery Set
	FPathFindingQuery BuildPathFindingQuery(const FVector inStartLoc, const FVector inEndLoc) const;

public:
	// 전체 경로를 탐색합니다. // 몬스터 스폰시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	void UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray);
	
	// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
	void MakeSplinePath();

	// 스플라인 경로를 따라가게 AddForce 해줍니다.
	void AddForceToSplinePath();

	// 경로 DrawDebug
	void DrawDebugSpline();

public:	
	// Sets default values for this component's properties
	UPathFindingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
