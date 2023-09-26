// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include <GameFramework/Actor.h>
#include "DamageUIActor.generated.h"

class UWidgetComponent;
class UDamageUI;

UCLASS()
class DIESELPUNK_API ADamageUIActor : public AActor
{
	GENERATED_BODY()

	
protected:

	UWidgetComponent* WidgetComp;			// 위젯 컴포넌트
	TWeakObjectPtr< UDamageUI > DamageUI;	// 데미지 UI 포인터
	
	float Damage;						// DamageUI에 전달할 데미지 값

	float XVelocity = 100;				// x 상수
	float YVelocity = 100;				// y 상수
	float ZVelocity = 300;				// z 상수

	float XYAccel;						// DamageUIActor XY 가속도 변수
	Animator XYAccelAnimator;			// DamageUIActor XY 가속도 변수를 애니메이팅 합니다.
	
	float ZAccel;						// DamageUIActor Z 가속도 변수
	Animator ZAccelAnimator;			// DamageUIActor Z 가속도 변수를 애니메이팅 합니다.
	
	float LifeTime = 1.5f;				// 액터 생명주기
	FTimerHandle DestroyTHandle;		// Destroy 함수 타이머핸들
	
public:	
	// Sets default values for this actor's properties
	ADamageUIActor();

	// 데미지UI 위젯을 생성한다.
	void CreateDamageUI();

	// 데미지 세팅
	void SetDamage(float inDamage);
	
	// AccelAnimator 애니메이터
	void StartAnimator();

	// LifeTime 후 파괴됩니다.
	void SelfDestroy();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;
	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;
};
