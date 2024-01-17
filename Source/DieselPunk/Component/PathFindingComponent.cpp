// Fill out your copyright notice in the Description page of Project Settings.


#include "PathFindingComponent.h"
#include "../Character/CharacterBase.h"

#include <NavigationSystem.h>

#include "DrawDebugHelpers.h"


//===================================================================
#pragma region FSplinePath
int32 FSplinePath::s_ReparamStepsPerSegment = 10;

// 생성자
FSplinePath::FSplinePath()
	: Transform(FTransform::Identity)
{
}

// Path 유효성 검사
bool FSplinePath::IsValid() const
{
	return Path.GetSplineLength() > 0.0f;
}

// Spline 에 포인트를 추가합니다.
void FSplinePath::AddSplinePoint(const FVector& InPosition, ESplineCoordinateSpace::Type InCoordinateSpace, ESplinePointType::Type InCurveMode)
{
	const FVector TransformedPosition = (InCoordinateSpace == ESplineCoordinateSpace::World) ?
		Transform.InverseTransformPosition(InPosition) : InPosition;

	// Add the spline point at the end of the array, adding 1.0 to the current last input key.
	// This continues the former behavior in which spline points had to be separated by an interval of 1.0.
	const float InKey = Path.Position.Points.Num() ? Path.Position.Points.Last().InVal + 1.0f : 0.0f;

	EInterpCurveMode&& InterpCurveMode = ConvertSplinePointTypeToInterpCurveMode(InCurveMode);

	Path.Position.Points.Emplace(InKey, TransformedPosition, FVector::ZeroVector, FVector::ZeroVector, InterpCurveMode);
	Path.Rotation.Points.Emplace(InKey, FQuat::Identity, FQuat::Identity, FQuat::Identity, InterpCurveMode);
	Path.Scale.Points.Emplace(InKey, FVector(1.0f), FVector::ZeroVector, FVector::ZeroVector, InterpCurveMode);
}

// Spline 의 포인트를 모두 지웁니다.
void FSplinePath::ClearSplinePoints()
{
	Path.Position.Points.Reset();
	Path.Rotation.Points.Reset();
	Path.Scale.Points.Reset();

	UpdateSpline();
}

// Spline의 변경사항을 업데이트합니다.
void FSplinePath::UpdateSpline()
{
	const bool bClosedLoop = false;
	const bool bStationaryEndpoints = false;
	bool bLoopPositionOverride = false;
	float LoopPosition = 0.0f;
	const FVector& Scale3D = FVector(1.0f);

	// leave, arrive tangent가 세팅되도록 Update를 한 번 해줍니다.
	Path.UpdateSpline(bClosedLoop, bStationaryEndpoints, s_ReparamStepsPerSegment, bLoopPositionOverride, LoopPosition, Scale3D);
}

FVector FSplinePath::GetLocationAtDistanceAlongSpline(float Distance)
{
	const float Param = Path.ReparamTable.Eval(Distance, 0.0f);
	
	FVector location =  Path.Position.Eval(Param, FVector::ZeroVector);
	
	location = Transform.TransformPosition(location);
	
	return location;
}

FRotator FSplinePath::GetRotationAtDistanceAlongSpline(float Distance)
{
	const float Param = Path.ReparamTable.Eval(Distance, 0.0f);
	
	FQuat Quat = Path.Rotation.Eval(Param, FQuat::Identity);
	Quat.Normalize();
	
	const FVector Direction = Path.Position.EvalDerivative(Param, FVector::ZeroVector).GetSafeNormal();
	const FVector UpVector = Quat.RotateVector(FVector(0,0,1));
	
	FQuat Rot = (FRotationMatrix::MakeFromXZ(Direction, UpVector)).ToQuat();
	
	Rot = Transform.GetRotation() * Rot;

	return Rot.Rotator();
}

#pragma endregion 
//===================================================================




UPathFindingComponent::UPathFindingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPathFindingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPathFindingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// inStartLoc to inEndLoc 경로탐색 // 기존의 경로탐색 로직을 그대로 따라합니다.(아마도)
FNavPathSharedPtr UPathFindingComponent::SearchPathTo(const FVector inStartLoc, const FVector inEndLoc)
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (NavSys == nullptr)
		return nullptr;
	
	ANavigationData* NavData = Cast<ANavigationData>(NavSys->GetNavDataForActor(*GetOwner()));
	if (NavData == nullptr)
		return nullptr;

	if (!MyNavData && GetWorld() && GetWorld()->GetNavigationSystem())
		MyNavData = NavSys->GetNavDataForProps(Cast<ACharacterBase>(GetOwner())->GetNavAgentPropertiesRef(), GetOwner()->GetActorLocation());

	FPathFindingQuery Query = BuildPathFindingQuery(inStartLoc, inEndLoc);
	
	//Apply cost limit factor
	FSharedConstNavQueryFilter NavQueryFilter = Query.QueryFilter ? Query.QueryFilter : NavData->GetDefaultQueryFilter();
	const float HeuristicScale = NavQueryFilter->GetHeuristicScale();
	float CostLimitFactor = FLT_MAX;
	float MinimumCostLimit = 0.f;
	Query.CostLimit = FPathFindingQuery::ComputeCostLimitFromHeuristic(Query.StartLocation, Query.EndLocation, HeuristicScale, CostLimitFactor, MinimumCostLimit);

	EPathFindingMode::Type Mode = EPathFindingMode::Regular;
	FPathFindingResult Result = NavSys->FindPathSync(Cast<ACharacterBase>(GetOwner())->GetNavAgentPropertiesRef(), Query, Mode);
	
	return Result.Path;
}

