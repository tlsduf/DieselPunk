// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Manager/ObjectManager.h"
#include "../Skill/SkillBase.h"
#include "../Skill/SkillNPC/TargetAttack.h"
#include "../UI/HUD/EnemyStatusUI.h"
#include "../Manager/NavigationManager.h"
#include "../Actor/PathRouter.h"
#include "../Core/DPLevelScriptActor.h"

#include <Components/WidgetComponent.h>
#include <AIController.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <NavigationSystem.h>
#include <Navigation/PathFollowingComponent.h>
#include <Engine/Level.h>

#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"


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
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = Stat.GetStat(ECharacterStatType::MoveSpeed);
	
	// SKill Stat Initialize
	if(MeleeAttack != nullptr)
		MeleeAttack->InitSkillStat();

	if(ProjectileAttack != nullptr)
		ProjectileAttack->InitSkillStat();

	if(TargetAttack != nullptr)
		TargetAttack->InitSkillStat();
	
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
		SetEnemyTarget();
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
	if(MeleeAttack != nullptr)
		MeleeAttack->AbilityStart();
}

void ACharacterNPC::DoProjectileAttack()
{
	if(ProjectileAttack != nullptr)
		ProjectileAttack->AbilityStart();
}

void ACharacterNPC::DoTargetAttack()
{
	if(TargetAttack != nullptr)
		if(auto TA = Cast<UTargetAttack>(TargetAttack))
			TA->TargetAttack(Target.Get());
}

// =============================================================
// 스폰시 '몬스터'의 Proportion을 설정합니다. // 호출부 : MonsterSpanwer.cpp SpawnMonster()
// =============================================================
void ACharacterNPC::SetProportion(TArray<FVector> inRectanglePoints)
{
	if(inRectanglePoints.IsEmpty())
		return;
	
	// Get distance between (firstPoint-secondPoint)Line and ThirdPoint
	FVector firstPoint, secondPoint, thirdPoint;
	double a, b, c;
				
	firstPoint = inRectanglePoints[0];
	secondPoint = inRectanglePoints[3];
	thirdPoint = GetActorLocation();
	a = firstPoint.Y - secondPoint.Y;
	b = secondPoint.X - firstPoint.X;
	c = firstPoint.X * secondPoint.Y - secondPoint.X * firstPoint.Y;
	float widthDist = abs((a * thirdPoint.X) + (b * thirdPoint.Y) + c) / sqrt((a * a) + (b * b));
				
	Proportion.Width = widthDist / FVector::Dist(inRectanglePoints[0], inRectanglePoints[1]);

	firstPoint = inRectanglePoints[0];
	secondPoint = inRectanglePoints[1];
	thirdPoint = GetActorLocation();
	a = firstPoint.Y - secondPoint.Y;
	b = secondPoint.X - firstPoint.X;
	c = firstPoint.X * secondPoint.Y - secondPoint.X * firstPoint.Y;
	float lengthDist = abs((a * thirdPoint.X) + (b * thirdPoint.Y) + c) / sqrt((a * a) + (b * b));
				
	Proportion.Length = lengthDist / FVector::Dist(inRectanglePoints[0], inRectanglePoints[3]);
}

