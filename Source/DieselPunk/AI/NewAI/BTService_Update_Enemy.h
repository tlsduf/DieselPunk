// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_Update_Enemy.generated.h"

class ACharacterNPC;
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
	// 현재 캐릭터로부터 가장 가까운 적을 반환한다.
	ACharacterNPC* SearchNearestEnemy(ACharacterNPC* inThisCharacter);

	ACharacterNPC* CurTarget = nullptr;
	
};
