// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterMonster.h"

#include "CharacterTurret.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "DieselPunk/Component/DPNavigationComponent.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "..\Component\DPNavigationComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// =============================================================
// 생성자
// =============================================================
ACharacterMonster::ACharacterMonster()
{
	DPNavigationComponent = CreateDefaultSubobject<UDPNavigationComponent>(TEXT("DPNavigationComponent"));
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterMonster::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Monster;
	NPCType = ENPCType::Enemy;

	//StatControlComponent->GetSetStatDelegate().AddUObject(this, &ACharacterMonster)
}

// =============================================================
// Tick
// =============================================================
void ACharacterMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OriginForwardVector = GetActorForwardVector();
	UpdateSplineWhenFarAwayFromSpline(DeltaTime);
}

// =============================================================
// SetupPlayerInputComponent
// =============================================================
void ACharacterMonster::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
}

void ACharacterMonster::SetTarget()
{
	Super::SetTarget();
	// 타겟 업데이트
	UpdateEnemyTarget();	// 몬스터 타겟 업데이트
	SetInRange();	// 타겟 위치에 따른 조건 업데이트
	MakeSearchArea();	// 탐색범위타입이 Rectangle일 경우, 사각형 탐색범위를 생성합니다.
	if(DebugOnOff)
		DrawDebugPoint(GetWorld(), NowGoalLoc, 30, FColor::Orange, false);

	// Navigation
	if(DPNavigationComponent == nullptr)
		return;
	// 몬스터 AddMovementInput
	if(!InRange && !bPlayerTargeting())
	{
		DPNavigationComponent->AddForceAlongSplinePath();
		if(GetCharacterName() == TEXT("E_Mokosh"))
		{
			SetActorRotation(DPNavigationComponent->GetForceDirection().Rotation());
		}
	}
	/*if(!InRange && !bPlayerTargeting())
		if(AIController)
			AIController->MoveToLocation(DPNavigationComponent->MoveToAlongSplinePath(), 1, false, false);*/
	// 경로 Draw
	if(DebugOnOff)
		DPNavigationComponent->DrawDebugSpline();
}

// =============================================================
// '몬스터'의 Target을 설정합니다.
// =============================================================
void ACharacterMonster::UpdateEnemyTarget()
{
	//공격 대상이 사라졌다면 nullptr로 초기화
	if(!Target.IsValid())
		ChangeTarget(nullptr);
	
	// (최우선)플레이어가 조건에 일치하는가? // 일치한다면 타겟을 플레이어로 지정
	if(bPlayerTargeting())
	{
		ChangeTarget(Player);
		return;
	}

	// (우선) 터렛에 의해 길이 막혔는가? // 타겟을 터렛으로 설정
	// TargetedTurretID가 유효한 값일 경우
	if(TargetedTurretID != FObjectManager::INVALID_OBJECTID)
	{
		// TargetedTurretID의 액터가 유효한 경우
		if(FObjectManager::GetInstance()->FindActor(TargetedTurretID) != nullptr)
		{
			// 타겟을 해당 터렛으로 설정
			ChangeTarget(FObjectManager::GetInstance()->FindActor(TargetedTurretID));
			return;
		}
		// TargetedTurretID가 유효하지 않다면 값 리셋
		TargetedTurretID = FObjectManager::INVALID_OBJECTID;
	}
	
	// (최하위) 기본 상태는 Nullptr // 넥서스가 공격범위 안이면 Nexus
	// 넥서스가 조건없이 Target 이면, Target이 Nexus 로 업데이트 되기 전의 데미지 호출에 의해 데미지를 입는 경우가 생김.
	auto nexus = FObjectManager::GetInstance()->GetNexus();
	if(nexus == nullptr)
	{
		ChangeTarget(nullptr);
		return;
	}
	
	float distance = FVector::Dist(GetActorLocation(), nexus->GetActorLocation());
	if(distance > GetStat(ECharacterStatType::AtkMaxRange))
		ChangeTarget(nullptr);
	else
		ChangeTarget(nexus);
}

