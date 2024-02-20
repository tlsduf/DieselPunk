// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Manager/ObjectManager.h"
#include "../Skill/SkillBase.h"
#include "../UI/HUD/EnemyStatusUI.h"
#include "../Manager/NavigationManager.h"
#include "..\Component\DPNavigationComponent.h"
#include "../Character/CharacterTurret.h"

#include <Components/WidgetComponent.h>
#include <AIController.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <NavigationSystem.h>
#include <DrawDebugHelpers.h>
#include <Kismet/GameplayStatics.h>
#include <Components/CapsuleComponent.h>


// =============================================================
// 생성자
// =============================================================
ACharacterNPC::ACharacterNPC()
{
	// AI possess
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	DPNavigationComponent = CreateDefaultSubobject<UDPNavigationComponent>(TEXT("PathFindingComponent"));
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Monster;

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	// Stat Init
	GetCharacterMovement()->MaxWalkSpeed = Stat.GetStat(ECharacterStatType::MoveSpeed);

	if(NPCType == ENPCType::Enemy)
	{
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(PathTHandle1, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->_UpdateSplinePath();
			},0.5f, false);
	}

	// Skill Instancing , SKill Stat Initialize
	if(MeleeAttackClass)
	{
		MeleeAttack = NewObject<USkillBase>(this, MeleeAttackClass);
		MeleeAttack->RegisterComponent();
		MeleeAttack->InitSkill();
	}

	if(ProjectileAttackClass)
	{
		ProjectileAttack = NewObject<USkillBase>(this, ProjectileAttackClass);
		ProjectileAttack->RegisterComponent();
		ProjectileAttack->InitSkill();
	}

	if(TargetAttackClass)
	{
		TargetAttack = NewObject<USkillBase>(this, TargetAttackClass);
		TargetAttack->RegisterComponent();
		TargetAttack->InitSkill();
	}
}

// =============================================================
// Tick
// =============================================================
void ACharacterNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( EnemyStatusUI != nullptr )
	{
		EnemyStatusUI->SetHPPercent(HpPercent);
		EnemyStatusUI->SetHPPercentAfterImage(HpPercentAfterImage);
	}
	
	if(IsDead())
		WidgetComp->bHiddenInGame = 1;
	
	// 타겟 업데이트
	if(NPCType == ENPCType::Enemy)
	{
		UpdateEnemyTarget();	// 몬스터 타겟 업데이트
		SetInRange();	// 타겟 위치에 따른 조건 업데이트
		if(DebugOnOff)
			DrawDebugPoint(GetWorld(), NowGoalLoc, 30, FColor::Orange, false);

		// Navigation
		if(DPNavigationComponent == nullptr)
			return;
		// 몬스터 AddMovementInput
		if(!InRange && !bPlayerTargeting())
			DPNavigationComponent->AddForceAlongSplinePath();
		/*if(!InRange && !bPlayerTargeting())
			if(AIController)
				AIController->MoveToLocation(DPNavigationComponent->MoveToAlongSplinePath(), 1, false, false);*/
		// 경로 Draw
		if(DebugOnOff)
			DPNavigationComponent->DrawDebugSpline();
	}
}

// =============================================================
// SetupPlayerInputComponent
// =============================================================
void ACharacterNPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterNPC::CreateStatusUI()
{
	if( EnemyStatusUI.IsValid() )
		return;

	FString inPath = UtilPath::GetUIPath( TEXT("NPC_HpBar") );
	UClass* widgetClass = ConstructorHelpersInternal::FindOrLoadClass( inPath, UUserWidget::StaticClass() );
	if(!widgetClass)
		return;
	
	UUserWidget* userWidget = CreateWidget<UUserWidget>( GetWorld(), widgetClass );
	if ( userWidget )
	{
		userWidget->AddToRoot();

		UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( userWidget );
		if ( userWidgetBase )
			userWidgetBase->OnCreated();
	}
	UEnemyStatusUI* myWidget = Cast<UEnemyStatusUI>(userWidget);
	if(myWidget)
		myWidget->RemoveFromRoot();
		
	EnemyStatusUI = myWidget;

	
	if ( !WidgetComp || !EnemyStatusUI.IsValid() )
		return;

	WidgetComp->SetWidget( EnemyStatusUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );
	WidgetComp->bHiddenInGame = 1;
	
	EnemyStatusUI->SetHPPercent(HpPercent);
	EnemyStatusUI->SetHPPercentAfterImage(HpPercentAfterImage);
}

