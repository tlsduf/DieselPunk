// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PlayRotateAnimation.h"

#include "AIController.h"
#include "Animation/AnimInstance.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/Character/CharacterBase.h"
#include "DieselPunk/Character/CharacterTurret.h"
#include "GameFramework/Character.h"

UBTTask_PlayRotateAnimation::UBTTask_PlayRotateAnimation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Play Rotate Animation";
	// instantiating to be able to use Timers
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_PlayRotateAnimation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type returnType = Super::ExecuteTask(OwnerComp, NodeMemory);

	MyOwnerComp = OwnerComp;
	
	AAIController* const MyController = OwnerComp.GetAIOwner();
	OwnerCharacter = Cast<ACharacterTurret>(MyController->GetPawn());
	if(TurnLeftAnimationMontage && TurnRightAnimationMontage && MyController && OwnerCharacter.IsValid())
	{
		ACharacterBase* target = Cast<ACharacterBase>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
		if(target == nullptr)
			return EBTNodeResult::Type::Succeeded;

		FVector toTargetDir = target->GetActorLocation() - OwnerCharacter->GetActorLocation();
		toTargetDir.Normalize();

		FVector forwardDir = OwnerCharacter->GetActorForwardVector();
		forwardDir.Normalize();
		
		//애니메이션 로테이트 앵글 범위 밖에 타겟이 있는 경우
		if(FVector::DotProduct(toTargetDir, forwardDir) < FMath::Cos(FMath::DegreesToRadians(AnimationRotateAngle)))
		{
			FVector rightDir = OwnerCharacter->GetActorRightVector();
			rightDir.Normalize();

			bool turnRight = true;
			//왼쪽에 있는거
			if(FVector::DotProduct(toTargetDir, rightDir) < 0)
				turnRight = false;

			if(OwnerCharacter->GetMesh())
			{
				UAnimInstance* animInstance = Cast<UAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance());
				if(animInstance)
				{
					animInstance->OnMontageEnded.Clear();
					animInstance->OnMontageEnded.AddDynamic(this, &UBTTask_PlayRotateAnimation::RotateAnimationEnded);
					returnType = EBTNodeResult::Type::InProgress;
				}
			}
			FVector curDir = OwnerCharacter->GetActorForwardVector();
			FVector initDir = OwnerCharacter->GetInitForwardVector();
			FVector initRightDir = FVector(initDir.Y, initDir.X, initDir.Z);
			
			double angleRadian = FMath::Acos(FMath::Clamp(FVector::DotProduct(curDir, initDir), -1.0, 1.0));
			double angleDegree = FMath::RadiansToDegrees(angleRadian);

			if(FVector::DotProduct(initRightDir, curDir) < 0)
				angleDegree *= -1.0;
			
			if(turnRight && (angleDegree + AnimationRotateAngle) <= MaxRotateAngle)
				OwnerCharacter->PlayAnimMontage(TurnRightAnimationMontage, PlayRate);
			else if (!turnRight && (angleDegree - AnimationRotateAngle) >= -MaxRotateAngle)
				OwnerCharacter->PlayAnimMontage(TurnLeftAnimationMontage, PlayRate);
			return returnType == EBTNodeResult::Type::InProgress ? returnType : EBTNodeResult::Type::Succeeded;
		}
		return EBTNodeResult::Type::Succeeded;
	}
	
	return EBTNodeResult::Type::Failed;
}

void UBTTask_PlayRotateAnimation::RotateAnimationEnded(UAnimMontage* InMontage, bool InbInterrupted)
{
	if(InbInterrupted || !OwnerCharacter.IsValid())
	{
		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Failed);
		return;
	}
	if(RotateBoneName == NAME_None)
	{
		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
		return;
	}

	FQuat goalQuat = OwnerCharacter->GetMesh()->GetBoneQuaternion(RotateBoneName, EBoneSpaces::Type::WorldSpace);
	if(InMontage == TurnLeftAnimationMontage)
		OwnerCharacter->AddActorWorldRotation(FRotator(0.0, -AnimationRotateAngle, 0.0));
	else
		OwnerCharacter->AddActorWorldRotation(FRotator(0.0, AnimationRotateAngle, 0.0));

	FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
}