// =============================================================
// 조건이 맞다면 '몬스터'의 타겟을 플레이어로 설정합니다.
// =============================================================
bool ACharacterMonster::bPlayerTargeting()
{
	if(Player == nullptr)
		return false;

	// DrawDebug
	if(DebugOnOff)
		DrawDebugSearchArea();
	
	FVector playerLoc = Player->GetActorLocation();
	FVector playerLocXY = FVector(playerLoc.X, playerLoc.Y, GetActorLocation().Z);
	
	bool inRange = InValidSearchArea(playerLoc);
	if(!inRange)
		return inRange;
	
	// 플레이와 몬스터 사이에 벽이나 포탑 있는지 탐색
	TArray<FHitResult> hits;
	// 모든 몬스터들을 IgnoredActor에 등록합니다.
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
	
	bool bIsWall = false;
	// y길이가 캡슐반지름*2인 박스로 스윕하여 맵 오브젝트가 있는지 확인. 있으면 true
	FVector boxSize = FVector(1,GetCapsuleComponent()->GetScaledCapsuleRadius(),1);
	if(GetWorld()->SweepMultiByChannel(hits, GetActorLocation(), playerLocXY, FQuat::Identity, ECC_DP_CharacterMultiTrace, FCollisionShape::MakeBox(boxSize), params))
	{
		if(DebugOnOff)
			DrawDebugLine(GetWorld(), GetActorLocation(), playerLoc, FColor::Black, false);
		if(Cast<ACharacterTurret>(hits[hits.Num() - 1].GetActor()))
			bIsWall = true;
		for(const auto& hit : hits)
		{
			if(hit.GetActor()->GetClass()->ImplementsInterface(UDpManagementTargetInterFace::StaticClass()))
				continue;
			bIsWall = true;
		}
	}
	return inRange && !bIsWall;
}

// =============================================================
// 몬스터와 목표의 거리에 따른 조건 설정 // BT 활용
// =============================================================
void ACharacterMonster::SetInRange()
{
	// 몬스터와 목표의 거리에 따른 조건 설정
	//float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 200;
	if(Target.IsValid())
	{
		FVector VRange = GetActorLocation() - GetAttackTarget()->GetActorLocation();
		float FRange = VRange.Size();
		InRange = (GetStat(ECharacterStatType::AtkMaxRange) < FRange) ? false : true;
	}
	else
		InRange = false;
}

// =============================================================
// 몬스터의 RoutingLines배열에 값을 추가합니다.
// =============================================================
void ACharacterMonster::AddEnemyRoutingLines(FVector inGoalLoc, FVector inStart, FVector inEnd)
{
	FRoutingLine routingLine(inStart, inEnd);
	RoutingLines.Add(inGoalLoc, routingLine);

	if(DebugOnOff)
	{
		FVector dir = inEnd - inStart;
		dir.Normalize();
		DrawDebugLine(GetWorld(), inStart + FVector(0,0,50), inEnd - (dir * 600) + FVector(0,0,50), FColor::Cyan, true, -1, 0, 5);
	}
}

// =============================================================
// 스폰시 '몬스터'의 GoalArray를 설정합니다.
// =============================================================
TArray<FVector> ACharacterMonster::GetGoalLocArrayFromRoutingLines()
{
	TArray<FVector> goalLocArray;
	for(auto& routingLine : RoutingLines)
		goalLocArray.Add(routingLine.Key);
	auto nexus = FObjectManager::GetInstance()->GetNexus();
	if(nexus == nullptr)
		goalLocArray.Add(GetActorLocation());
	else
		goalLocArray.Add(nexus->GetActorLocation());
	return goalLocArray;
}

// =============================================================
// self와 선분사이의 거리를 반환합니다. (z축 무시) 
// =============================================================
float ACharacterMonster::DistanceSegmentToSelf(FVector inStart, FVector inEnd)
{
	// 해당 선분은 아래 DrawDebug 라인과 같습니다.
	// DrawDebugLine(GetWorld(), inStart + FVector(0,0,50), inEnd - (dir * 600) + FVector(0,0,50), FColor::Cyan, true, -1, 0, 5);

	FVector2D A = FVector2D(inStart.X, inStart.Y);
	FVector2D B = FVector2D(inEnd.X, inEnd.Y);
	FVector2D P = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	FVector2D dir = B - A;
	dir.Normalize();
	FVector2D B2 = B - (dir * 600);
	
	FVector2D AB2 = B2 - A;
	FVector2D AP = P - A;
	float lengthSqrAB = AB2.X * AB2.X + AB2.Y * AB2.Y;
	float t = (AP.X * AB2.X + AP.Y * AB2.Y) / lengthSqrAB;

	if(t < 0)
		t = 0;
	if(t > 1)
		t = 1;

	FVector2D closestPointOnLine = A + (t * AB2);

	return FVector2D::Distance(P, closestPointOnLine);
}

