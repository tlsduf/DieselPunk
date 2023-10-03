// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include <BehaviorTree/BTTaskNode.h>
#include "BTTask_LookAtTarget.generated.h"

//몬스터 공격을 하기 전 타겟을 쳐다보기 위해 회전합니다.
class ACharacterBase;
UCLASS()
class DIESELPUNK_API UBTTask_LookAtTarget : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY()
	TWeakObjectPtr<ACharacterBase>	OwnerCharacter;	//몬스터
	
	float							DegreeRange;	//몬스터가 바라보는 방향과 타겟이 있는 위치사이의 허용 각도입니다. 이 각도 내부로 들어오면 태스크를 마칩니다.
public:
	//생성자
	UBTTask_LookAtTarget();
	//몬스터가 회전을 하기 전 때 초기화 작업을 진행합니다.
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory) override;
protected:
	//몬스터가 회전동안 호출합니다.
	virtual void TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds) override;
private:
	//Owner가 바라보는 방향을 기준으로 Target이 오른쪽에 있는 지 확인합니다.
	bool IsTargetRight(const ACharacterBase* InOwner, const ACharacterBase* InTarget);
	//Owner가 타겟을 바라보고 있는 지 확인합니다. DegreeRange만큼의 오차를 허용합니다.
	bool IsLookAtTarget(const ACharacterBase* InOwner, const ACharacterBase* InTarget);
};
