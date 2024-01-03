// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Enemy.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"


#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <AIController.h>
#include <Navigation/PathFollowingComponent.h>

#include "Interfaces/ITargetDevice.h"


UBTService_Update_Enemy::UBTService_Update_Enemy()
{
    NodeName = "Update_Enemy";
}

void UBTService_Update_Enemy::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
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
    auto AICharacter = Cast<ACharacterNPC>(AIController->GetPawn());

    // 타겟 SET
    if(AICharacter->GetAttackTarget().IsValid())
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), AICharacter->GetAttackTarget().Get());
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), AICharacter);
    

    /*
    UWorld* world = GetWorld();
    if(world == nullptr)
        return;
	
    //사거리 내에 있는가?
    TWeakObjectPtr<AActor> target = AICharacter->GetAttackTarget();
    FVector dist = FVector::ZeroVector;
    if(target.IsValid())
        dist = target->GetActorLocation() - AICharacter->GetActorLocation();
    else
    {
        target = FObjectManager::GetInstance()->GetNexus();
        if(target == nullptr)
            return;
		
        dist = target->GetActorLocation() - AICharacter->GetActorLocation();
    }
    if(dist.Length() <= AICharacter->GetStat().GetStat(ECharacterStatType::AttackRange))
    {
        //라인트레이싱에 성공했는가
        TArray<FHitResult> hit;
        FVector start = AICharacter->GetActorLocation();
        FVector end = target->GetActorLocation();

        FCollisionQueryParams params;
        params.AddIgnoredActor(AICharacter);
    
        //가장 가까운 라인트레이싱의 액터가 공격 대상인지 확인
        if(world->LineTraceMultiByChannel(hit, start, end, ECollisionChannel::ECC_WorldStatic, params))
        {
            hit.Sort([](const FHitResult& lhs, const FHitResult& rhs)
            {
                return lhs.Distance < rhs.Distance;
            });
    
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), (hit[0].GetActor() == target));
        }
        else
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), false);
    }
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAbleAttack"), false);*/
    

    // 몬스터와 목표의 거리에 따른 조건 설정
    //float MeleeRange = AICharacter->GetCapsuleComponent()->GetScaledCapsuleRadius() + 200;
    FVector VRange = AICharacter->GetActorLocation() - AICharacter->GetAttackTarget()->GetActorLocation();
    float FRange = VRange.Size();
    if (AICharacter->GetStat().GetStat(ECharacterStatType::AttackRange) < FRange)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);


    
    // 죽음 시 블랙보드 제어
    if (AICharacter->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    // 캐릭터가 생성될 때, 일정시간동안 Spawn 애니메이션을 실행시킴
    ANPCAIController * Controller = Cast<ANPCAIController>(AIController);
    if (Controller->bPlaySpawnAnim)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);
}