// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_Update_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UBTService_Update_Enemy : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	

public:
	UBTService_Update_Enemy();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

private:
	// 넥서스의 위치를 반환한다.
	FVector GetNexusLocation();
};