// =============================================================
// UI 컨트롤 하기 위한 오버라이드
// =============================================================
float ACharacterNPC::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,AActor* DamageCauser)
{
	HandleStatusUI();
	
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

// =============================================================
// UI 타이머 컨트롤
// =============================================================
void ACharacterNPC::HandleStatusUI()
{
	WidgetComp->bHiddenInGame = 0;

	// 만약 타이머가 이미 실행 중이면, 타이머를 초기화하고 재설정합니다.
	if (GetWorldTimerManager().IsTimerActive(EnemyStatusUITHandle))
	{
		GetWorldTimerManager().ClearTimer(EnemyStatusUITHandle);
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(EnemyStatusUITHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->WidgetComp->bHiddenInGame = 1;
			},10.0f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 10초 후에 EnemyStatusUI를 화면에서 제거합니다.(SetHidden)
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(EnemyStatusUITHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->WidgetComp->bHiddenInGame = 1;
			},10.0f, false);
	}
}

// =============================================================
// 몬스터 스킬
// =============================================================
void ACharacterNPC::DoMeleeAttack()
{
	//if(MeleeAttack != nullptr)
		//MeleeAttack->AbilityStart();
}

void ACharacterNPC::DoProjectileAttack()
{
	if(ProjectileAttack != nullptr)
		ProjectileAttack->AbilityStart(Target.Get());
}

void ACharacterNPC::DoTargetAttack()
{
	if(TargetAttack != nullptr)
		TargetAttack->AbilityStart(Target.Get());
}

// =============================================================
// '몬스터'의 Target을 설정합니다.
// =============================================================
void ACharacterNPC::UpdateEnemyTarget()
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
	if(distance > GetStat().GetStat(ECharacterStatType::AttackMaxRange))
		ChangeTarget(nullptr);
	else
		ChangeTarget(nexus);
}

// =============================================================
// 타겟을 업데이트하고, 업데이트 조건에 따라 함수를 실행합니다.
// =============================================================
void ACharacterNPC::ChangeTarget(TWeakObjectPtr<AActor> inTarget)
{
	if(inTarget == Target)
		return;

	// 타겟이 플레이어에서 다른 타겟으로 업데이트 되면 경로재설정
	if(Target == Player)
		if(inTarget != Player)
			UpdateSplinePath();
	
	Target = inTarget;
}

// =============================================================
// 조건이 맞다면 '몬스터'의 타겟을 플레이어로 설정합니다.
// =============================================================
bool ACharacterNPC::bPlayerTargeting()
{
	if(Player == nullptr)
		return false;

	FVector playerLoc = Player->GetActorLocation();
	FVector playerLocXY = FVector(playerLoc.X, playerLoc.Y, GetActorLocation().Z);

	const int range = 1500;
	// DrawDebug
	if(DebugOnOff)
	{
		DrawDebugCircleArc(GetWorld(), GetActorLocation(), range, GetActorForwardVector(), 0.523, 8, FColor::Red, false);
		FVector rightVector = (GetActorForwardVector().GetSafeNormal().Rotation() + FRotator(0, 30, 0)).Vector().GetSafeNormal();
		FVector leftVector = (GetActorForwardVector().GetSafeNormal().Rotation() - FRotator(0, 30, 0)).Vector().GetSafeNormal();
		DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + rightVector * range, FColor::Red, false);
		DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + leftVector * range, FColor::Red, false);
	}
	
	// 플레이어가 유효 사거리 안에 위치
	//const int range = 1500;
	bool inRange = FVector::Dist(GetActorLocation(), playerLoc) <= range;
	if(!inRange)
		return inRange;

	// 유효 수직 거리안에 위치
	const int zRange = 300;
	auto zDif = GetActorLocation().Z < playerLoc.Z ? playerLoc.Z - GetActorLocation().Z : GetActorLocation().Z - playerLoc.Z ;
	bool inZRange = zDif <= zRange;
	if(!inZRange)
		return inZRange;
	
	// 플레이어가 유효 각도 안에 위치
	float forwardDir = GetActorForwardVector().GetSafeNormal().Rotation().Yaw;
	float toTargetDir = (playerLocXY - GetActorLocation()).GetSafeNormal().Rotation().Yaw;
	bool inDegree = ( -SearchPlayerDEGREE < (forwardDir - toTargetDir) ) && ( (forwardDir - toTargetDir) < SearchPlayerDEGREE );
	if(!inDegree)
		return inDegree;
	
	// 플레이어가 유효 공간 안에 위치
	// TODO
	
	// 플레이와 몬스터 사이에 벽이나 포탑 있는지 탐색
	TArray<FHitResult> hits;
	// 모든 몬스터들을 IgnoredActor에 등록합니다.
	FCollisionQueryParams params;
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->NPCType == ENPCType::Enemy)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	
	bool bIsWall = false;
	// 캡슐반지름 크기의 구로 스윕하여 맵 오브젝트가 있는지 확인. 있으면 true
	if(GetWorld()->SweepMultiByChannel(hits, GetActorLocation(), playerLoc, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel6, FCollisionShape::MakeSphere(GetCapsuleComponent()->GetScaledCapsuleRadius()), params))
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
	
	return inRange && inZRange && inDegree && !bIsWall;
}

