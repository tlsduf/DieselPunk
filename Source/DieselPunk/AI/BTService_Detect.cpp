// Copyright GuardiansW. All Rights Reserved.


#include "BTService_Detect.h"

#include "../Logic/EnemyAIController.h"
#include "../Character/CharacterPC.h"
#include "../Character/CharacterNPC.h"

#include <BehaviorTree/BlackboardComponent.h>
#include <DrawDebugHelpers.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(BTService_Detect)

//생성자
UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

//비헤이비어 트리에서 지정한 Interval마다 한번씩 호출합니다. 몬스터가 타겟을 탐지합니다.
void UBTService_Detect::TickNode(UBehaviorTreeComponent& InOwnerComp, uint8* InNodeMemory, float InDeltaSeconds)
{
	Super::TickNode(InOwnerComp, InNodeMemory, InDeltaSeconds);

	APawn* controlPawn = InOwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == controlPawn)
		return;

	UWorld* world = controlPawn->GetWorld();
	if (nullptr == world)
		return;

	//적군에게 피격 당한 경우 무적상태인지 판별 후 타깃으로 선정
	/*
	ACharacterNPC* monster = Cast<ACharacterNPC>(controlPawn);
	if (nullptr == monster)
		return;
	if (monster->IsDamaged())
	{
		ACharacterPC* characterPc = monster->GetCharacterAttackToMonster();
		if (nullptr == characterPc)
			return;
		if (false == characterPc->GetStat(EActorStatType::Immortal))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMonsterAIController::TargetKey, characterPc);
			return;
		}
	}
	*/

	//선공몹이 아닐 경우 범위 탐색연산 안함.
	/*
	ACharacterNPC* monster = Cast<ACharacterNPC>(controlPawn);
	if (nullptr == monster)
		return;
	if (false == monster->GetStat(EActorStatType::Aggressive))
		return;
	*/

	FVector center = controlPawn->GetActorLocation();
	float detectRadius = 600.0f;

	TArray<FOverlapResult> overlapResults;
	FCollisionQueryParams collisionQueryParam(NAME_None, false, controlPawn);
	//몬스터 위치의 임의의 반지름(600.f)의 크기의 구를 생성해 오버랩되는 오브젝트를 찾아낸다.
	bool bResult = world->OverlapMultiByChannel(
		overlapResults,
		center,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(detectRadius),
		collisionQueryParam
	);

	double distMonsterPlayer = DBL_MAX;
	ACharacterPC* targetCharacterPc = nullptr;

	//찾아낸 오브젝트 중 플레이어 클래스가 있다면 해당 액터중 가장 가까운 플레이어를 탐색한다.
	for (FOverlapResult overlapResult : overlapResults)
	{
		ACharacterPC* characterPc = Cast<ACharacterPC>(overlapResult.GetActor());
		if (nullptr == characterPc)
			continue;
		//버프 시스템에서 무적을 찾아와야함.
		//if (true == characterPc->GetStat(EActorStatType::Immortal))
		//	continue;

		FVector playerLocation = characterPc->GetActorLocation();
		double tempDistMonsterPlayer = FVector::Distance(center, playerLocation);

		//가장 가까운 플레이어를 탐색한다.
		if (distMonsterPlayer > tempDistMonsterPlayer)
		{
			distMonsterPlayer = tempDistMonsterPlayer;
			targetCharacterPc = characterPc;
		}
	}
	//탐색된 플레이어가 없다면 블랙보드 Target에 nullptr을 등록한다.
	if (nullptr == targetCharacterPc)
	{
#ifdef UE_BUILD_DEBUG
		DrawDebugSphere(world, center, detectRadius, 16, FColor::Red, false, 0.2f);
#endif // UE_BUILD_DEBUG
		InOwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, nullptr);
		return;
	}

	//탐색된 플레이어가 있다면 가장 가까운 플레이어를 블랙보드 Target에 등록한다.
#ifdef UE_BUILD_DEBUG
	DrawDebugSphere(world, center, detectRadius, 16, FColor::Green, false, 0.2f);
#endif // UE_BUILD_DEBUG
	InOwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, targetCharacterPc);
			
}
