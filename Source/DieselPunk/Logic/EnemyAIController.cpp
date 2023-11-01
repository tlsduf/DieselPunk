// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "..\Character\CharacterPC.h"

#include <Kismet/GameplayStatics.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Math/Vector.h>
#include <Navigation/PathFollowingComponent.h>

#include "DrawDebugHelpers.h"

const FName AEnemyAIController::TargetKey(TEXT("Target"));

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    
   
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // PathPoint 받아서 표시
    if(GetPathFollowingComponent()->GetPath().IsValid())
    {
        TArray<FNavPathPoint> pathPoints = GetPathFollowingComponent()->GetPath()->GetPathPoints();
        for(FNavPathPoint i:pathPoints)
        {
            DrawDebugPoint(GetWorld(), i.Location, 10, FColor::Red, false, -1);
        }
    }

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
