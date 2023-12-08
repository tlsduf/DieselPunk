// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_Update_Enemy.generated.h"

/**
 * 
 */

class ACharacterNPC;
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
	// 타겟의 위치를 반환하도록 변경합니다. ACharacterNPC에 Target이 등록되어 있다면 해당 액터의 위치를 반환합니다. 없다면 nexus를 찾아 위치를 반환합니다.
	FVector GetTargetLocation(ACharacterNPC* InAICharacter);
};
