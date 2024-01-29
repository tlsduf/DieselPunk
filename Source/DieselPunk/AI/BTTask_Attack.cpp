// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "..\Character\CharacterNPC.h"

#include <AIController.h>


UBTTask_Attack::UBTTask_Attack()
{
    NodeName = "Attack";
    bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);
    
    //공격상태에 들어갈 때 아래에 초기화 작업을 진행합니다.
    
    if (OwnerComp.GetAIOwner() == nullptr)
        return EBTNodeResult::Failed;
    
    ACharacterNPC *Character = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr)
        return EBTNodeResult::Failed;

    Character->DoProjectileAttack();
    Character->DoMeleeAttack();
    Character->DoTargetAttack();

    return EBTNodeResult::Succeeded;

    auto temp = BlackboardKey;
}
