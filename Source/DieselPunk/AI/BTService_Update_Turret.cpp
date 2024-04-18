// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Turret.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"

#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <AIController.h>


UBTService_Update_Turret::UBTService_Update_Turret()
{
    NodeName = "Update_Turret";
    bCreateNodeInstance = true;
}

void UBTService_Update_Turret::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController* AIController = OwnerComp.GetAIOwner();
    ACharacterNPC* AICharacter = Cast<ACharacterNPC>(AIController->GetPawn());
    
    // 타겟 SET
    OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), AICharacter->GetAttackTarget().Get());

    
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

    int32 shotPerMin = AICharacter->GetStat(ECharacterStatType::AtkSpeed);
    float shorPerSec = shotPerMin / 60.f;
    float waitTime = 1.f / shorPerSec;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("WaitTime"), waitTime);
    OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
}


