// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SkillBase.h"
#include "../Interface/PlayerInputInterface.h"
#include "PlayerSkill.generated.h"




UCLASS(Blueprintable)
class DIESELPUNK_API UPlayerSkill : public USkillBase, public IPlayerInputInterface
{
	GENERATED_BODY()
	

	
public:
	// 생성자
	UPlayerSkill();
	
protected:
	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
private:
	// 해당 스킬이 어떤 입력 방식을 가지는지 설정합니다.
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputTrigger> TriggerType;
	
public:
	// TriggerType Getter입니다.
	FORCEINLINE const TObjectPtr<UInputTrigger>& GetTriggerType() const { return TriggerType; }
	
	// Input 상황에 따른 로직 처리 함수들입니다.
	virtual void SkillStarted() override;
	virtual void SkillOngoing() override;
	virtual void SkillTriggered() override;
	virtual void SkillCompleted() override;
	virtual void SkillCanceled() override;

	// 스킬이 어떠한 이유로 인해 캔슬될 때 호출됩니다.
	virtual void CancelSkill() override;

	TMap<EAbilityType, bool> temp;

	virtual void InitSkill() {};
};


// 각 스킬들의 강화 특성입니다. 프로토타입용
UENUM(BlueprintType)
enum class ESoldierSkillLMUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CastSpeedUp				UMETA( ToolTip = "공격속도 상승"),
	StackingPercentage		UMETA( ToolTip = "스택 확률 상승"),
};

UENUM(BlueprintType)
enum class ESoldierSkillRMUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	StackingDamageUp		UMETA( ToolTip = "스택데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
};

UENUM(BlueprintType)
enum class ESoldierSkillShiftUpgradeType : uint8
{
	CoolDown				UMETA( ToolTip = "쿨감"),
};

UENUM(BlueprintType)
enum class ESoldierSkillQUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	WideRange				UMETA( ToolTip = "범위증가"),
};

UENUM(BlueprintType)
enum class ESoldierSkillEUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	StackUp					UMETA( ToolTip = "스택 상승"),
};

UENUM(BlueprintType)
enum class ESoldierSkillRUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	WideRange				UMETA( ToolTip = "범위증가"),
};



