// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MeleeAttack.generated.h"

class ACharacterNPC;
UCLASS()
class DIESELPUNK_API UBTTask_MeleeAttack : public UBTTaskNode
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<ACharacterNPC>		OwnerCharacter;		//몬스터를 들고있습니다.
	bool								Looping;			//실행할 애니메이션을 반복할 지 결정합니다. 클래스 내부에서 사용할 스킬의 정보를 받아와 세팅합니다.
	int32								LoopValue;			//반복할 횟수를 지정합니다. 클래스 내부에서 사용할 스킬의 정보를 받아와 세팅합니다.
	float								Duration;			//공격하는 데 걸리는 시간입니다.

	int32								LoopCount;			//반복 횟수입니다.
	float								DeltaTime;			//공격 진행 시간입니다.
	
public:
	UBTTask_MeleeAttack();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

protected:
	//몬스터가 공격하는 시간 동안 대기 상태를 유지합니다.
	virtual void TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds) override;
};
