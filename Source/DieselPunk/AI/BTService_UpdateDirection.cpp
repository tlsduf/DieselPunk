// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_UpdateDirection.h"
#include "..\Logic\EnemyAIController.h"
#include "../Character/CharacterNPC.h"

#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Pawn.h>
#include <AIController.h>


UBTService_UpdateDirection::UBTService_UpdateDirection()
{
    NodeName = "UpdateDirection";
}

void UBTService_UpdateDirection::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = DpGetPlayer();
    if (PlayerPawn == nullptr)
        return;
    
    APawn *AIPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (OwnerComp.GetAIOwner() == nullptr)
        return;
    
    FVector location = AIPawn->GetActorForwardVector().GetSafeNormal() - (PlayerPawn->GetActorLocation() - AIPawn->GetActorLocation()).GetSafeNormal();
    
    FRotator direction = location.Rotation().GetDenormalized();
    
   // AIPawn->SetActorRotation();
    AIPawn->AddActorLocalRotation(FRotator(0 ,direction.Yaw * DeltaSeconds, 0));
}
