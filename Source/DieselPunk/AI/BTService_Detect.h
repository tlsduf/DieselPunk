// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <BehaviorTree/BTService.h>
#include "BTService_Detect.generated.h"

//몬스터가 주변에 플레이어가 있는 지 탐색하는 비헤이비어 트리 서비스 클래스입니다.
UCLASS()
class DIESELPUNK_API UBTService_Detect : public UBTService
{
	GENERATED_BODY()
public:
	//생성자
	UBTService_Detect();
protected:
	//플레이어를 탐지한다.
	virtual void TickNode(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds) override;
};
