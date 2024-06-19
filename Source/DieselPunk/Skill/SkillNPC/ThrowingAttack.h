// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "../../Util/SplineConstructor.h"
#include "ThrowingAttack.generated.h"


struct FThrowActorSplineInfo
{
	FSplinePath SplinePath;

	double FlightTime = 1.f;
	float FlightDelta = 0.f;
};

class AProjectileBase;
UCLASS()
class DIESELPUNK_API UThrowingAttack : public USkillBase
{
	GENERATED_BODY()

	//던질 액터 클래스
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	TSubclassOf<AActor> ThrowingActorClass = nullptr;

	//높이 계수, 포물선 운동의 높이 계산에 들어가는 계수입니다. 적으면 적을수록 직사에 가깝게 날라갑니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	double HeightCoefficient = 2000.f;

	//최대 체공 시간
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	double MaxFlightTime = 3.f;

	int32 ThrowActorId = -9999;

	TMap<int32, FThrowActorSplineInfo> ThrowActorInfos;

public:
	// 생성자
	UThrowingAttack();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;

protected:
	// Target의 위치를 기반으로 곡사궤도를 생성하고, Projectile에 Spline정보를 줍니다.
	bool MakeSplinePath(AActor* InTarget, float InFlightTime, FSplinePath* OutSplinePath);
};