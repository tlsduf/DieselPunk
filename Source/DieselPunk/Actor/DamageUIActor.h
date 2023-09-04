// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <GameFramework/Actor.h>
#include "DamageUIActor.generated.h"

class UWidgetComponent;
class UDamageUI;

UCLASS()
class DIESELPUNK_API ADamageUIActor : public AActor
{
	GENERATED_BODY()

public:
	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;

	// 액터속도 확인용 임시 변수
	UPROPERTY( EditAnywhere )
	float TempVelocity = 100;
	
protected:
	TWeakObjectPtr< UDamageUI > DamageUI; // 데미지 UI 포인터

	float Damage;						// DamageUI에 전달할 데미지 값

	float Accel;						// DamageUIActor Z 가속도 변수
	Animator AccelAnimator;				// DamageUIActor Z 가속도 변수를 애니메이팅 합니다.
	
	float LifeTime = 1.5f;				// 액터 생명주기
	FTimerHandle DestroyTHandle;		// Destroy 함수 타이머핸들
	
public:	
	// Sets default values for this actor's properties
	ADamageUIActor();

	// 데미지UI 위젯을 생성한다.
	void CreateDamageUI();

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
