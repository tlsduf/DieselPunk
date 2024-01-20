// Fill out your copyright notice in the Description page of Project Settings.


#include "DPNavigationComponent.h"
#include "../Character/CharacterBase.h"
#include "../Character/CharacterNPC.h"
#include "../Character/CharacterTurret.h"
#include "../Manager/ObjectManager.h"

#include <NavigationSystem.h>
#include <DrawDebugHelpers.h>




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

// 주어진 월드 위치(InWorldLocation)로부터 가장 가까운 Spline Distance 리턴
float FSplinePath::GetDistanceClosestToWorldLocation(const FVector& InWorldLocation) const
{
	const FVector LocalLocation = Transform.InverseTransformPosition(InWorldLocation);
	float Dummy;
	float&& InputKey = Path.Position.FindNearest(LocalLocation, Dummy);

	const int32 NumPoints = Path.Position.Points.Num();
	const int32 NumSegments = NumPoints - 1;

	if ((InputKey >= 0) && (InputKey < NumSegments))
	{
		const int32 PointIndex = FMath::FloorToInt(InputKey);
		const float Fraction = InputKey - PointIndex;
		const int32 ReparamPointIndex = PointIndex * s_ReparamStepsPerSegment;
		const float Distance = Path.ReparamTable.Points[ReparamPointIndex].InVal;
		return Distance + Path.GetSegmentLength(PointIndex, Fraction);
	}
	else if (InputKey >= NumSegments)
	{
		return Path.GetSplineLength();
	}

	return 0.0f;
}

#pragma endregion 
//===================================================================




UDPNavigationComponent::UDPNavigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	if(Cast<ACharacterBase>(GetOwner()))
		Owner = Cast<ACharacterBase>(GetOwner());
}

void UDPNavigationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDPNavigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// inStartLoc to inEndLoc 경로탐색 // 기존의 경로탐색 로직을 그대로 따라합니다.(아마도)
FNavPathSharedPtr UDPNavigationComponent::SearchPathTo(const FVector inStartLoc, const FVector inEndLoc)
{
	if(!Owner.IsValid())
		return nullptr;
	
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (NavSys == nullptr)
		return nullptr;
	
	ANavigationData* NavData = Cast<ANavigationData>(NavSys->GetNavDataForActor(*Owner));
	if (NavData == nullptr)
		return nullptr;

	if (!MyNavData && GetWorld() && GetWorld()->GetNavigationSystem())
		MyNavData = NavSys->GetNavDataForProps(Owner->GetNavAgentPropertiesRef(), Owner->GetActorLocation());

	FPathFindingQuery Query = BuildPathFindingQuery(inStartLoc, inEndLoc);
	
	//Apply cost limit factor
	FSharedConstNavQueryFilter NavQueryFilter = Query.QueryFilter ? Query.QueryFilter : NavData->GetDefaultQueryFilter();
	const float HeuristicScale = NavQueryFilter->GetHeuristicScale();
	float CostLimitFactor = FLT_MAX;
	float MinimumCostLimit = 0.f;
	Query.CostLimit = FPathFindingQuery::ComputeCostLimitFromHeuristic(Query.StartLocation, Query.EndLocation, HeuristicScale, CostLimitFactor, MinimumCostLimit);

	EPathFindingMode::Type Mode = EPathFindingMode::Regular;
	FPathFindingResult Result = NavSys->FindPathSync(Owner->GetNavAgentPropertiesRef(), Query, Mode);
	
	return Result.Path;
}

