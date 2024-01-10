// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Components/SplineComponent.h>
#include <Components/ActorComponent.h>
#include "SplineGrinderComponent.generated.h"

/*
 * Rail 태그를 가지고 있는 스플라인을 밟으면 라인을 따라 미끄러집니다.
 */

class USplineComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API USplineGrinderComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	USplineComponent* SplineComponent;	// 레일 스플라인 컴포넌트
	
	bool bOnRail = true;		// 레일에 타 있는 상태인지
	bool bForwardDir;			// 레일 방향과 캐릭터의 방향이 일치하는지 (정방향 역방향)
	
	Animator Animator;			// 캐릭터 Loc, Rot 애니메이터


public:	
	// Sets default values for this component's properties
	USplineGrinderComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Character 클래스의 LandedDelegate 에 바인드되어 호출될 함수입니다.
	// 착지 시, Spline을 타기위한 Setting 을 합니다.
	UFUNCTION()
	void GrindAction(const FHitResult& Hit);

	// CharacterPC 클래스의 DelegateJumpAction 에 바인드되어 호출될 함수입니다.
	// 점프 시, Spline을 탈출하기위한 Setting 을 합니다.
	UFUNCTION()
	void JumpAction();
};
