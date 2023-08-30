// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_UpdatePlayerActor.h"
#include "..\Logic\EnemyAIController.h"
#include "../Character/CharacterNPC.h"

#include <Components/CapsuleComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Pawn.h>
#include <AIController.h>


UBTService_UpdatePlayerActor::UBTService_UpdatePlayerActor()
{
    NodeName = "Update Player Actor";
}

void UBTService_UpdatePlayerActor::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
        return;
    
    APawn *AIPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (OwnerComp.GetAIOwner() == nullptr)
        return;
    
    auto AICharacter = Cast<ACharacterNPC>(AIPawn);
    float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 200;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());

    FVector VRange = AIPawn->GetActorLocation() - PlayerPawn->GetActorLocation();
    float FRange = VRange.Size();

    // 몬스터와 플레이어의 거리에 따른 조건 설정 // 이딴식으로 하는게 맞는것인가?
    if (1500 < FRange)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), false);
    }
    else if (MeleeRange < FRange && FRange < 1500)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), false);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("Player"));
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InMeleeRange"), true);
    }


    // 스폰 시, 죽음 시 블랙보드를 멈추기위해서 임시로 구현함 // 이딴식으로 하는 게 맞는 것인가?
    AEnemyAIController * Controller = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
    
    if (Controller->IsDead())
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    }
    if (Controller->PlaySpawnAnim())
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    }
    
}
