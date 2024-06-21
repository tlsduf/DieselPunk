// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "../../Util/SplineConstructor.h"
#include "ThrowingAttack.generated.h"

class AProjectileBase;
UCLASS()
class DIESELPUNK_API UThrowingAttack : public USkillBase
{
	GENERATED_BODY()

	//던질 액터 클래스
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	TSubclassOf<AActor> ThrowingActorClass = nullptr;

	//최대 체공 시간
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	double MaxFlightTime = 3.f;

	//ArcValue
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting", meta=(ClampMin=0.0, ClampMax=1.0))
	double ArcValue = 0.5;

	////InitSpeed
	//UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	//double InitSpeed = 5000.f;

	////HighArc
	//UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	//bool HighArc = true;
	
	int32 ThrowActorId = -9999;

public:
	// 생성자
	UThrowingAttack();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;
};