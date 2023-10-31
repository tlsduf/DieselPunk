// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "..\Character\CharacterPC.h"

#include <Kismet/GameplayStatics.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Math/Vector.h>
#include <Navigation/PathFollowingComponent.h>

const FName AEnemyAIController::TargetKey(TEXT("Target"));

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    
   // GetPathFollowingComponent()->IsBlocked();
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //UE_VLOG(GetOwner(), LogPathFollowing, Log, TEXT("OnPathFinished: %s"), *Result.ToString());

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
