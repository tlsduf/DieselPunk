// Fill out your copyright notice in the Description page of Project Settings.


#include "../Component/SplineGrinder.h"
#include "../Character/CharacterPC.h"
#include "Components/CapsuleComponent.h"


USplineGrinder::USplineGrinder()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USplineGrinder::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<ACharacterPC>(GetOwner())->DelegateLandAction.BindDynamic(this, &USplineGrinder::GrindAction);
	Cast<ACharacterPC>(GetOwner())->DelegateJumpAction.BindDynamic(this, &USplineGrinder::JumpAction);
}

void USplineGrinder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Animator.Update(DeltaTime);
}

// Character 클래스의 LandedDelegate 에 바인드되어 호출될 함수입니다.
// 착지 시, Spline을 타기위한 Setting 을 합니다.
void USplineGrinder::GrindAction(const FHitResult& Hit)
{
	LOG_SCREEN(FColor::Red, TEXT("Landed"));
	// 착지한 컴포넌트 태그 Rail 확인
	if(Hit.Component->ComponentHasTag("Rail") && !bOnRail)
	{
		bOnRail = true;
		
		SplineComponent = Hit.GetActor()->GetComponentByClass<USplineComponent>();
		const FVector hitPointOnSpline = SplineComponent->FindLocationClosestToWorldLocation(Hit.ImpactPoint, ESplineCoordinateSpace::World);
		const float splineInputKey = SplineComponent->FindInputKeyClosestToWorldLocation(hitPointOnSpline);
		
		// 착지한 위치와 스플라인 시작점과의 거리
		const float distanceFromStart = SplineComponent->GetDistanceAlongSplineAtSplineInputKey(splineInputKey);
		// 착지한 위치의 스플라인 접선방향
		const FRotator hitRotOnSpline = SplineComponent->GetWorldRotationAtDistanceAlongSpline(distanceFromStart);
		// 캐릭터와 스플라인의 방향 지향성(정방향or역방향)이 일치하는가?
		bForwardDir = (bInsideRot(hitRotOnSpline, 90) || bInsideRot(hitRotOnSpline, -90));

		Cast<ACharacter>(GetOwner())->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Overlap);
		
		AnimatorParam param;
		param.StartValue = distanceFromStart;
		param.EndValue = bForwardDir ? SplineComponent->GetSplineLength() : 0;
		param.DurationTime = bForwardDir ? ((SplineComponent->GetSplineLength() - distanceFromStart) / 1500) : (distanceFromStart / 1500);
		param.AnimType = EAnimType::Linear;
		TWeakObjectPtr<USplineGrinder> thisPtr = this;
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
void USplineGrinder::JumpAction()
{
	LOG_SCREEN(FColor::Red, TEXT("Jumped"));
	Animator.Stop();
	bOnRail = false;
	SplineComponent = nullptr;
	Cast<ACharacter>(GetOwner())->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Block);
}

// 플레이어의 방향이 InRot 과 InRot + InYaw 사이에 있는지 판별합니다.
bool USplineGrinder::bInsideRot(FRotator InRot, float InYaw)
{
	const float yawInRot = InRot.Yaw;
	const float checkYaw = yawInRot + InYaw;
	const float normalCheckYaw = FRotator::NormalizeAxis(yawInRot + InYaw);
	
	const float min = (yawInRot > normalCheckYaw) ? normalCheckYaw : yawInRot;
	const float max = (yawInRot > normalCheckYaw) ? yawInRot : normalCheckYaw;
	
	bool nealyEqual = ((( checkYaw - normalCheckYaw ) < float(0)) ? -( checkYaw - normalCheckYaw ) : ( checkYaw - normalCheckYaw ))<= 0.1;

	const float charYaw = GetOwner()->GetActorRotation().Yaw;

	bool inRange = nealyEqual ?
		((min <= charYaw) && (charYaw <= max))
	:	((min < charYaw) && (charYaw < max));
	
	return nealyEqual ? inRange : !inRange;
}

