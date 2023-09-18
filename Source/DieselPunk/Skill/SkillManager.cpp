// Copyright GuardiansW. All Rights Reserved.


#include "SkillManager.h"


// =============================================================
// 생성자
// =============================================================
SkillManager::SkillManager()
{

}

// =============================================================
// 소멸자
// =============================================================
SkillManager::~SkillManager()
{
	
}

// =============================================================
// 스킬 특성을 초기화합니다. //CharacterPC 비긴플레이에서 호출
// =============================================================
void SkillManager::ResetSkill()
{
	// MouseLM 초기화
	SoldierMouseLMUpgradeType.Empty();
	SoldierMouseLMUpgradeType.Add(ESoldierMouseLMUpgradeType::DamageUp,0);
	SoldierMouseLMUpgradeType.Add(ESoldierMouseLMUpgradeType::CastSpeedUp,0);
	SoldierMouseLMUpgradeType.Add(ESoldierMouseLMUpgradeType::StackingPercentage,0);

	// MouseRM 초기화
	SoldierMouseRMUpgradeType.Empty();
	SoldierMouseRMUpgradeType.Add(ESoldierMouseRMUpgradeType::DamageUp,0);
	SoldierMouseRMUpgradeType.Add(ESoldierMouseRMUpgradeType::StackingDamageUp,0);
	SoldierMouseRMUpgradeType.Add(ESoldierMouseRMUpgradeType::CoolDown,0);

	// Shift 초기화
	SoldierShiftUpgradeType.Empty();
	SoldierShiftUpgradeType.Add(ESoldierShiftUpgradeType::DashDistance,0);
	SoldierShiftUpgradeType.Add(ESoldierShiftUpgradeType::CoolDown,0);
	SoldierShiftUpgradeType.Add(ESoldierShiftUpgradeType::SpeedUp,0);

	// SkillQ 초기화
	SoldierSkillQUpgradeType.Empty();
	SoldierSkillQUpgradeType.Add(ESoldierSkillQUpgradeType::DamageUp,0);
	SoldierSkillQUpgradeType.Add(ESoldierSkillQUpgradeType::CoolDown,0);
	SoldierSkillQUpgradeType.Add(ESoldierSkillQUpgradeType::AddProjectile,0);

	// SkillE 초기화
	SoldierSkillEUpgradeType.Empty();
	SoldierSkillEUpgradeType.Add(ESoldierSkillEUpgradeType::DamageUp,0);
	SoldierSkillEUpgradeType.Add(ESoldierSkillEUpgradeType::CoolDown,0);
	SoldierSkillEUpgradeType.Add(ESoldierSkillEUpgradeType::StackUp,0);

	// SkillR 초기화
	SoldierSkillRUpgradeType.Empty();
	SoldierSkillRUpgradeType.Add(ESoldierSkillRUpgradeType::DamageUp,0);
	SoldierSkillRUpgradeType.Add(ESoldierSkillRUpgradeType::CoolDown,0);
	SoldierSkillRUpgradeType.Add(ESoldierSkillRUpgradeType::WideRange,0);
}
