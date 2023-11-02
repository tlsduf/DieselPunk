// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "../Character/CharacterPC.h"
#include "../Character/CharacterTurret.h"

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
    if(!GetPathFollowingComponent()->GetPath().IsValid())
        return;
    if(GetPawn() == nullptr)
        return;
    TArray<FNavPathPoint> pathPoints = GetPathFollowingComponent()->GetPath()->GetPathPoints();
    FVector beforePoint = pathPoints[0].Location;
    for(FNavPathPoint i:pathPoints)
    {
        DrawDebugLine(GetWorld(),beforePoint, i.Location, FColor::Red);
        DrawDebugPoint(GetWorld(), i.Location, 10, FColor::Red, false, -1);
        beforePoint = i.Location;
    }
    DrawDebugPoint(GetWorld(), pathPoints[pathPoints.Num()-1].Location, 25, FColor::Blue, false, -1);
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

    RunAi(InPawn, false);

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

//Ai를 실행합니다.
void AEnemyAIController::RunAi(APawn* InPawn, bool InForced)
{
    if(InPawn == nullptr)
        return;

    //포탑의 경우에는 배치 후에 Ai가 진행되어야 합니다.
    if(InForced == false && Cast<ACharacterTurret>(InPawn) != nullptr)
        return;
    
    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        GetBlackboardComponent()->SetValueAsVector(TEXT("SpawnLocation"), GetPawn()->GetActorLocation());
    }
}