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
	UPROPERTY()
	UWidgetComponent* WidgetComp;			// 위젯 컴포넌트

	UPROPERTY()
	TWeakObjectPtr< UDamageUI > DamageUI;	// 데미지 UI 포인터
	
	float Damage;						// DamageUI에 전달할 데미지 값

	float XVelocity = 100;				// x 계수
	float YVelocity = 100;				// y 계수
	float ZVelocity = 200;				// z 계수

	float Alpha = 1.f;					//위치 알파 1 to 0
	
	float LifeTime = 1.5f;				// 액터 생명주기
	FTimerHandle DestroyTHandle;		// Destroy 함수 타이머핸들
	
public:	
	// Sets default values for this actor's properties
	ADamageUIActor();

	// 데미지UI 위젯을 생성한다.
	void CreateDamageUI();

	// 데미지 세팅
	void SetDamage(const float& inDamage);

	// LifeTime 후 파괴됩니다.
	void SelfDestroy();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;
	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;
};
