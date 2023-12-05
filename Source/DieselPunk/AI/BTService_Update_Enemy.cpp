// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Enemy.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"

#include <Components/CapsuleComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Pawn.h>
#include <AIController.h>
#include <Navigation/PathFollowingComponent.h>


UBTService_Update_Enemy::UBTService_Update_Enemy()
{
    NodeName = "Update_Enemy";
}

void UBTService_Update_Enemy::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
        return;
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController *AIController = OwnerComp.GetAIOwner();
    auto AICharacter = Cast<ACharacterNPC>(AIController->GetPawn());

    
    // 플레이어 위치 업데이트
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());

    // 넥서스 위치 SET // Tick에 있어야 하는가?
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("Nexus"), GetTargetLocation(AICharacter));

    UWorld* world = GetWorld();
    if(world == nullptr)
        return;
	
    //사거리 내에 있는가?
    TWeakObjectPtr<AActor> target = AICharacter->GetAttackTarget();
    FVector dist = FVector::ZeroVector;
    if(target.IsValid())
        dist = target->GetActorLocation() - AICharacter->GetActorLocation();
    else
    {
        target = FObjectManager::GetInstance()->GetNexus();
        if(target == nullptr)
            return;
		
        dist = target->GetActorLocation() - AICharacter->GetActorLocation();
    }
    if(dist.Length() <= AICharacter->GetStat().GetStat(ECharacterStatType::AttackRange))
    {
        //라인트레이싱에 성공했는가
        TArray<FHitResult> hit;
        FVector start = AICharacter->GetActorLocation();
        FVector end = target->GetActorLocation();

        FCollisionQueryParams params;
        params.AddIgnoredActor(AICharacter);
    
        //가장 가까운 라인트레이싱의 액터가 공격 대상인지 확인
        if(world->LineTraceMultiByChannel(hit, start, end, ECollisionChannel::ECC_WorldStatic, params))
        {
            hit.Sort([](const FHitResult& lhs, const FHitResult& rhs)
            {
                return lhs.Distance < rhs.Distance;
            });
    
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), (hit[0].GetActor() == target));
        }
        else
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), false);
    }
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), false);

    

    // 넥서스에 도달 할 수 있는가?
    // lastPathPoint : 마지막 도달가능 위치 // 길이 막혀있거나 못갈 경우 목표에 도달할 수 있는 가장 가까운 PathPoint 위치
    FVector lastPathPoint = FVector::ZeroVector;
    if(AIController->GetPathFollowingComponent()->GetPath().IsValid())
        lastPathPoint = AIController->GetPathFollowingComponent()->GetPath()->GetGoalLocation();
    if((GetTargetLocation(AICharacter).X == lastPathPoint.X) && (GetTargetLocation(AICharacter).Y == lastPathPoint.Y))
    {
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, FString::Printf(TEXT("canG%f"), 0.0f));
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, FString::Printf(TEXT("Nexus %s"), *GetNexusLocation().ToString()));
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, FString::Printf(TEXT("lastLoc %s"), *lastPathPoint.ToString()));
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("bCanReach"), true);
    }
    else
    {
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, FString::Printf(TEXT("N%f"), 0.0f));
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, FString::Printf(TEXT("Nexus %s"), *GetNexusLocation().ToString()));
        //GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, FString::Printf(TEXT("lastLoc %s"), *lastPathPoint.ToString()));
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("bCanReach"), false);
    }
    
    float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 400;
    FVector VRange = AICharacter->GetActorLocation() - GetTargetLocation(AICharacter);
    float FRange = VRange.Size();

    // 몬스터와 목표의 거리에 따른 조건 설정
    if (1700 < FRange)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("OutRange"), true);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), false);
    }
    else if (MeleeRange < FRange && FRange < 1700)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("OutRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), false);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("OutRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), true);
    }
    
    
    // 죽음 시 블랙보드 제어
    if (AICharacter->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    // 캐릭터가 생성될 때, 일정시간동안 Spawn 애니메이션을 실행시킴
    ANPCAIController * Controller = Cast<ANPCAIController>(AIController);
    if (Controller->bPlaySpawnAnim)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
    
    // 몬스터의 머리 앞에 플레이어가 위치할 경우 true 반환
    float AIDirection = AICharacter->GetActorForwardVector().GetSafeNormal().Rotation().Yaw;
    float AItoPlayerDirection = (PlayerPawn->GetActorLocation() - AICharacter->GetActorLocation()).GetSafeNormal().Rotation().Yaw;
    if(-30 < (AIDirection - AItoPlayerDirection) && (AIDirection - AItoPlayerDirection) < 30)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsPlayerInFront"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsPlayerInFront"), false);
}

// =============================================================
// 넥서스의 위치를 반환한다.
// 타겟의 위치를 반환하도록 변경합니다. ACharacterNPC에 Target이 등록되어 있다면 해당 액터의 위치를 반환합니다. 없다면 nexus를 찾아 위치를 반환합니다.
// =============================================================
FVector UBTService_Update_Enemy::GetTargetLocation(ACharacterNPC* InAiCharacter)
{
    if(InAiCharacter->GetAttackTarget().IsValid())
        return InAiCharacter->GetAttackTargetLocation();
    
    int nexusID = FObjectManager::GetInstance()->FindActorByPredicate([](AActor* InActor)
    {
        if(ACharacterNPC* thisNPC = Cast<ACharacterNPC>(InActor))
            if(thisNPC->NPCType == ENPCType::Nexus)
                return true;
        
        return false;
    });

    if(nexusID == FObjectManager::GetInstance()->INVALID_OBJECTID)
        return FVector::ZeroVector;
    
    return FObjectManager::GetInstance()->FindActor(nexusID)->GetActorLocation();
}