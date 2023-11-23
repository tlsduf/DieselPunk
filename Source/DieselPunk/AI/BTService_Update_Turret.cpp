// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Turret.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"
#include "DieselPunk/Animation/TurretAnimInstace.h"

#include <Components/CapsuleComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <AIController.h>
#include <Components/SkeletalMeshComponent.h>


UBTService_Update_Turret::UBTService_Update_Turret()
{
    NodeName = "Update_Turret";
    bCreateNodeInstance = true;
}

void UBTService_Update_Turret::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    // 플레이어 정보
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
        return;
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController *AIController = OwnerComp.GetAIOwner();
    APawn *AIPawn = AIController->GetPawn();
    auto AICharacter = Cast<ACharacterNPC>(AIPawn);
    

    // * 터렛은 현재 목표가 없으면 탐색을 하여, 사거리가 유효한 가장 가까운 적을 목표로 삼는다.
    // * 목표가 사거리에서 벗어나면 목표를 재탐색한다.
        
    // TODO 사거리 정보 받아오기
    float attackRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 1000;
        
    if(!CurTarget.IsValid())
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
        // 가장 가까운 적 탐색 후, 거리 계산
        float distance = FLT_MAX;
        if(SearchNearestEnemy(AICharacter) != nullptr)
            distance = FVector::Dist(SearchNearestEnemy(AICharacter)->GetActorLocation(), AICharacter->GetActorLocation());
        // 거리가 유효하면 타겟설정
        if(distance < attackRange)
        {
            CurTarget = SearchNearestEnemy(AICharacter);
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
            OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("NearestActor"), CurTarget.Get());
        }
    }
    else
    {
        // 목표와의 거리 측정
        float distance = FVector::Dist(CurTarget->GetActorLocation(), AICharacter->GetActorLocation());
        // 거리가 유효하지 않으면 초기화
        if(distance > attackRange)
        {
            CurTarget = nullptr;
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
            OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("NearestActor"));
        }
    }
        
    UTurretAnimInstace* Temp = Cast<UTurretAnimInstace>(AICharacter->GetMesh()->GetAnimInstance());
    if(Temp != nullptr)
        Temp->SetCurTarget(CurTarget);
    
    

    // 죽음 시 블랙보드 제어
    if (AICharacter->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    // 캐릭터가 생성될 때, 일정시간동안 Spawn 애니메이션을 실행시킴
    ANPCAIController *Controller = Cast<ANPCAIController>(AIController);
    if (Controller->bPlaySpawnAnim)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
}

// =============================================================
// 현재 캐릭터로부터 가장 가까운 적을 반환한다. // TODO ObjectManager
// =============================================================
ACharacterNPC* UBTService_Update_Turret::SearchNearestEnemy(ACharacterNPC* inThisCharacter)
{
    ACharacterNPC* nearestActor = nullptr;
    
    TArray<AActor*> OutActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterNPC::StaticClass(), OutActors);
    float minDistance = FLT_MAX;
    for (AActor* a : OutActors)
    {
        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Alliance)
            continue;

        if(Cast<ACharacterNPC>(a)->NPCType == ENPCType::Nexus)
            continue;
        
        float distance = FVector::Dist(Cast<ACharacterNPC>(a)->GetActorLocation(), inThisCharacter->GetActorLocation());
        if ( minDistance < distance )
            continue;
        
        minDistance = distance;
        nearestActor = Cast<ACharacterNPC>(a);
    }
    
    return nearestActor;
}


