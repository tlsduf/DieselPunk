// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Update_Enemy.h"
#include "..\Logic\NPCAIController.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"


#include <BehaviorTree/BlackboardComponent.h>
#include <Kismet/GameplayStatics.h>
#include <AIController.h>
#include <Navigation/PathFollowingComponent.h>

#include "DieselPunk/Skill/SkillBase.h"
#include "DieselPunk/Skill/SkillNPC/NPCAttack.h"
#include "Interfaces/ITargetDevice.h"


UBTService_Update_Enemy::UBTService_Update_Enemy()
{
    NodeName = "Update_Enemy";
}

void UBTService_Update_Enemy::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    
    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    // AIController , self
    AAIController *AIController = OwnerComp.GetAIOwner();
    ACharacterNPC* AICharacter = Cast<ACharacterNPC>(AIController->GetPawn());
    if(AICharacter == nullptr)
        return;

    // 타겟 SET
    if(AICharacter->GetAttackTarget().IsValid())
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), AICharacter->GetAttackTarget().Get());
    else
        OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("Target"));

    // 타겟이 플레이어 일 경우
    if(AICharacter->bPlayerTargeting())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsTargetPlayer"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsTargetPlayer"), false);
    

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
    if(AICharacter->GetInRange())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("InRange"), false);

    TArray<EAbilityType> melee;
    TArray<EAbilityType> ranged;
    
    for(const EAbilityType& useableSkill : AICharacter->GetUseableSkills())
    {
        const UNPCAttack* attack = AICharacter->GetNPCAttack(useableSkill);
        if(attack->GetSkillDistanceType() == ESkillDistanceType::MeleeAttack)
            melee.Add(useableSkill);
        else if(attack->GetSkillDistanceType() == ESkillDistanceType::RangedAttack)
            ranged.Add(useableSkill);
    }

    if(!melee.IsEmpty())
    {
        int32 random = FMath::RandRange(0, melee.Num() - 1);
        OwnerComp.GetBlackboardComponent()->SetValueAsString(TEXT("AbilityType"), UtilPath::EnumToString(melee[random]));
    }
    else
    {
        if(!ranged.IsEmpty())
        {
            int32 random = FMath::RandRange(0, ranged.Num() - 1);
            OwnerComp.GetBlackboardComponent()->SetValueAsString(TEXT("AbilityType"), UtilPath::EnumToString(ranged[random]));
        }
        else
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsString(TEXT("AbilityType"), UtilPath::EnumToString(EAbilityType::None));
        }
    }
    
    // 죽음 시 블랙보드 제어
    if (AICharacter->IsDead())
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), false);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsLive"), true);
    
    // 캐릭터가 생성될 때, 일정시간동안 Spawn 애니메이션을 실행시킴
    ANPCAIController* controller = Cast<ANPCAIController>(AIController);
    if (controller->bPlaySpawnAnim)
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), true);
    else
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("PlaySpawnAnim"), false);

    //공격 속도 적용
    int32 shotPerMin = AICharacter->GetStat(ECharacterStatType::AtkSpeed);
    float shorPerSec = shotPerMin / 60.f;
    float waitTime = 1.f / shorPerSec;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("WaitTime"), waitTime);
}