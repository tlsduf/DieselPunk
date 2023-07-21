// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "..\Character\CharacterPC.h"

#include <Kismet/GameplayStatics.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Math/Vector.h>

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool AEnemyAIController::IsDead() const
{
    ACharacterPC * ControlledCharacter = Cast<ACharacterPC>(GetPawn());
    if(ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }
    return true;
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        
        GetBlackboardComponent()->SetValueAsVector(TEXT("SpawnLocation"), GetPawn()->GetActorLocation());
    }
    GetWorldTimerManager().SetTimer(SpawnAnimTHandle, this, &AEnemyAIController::SetTruePlaySpawnAnim, SpawnTime, false);
}

bool AEnemyAIController::PlaySpawnAnim()
{
    if(GPlaySpawnAnim)
    {
        return false;
    }
    return true;
}

void AEnemyAIController::SetTruePlaySpawnAnim()
{
    GPlaySpawnAnim = true;
}
