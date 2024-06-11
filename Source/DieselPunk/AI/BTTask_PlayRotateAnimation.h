// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_PlayRotateAnimation.generated.h"

class ACharacterTurret;
class UAnimMontage;
/**
 * 로테이트 애니메이션 재생 후, 회전값만큼 액터를 회전시킵니다.
 */
UCLASS()
class DIESELPUNK_API UBTTask_PlayRotateAnimation : public UBTTaskNode
{
	GENERATED_BODY()

	/** Animation asset to play. Note that it needs to match the skeleton of pawn this BT is controlling */
	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	TObjectPtr<UAnimMontage> TurnLeftAnimationMontage = nullptr;
	
	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	TObjectPtr<UAnimMontage> TurnRightAnimationMontage = nullptr;

	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	double AnimationRotateAngle = 15.f;
	
	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	double MaxRotateAngle = 30.0;
	
	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	float PlayRate = 1.f;

	UPROPERTY(Category ="MYDP_Node", EditAnywhere)
	FName RotateBoneName = NAME_None;

	TWeakObjectPtr<ACharacterTurret> OwnerCharacter = nullptr;

	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> MyOwnerComp = nullptr;
	
public:
	UBTTask_PlayRotateAnimation(const FObjectInitializer& ObjectInitializer);
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void RotateAnimationEnded(UAnimMontage* InMontage, bool InbInterrupted);
};
