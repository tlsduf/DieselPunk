#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_RotateToTarget.generated.h"

UCLASS()
class DIESELPUNK_API UBTService_RotateToTarget : public UBTService_BlackboardBase
{

	GENERATED_BODY()

public:
	UBTService_RotateToTarget();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

	
};
