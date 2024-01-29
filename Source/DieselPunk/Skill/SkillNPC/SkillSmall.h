// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "SkillSmall.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API USkillSmall : public USkillBase
{
	GENERATED_BODY()

public:
	// 생성자
	USkillSmall();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* inTarget) override;
	
	float CaptureDamage;	// 람다함수 캡쳐용 변수

private:
	FVector ShotLocation;
	FRotator ShotRotation;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileBaseClass;

	FTimerHandle FireHandle2;
	FTimerHandle FireHandle3;
	FTimerHandle FireHandle4;

};
