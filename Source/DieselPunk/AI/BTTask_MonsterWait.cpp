#include "BTTask_MonsterWait.h"

#include "../Logic/EnemyAIController.h"

#include <BehaviorTree/BlackboardComponent.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(BTTask_MonsterWait)

//생성자
UBTTask_MonsterWait::UBTTask_MonsterWait()
{
	NodeName = TEXT("MonsterWait");
	//bNotifyTick변수를 true로 지정해야만 TickTask함수를 호출합니다.
	bNotifyTick = true;
}

//몬스터가 대기 상태에 들어갈 때 초기화 작업을 실행합니다.
EBTNodeResult::Type UBTTask_MonsterWait::ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(InOwnerComp, InNodeMemory);
	//대기상태에 들어갈 때 아래에 초기화 작업을 진행합니다.

	return EBTNodeResult::InProgress;
}

//몬스터가 대기 상태를 유지합니다. 대기 상태를 벗어나야 할 경우 태스크를 종료합니다.
void UBTTask_MonsterWait::TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds)
{
	Super::TickTask(InOwnerComp, InNodeMemory, InDeltaSeconds);
	
	//대기 상태를 종료해야하는 경우 아래에 추가합니다.
	UObject* target = InOwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey);
	if (nullptr != target)
		FinishLatentTask(InOwnerComp, EBTNodeResult::Succeeded);
}