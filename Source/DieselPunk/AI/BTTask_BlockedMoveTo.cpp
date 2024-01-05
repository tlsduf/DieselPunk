// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BlockedMoveTo.h"
#include "../Character/CharacterTurret.h"
#include "../Logic/NPCAIController.h"
#include "../Manager/NavigationManager.h"
#include "../Manager/ObjectManager.h"

#include <BehaviorTree/BlackboardComponent.h>

#include "DrawDebugHelpers.h"


UBTTask_BlockedMoveTo::UBTTask_BlockedMoveTo()
{
	NodeName = TEXT("BlockedMoveTo");
	bNotifyTick = false;
	bCreateNodeInstance = false;

	// accept only actors and vectors
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_BlockedMoveTo, BlackboardKey), AActor::StaticClass());
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_BlockedMoveTo, BlackboardKey));
}

EBTNodeResult::Type UBTTask_BlockedMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerCharacter = Cast<ACharacterNPC>(OwnerComp.GetAIOwner()->GetPawn());

	if(OwnerCharacter == nullptr)
		return EBTNodeResult::Failed;

	if(FObjectManager::GetInstance()->GetNexus() == nullptr)
		return EBTNodeResult::Failed;
	
	int nexusID = FObjectManager::GetInstance()->GetNexus()->GetObjectId();
	if(nexusID == FObjectManager::GetInstance()->INVALID_OBJECTID)
		return EBTNodeResult::Failed;

	//넥서스까지의 최단 경로 탐색(설치물에 방해받지 않고)
	if(!OwnerCharacter->FindShortestPath(FObjectManager::GetInstance()->FindActor(nexusID)->GetActorLocation()))
		return EBTNodeResult::Failed;
	const TArray<FVector>& path = OwnerCharacter->GetShortestPath();

	// 타겟이 넥서스가 아닐 경우 수행안함. = 타겟이 플레이어 일 경우 or 타겟이 터렛으로 등록 된 경우
	if(OwnerCharacter->GetAttackTarget() != FObjectManager::GetInstance()->FindActor(nexusID))
		return EBTNodeResult::Succeeded;
	
	UWorld* world = GetWorld();
	if(world == nullptr)
		return EBTNodeResult::Failed;
	
	//공격 대상 찾기
	AActor* target = nullptr;
	for(int point = 0 ; point < path.Num(); ++point)
	{
		DrawDebugPoint(GetWorld(), path[point], 5, FColor::Blue, false, -1);
		
		TArray<FOverlapResult> hitResult;
		world->OverlapMultiByChannel(hitResult, path[point], FQuat::Identity, ECC_WorldStatic,
					FCollisionShape::MakeSphere(OwnerCharacter->GetGridSize() * FNavigationManager::GridSize));

		for(const FOverlapResult& result : hitResult)
		{
			if(Cast<ACharacterTurret>(result.GetActor()) != nullptr)
			{
				if(OwnerCharacter->SetAttackTarget(result.GetActor(), path, point))
				{
					target = result.GetActor();
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("BlockedTargetLocation"), OwnerCharacter->GetAttackTargetLoc());
					break;
				}
			}
		}
		if(target != nullptr)
			break;
	}
	
	EBTNodeResult::Type returnType = Super::ExecuteTask(OwnerComp, NodeMemory);
	return returnType;
}
