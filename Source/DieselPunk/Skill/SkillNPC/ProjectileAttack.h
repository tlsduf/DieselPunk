// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "../../Util/SplineConstructor.h"
#include "ProjectileAttack.generated.h"


class AProjectileBase;


UCLASS()
class DIESELPUNK_API UProjectileAttack : public USkillBase
{
	GENERATED_BODY()
	
	// 체크하면 곡사로 쏩니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bHowitzer = false;

	// 체크하면 직사궤적을 나타내는 투사체를 쏩니다. 해당 투사체는 상호작용하지 않습니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bDirectFireEffect = false;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileBaseClass;

public:
	// 생성자
	UProjectileAttack();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(double InDamageCoefficient, AActor* InTarget = nullptr) override;

	// Target의 위치를 기반으로 곡사궤도를 생성하고, Projectile에 Spline정보를 줍니다.
	FSplinePath MakeSplinePath(AActor* InTarget);

	// Target의 위치를 기반으로 곡사궤도를 생성하고, Projectile에 Spline정보를 줍니다.
	FSplinePath MakeSplinePathForDirectFire(AActor* InTarget);

	// 경로 DrawDebug
	void DrawDebugSpline(FSplinePath InSpline);
};
