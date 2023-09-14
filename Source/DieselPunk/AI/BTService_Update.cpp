// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update.h"
#include "..\Logic\EnemyAIController.h"
#include "../Character/CharacterNPC.h"

#include <Components/CapsuleComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Pawn.h>
#include <AIController.h>


UBTService_Update::UBTService_Update()
{
    NodeName = "Update";
}

void UBTService_Update::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = DpGetPlayer();
    if (PlayerPawn == nullptr)
        return;
    
    APawn *AIPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (OwnerComp.GetAIOwner() == nullptr)
        return;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    
    
    FVector VRange = AIPawn->GetActorLocation() - PlayerPawn->GetActorLocation();
    float FRange = VRange.Size();

    // 몬스터와 플레이어의 거리에 따른 조건 설정 // 이딴식으로 하는게 맞는것인가?
    if (1700 < FRange)
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("InRange"));
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("Player"));
    }


    // 스폰 시, 죽음 시 블랙보드를 멈추기위해서 임시로 구현함 // 이딴식으로 하는 게 맞는 것인가?
    AEnemyAIController * Controller = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
    
    if (Controller->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    if (Controller->PlaySpawnAnim())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    
}
