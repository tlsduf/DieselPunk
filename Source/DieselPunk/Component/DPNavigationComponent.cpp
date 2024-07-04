// Fill out your copyright notice in the Description page of Project Settings.


#include "DPNavigationComponent.h"
#include "../Character/CharacterBase.h"
#include "../Character/CharacterNPC.h"
#include "../Character/CharacterTurret.h"
#include "../Manager/ObjectManager.h"
#include "../Util/SplineConstructor.h"

#include <NavigationSystem.h>
#include <DrawDebugHelpers.h>
#include <Components/CapsuleComponent.h>


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
FNavPathSharedPtr UDPNavigationComponent::SearchPathTo(const FVector& inStartLoc, const FVector& inEndLoc)
{
	if(!Owner.IsValid())
		return nullptr;
	
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (NavSys == nullptr)
		return nullptr;

	// 내비게이션 리빌드
	//NavSys->Build();

	// 커스텀 에이전트 설정을 위한 NavAgentPropertiesRef 변수를 추가합니다. // 에이전트 반경을 설정합니다.
	FNavAgentProperties CustomNavAgentProperties = Owner->GetNavAgentPropertiesRef();
	//CustomNavAgentProperties.AgentRadius = Owner->GetCharacterRadius();

	// ANavigationData를 커스텀 에이전트 속성으로 가져옵니다.
	ANavigationData* NavData = Cast<ANavigationData>(NavSys->GetNavDataForProps(CustomNavAgentProperties, Owner->GetActorLocation()));
	if (NavData == nullptr)
		return nullptr;

	if (!MyNavData && GetWorld() && GetWorld()->GetNavigationSystem())
		MyNavData = NavSys->GetNavDataForProps(CustomNavAgentProperties, Owner->GetActorLocation());

	FPathFindingQuery Query = BuildPathFindingQuery(inStartLoc, inEndLoc);
	
	//Apply cost limit factor
	FSharedConstNavQueryFilter NavQueryFilter = Query.QueryFilter ? Query.QueryFilter : NavData->GetDefaultQueryFilter();
	const float HeuristicScale = NavQueryFilter->GetHeuristicScale();
	float CostLimitFactor = FLT_MAX;
	float MinimumCostLimit = 0.f;
	Query.CostLimit = FPathFindingQuery::ComputeCostLimitFromHeuristic(Query.StartLocation, Query.EndLocation, HeuristicScale, CostLimitFactor, MinimumCostLimit);

	EPathFindingMode::Type Mode = EPathFindingMode::Regular;
	FPathFindingResult Result = NavSys->FindPathSync(CustomNavAgentProperties, Query, Mode);
	
	return Result.Path;
}

// FPathFindingQuery Set
FPathFindingQuery UDPNavigationComponent::BuildPathFindingQuery(const FVector& inStartLoc, const FVector& inEndLoc) const
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

