// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateDirection.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UBTService_UpdateDirection : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	

public:
	UBTService_UpdateDirection();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
	
};
