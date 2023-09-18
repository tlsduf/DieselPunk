// Copyright GuardiansW. All Rights Reserved.


#include "DamageBrowserUI.h"
#include "../../Manager/UIManager.h"
#include <Components/TextBlock.h>

#include <string>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DamageBrowserUI)


// =============================================================
// UI를 생성한다.
// =============================================================
UDamageBrowserUI* UDamageBrowserUI::CreateUI()
{
	return GetUIManager().CreateUnmanagedUI< UDamageBrowserUI >( TEXT( "HUD/WBP_SkillBrowserUI" ) );
}

// =============================================================
// 생성자
// =============================================================
void UDamageBrowserUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();
}

// =============================================================
// 소멸자
// =============================================================
void UDamageBrowserUI::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UDamageBrowserUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UDamageBrowserUI::OnDisappeared()
{
	Super::OnDisappeared();
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UDamageBrowserUI::_InitControls()
{
	_InitControl( DamageText, TEXT( "DamageText" ) );
}

