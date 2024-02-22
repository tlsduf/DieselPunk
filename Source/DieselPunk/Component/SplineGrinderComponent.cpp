// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineGrinderComponent.h"
#include "../Character/CharacterPC.h"
#include "../Animation/DPAnimInstance.h"

#include <Components/CapsuleComponent.h>
#include <Components/SkeletalMeshComponent.h>


USplineGrinderComponent::USplineGrinderComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USplineGrinderComponent::BeginPlay()
{
	Super::BeginPlay();

	if(Cast<ACharacterPC>(GetOwner()))
	{
		Cast<ACharacterPC>(GetOwner())->DelegateLandAction.BindDynamic(this, &USplineGrinderComponent::GrindAction);
		Cast<ACharacterPC>(GetOwner())->DelegateJumpAction.BindDynamic(this, &USplineGrinderComponent::JumpAction);
	}
}

void USplineGrinderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Animator.Update(DeltaTime);
}

// Character 클래스의 LandedDelegate 에 바인드되어 호출될 함수입니다.
// 착지 시, Spline을 타기위한 Setting 을 합니다.
void USplineGrinderComponent::GrindAction(const FHitResult& Hit)
{
	// 착지한 컴포넌트 태그 Rail 확인
	if(Hit.Component->ComponentHasTag("Rail") && !bOnRail)
	{
		bOnRail = true;
		Cast<UDPAnimInstance>(Cast<ACharacterPC>(GetOwner())->GetMesh()->GetAnimInstance())->SetOnRail(bOnRail);
		
		SplineComponent = Hit.GetActor()->GetComponentByClass<USplineComponent>();
		const FVector hitPointOnSpline = SplineComponent->FindLocationClosestToWorldLocation(Hit.ImpactPoint, ESplineCoordinateSpace::World);
		const float splineInputKey = SplineComponent->FindInputKeyClosestToWorldLocation(hitPointOnSpline);
		
		// 착지한 위치와 스플라인 시작점과의 거리
		const float distanceFromStart = SplineComponent->GetDistanceAlongSplineAtSplineInputKey(splineInputKey);
		// 착지한 위치의 스플라인 접선방향
		const FRotator hitRotOnSpline = SplineComponent->GetWorldRotationAtDistanceAlongSpline(distanceFromStart);
		// 캐릭터와 스플라인의 방향 지향성(정방향or역방향)이 일치하는가?
		bForwardDir = IsBetweenYaw(GetOwner()->GetActorRotation(), hitRotOnSpline, 90);
		
		AnimatorParam param;
		param.StartValue = distanceFromStart;
		param.EndValue = bForwardDir ? SplineComponent->GetSplineLength() : 0;
		param.DurationTime = bForwardDir ? ((SplineComponent->GetSplineLength() - distanceFromStart) / 1500) : (distanceFromStart / 1500);
		param.AnimType = EAnimType::Linear;
		TWeakObjectPtr<USplineGrinderComponent> thisPtr = this;
		param.DurationFunc = [thisPtr](float InCurValue)
		{
			if(thisPtr.IsValid())
			{
				thisPtr->GetOwner()->SetActorLocation(thisPtr->SplineComponent->GetLocationAtDistanceAlongSpline(InCurValue, ESplineCoordinateSpace::Type::World) + FVector(0,0,60));
				if(!Cast<ACharacterPC>(thisPtr->GetOwner())->InCombat)
				{
					if( thisPtr->bForwardDir )
						thisPtr->GetOwner()->SetActorRotation(thisPtr->SplineComponent->GetRotationAtDistanceAlongSpline(InCurValue, ESplineCoordinateSpace::Type::World));
					else
						thisPtr->GetOwner()->SetActorRotation(FRotator(
							thisPtr->SplineComponent->GetRotationAtDistanceAlongSpline(InCurValue, ESplineCoordinateSpace::Type::World).Pitch ,
							thisPtr->SplineComponent->GetRotationAtDistanceAlongSpline(InCurValue, ESplineCoordinateSpace::Type::World).Yaw + 180,
							thisPtr->SplineComponent->GetRotationAtDistanceAlongSpline(InCurValue, ESplineCoordinateSpace::Type::World).Roll)
							);
				}
			}
		};
		param.CompleteFunc = [thisPtr](float InCurValue)
		{
			if(thisPtr.IsValid())
				Cast<ACharacterPC>(thisPtr->GetOwner())->Jump();
		};
		Animator.SetParam(param);
		Animator.Start();
	}
}

// CharacterPC 클래스의 DelegateJumpAction 에 바인드되어 호출될 함수입니다.
// 점프 시, Spline을 탈출하기위한 Setting 을 합니다.
void USplineGrinderComponent::JumpAction()
{
	Animator.Stop();
	bOnRail = false;
	Cast<UDPAnimInstance>(Cast<ACharacterPC>(GetOwner())->GetMesh()->GetAnimInstance())->SetOnRail(bOnRail);
	SplineComponent = nullptr;
}


