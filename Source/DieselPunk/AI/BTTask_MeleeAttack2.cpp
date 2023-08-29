// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MeleeAttack2.h"
#include "../Character/CharacterNPC.h"

#include <AIController.h>


UBTTask_MeleeAttack2::UBTTask_MeleeAttack2()
{
    NodeName = "MeleeAttack2";
}

EBTNodeResult::Type UBTTask_MeleeAttack2::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    OwnerCharacter = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());
    if (OwnerCharacter == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    //OwnerCharacter->DoMeleeAttack();
    OwnerCharacter->TempDoMeleeAttack();

    return EBTNodeResult::Succeeded;
}
