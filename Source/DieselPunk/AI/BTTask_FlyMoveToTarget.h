// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include <BehaviorTree/Tasks/BTTask_BlackboardBase.h>
#include "BTTask_FlyMoveToTarget.generated.h"

class UBlackboardComponent;
class ACharacterBase;

UCLASS()
class DIESELPUNK_API UBTTask_FlyMoveToTarget : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	TWeakObjectPtr<ACharacterBase>	OwnerCharacter;	//몬스터
public:
	//생성자
	UBTTask_FlyMoveToTarget();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

	//플레이어를 탐지한다.
	virtual void TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds) override;

private:
	// 공중에서 플레이어를 향해 움직입니다.
	EBTNodeResult::Type MoveToTarget(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
