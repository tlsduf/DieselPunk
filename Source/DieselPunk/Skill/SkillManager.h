// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

/*
 * !! 20231124 부로 사용하고있지 않습니다. !!
 * 
 */


#include <functional>


// 각 스킬들의 강화 특성입니다. 프로토타입용
enum class ESoldierMouseLMUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CastSpeedUp				UMETA( ToolTip = "공격속도 상승"),
	StackingPercentage		UMETA( ToolTip = "스택 확률 상승"),
};

enum class ESoldierMouseRMUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	StackingDamageUp		UMETA( ToolTip = "스택데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
};

enum class ESoldierShiftUpgradeType : uint8
{
	DashDistance			UMETA( ToolTip = "대쉬거리"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	SpeedUp					UMETA( ToolTip = "이동속도 증가"),
};

enum class ESoldierSkillQUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	AddProjectile			UMETA( ToolTip = "범위증가"),
};

enum class ESoldierSkillEUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	StackUp					UMETA( ToolTip = "스택 상승"),
};

enum class ESoldierSkillRUpgradeType : uint8
{
	DamageUp				UMETA( ToolTip = "데미지 상승"),
	CoolDown				UMETA( ToolTip = "쿨감"),
	WideRange				UMETA( ToolTip = "범위증가"),
};


class SkillManager
{
public:
	TMap<ESoldierMouseLMUpgradeType, int8>	SoldierMouseLMUpgradeType;
	TMap<ESoldierMouseRMUpgradeType, int8>	SoldierMouseRMUpgradeType;
	TMap<ESoldierShiftUpgradeType, int8>	SoldierShiftUpgradeType;
	TMap<ESoldierSkillQUpgradeType, int8>	SoldierSkillQUpgradeType;
	TMap<ESoldierSkillEUpgradeType, int8>	SoldierSkillEUpgradeType;
	TMap<ESoldierSkillRUpgradeType, int8>	SoldierSkillRUpgradeType;
	
public:
	// 생성자
	SkillManager();

	// 소멸자
	~SkillManager();

	// 스킬 특성을 초기화합니다.
	void ResetSkill();
};



