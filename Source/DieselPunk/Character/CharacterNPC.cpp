// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Manager/ObjectManager.h"
#include "../Skill/SkillBase.h"
#include "../Skill/SkillNPC/TargetAttack.h"
#include "../UI/HUD/EnemyStatusUI.h"
#include "../Manager/NavigationManager.h"

#include <Components/WidgetComponent.h>
#include <AIController.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <NavigationSystem.h>
#include <Navigation/PathFollowingComponent.h>




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

			BlockedTargetLocation = InPath[InIndex - i];
			break;
		}
		
		return true;
	}
	return false;
}

void ACharacterNPC::SetEnemyTarget()
{
	// Default 타겟은 넥서스
	if(Target == nullptr)
	{
		Target = FObjectManager::GetInstance()->GetNexus();
		return;
	}
	
	// (최우선)플레이어가 근처에 있는가 혹은 조건에 일치하는가? 	// 일치한다면 타겟을 플레이어로 지정
	/*if(bIsPlayerNear)
	{
		Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		return;
	}*/

	// 타겟이 넥서스 일 때
	// (우선)넥서스에 도달할 수 없는가? // 타겟을 포탑으로 설정 //TODO 터렛 설치 시, 한 번 호출
	// AAIController > PathFollowingComponent > GetPath > GetGoalLocation
	/*AAIController *AIController = Cast<AAIController>(GetController());
	FVector lastPathPoint = FVector::ZeroVector;
	if(AIController->GetPathFollowingComponent()->GetPath().IsValid())
		lastPathPoint = AIController->GetPathFollowingComponent()->GetPath()->GetGoalLocation();
	// lastPathPoint 가 넥서스 위치와 일치하는가? (z성분 제외)
	bool bCanReach = ( FObjectManager::GetInstance()->GetNexus()->GetActorLocation().X == lastPathPoint.X) && ( FObjectManager::GetInstance()->GetNexus()->GetActorLocation().Y == lastPathPoint.Y);
	if(!bCanReach)
	{
		//넥서스까지의 최단 경로 탐색(설치물에 방해받지 않고)
		if(!FindShortestPath(FObjectManager::GetInstance()->GetNexus()->GetActorLocation()))
			return;
		const TArray<FVector>& path = GetShortestPath();
		
		//공격 대상 찾기
		AActor* target = nullptr;
		for(int point = 0 ; point < path.Num(); ++point)
		{
			DrawDebugPoint(GetWorld(), path[point], 5, FColor::Blue, false, -1);
			DrawDebugSphere(GetWorld(), Target->GetActorLocation(), 150, 16, FColor::Red, false, -1);
			
			TArray<FOverlapResult> hitResult;
			GetWorld()->OverlapMultiByChannel(hitResult, path[point], FQuat::Identity, ECC_WorldStatic,
						FCollisionShape::MakeSphere(GetGridSize() * FNavigationManager::GridSize));

			for(const FOverlapResult& result : hitResult)
			{
				if(Cast<ACharacterTurret>(result.GetActor()) != nullptr)
				{
					if(SetAttackTarget(result.GetActor(), path, point))
					{
						target = result.GetActor();
						break;
					}
				}
			}
			if(target != nullptr)
				break;
		}
		return;
	}*/

	AAIController *AIController = Cast<AAIController>(GetController());
	FVector lastPathPoint = FVector::ZeroVector;
	if(AIController->GetPathFollowingComponent()->GetPath().IsValid())
		lastPathPoint = AIController->GetPathFollowingComponent()->GetPath()->GetGoalLocation();
	// lastPathPoint 가 넥서스 위치와 일치하는가? (z성분 제외)
	bool bCanReach = ( FObjectManager::GetInstance()->GetNexus()->GetActorLocation().X == lastPathPoint.X) && ( FObjectManager::GetInstance()->GetNexus()->GetActorLocation().Y == lastPathPoint.Y);
	if(!bCanReach)
		return;
	
	// Default 타겟은 넥서스
	Target = FObjectManager::GetInstance()->GetNexus();
}
