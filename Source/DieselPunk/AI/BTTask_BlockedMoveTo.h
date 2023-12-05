// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_BlockedMoveTo.generated.h"

/**
 * 
 */

class ACharacterNPC;

UCLASS()
class DIESELPUNK_API UBTTask_BlockedMoveTo : public UBTTask_MoveTo
{
	GENERATED_BODY()
	UPROPERTY()
	TWeakObjectPtr<ACharacterNPC>	OwnerCharacter;	//몬스터
	public:
	//생성자
	UBTTask_BlockedMoveTo();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
