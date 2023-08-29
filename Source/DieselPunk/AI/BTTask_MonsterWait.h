#pragma once

#include <BehaviorTree/BTTaskNode.h>
#include "BTTask_MonsterWait.generated.h"

//몬스터가 대기 상태일 때 처리를 담당하는 비헤이비어 트리 태스크 클래스입니다.
UCLASS()
class DIESELPUNK_API UBTTask_MonsterWait : public UBTTaskNode
{
	GENERATED_BODY()
public:
	//생성자
	UBTTask_MonsterWait();
	//몬스터가 대기 상태에 들어갈 때 초기화 작업을 실행합니다.(예정)
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory) override;
protected:
	//몬스터가 대기 상태를 유지합니다. 대기 상태를 벗어나야 할 경우 태스크를 종료합니다.
	virtual void TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds) override;
};