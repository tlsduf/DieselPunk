// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <Components/ActorComponent.h>

#include "SkillBase.generated.h"

class UInputTrigger;
class FCoolTimeHandler;

UCLASS(Blueprintable)
class DIESELPUNK_API USkillBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 쿨타임을 관리하기 위한 CoolTime Handler입니다.
	FCoolTimeHandler* CoolTimeHandler;

public:
	UPROPERTY(EditAnywhere, Category = Skill)
	float CoolTime = 5;

	// 스킬 발동 시간입니다. 해당 시간동안 SkillActivating이 On 됩니다.
	UPROPERTY(EditAnywhere, Category = Skill)
	float SkillPlayTime = 1;
public:
	// Sets default values for this component's properties
	USkillBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// 소멸자 용도로 쓸 BeginDestroy
	virtual void BeginDestroy() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	// 스킬이 어떠한 이유로 인해 캔슬될 때 호출됩니다.
	virtual void CancelSkill(){};

	// 능력이 사용 가능한지 확인합니다.
	// 마나, 상태 이상 등 더 필요한 것들을 추후 추가할 예정입니다.
	// 더 자세한 확인 필요 시 오버라이드하여 Super::를 통해 같이 호출하여 사용하시면 됩니다.
	virtual bool CanActivateAbility();

	virtual float GetCoolTime();

	virtual float GetCoolTimePercent();
};
