// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_Update_Turret.generated.h"

class ACharacterNPC;
/**
 * 
 */
UCLASS()
class DIESELPUNK_API UBTService_Update_Turret : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	UPROPERTY()
	TWeakObjectPtr<ACharacterNPC> CurTarget = nullptr;

public:
	UBTService_Update_Turret();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
