// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectileBase.h"
#include "SoldierProjectile.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API ASoldierProjectile : public AProjectileBase
{
	GENERATED_BODY()

	ASoldierProjectile();

protected:
	// bUseOneTick = true 일 시, 처리를 담당
	virtual void OneTickTask() override;
	
	// OnHit의 실질적인 기능을 담고있는 함수 // OnHit이 상속이안됨.
	virtual void _OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult) override;
	
	// Overlap의 실질적인 기능을 담고있는 함수 // Overlap이 상속이안됨.
	virtual void _BeginOverlapEvent(class UPrimitiveComponent* InHitComp, class AActor* InOtherActor, class UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult & InSweepResult) override;

public:
	// 스택 쌓는 투사체
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	bool isStackin = false;

	int8 Stack = 0;
	
	// 스택 터뜨리는 투사체
	bool IsStackBoom = false;

	int StackDamage = 5;
};