// FPathFindingQuery Set
FPathFindingQuery UPathFindingComponent::BuildPathFindingQuery(const FVector inStartLoc, const FVector inEndLoc) const
{
	if (MyNavData)
	{
		constexpr float DefaultCostLimit = FLT_MAX;
		const FNavPathSharedPtr NoSharedPath = nullptr;
		return FPathFindingQuery(this,
			*MyNavData,
			UtilCollision::GetZTrace(inStartLoc, -1).Location,
			UtilCollision::GetZTrace(inEndLoc, -1).Location,
			UNavigationQueryFilter::GetQueryFilter(*MyNavData, this, nullptr),
			NoSharedPath, DefaultCostLimit, true);
	}
	return FPathFindingQuery();
}

// 전체 경로를 탐색하여 Location을 MyPathPoints배열에 담습니다. // 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
void UPathFindingComponent::UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray)
{
	// 경로 초기화
	MyPathPoints.Empty();
	
	// 액터와 첫 목적지 까지의 경로를 담습니다.
	TArray<FNavPathPoint> pathPoints = SearchPathTo(GetOwner()->GetActorLocation(), inGoalLoc)->GetPathPoints();
	for(int i = 0; i < pathPoints.Num(); i++)
	{
		MyPathPoints.Add(pathPoints[i]);
	}

	// 목적지 부터 다음 목적지 까지의 경로를 담습니다.
	int32 index;
	inGoalLocArray.Find(inGoalLoc, index);
	for(int i = index; i < inGoalLocArray.Num() ; i++)
	{
		if(!inGoalLocArray.IsValidIndex(i + 1))
			return;
		TArray<FNavPathPoint> pathPoints1 = SearchPathTo(inGoalLocArray[i], inGoalLocArray[i + 1])->GetPathPoints();
		for(int j = 1; j < pathPoints1.Num(); j++)
		{
			MyPathPoints.Add(pathPoints1[j]);
		}
	}
}

// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
void UPathFindingComponent::MakeSplinePath()
{
	if(MyPathPoints.IsEmpty())
		return;
	
	SplinePath.ClearSplinePoints();
	for(const FVector& pathPoint : MyPathPoints)
	{
		SplinePath.AddSplinePoint(pathPoint, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	}
	SplinePath.UpdateSpline();
}

// 스플라인 경로를 따라가게 AddForce 해줍니다.
void UPathFindingComponent::AddForceToSplinePath()
{
	
}

// 경로 DrawDebug
void UPathFindingComponent::DrawDebugSpline()
{
	if(MyPathPoints.IsEmpty())
		return;
	
	if(!SplinePath.IsValid())
		return;

	// 점과 직선 경로
	if(MyPathPoints.IsValidIndex(0))
	{
		auto beforePoint = MyPathPoints[0];
		DrawDebugPoint(GetWorld(), beforePoint, 25, FColor::Green, false, -1);
		for(auto& point : MyPathPoints)
		{
			DrawDebugLine(GetWorld(),beforePoint, point, FColor::Purple, false, -1);
			DrawDebugPoint(GetWorld(), point, 10, FColor::Purple, false, -1);
			beforePoint = point;
		}
		DrawDebugPoint(GetWorld(), MyPathPoints.Last(), 25, FColor::Blue, false, -1);
	}

	// Spline 경로
	double splineLength = SplinePath.Path.GetSplineLength();
	double sectionLength = 1000.0 / 10;
	int value = static_cast<int>(splineLength / sectionLength);
	for(int i = 0 ; i < value; ++i)
	{
		FVector location = SplinePath.GetLocationAtDistanceAlongSpline(i * sectionLength);
		FRotator rotation = SplinePath.GetRotationAtDistanceAlongSpline(i * sectionLength);
		DrawDebugDirectionalArrow(GetWorld(),
			location - 10 * rotation.Vector(),
			location + 20 * rotation.Vector(),
			10, FColor::Red, false, -1, 0, 3);
	}
}
