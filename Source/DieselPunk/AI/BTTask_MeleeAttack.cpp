// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MeleeAttack.h"

#include "..\Character\CharacterNPC.h"

#include <AIController.h>
#include <BehaviorTree/BehaviorTreeComponent.h>


UBTTask_MeleeAttack::UBTTask_MeleeAttack()
: OwnerCharacter(nullptr), Looping(false), LoopValue(0), Duration(1.f), LoopCount(0), DeltaTime(0.f)
{
    NodeName = "MeleeAttack";
    //bNotifyTick변수를 true로 지정해야만 TickTask함수를 호출합니다.
    bNotifyTick = true;
    bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

    //공격상태에 들어갈 때 아래에 초기화 작업을 진행합니다.
    
    OwnerCharacter = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());
    if (!OwnerCharacter.IsValid())
    {
        WARN_LOG(TEXT("UBTTask_Attack::ExecuteTask Failed! : OwnerCharacter가 없습니다."));
        return EBTNodeResult::Failed;
    }

    //스킬 정보 데이터 테이블이 제작 된 후 값을 입력해줄 예정입니다. 현재는 데이터를 테스트 하기 위해 상수로 대입중입니다.
    Looping = false;
    LoopValue = 1;

    //아래는 매번 노드에 새로 들어올 때마다 초기화 해주는 값입니다.
    LoopCount = 0;
    DeltaTime = 0.f;

    
    Duration = OwnerCharacter->DoMeleeAttack();

    return EBTNodeResult::InProgress;
}

//몬스터가 공격하는 시간 동안 대기 상태를 유지합니다.
void UBTTask_MeleeAttack::TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds)
{
    Super::TickTask(InOwnerComp, InNodeMemory, InDeltaSeconds);
    DeltaTime += InDeltaSeconds;
    if (DeltaTime >= Duration)
    {
        if (++LoopCount < LoopValue)
            Duration = OwnerCharacter->DoMeleeAttack();
        else
            FinishLatentTask(InOwnerComp, EBTNodeResult::Succeeded);
        DeltaTime = 0.f;
    }
}