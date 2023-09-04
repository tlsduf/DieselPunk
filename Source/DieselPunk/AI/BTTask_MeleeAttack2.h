// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MeleeAttack2.generated.h"

class ACharacterNPC;

UCLASS()
class DIESELPUNK_API UBTTask_MeleeAttack2 : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<ACharacterNPC>		OwnerCharacter;		//몬스터를 들고있습니다.
	
public:
	UBTTask_MeleeAttack2();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