// FPathFindingQuery Set
FPathFindingQuery UDPNavigationComponent::BuildPathFindingQuery(const FVector inStartLoc, const FVector inEndLoc) const
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
void UDPNavigationComponent::UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray)
{
	if(!Owner.IsValid())
		return;
	
	// 경로 초기화
	MyPathPoints.Empty();
	
	// 액터와 첫 목적지 까지의 경로를 담습니다.
	TArray<FNavPathPoint> pathPoints = SearchPathTo(Owner->GetActorLocation(), inGoalLoc)->GetPathPoints();
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

// 생성된 경로(곡선경로 아님 MyPathPoints) 위에 포탑이 있는지 확인합니다.
// 포탑이 있다면, 경로의 주인(몬스터)와 가장 가까운 포탑의 ID를 반환하고,
// MyPathPoints를 포탑이 최종목적지가 되도록 포탑의 위치를 추가하고, 뒤의 value들을 제거합니다.
// index 0부터 순차적으로 탐색하고, 첫 포탑 반환시 탐색을 종료합니다.
int32 UDPNavigationComponent::GetTurretIdOnPath()
{
	int32 turretID = FObjectManager::INVALID_OBJECTID;
	
	if(MyPathPoints.IsEmpty())
		return turretID;
	
	TArray<FHitResult> hit;
	FCollisionQueryParams params;

	// 모든 몬스터들을 IgnoredActor에 등록합니다.
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->NPCType == ENPCType::Enemy)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
	{
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	}

	// 순차적으로 점과 점 사이를 검사합니다.
	for(int32 i = 0 ; i < (MyPathPoints.Num() - 1) ; i++)
	{
		FVector startPoint = MyPathPoints[i] + FVector(0,0,100);
		FVector endPoint = MyPathPoints[i+1] + FVector(0,0,100);
		// Warning 터렛이 탐색이 안 될 경우 트레이스채널 확인
		bool hasHit = GetWorld()->LineTraceMultiByChannel(hit, startPoint, endPoint, ECollisionChannel::ECC_EngineTraceChannel5, params);
		if(hasHit)
		{
			TArray<int32> turretIDs;
			for(const FHitResult& hitResult : hit)
			{
				// 탑색된 액터가 터렛이라면 turretIDs 등록
				if(auto turret = Cast<ACharacterTurret>(hitResult.GetActor()))
					turretIDs.Add(turret->GetObjectId());
			}
			if(!turretIDs.IsEmpty())
			{
				// turretArray 의 value 중 Owner의 위치와 가장 가까운 turret 반환
				turretID = FObjectManager::GetInstance()->GetNearestACtorByRangeAndIds(Owner->GetActorLocation(), turretIDs);
				// MyPathPoints 의 i+1의 인덱스부터 끝 인덱스까지 삭제
				int32 num = MyPathPoints.Num();
				for(int32 j = i+1 ; j < num ; j++)
				{
					MyPathPoints.RemoveAt(i+1);
				}
				// turret 위치를 MyPathPoints에 추가
				MyPathPoints.Add(FObjectManager::GetInstance()->FindActor(turretID)->GetActorLocation());
				// for문 종료
				break;
			}
		}
	}
	return turretID;
}

// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
void UDPNavigationComponent::MakeSplinePath()
{
	if(MyPathPoints.IsEmpty())
		return;

	// MyPathPoints 배열에 담긴 Loc 정보로 SplinePath를 구성합니다.
	SplinePath.ClearSplinePoints();
	for(const FVector& pathPoint : MyPathPoints)
	{
		SplinePath.AddSplinePoint(pathPoint, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	}
	SplinePath.UpdateSpline();

	// Set clamp tangent
	FSplineCurves& path = SplinePath.Path;
	int32&& numPoints = path.Position.Points.Num();
	for (int32 pointIdx = 0; pointIdx < numPoints; ++pointIdx)
	{
		const FVector& currentPointLoc = path.Position.Points[pointIdx].OutVal;

		// clamp leave tangent
		const int32 nextPointIndex = pointIdx + 1;
		if (nextPointIndex < numPoints)
		{
			const FVector& nextPointLoc = path.Position.Points[nextPointIndex].OutVal;
			const float distToNext = FVector::Distance(nextPointLoc, currentPointLoc);
			path.Position.Points[pointIdx].LeaveTangent = path.Position.Points[pointIdx].LeaveTangent.GetClampedToMaxSize(distToNext);
		}
		
		// clamp arrive tangent
		const int32 prevPointIndex = pointIdx - 1;
		if (prevPointIndex >= 0)
		{
			const FVector& prevPointLoc = path.Position.Points[prevPointIndex].OutVal;
			const float distToPrev = FVector::Distance(prevPointLoc, currentPointLoc);
			path.Position.Points[pointIdx].ArriveTangent = path.Position.Points[pointIdx].ArriveTangent.GetClampedToMaxSize(distToPrev);
		}
		
		path.Position.Points[pointIdx].InterpMode = CIM_CurveUser;
	}
	SplinePath.UpdateSpline();
}

// 스플라인 경로를 따라가게 AddForce 해줍니다.
void UDPNavigationComponent::AddForceAlongSplinePath()
{
	if(!Owner.IsValid())
		return;

	if(!SplinePath.IsValid())
		return;
	
	float distOwnerToSplinePath = SplinePath.GetDistanceClosestToWorldLocation(Owner->GetActorLocation());
	FVector nearestSplineLocation = SplinePath.GetLocationAtDistanceAlongSpline(distOwnerToSplinePath);
	FRotator nearestSplineRotation = SplinePath.GetRotationAtDistanceAlongSpline(distOwnerToSplinePath);

	FVector toSplineDir = (nearestSplineLocation - Owner->GetActorLocation()).GetSafeNormal();
	
	FVector addForceDir = nearestSplineRotation.Vector().GetSafeNormal();
	
	if( 10 < FVector::Dist(nearestSplineLocation, Owner->GetActorLocation()) )
		addForceDir = (addForceDir + toSplineDir).GetSafeNormal();
		
	Owner->AddMovementInput(addForceDir, 100);
}

// 경로 DrawDebug
void UDPNavigationComponent::DrawDebugSpline()
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