// =============================================================
// 몬스터와 목표의 거리에 따른 조건 설정 // BT 활용
// =============================================================
void ACharacterNPC::SetInRange()
{
	// 몬스터와 목표의 거리에 따른 조건 설정
	//float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 200;
	if(Target.IsValid())
	{
		FVector VRange = GetActorLocation() - GetAttackTarget()->GetActorLocation();
		float FRange = VRange.Size();
		InRange = (GetStat().GetStat(ECharacterStatType::AttackMaxRange) < FRange) ? false : true;
	}
	else
		InRange = false;
}

// =============================================================
// 몬스터의 RoutingLines배열에 값을 추가합니다.
// =============================================================
void ACharacterNPC::AddEnemyRoutingLines(FVector inGoalLoc, FVector inStart, FVector inEnd)
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
TArray<FVector> ACharacterNPC::GetGoalLocArrayFromRoutingLines()
{
	TArray<FVector> goalLocArray;
	for(auto& routingLine : RoutingLines)
		goalLocArray.Add(routingLine.Key);
	return goalLocArray;
}

// =============================================================
// self와 선분사이의 거리를 반환합니다. (z축 무시) 
// =============================================================
float ACharacterNPC::DistanceSegmentToSelf(FVector inStart, FVector inEnd)
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
void ACharacterNPC::UpdateEnemyGoalLoc()
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
// 길이 막혔을 때, 파괴시 진행할 수 있는 포탑의 위치를 찾습니다.
// =============================================================
bool ACharacterNPC::FindShortestPath(const FVector& InEndLocation)
{
	ShortestPath = FNavigationManager::GetInstance()->PathFinding(GetActorLocation(), InEndLocation, GridSizeHorizontal);
	return !ShortestPath.IsEmpty();
}

// =============================================================
// 길이 막혔을 때, '몬스터'의 타겟을 지정합니다.
// =============================================================
bool ACharacterNPC::SetBlockedAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath, int InIndex)
{
	if(InTarget.IsValid() && InTarget != nullptr)
	{
		Target = InTarget;

		//Path중에 네비메쉬 안에 포함되는 지점 등록
		UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
		const FNavAgentProperties& agentProps = GetNavAgentPropertiesRef();
		FNavLocation projectedLocation;
		
		for(int i = 0; i < InIndex; ++i)
		{
			if(navSys && !navSys->ProjectPointToNavigation(InPath[InIndex - i], projectedLocation, INVALID_NAVEXTENT, &agentProps))
				continue;

			BlockedTargetLoc = InPath[InIndex - i];
			break;
		}
		
		return true;
	}
	return false;
}

// =============================================================
// Curved Spline으로 된 경로를 생성합니다. // 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
// =============================================================
void ACharacterNPC::UpdateSplinePath()
{
	LOG_SCREEN(FColor::Red, TEXT("경로 재탐색"))
	if(NPCType != ENPCType::Enemy)
		return;
	if(DPNavigationComponent == nullptr)
		return;

	// 내비메쉬 업데이트가 FindPathSync호출 보다 느려서 간격을 두고 호출합니다.
	TWeakObjectPtr<ACharacterNPC> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PathTHandle2, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->_UpdateSplinePath();
		},0.2f, false);
}

// 내비메쉬 업데이트가 FindPathSync호출 보다 느려서 간격을 두고 호출합니다.
void ACharacterNPC::_UpdateSplinePath()
{
	__UpdateSplinePath();
	// 길이 막힌 결과가 나오면, 한 번 더 경로를 확인합니다.
	// 내비메쉬 업데이트와 FindPathSync호출이 오차가 있어, 의도하지 않은 결과가 나옴.
	if(TargetedTurretID != FObjectManager::INVALID_OBJECTID)
	{
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(PathTHandle3, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->__UpdateSplinePath();
			},0.2f, false);
	}
}

void ACharacterNPC::__UpdateSplinePath()
{
	UpdateEnemyGoalLoc();
	TargetedTurretID = DPNavigationComponent->UpdatePath(NowGoalLoc, GetGoalLocArrayFromRoutingLines());
	DPNavigationComponent->MakeSplinePath();
}

// =============================================================
// Enemy 타입을 가진 모든 NPC들의 경로를 재탐색 합니다.
// =============================================================
void ACharacterNPC::UpdateSplinePathAll()
{
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
		Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(ID))->UpdateSplinePath();
	}
	LOG_SCREEN(FColor::Red, TEXT("모든 적 경로 재탐색"))
}