// 전체 경로를 탐색하여 Location을 MyPathPoints배열에 담습니다. // 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Player에서 다른액터로 업데이트될 때 호출합니다.
int32 UDPNavigationComponent::UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray)
{
	/*
	 * 전체과정
	 * 0 경로 초기화
	 * 1 처음 도달할 목적지 이전의 목적지를 제거합니다.
	 * 2 목적지와 다음목적지 사이에 포탑이 설치된 경우 두 목적지를 제거 합니다. // SweepMulti by Sphere
	 * 3 목적지 위에 포탑이 설치 되어 있을 경우, 해당 목적지를 제거합니다.
	 * 4 액터와 첫 목적지 까지의 경로를 담습니다.
	 * 5 목적지 부터 다음 목적지 까지의 경로를 담습니다.
	 * 6 경로를 탐색하여 경로위에 포탑이 있다면(길이막혔다고 판단), 해당 포탑의 ID를 반환하고 뒤의 경로를 제거하고 포탑의 위치를 경로에 추가합니다.
	 */

	int32 BlockedTurretID = FObjectManager::INVALID_OBJECTID;
	
	if(!Owner.IsValid())
		return BlockedTurretID;

	//=========================================================================
	// 0 경로 초기화
	MyPathPoints.Empty();

	//=========================================================================
	// 1 처음 도달할 목적지 이전의 목적지를 제거합니다.
	int32 index;
	TArray<FVector> goalLocArray = inGoalLocArray;
	goalLocArray.Find(inGoalLoc, index);
	for(int i = 0; i < index ; i++)
	{
		if(goalLocArray.IsValidIndex(0))
			goalLocArray.RemoveAt(0);
	}

	//=========================================================================
	// 목적지가 없다면 더 이상 연산하지 않습니다.
	if(goalLocArray.IsEmpty())
		return BlockedTurretID;

	//=========================================================================
	// 포탑만을 감지하기 위한 FCollisionQueryParams
	// 모든 몬스터들을 IgnoredActor에 등록합니다. // 플레이어와 Nexus를 IgnoredActor에 등록합니다.
	FCollisionQueryParams params;
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->GetNPCType() == ENPCType::Enemy)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetPlayer());
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetNexus());
	
	//=========================================================================
	// 2 목적지와 다음목적지 사이에 포탑이 설치된 경우 두 목적지를 제거 합니다. // SweepMulti by Sphere(r = CapsuleRadius)
	TArray<FVector> removeVector;	// 제거대상이 된 목적지 배열
	TArray<FHitResult> hits;
	// owner의 현재위치와 첫 목적지 까지 트레이스 // 포탑이 있다면 목적지를 removeVector에 Add
	hits.Empty();
	if(	GetWorld()->SweepMultiByChannel(hits, Owner->GetActorLocation(), goalLocArray[0] + FVector(0, 0, 50),
		FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel6, FCollisionShape::MakeSphere(Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params))
		removeVector.AddUnique(goalLocArray[0]);
	// 목적지 to 다음목적지 트레이스 // 포탑이 있다면 목적지를 removeVector에 Add
	hits.Empty();
	for(int32 i = 0 ; i < goalLocArray.Num() - 2 ; i++)
	{
		if(!GetWorld()->SweepMultiByChannel(hits, goalLocArray[i] + FVector(0, 0, 50), goalLocArray[i + 1] + FVector(0, 0, 50),
			FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel6, FCollisionShape::MakeSphere(Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params))
			continue;
		removeVector.AddUnique(goalLocArray[i]);
		removeVector.AddUnique(goalLocArray[i + 1]);
	}
	// 제거해야 할 목적지Key들을 제거합니다.
	if(!removeVector.IsEmpty())
		for(const FVector& vectorKey : removeVector)
			goalLocArray.Remove(vectorKey);

	//=========================================================================
	// 3 목적지 위에 포탑이 설치 되어 있을 경우, 해당 목적지를 제거(Remove)합니다.
	TWeakObjectPtr<UDPNavigationComponent> thisPtr = this;
	goalLocArray.RemoveAll([thisPtr, params](FVector goalLoc)
	{
		if(!thisPtr.IsValid())
			return true;
		
		TArray<FHitResult> hits;
		if(thisPtr->GetWorld()->SweepMultiByChannel(hits, goalLoc, goalLoc + FVector(0,0,300),
			FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel6, FCollisionShape::MakeSphere(thisPtr->Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params))
			return true;
		return false;
	});

	//=========================================================================
	// 목적지가 없다면 더 이상 연산하지 않습니다.
	if(!goalLocArray.IsValidIndex(0))
		return BlockedTurretID;
	
	//=========================================================================
	// 4 액터와 첫 목적지 까지의 경로를 담습니다.
	if(goalLocArray.IsValidIndex(0))
	{
		TArray<FNavPathPoint> pathPoints = SearchPathTo(Owner->GetActorLocation(), goalLocArray[0])->GetPathPoints();
		if(pathPoints.IsValidIndex(0))
		{
			for(int i = 0; i < pathPoints.Num(); i++)
				MyPathPoints.Add(pathPoints[i]);
		}
	}

	//=========================================================================
	// 5 목적지 부터 다음 목적지 까지의 경로를 담습니다.a
	for(int i = 0; i < goalLocArray.Num() ; i++)
	{
		if(!goalLocArray.IsValidIndex(i + 1))
			break;
		TArray<FNavPathPoint> pathPoints1 = SearchPathTo(goalLocArray[i], goalLocArray[i + 1])->GetPathPoints();
		for(int j = 1; j < pathPoints1.Num(); j++)
			MyPathPoints.Add(pathPoints1[j]);
	}

	//=========================================================================
	// 6 경로를 탐색하여 경로위에 포탑이 있다면(길이막혔다고 판단), 해당 포탑의 ID를 반환하고 뒤의 경로를 제거하고 포탑의 위치를 경로에 추가합니다.
	BlockedTurretID =  GetTurretIdOnPath();
	return BlockedTurretID;
}


// 경로위에 포탑이 있다면 해당 포탑의 ID를 반환합니다.
int32 UDPNavigationComponent::GetTurretIdOnPath()
{
	// 0 MyPathPoints 의 index 0부터 순차적으로 탐색하고, 첫 포탑 감지 시 탐색을 종료합니다.
	// 1 생성된 경로(곡선경로 아님 MyPathPoints) 위에 포탑이 있는지 확인합니다.
	// 2 포탑이 있다면 포탑의 ID를 반환할 수 있게 turretID 값을 업데이트합니다.
	// 3 MyPathPoints를 포탑이 최종목적지가 되게 설정: 뒤의 value들을 제거하고 포탑의 위치를 추가합니다.
	
	int32 BlockedTurretID = FObjectManager::INVALID_OBJECTID;
	
	if(MyPathPoints.IsEmpty())
		return BlockedTurretID;
	
	TArray<FHitResult> hits;
	// 포탑만을 감지하기 위한 FCollisionQueryParams
	// 모든 몬스터들을 IgnoredActor에 등록합니다. // 플레이어와 Nexus를 IgnoredActor에 등록합니다.
	FCollisionQueryParams params;
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->GetNPCType() == ENPCType::Enemy)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetPlayer());
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetNexus());
	
	// 순차적으로 점과 점 사이를 검사합니다.
	for(int32 i = 0 ; i < (MyPathPoints.Num() - 1) ; i++)
	{
		// Warning 터렛이 탐색이 안 될 경우 트레이스채널 확인
		// Warning 부하가 될 수 있음
		bool hasHit = GetWorld()->SweepMultiByChannel(hits, MyPathPoints[i] + FVector(0,0,100), MyPathPoints[i+1] + FVector(0,0,100),
			FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel6, FCollisionShape::MakeSphere(Owner->GetCapsuleComponent()->GetScaledCapsuleRadius()), params);
		if(!hasHit)
			continue;

		// 탐색된 액터(터렛)의 ObjectID를 turretID에 전달
		if(ACharacterTurret* turret = Cast<ACharacterTurret>(hits[hits.Num() - 1].GetActor()))
			BlockedTurretID = (turret->GetObjectId());
		// MyPathPoints 의 i+1의 Key부터 끝 까지 삭제
		int32 num = MyPathPoints.Num();
		for(int32 j = i+1 ; j < num ; j++)
			MyPathPoints.RemoveAt(i+1);
		// turret 위치를 MyPathPoints에 추가
		MyPathPoints.Add(FObjectManager::GetInstance()->FindActor(BlockedTurretID)->GetActorLocation());
		// 포탑이 감지 되었으므로 for문 종료
		break;
	}
	return BlockedTurretID;
}

// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
void UDPNavigationComponent::MakeSplinePath()
{
	if(MyPathPoints.IsEmpty())
		return;

	// MyPathPoints 배열에 담긴 Loc 정보로 SplinePath를 구성합니다.
	SplinePath.ClearSplinePoints();
	for(const FVector& pathPoint : MyPathPoints)
		SplinePath.AddSplinePoint(pathPoint, ESplineCoordinateSpace::World, ESplinePointType::Curve);
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
void UDPNavigationComponent::AddForceAlongSplinePath()
{
	if(!Owner.IsValid())
		return;
	
	if(!SplinePath.IsValid())
		return;
	
	FVector nearestSplineLocation;	// 가장 가까운 스플라인 점의 위치
	FRotator nearestSplineRotation;	// 가장 가까운 스플라인 점의 방향
	FVector toSplineDir;			// 가장 가까운 스플라인 점을 향한 벡터
	FVector addForceDir;			// 스플라인 위에 있을 때는 nearestSplineRotation를, 스플라인과 멀어졌을 때는 toSplineDir과 합성한 벡터를 반환

	FVector feetLocation = FVector(Owner->GetActorLocation().X, Owner->GetActorLocation().Y, Owner->GetActorLocation().Z - Owner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight());
	float distOwnerToSplinePath = SplinePath.GetDistanceClosestToWorldLocation(feetLocation);
	nearestSplineLocation = SplinePath.GetLocationAtDistanceAlongSpline(distOwnerToSplinePath);
	nearestSplineRotation = SplinePath.GetRotationAtDistanceAlongSpline(distOwnerToSplinePath);

	toSplineDir = (nearestSplineLocation - feetLocation);
	toSplineDir = FVector(toSplineDir.X, toSplineDir.Y, 0).GetSafeNormal();
	addForceDir = nearestSplineRotation.Vector();
	addForceDir = FVector(addForceDir.X, addForceDir.Y, 0).GetSafeNormal();
	
	if( 50 < FVector::Dist(nearestSplineLocation, feetLocation) )
		addForceDir = (addForceDir + toSplineDir).GetSafeNormal();

	ForceDirection = addForceDir;

	constexpr int scaleValue = 100;
	Owner->AddMovementInput(addForceDir, scaleValue);

	if(Owner->GetDebugOnOff())
		DrawDebugDirectionalArrow(GetWorld(), Owner->GetActorLocation(), Owner->GetActorLocation() + addForceDir * 200, 5, FColor::Red, false);
}

FVector UDPNavigationComponent::MoveToAlongSplinePath()
{
	if(!Owner.IsValid())
		return FVector::ZeroVector;
	
	if(!SplinePath.IsValid())
		return Owner->GetActorLocation();

	FVector nearestSplineLocation;	// 가장 가까운 스플라인 점의 위치
	FRotator nearestSplineRotation;	// 가장 가까운 스플라인 점의 방향
	FVector dest;					// 캐릭터의 Move 목표위치
	FVector feetLocation = FVector(Owner->GetActorLocation().X, Owner->GetActorLocation().Y, Owner->GetActorLocation().Z - Owner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight());
	
	float distOwnerToSplinePath = SplinePath.GetDistanceClosestToWorldLocation(Owner->GetActorLocation());
	nearestSplineLocation = SplinePath.GetLocationAtDistanceAlongSpline(distOwnerToSplinePath);
	nearestSplineRotation = SplinePath.GetRotationAtDistanceAlongSpline(distOwnerToSplinePath);
	dest = nearestSplineLocation + nearestSplineRotation.Vector().GetSafeNormal() * 500;

	if(Owner->GetDebugOnOff())
		DrawDebugLine(GetWorld(), feetLocation, dest, FColor::Black, false);
	
	return dest;
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
			DrawDebugPoint(GetWorld(), point, 10, FColor::Purple, false, -1);
			beforePoint = point;
		}
		DrawDebugPoint(GetWorld(), MyPathPoints.Last(), 25, FColor::Blue, false, -1);
	}

	// Spline 경로
	double splineLength = SplinePath.Path.GetSplineLength();
	constexpr double sectionLength = 100;
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