// =============================================================
// '몬스터'의 GoalLoc를 갱신합니다. // GoalLoc는 도달할 수 있는 가장 가까운(경로상) 경유지점입니다.
// =============================================================
void ACharacterMonster::UpdateEnemyGoalLoc()
{
	if(RoutingLines.IsEmpty())
	{
		NowGoalLoc = GetActorLocation();
		return;
	}

	double dist = MAX_dbl;
	FVector goalLoc;
	for(auto& routingLine : RoutingLines)
	{
		double curDist = DistanceSegmentToSelf(routingLine.Value.Start, routingLine.Value.End);
		if(curDist < dist)
		{
			dist = curDist;
			goalLoc = routingLine.Key;
		}
	}
	NowGoalLoc = goalLoc;
}

// =============================================================
// Curved Spline으로 된 경로를 생성합니다. // 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
// =============================================================
void ACharacterMonster::UpdateSplinePath()
{
	LOG_SCREEN(FColor::Red, TEXT("경로 재탐색"))
	if(NPCType != ENPCType::Enemy)
		return;
	if(DPNavigationComponent == nullptr)
		return;

	// 내비메쉬 업데이트가 FindPathSync호출 보다 느려서 간격을 두고 호출합니다.
	TWeakObjectPtr<ACharacterMonster> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PathTHandle2, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->_UpdateSplinePath();
		},0.2f, false);
}

// 내비메쉬 업데이트가 FindPathSync호출 보다 느려서 간격을 두고 호출합니다.
void ACharacterMonster::_UpdateSplinePath()
{
	__UpdateSplinePath();
	// 길이 막힌 결과가 나오면, 한 번 더 경로를 확인합니다.
	// 내비메쉬 업데이트와 FindPathSync호출이 오차가 있어, 의도하지 않은 결과가 나옴.
	if(TargetedTurretID != FObjectManager::INVALID_OBJECTID)
	{
		TWeakObjectPtr<ACharacterMonster> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(PathTHandle3, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->__UpdateSplinePath();
			},0.2f, false);
	}
}

void ACharacterMonster::__UpdateSplinePath()
{
	UpdateEnemyGoalLoc();
	TargetedTurretID = DPNavigationComponent->UpdatePath(NowGoalLoc, GetGoalLocArrayFromRoutingLines());
	DPNavigationComponent->MakeSplinePath();
}

// 경로에서 멀리 벗어났을 때 1마다 경로를 갱신합니다.(Tick함수)
void ACharacterMonster::UpdateSplineWhenFarAwayFromSpline(float DeltaTime)
{
	if(!DPNavigationComponent->bFarAwayActorToSpline())
		return;
	
	elapsedTime += DeltaTime;
	if(elapsedTime >= 1.f)
	{
		elapsedTime = 0.f;
		UpdateSplinePath();
	}
}

void ACharacterMonster::ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner)
{
	IThrowableInterface::ThrowReady(InThrowingOwner);
	if(AAIController* aiController = Cast<AAIController>(GetController()))
	{
		UBehaviorTreeComponent* btTree = Cast<UBehaviorTreeComponent>(aiController->GetBrainComponent());
		if(btTree)
		{
			CachedBehaviorTree = btTree->GetCurrentTree();
			btTree->StopTree(EBTStopMode::Type::Safe);
		}
	}
	if(UCharacterMovementComponent* charMovementComp = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		charMovementComp->Deactivate();
	}
}

void ACharacterMonster::ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner)
{
	IThrowableInterface::ThrowExecute(InThrowingOwner);
	if(UCharacterMovementComponent* charMovementComp = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		charMovementComp->Activate();
		CachedMass = charMovementComp->Mass;
		charMovementComp->Mass = 1.f;
	}
}

void ACharacterMonster::ThrowComplete()
{
	IThrowableInterface::ThrowComplete();
	if(AAIController* aiController = Cast<AAIController>(GetController()))
	{
		UBehaviorTreeComponent* btTree = Cast<UBehaviorTreeComponent>(aiController->GetBrainComponent());
		if(btTree && CachedBehaviorTree.IsValid())
			btTree->StartTree(*CachedBehaviorTree, EBTExecutionMode::Looped);
	}
	if(UCharacterMovementComponent* charMovementComp = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		charMovementComp->Mass = CachedMass;
	}
}

// Ragdoll Test
void ACharacterMonster::StartRagdollAndDestroy()
{
	GetMesh()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
	
	TWeakObjectPtr<ACharacterMonster> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(DestroyTHandle, [thisPtr](){
	if(thisPtr.IsValid())
		thisPtr->Destroy();
	},5.f, false);
}

