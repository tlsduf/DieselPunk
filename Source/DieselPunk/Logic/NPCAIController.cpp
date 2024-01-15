// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCAIController.h"
#include "../Character/CharacterTurret.h"

#include <Math/Vector.h>
#include <Navigation/PathFollowingComponent.h>
#include <DrawDebugHelpers.h>

const FName ANPCAIController::TargetKey(TEXT("Target"));

void ANPCAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ANPCAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // PathPoint 받아서 표시
    if(!GetPathFollowingComponent()->GetPath().IsValid())
        return;

    // PathPoint 경로 DrawDebug
    TArray<FNavPathPoint> pathPoints = GetPathFollowingComponent()->GetPath()->GetPathPoints();
    FVector beforePoint = pathPoints[0].Location;
    for(FNavPathPoint i : pathPoints)
    {
        DrawDebugLine(GetWorld(),beforePoint, i.Location, FColor::Red, false, -1);
        DrawDebugPoint(GetWorld(), i.Location, 10, FColor::Red, false, -1);
        beforePoint = i.Location;
    }
    DrawDebugPoint(GetWorld(), pathPoints[pathPoints.Num()-1].Location, 25, FColor::Blue, false, -1);
}

void ANPCAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    RunAi(InPawn, false);

    // 스폰 애니메이션
    TWeakObjectPtr<ANPCAIController> thisPtr = this;
    GetWorld()->GetTimerManager().SetTimer(SpawnAnimTHandle, [thisPtr](){
            if(thisPtr.IsValid())
                thisPtr->bPlaySpawnAnim = false;
        },SpawnTime, false);
}

//Ai를 실행합니다.
void ANPCAIController::RunAi(APawn* inPawn, bool inForced)
{
    if(inPawn == nullptr)
        return;

    //포탑의 경우에는 배치 후에 Ai가 진행되어야 합니다.
    if(inForced == false && Cast<ACharacterTurret>(inPawn) != nullptr)
        return;
    
    if(AIBehavior != nullptr)
        RunBehaviorTree(AIBehavior);
}