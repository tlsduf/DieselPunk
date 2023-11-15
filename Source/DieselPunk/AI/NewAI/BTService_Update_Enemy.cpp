// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Enemy.h"
#include "..\../Logic\EnemyAIController.h"
#include "../../Character/CharacterNPC.h"

#include <Components/CapsuleComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Pawn.h>
#include <AIController.h>
#include <Navigation/PathFollowingComponent.h>


UBTService_Update_Enemy::UBTService_Update_Enemy()
{
    NodeName = "UpdateEnemy";
    bCreateNodeInstance = true;
}

void UBTService_Update_Enemy::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    // 플레이어 정보
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
        return;
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController *AIController = OwnerComp.GetAIOwner();
    APawn *AIPawn = AIController->GetPawn();
    auto AICharacter = Cast<ACharacterNPC>(AIPawn);
    
    

    // 플레이어 위치 업데이트
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());

    // 넥서스 위치 SET // Tick에 있어야 하는가?
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("Nexus"), GetNexusLocation());

    // 넥서스에 도달 할 수 있는가?
    // lastPathPoint : 마지막 도달가능 위치 // 길이 막혀있거나 못갈 경우 목표에 도달할 수 있는 가장 가까운 PathPoint 위치
    if(AICharacter->NPCType == ENPCType::Enemy)
    {
        FVector lastPathPoint = FVector::ZeroVector;
        if(AIController->GetPathFollowingComponent()->GetPath().IsValid())
            lastPathPoint = AIController->GetPathFollowingComponent()->GetPath()->GetGoalLocation();
        if((GetNexusLocation().X == lastPathPoint.X) && (GetNexusLocation().Y == lastPathPoint.Y))
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
    }

    // 캐릭터가 아군일 때
    if(AICharacter->NPCType == ENPCType::Alliance)
    {
        // * 터렛은 현재 목표가 없으면 탐색을 하여, 사거리가 유효한 가장 가까운 적을 목표로 삼는다.
        // * 목표가 사거리에서 벗어나면 목표를 재탐색한다.
        
        // TODO 사거리 정보 받아오기
        float attackRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 1000;
        
        if(!CurTarget.IsValid())
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
            // 가장 가까운 적 탐색 후, 거리 계산
            float distance = FLT_MAX;
            if(SearchNearestEnemy(AICharacter) != nullptr)
                distance = FVector::Dist(SearchNearestEnemy(AICharacter)->GetActorLocation(), AICharacter->GetActorLocation());
            // 거리가 유효하면 타겟설정
            if(distance < attackRange)
            {
                CurTarget = SearchNearestEnemy(AICharacter);
                OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
                OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("NearestActor"), CurTarget.Get());
            }
        }
        else
        {
            // 목표와의 거리 측정
            float distance = FVector::Dist(CurTarget->GetActorLocation(), AICharacter->GetActorLocation());
            // 거리가 유효하지 않으면 초기화
            if(distance > attackRange)
            {
                CurTarget = nullptr;
                OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
                OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("NearestActor"));
            }
        }
    }

    
    // 캐릭터가 적군일 때 // TODO 현재는 목표가 넥서스지만, 목표를 바꿀 수 있게
    if(AICharacter->NPCType == ENPCType::Enemy)
    {
        float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 400;
        FVector VRange = AIPawn->GetActorLocation() - GetNexusLocation();
        float FRange = VRange.Size();

        // 몬스터와 플레이어의 거리에 따른 조건 설정
        if (1300 < FRange)
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("OutRange"), true);
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), false);
        }
        else if (MeleeRange < FRange && FRange < 1300)
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
    }


    // 스폰 시, 죽음 시 블랙보드를 멈추기위해서 임시로 구현함
    AEnemyAIController * Controller = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
    
    if (Controller->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    if (Controller->PlaySpawnAnim())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);

    // 몬스터의 머리 앞에 플레이어가 위치할 경우 true 반환
    float AIDirection = AICharacter->GetActorForwardVector().GetSafeNormal().Rotation().Yaw;
    float AItoPlayerDirection = (PlayerPawn->GetActorLocation() - AICharacter->GetActorLocation()).GetSafeNormal().Rotation().Yaw;
    if(-30 < (AIDirection - AItoPlayerDirection) && (AIDirection - AItoPlayerDirection) < 30)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsPlayerInFront"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsPlayerInFront"), false);
    
    
}

// =============================================================
// 현재 캐릭터로부터 가장 가까운 적을 반환한다. // TODO ObjectManager
// =============================================================
ACharacterNPC* UBTService_Update_Enemy::SearchNearestEnemy(ACharacterNPC* inThisCharacter)
{
    ACharacterNPC* nearestActor = nullptr;
    
    TArray<AActor*> OutActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterNPC::StaticClass(), OutActors);
    float minDistance = FLT_MAX;
    for (AActor* a : OutActors)
    {
        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Alliance)
            continue;

        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Nexus)
            continue;
        
        float distance = FVector::Dist(Cast<ACharacterNPC>(a)->GetActorLocation(), inThisCharacter->GetActorLocation());
        if ( minDistance < distance )
            continue;
        
        minDistance = distance;
        nearestActor = Cast<ACharacterNPC>(a);
    }
    
    return nearestActor;
}

// =============================================================
// 넥서스의 위치를 반환한다.
// =============================================================
FVector UBTService_Update_Enemy::GetNexusLocation()
{
    FVector returnVector = FVector::ZeroVector;

    TArray<AActor*> OutActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterNPC::StaticClass(), OutActors);
    for (AActor* a : OutActors)
    {
        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Alliance)
            continue;

        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Enemy)
            continue;

        returnVector = Cast<ACharacterNPC>(a)->GetActorLocation();
    }

    return returnVector;
}
