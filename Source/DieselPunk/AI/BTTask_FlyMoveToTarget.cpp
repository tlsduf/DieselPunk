// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FlyMoveToTarget.h"

#include "..\Character\CharacterNPC.h"
#include "../Character/CharacterBase.h"
#include "..\Logic\NPCAIController.h"

#include <BehaviorTree/Blackboard/BlackboardKeyType_Object.h>
#include <BehaviorTree/Blackboard/BlackboardKeyType_Vector.h>
#include <BehaviorTree/BlackboardComponent.h>

#include "GameFramework/CharacterMovementComponent.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(BTTask_FlyMoveToTarget)

//생성자
UBTTask_FlyMoveToTarget::UBTTask_FlyMoveToTarget()
{
	NodeName = TEXT("FlyMoveToTarget");
	//bNotifyTick변수를 true로 지정해야만 TickTask함수를 호출합니다.
	bNotifyTick = true;
	bCreateNodeInstance = true;

	// accept only actors and vectors
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FlyMoveToTarget, BlackboardKey), AActor::StaticClass());
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FlyMoveToTarget, BlackboardKey));
}

EBTNodeResult::Type UBTTask_FlyMoveToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type NodeResult = Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerCharacter = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());
	if (!OwnerCharacter.IsValid())
	{
		NodeResult = EBTNodeResult::Failed;
	}
	else
	{
		NodeResult = MoveToTarget(OwnerComp, NodeMemory);
	}

	// 기능 실현부
	//OwnerCharacter->GetCharacterMovement()->AddForce(FVector(0,1,0) * 400);
	
	
	//NodeResult = EBTNodeResult::Succeeded;
	return NodeResult;
}


//LookAtTarget노드에서 Tick마다 호출합니다.
void UBTTask_FlyMoveToTarget::TickTask(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds)
{
	Super::TickTask(InOwnerComp, InNodeMemory, InDeltaSeconds);
	
}

// 공중에서 플레이어를 향해 움직입니다.
EBTNodeResult::Type UBTTask_FlyMoveToTarget::MoveToTarget(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();
	//FBTMoveToTaskMemory* MyMemory = CastInstanceNodeMemory<FBTMoveToTaskMemory>(NodeMemory);
	AAIController* MyController = OwnerComp.GetAIOwner();

	EBTNodeResult::Type NodeResult = EBTNodeResult::Failed;
	if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
	{
		//OwnerCharacter->GetCharacterMovement()->AddForce();
		
		NodeResult = EBTNodeResult::Succeeded;
	}
	else if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass())
	{
		const FVector targetLocation = MyBlackboard->GetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID());
		const FVector myLocation = OwnerCharacter->GetActorLocation();
		const FVector normalDirection = (targetLocation + FVector(0,0,500) - myLocation).GetSafeNormal();
		OwnerCharacter->GetCharacterMovement()->AddForce(normalDirection * 200000);
		//OwnerCharacter->GetCharacterMovement()->AddInputVector(normalDirection * 100);
		
		NodeResult = EBTNodeResult::Succeeded;
	}


	return NodeResult;
}
