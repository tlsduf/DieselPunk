// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Manager/ObjectManager.h"
#include "../Skill/SkillBase.h"
#include "../Skill/SkillNPC/TargetAttack.h"
#include "../UI/HUD/EnemyStatusUI.h"
#include "../Manager/NavigationManager.h"
#include "..\Component\DPNavigationComponent.h"

#include <Components/WidgetComponent.h>
#include <AIController.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <NavigationSystem.h>

#include "DrawDebugHelpers.h"


// =============================================================
// 생성자
// =============================================================
ACharacterNPC::ACharacterNPC()
{
	// AI possess
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// ActorComponent
	MeleeAttack = CreateDefaultSubobject<USkillBase>(TEXT("MeleeAttack"));
	ProjectileAttack = CreateDefaultSubobject<USkillBase>(TEXT("ProjectileAttack"));
	TargetAttack = CreateDefaultSubobject<USkillBase>(TEXT("TargetAttack"));

	DPNavigationComponent = CreateDefaultSubobject<UDPNavigationComponent>(TEXT("PathFindingComponent"));
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Monster;

	GetCharacterMovement()->MaxWalkSpeed = Stat.GetStat(ECharacterStatType::MoveSpeed);
	
	// SKill Stat Initialize
	if(MeleeAttack != nullptr)
		MeleeAttack->InitSkill();

	if(ProjectileAttack != nullptr)
		ProjectileAttack->InitSkill();

	if(TargetAttack != nullptr)
		TargetAttack->InitSkill();
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

	//공격 대상이 사라졌다면 nullptr로 초기화
	if(!Target.IsValid())
		Target = nullptr;

	// 타겟 업데이트
	if(NPCType == ENPCType::Enemy)
	{
		UpdateEnemyTarget();
		UpdateEnemyGoalLoc();
		
		// 몬스터와 목표의 거리에 따른 조건 설정
		//float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 200;
		if(Target.IsValid())
		{
			FVector VRange = GetActorLocation() - GetAttackTarget()->GetActorLocation();
			float FRange = VRange.Size();
			InRange = (GetStat().GetStat(ECharacterStatType::AttackRange) < FRange) ? false : true;
		}
		else
			InRange = false;
		
		if(DPNavigationComponent != nullptr)
		{
			if(!InRange)
				DPNavigationComponent->AddForceAlongSplinePath();
			if(DebugOnOff)
				DPNavigationComponent->DrawDebugSpline();
		}

		if(DebugOnOff)
			DrawDebugPoint(GetWorld(), GetNowGoalLoc(), 30, FColor::Orange, false);
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
		GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->WidgetComp->bHiddenInGame = 1;
			},10.0f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 10초 후에 EnemyStatusUI를 화면에서 제거합니다.(SetHidden)
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
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
// 스폰시 '몬스터'의 GoalArray를 설정합니다.
// =============================================================
TArray<FVector> ACharacterNPC::GetGoalLocArrayFromRoutingLines()
{
	TArray<FVector> goalLocArray;
	for(auto& routingLine : RoutingLines)
	{
		goalLocArray.Add(routingLine.Key);
	}
	return goalLocArray;
}

// =============================================================
// '몬스터'의 Target을 설정합니다.
// =============================================================
void ACharacterNPC::UpdateEnemyTarget()
{
	// (최우선)플레이어가 근처에 있는가 혹은 조건에 일치하는가? 	// 일치한다면 타겟을 플레이어로 지정
	/*if(bIsPlayerNear)
	{
		Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		TargetLocation = UGameplayStatics::GetPlayerPawn(GetWorld(), 0).GetActorLocation();
		return;
	}*/

	// (우선) 터렛에 의해 길이 막혔는가? // 타겟을 터렛으로 설정
	// TargetedTurretID가 유효한 값일 경우
	if(TargetedTurretID != FObjectManager::INVALID_OBJECTID)
	{
		// TargetedTurretID의 액터가 유효한 경우
		if(FObjectManager::GetInstance()->FindActor(TargetedTurretID) != nullptr)
		{
			// 타겟을 해당 터렛으로 설정
			Target = FObjectManager::GetInstance()->FindActor(TargetedTurretID);
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
		Target = nullptr;
		return;
	}
	
	float distance = FVector::Dist(GetActorLocation(), nexus->GetActorLocation());
	if(distance > GetStat().GetStat(ECharacterStatType::AttackRange))
		Target = nullptr;
	else
	{
		UpdateSplinePath();
		Target = nexus;
	}
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
// self와 선분사이의 거리를 반환합니다. (z축 무시)
// =============================================================
float ACharacterNPC::DistanceSegmentToSelf(FVector inStart, FVector inEnd)
{
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
// '몬스터'의 GoalLoc를 갱신합니다. // GoalLoc는 경유지점입니다.
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
	ShortestPath = FNavigationManager::GetInstance()->PathFinding(GetActorLocation(), InEndLocation, GridSize);
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
	if(NPCType != ENPCType::Enemy)
		return;
	if(DPNavigationComponent == nullptr)
		return;

	// 내비메쉬 업데이트가 FindPathSync호출 보다 느려서 간격을 두고 호출합니다.
	TWeakObjectPtr<ACharacterNPC> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->_UpdateSplinePath();
		},0.075f, false);
}

void ACharacterNPC::_UpdateSplinePath()
{
	UpdateEnemyGoalLoc();
	DPNavigationComponent->UpdatePath(NowGoalLoc, GetGoalLocArrayFromRoutingLines());
	TargetedTurretID = DPNavigationComponent->GetTurretIdOnPath();
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
