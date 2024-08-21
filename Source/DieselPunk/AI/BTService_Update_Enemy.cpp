// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Enemy.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"

#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <AIController.h>

#include "DieselPunk/Character/CharacterMonster.h"


UBTService_Update_Enemy::UBTService_Update_Enemy()
{
    NodeName = "Update_Enemy";
}

void UBTService_Update_Enemy::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController *AIController = OwnerComp.GetAIOwner();
    ACharacterMonster* AICharacter = Cast<ACharacterMonster>(AIController->GetPawn());
    if(AICharacter == nullptr)
        return;

    // 타겟 SET
    if(AICharacter->GetAttackTarget().IsValid())
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), AICharacter->GetAttackTarget().Get());
    else
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("Target"));

    // 타겟이 플레이어 일 경우
    if(AICharacter->bPlayerTargeting())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsTargetPlayer"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsTargetPlayer"), false);
    
    // 몬스터와 목표의 거리에 따른 조건 설정
    if(AICharacter->GetInRange())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
    
    EAbilityType abilityType = AICharacter->GetTopPriorityUseableSkill();
    OwnerComp.GetBlackboardComponent()->SetValueAsString(TEXT("AbilityType"), UtilPath::EnumToString(abilityType));
    
    // 죽음 시 블랙보드 제어
    if (AICharacter->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    // 캐릭터가 생성될 때, 일정시간동안 Spawn 애니메이션을 실행시킴
    ANPCAIController* controller = Cast<ANPCAIController>(AIController);
    if (controller->bPlaySpawnAnim)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);

    //공격 속도 적용
    int32 shotPerMin = AICharacter->GetStat(ECharacterStatType::AtkSpeed);
    float shorPerSec = shotPerMin / 60.f;
    float waitTime = 1.f / shorPerSec;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("WaitTime"), waitTime);
}