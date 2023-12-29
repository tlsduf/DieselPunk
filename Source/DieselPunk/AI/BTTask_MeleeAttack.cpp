// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MeleeAttack.h"
#include "../Character/CharacterNPC.h"

#include <AIController.h>


UBTTask_MeleeAttack::UBTTask_MeleeAttack()
{
    NodeName = "MeleeAttack";
}

EBTNodeResult::Type UBTTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
        return EBTNodeResult::Failed;
    
    OwnerCharacter = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());
    if (OwnerCharacter == nullptr)
        return EBTNodeResult::Failed;
    
    //OwnerCharacter->DoMeleeAttack();
    OwnerCharacter->DoMeleeAttack();

    return EBTNodeResult::Succeeded;
}
