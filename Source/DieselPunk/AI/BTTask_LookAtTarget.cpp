// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_LookAtTarget.h"

#include "../Character/CharacterBase.h"
#include "../Logic/EnemyAIController.h"

#include <BehaviorTree/BlackboardComponent.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(BTTask_LookAtTarget)

//생성자
UBTTask_LookAtTarget::UBTTask_LookAtTarget()
{
	NodeName = TEXT("LookAtTarget");
	//bNotifyTick변수를 true로 지정해야만 TickTask함수를 호출합니다.
	bNotifyTick = true;
	bCreateNodeInstance = true;
	DegreeRange = 10.f;
}

//LookAtTarget노드 접근 시 호출 합니다.
EBTNodeResult::Type UBTTask_LookAtTarget::ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(InOwnerComp, InNodeMemory);

	OwnerCharacter = Cast<ACharacterBase>(InOwnerComp.GetAIOwner()->GetPawn());
	if (!OwnerCharacter.IsValid())
	{
		WARN_LOG(TEXT("UBTTask_LookAtTarget::ExecuteTask Failed! : OwnerCharacter가 없습니다."));
		return EBTNodeResult::Failed;
	}
	UObject* targetObject = InOwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey);
	if (nullptr == targetObject)
	{
		WARN_LOG(TEXT("UBTTask_LookAtTarget::ExecuteTask Failed! : Target이 없습니다."));
		return EBTNodeResult::Failed;
	}
	ACharacterBase* target = Cast<ACharacterBase>(targetObject);
	if(nullptr == target)
	{
		WARN_LOG(TEXT("UBTTask_LookAtTarget::ExecuteTask Failed! : Target이 ACharacterBase가 아닙니다."));
		return EBTNodeResult::Failed;
	}

	if(IsLookAtTarget(OwnerCharacter.Get(), target))
		return EBTNodeResult::Succeeded;

	return EBTNodeResult::Type::InProgress;
}

//LookAtTarget노드에서 Tick마다 호출합니다.
void UBTTask_LookAtTarget::TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds)
{
	Super::TickTask(InOwnerComp, InNodeMemory, InDeltaSeconds);

	UObject* targetObject = InOwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey);
	if (nullptr == targetObject)
		FinishLatentTask(InOwnerComp, EBTNodeResult::Failed);

	ACharacterBase* target = Cast<ACharacterBase>(targetObject);
	if(nullptr == target)
	{
		FinishLatentTask(InOwnerComp, EBTNodeResult::Failed);
		return;
	}

	//오너가 바라보는 방향을 기준으로 오른쪽에 있는 지 탐색
	bool targetRight = IsTargetRight(OwnerCharacter.Get(), target);

	FRotator rot(0.0,0.0,0.0);
	if(targetRight) //오른쪽에 타겟 있음
		rot.Yaw = 180.0 * InDeltaSeconds;
	else //왼쪽에 타겟 있음
		rot.Yaw = -180.0 * InDeltaSeconds;

	//회전
	OwnerCharacter->AddActorWorldRotation(rot);
	
	if(IsLookAtTarget(OwnerCharacter.Get(), target))
		FinishLatentTask(InOwnerComp, EBTNodeResult::Succeeded);
}

//Owner가 바라보는 방향을 기준으로 Target이 오른쪽에 있는 지 확인합니다.
bool UBTTask_LookAtTarget::IsTargetRight(const ACharacterBase* InOwner, const ACharacterBase* InTarget)
{
	FVector targetLocation = InTarget->GetActorLocation();
	FVector ownerLocation = InOwner->GetActorLocation();

	FVector atTarget = targetLocation - ownerLocation;
	atTarget.Z = 0.0;
	atTarget.Normalize();
	
	FVector ownerRight = InOwner->GetActorRightVector();
	ownerRight.Z = 0.0;
	ownerRight.Normalize();

	float dot = FVector::DotProduct(ownerRight, atTarget);

	return dot >= 0;
	
}

//Owner가 타겟을 바라보고 있는 지 확인합니다. DegreeRange만큼의 오차를 허용합니다.
bool UBTTask_LookAtTarget::IsLookAtTarget(const ACharacterBase* InOwner, const ACharacterBase* InTarget)
{
	FVector targetLocation = InTarget->GetActorLocation();
	FVector ownerLocation = InOwner->GetActorLocation();

	FVector atTarget = targetLocation - ownerLocation;
	atTarget.Z = 0.0;
	atTarget.Normalize();
	
	FVector ownerLook = InOwner->GetActorForwardVector();
	ownerLook.Z = 0.0;
	ownerLook.Normalize();

	float dot = FVector::DotProduct(ownerLook, atTarget);

	return dot >= cosf(FMath::DegreesToRadians(DegreeRange * 0.5f));
}