// =============================================================
// 스폰시 '몬스터'의 TargetArray를 설정합니다. // 호출부 : MonsterSpanwer.cpp SpawnMonster()
// =============================================================
void ACharacterNPC::SetTargetArray(int32 inSpawnerNumber)
{
	auto DPLevelScriptActor = Cast<ADPLevelScriptActor>(GetLevel()->GetLevelScriptActor());
	TArray<int32> PathRouterIDs = DPLevelScriptActor->GetPathRouterIDs();
	// 다른 OriginSpawnerNumber를 가진 경유지 제거
	PathRouterIDs.RemoveAll([inSpawnerNumber](int32 PathRouterID)
	{
		return Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(PathRouterID))->OriginSpawnerNumber != inSpawnerNumber;
	});
	// PathRouterNumber 순으로 정렬
	PathRouterIDs.Sort([](const int32 A, const int32 B)
	{
		return Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(A))->PathRouterNumber
		< Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(B))->PathRouterNumber;
	});
	// TargetArray 설정
	TargetArray.Empty();
	for(const int32 ID : PathRouterIDs)
	{
		TArray<FVector> points = Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(ID))->GetRectanglePoints();
		FVector targetLoc = points[0];
		targetLoc = targetLoc
		+ ( Proportion.Width * (points[1] - points[0]).GetSafeNormal() * FVector::Dist(points[1], points[0]) )
		+ ( Proportion.Length * (points[3] - points[0]).GetSafeNormal() * FVector::Dist(points[3], points[0]) );
		
		TargetArray.Add(targetLoc);
	}
	TargetArray.Add(FObjectManager::GetInstance()->GetNexus()->GetActorLocation());
	
	for(const FVector& targetLoc : TargetArray)
	{
		DrawDebugPoint(GetWorld(), targetLoc, 5, FColor::Red, true);
	}
	for(int i = 0; i < TargetArray.Num(); ++i)
	{
		if(i == TargetArray.Num() - 1)
			continue;
		DrawDebugLine( GetWorld(),TargetArray[i],TargetArray[i + 1], FColor::Magenta, true, -1, 0, 5);
	}
}

// =============================================================
// '몬스터'의 Target을 설정합니다. 
// =============================================================
void ACharacterNPC::SetEnemyTarget()
{
	// ======== Default 타겟은 넥서스
	if(Target == nullptr)
	{
		Target = FObjectManager::GetInstance()->GetNexus();
		TargetLoc =FObjectManager::GetInstance()->GetNexus()->GetActorLocation();
		return;
	}
	
	// ======== (최우선)플레이어가 근처에 있는가 혹은 조건에 일치하는가? 	// 일치한다면 타겟을 플레이어로 지정
	/*if(bIsPlayerNear)
	{
		Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		TargetLocation = UGameplayStatics::GetPlayerPawn(GetWorld(), 0).GetActorLocation();
		return;
	}*/

	// 타겟이 TargetArray[i] 일 때
	// ======== (우선)TargetArray[i]에 도달할 수 없는가? // 타겟을 포탑으로 설정하기위함
	
	// 1. AAIController > PathFollowingComponent > GetPath > GetGoalLocation
	AAIController *AIController = Cast<AAIController>(GetController());
	FVector lastPathPoint = FVector::ZeroVector;
	if(AIController->GetPathFollowingComponent()->GetPath().IsValid())
		lastPathPoint = AIController->GetPathFollowingComponent()->GetPath()->GetGoalLocation();
	// 2. TargetLocation 업데이트
	TargetLoc = TargetArray[TargetLocNum];
	if(FVector::Dist(TargetLoc, GetActorLocation()) < (GetCapsuleComponent()->GetScaledCapsuleRadius() * 2.5))
		TargetLocNum++;
	// 3. lastPathPoint 가 목표 위치와 일치하는가? (z성분 제외)
	bool bCanReach = ( TargetLoc.X == lastPathPoint.X) && ( TargetLoc.Y == lastPathPoint.Y);
	// 4. 목표에 도달할 수 없다면 타겟을 업데이트하지 않음 // UBTTask_BlockedMoveTo에서 Target업데이트
	if(!bCanReach)
		return;
	
	// ======== Default 타겟은 넥서스
	Target = FObjectManager::GetInstance()->GetNexus();
}

bool ACharacterNPC::FindShortestPath(const FVector& InEndLocation)
{
	ShortestPath = FNavigationManager::GetInstance()->PathFinding(GetActorLocation(), InEndLocation, GridSize);
	return !ShortestPath.IsEmpty();
}

bool ACharacterNPC::SetAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath, int InIndex)
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


