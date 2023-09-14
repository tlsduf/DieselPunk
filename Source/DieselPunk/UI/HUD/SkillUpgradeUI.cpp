// Copyright GuardiansW. All Rights Reserved.


#include "SkillUpgradeUI.h"
#include "../../Manager/UIManager.h"
#include <Components/TextBlock.h>

#include <string>

#include UE_INLINE_GENERATED_CPP_BY_NAME(SkillUpgradeUI)


// =============================================================
// 생성자
// =============================================================
void USkillUpgradeUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();
}

// =============================================================
// 소멸자
// =============================================================
void USkillUpgradeUI::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void USkillUpgradeUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void USkillUpgradeUI::OnDisappeared()
{
	Super::OnDisappeared();
}

void USkillUpgradeUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void USkillUpgradeUI::_InitControls()
{
	_InitControl( DamageText, TEXT( "DamageText" ) );
}
