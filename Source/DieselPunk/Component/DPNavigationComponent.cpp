// Fill out your copyright notice in the Description page of Project Settings.


#include "DPNavigationComponent.h"
#include "../Character/CharacterBase.h"
#include "../Character/CharacterNPC.h"
#include "../Character/CharacterTurret.h"
#include "../Manager/ObjectManager.h"
#include "../Util/SplineConstructor.h"

#include <NavigationSystem.h>
#include <DrawDebugHelpers.h>

#include "Components/CapsuleComponent.h"


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

	// 내비게이션 리빌드
	//NavSys->Build();
	
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
			UtilCollision::GetZTrace(GetWorld(), inStartLoc, -1).Location,
			UtilCollision::GetZTrace(GetWorld(), inEndLoc, -1).Location,
			UNavigationQueryFilter::GetQueryFilter(*MyNavData, this, nullptr),
			NoSharedPath, DefaultCostLimit, true);
	}
	return FPathFindingQuery();
}

// 전체 경로를 탐색하여 Location을 MyPathPoints배열에 담습니다. // 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
void UDPNavigationComponent::UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray)
{
	/*
	 * 전체과정
	 * 경로 초기화
	 * 처음 도달할 목적지 이전의 목적지를 제거합니다.
	 * 목적지와 다음목적지 사이에 포탑이 설치된 경우 두 목적지를 제거 합니다. // LineTrace
	 * 목적지 위에 포탑이 설치 되어 있을 경우, 해당 목적지를 제거합니다.
	 * 액터와 첫 목적지 까지의 경로를 담습니다.
	 * 목적지 부터 다음 목적지 까지의 경로를 담습니다.
	 */
	if(!Owner.IsValid())
		return;

	//UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	//if (NavSys != nullptr)
		//NavSys->Build();
	
	// 경로 초기화
	MyPathPoints.Empty();
	
	// 처음 도달할 목적지 이전의 목적지를 제거합니다.
	int32 index;
	TArray<FVector> goalLocArray = inGoalLocArray;
	goalLocArray.Find(inGoalLoc, index);
	for(int i = 0; i < index ; i++)
	{
		goalLocArray.RemoveAt(0);
	}

	// 목적지와 다음목적지 사이에 포탑이 설치된 경우 두 목적지를 제거 합니다. // LineTrace
	TArray<FVector> removeVector;
	for(int32 i = 0 ; i < goalLocArray.Num() - 2 ; i++)
	{
		TArray<FHitResult> hits;
		FCollisionQueryParams params;
		bool hasHit = GetWorld()->LineTraceMultiByChannel(hits, goalLocArray[i] + FVector(0, 0, 50), goalLocArray[i + 1] + FVector(0, 0, 50), ECollisionChannel::ECC_GameTraceChannel5, params);
		if(hasHit)
		{
			bool bTurret = false;
			for(auto hit : hits)
			{
				if(Cast<ACharacterTurret>(hit.GetActor()))
					bTurret = true;
			}
			if(bTurret)
			{
				removeVector.AddUnique(goalLocArray[i]);
				removeVector.AddUnique(goalLocArray[i + 1]);
			}
		}
	}
	if(!removeVector.IsEmpty())
	{
		for(const FVector& vectorKey : removeVector)
		{
			goalLocArray.Remove(vectorKey);
		}
	}
	
	// 목적지 위에 포탑이 설치 되어 있을 경우, 해당 목적지를 제거(Remove)합니다.
	goalLocArray.RemoveAll([this](FVector goalLoc)
	{
		TArray<FHitResult> hits;
		FCollisionQueryParams params;
		bool hasHit = GetWorld()->SweepMultiByChannel(hits, goalLoc, goalLoc + FVector(0,0,300), FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel5, FCollisionShape::MakeSphere(Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params);
		bool bTurret = false;
		if(hasHit)
		{
			for(auto hit : hits)
			{
				if(Cast<ACharacterTurret>(hit.GetActor()))
					bTurret = true;
			}
		}
		return bTurret;
	});

	
	// 액터와 첫 목적지 까지의 경로를 담습니다.
 	TArray<FNavPathPoint> pathPoints = SearchPathTo(Owner->GetActorLocation(), goalLocArray[0])->GetPathPoints();
	for(int i = 0; i < pathPoints.Num(); i++)
	{
		MyPathPoints.Add(pathPoints[i]);
	}
		
	// 목적지 부터 다음 목적지 까지의 경로를 담습니다.
	for(int i = 0; i < goalLocArray.Num() ; i++)
	{
		if(!goalLocArray.IsValidIndex(i + 1))
			break;
		TArray<FNavPathPoint> pathPoints1 = SearchPathTo(goalLocArray[i], goalLocArray[i + 1])->GetPathPoints();
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
	
	TArray<FHitResult> hits;
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
		bool hasHit = GetWorld()->SweepMultiByChannel(hits, startPoint, endPoint, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel5, FCollisionShape::MakeSphere(Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params);
		if(hasHit)
		{
			TArray<int32> turretIDs;
			for(const FHitResult& hitResult : hits)
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

// 스플라인 경로를 따라가게 움직임을 구현 해줍니다.
void UDPNavigationComponent::AddForceAlongSplinePath(float inDeltaTime)
{
	if(!Owner.IsValid())
		return;// FVector::ZeroVector;
	
	if(!SplinePath.IsValid())
		return;// Owner->GetActorLocation();
	
	FVector nearestSplineLocation;	// 가장 가까운 스플라인 점의 위치
	FRotator nearestSplineRotation;	// 가장 가까운 스플라인 점의 방향
	FVector toSplineDir;			// 가장 가까운 스플라인 점을 향한 벡터
	FVector addForceDir;			// 스플라인 위에 있을 때는 nearestSplineRotation를, 스플라인과 멀어졌을 때는 toSplineDir과 합성한 벡터를 반환
	
	// 성능향상을 위해 해당 구문을 인터벌로 호출합니다.
	IntervalDeltaTime += inDeltaTime;
	if(IntervalDeltaTime <= INTERVAL_TIME)
	{
		float distOwnerToSplinePath = SplinePath.GetDistanceClosestToWorldLocation(Owner->GetActorLocation());
		nearestSplineLocation = SplinePath.GetLocationAtDistanceAlongSpline(distOwnerToSplinePath);
		nearestSplineRotation = SplinePath.GetRotationAtDistanceAlongSpline(distOwnerToSplinePath);
		IntervalDeltaTime = 0.f;
	}
	toSplineDir = (nearestSplineLocation - Owner->GetActorLocation()).GetSafeNormal();
	addForceDir = nearestSplineRotation.Vector().GetSafeNormal();
	
	if( 10 < FVector::Dist(nearestSplineLocation, Owner->GetActorLocation()) )
		addForceDir = (addForceDir + toSplineDir).GetSafeNormal();

	constexpr int scaleValue = 100;
	Owner->AddMovementInput(addForceDir, scaleValue);

	//return FVector::ZeroVector;

	/*FVector nearestSplineLocation;	// 가장 가까운 스플라인 점의 위치
	FRotator nearestSplineRotation;	// 가장 가까운 스플라인 점의 방향
	FVector dest;					// 캐릭터의 Move 목표위치
	
	float distOwnerToSplinePath = SplinePath.GetDistanceClosestToWorldLocation(Owner->GetActorLocation());
	nearestSplineLocation = SplinePath.GetLocationAtDistanceAlongSpline(distOwnerToSplinePath);
	nearestSplineRotation = SplinePath.GetRotationAtDistanceAlongSpline(distOwnerToSplinePath);
	dest = nearestSplineLocation + nearestSplineRotation.Vector().GetSafeNormal() * 500;
	
	return dest;*/
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
			//DrawDebugLine(GetWorld(),beforePoint, point, FColor::Purple, false, -1);
			DrawDebugPoint(GetWorld(), point, 10, FColor::Purple, false, -1);
			beforePoint = point;
		}
		DrawDebugPoint(GetWorld(), MyPathPoints.Last(), 25, FColor::Blue, false, -1);
	}

	// Spline 경로
	double splineLength = SplinePath.Path.GetSplineLength();
	const double sectionLength = 100;
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

	// dest 위치
	//DrawDebugPoint(GetWorld(), AddForceAlongSplinePath(), 25, FColor::Black, false, -1);
}
