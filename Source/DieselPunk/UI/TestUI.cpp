// Copyright GuardiansW. All Rights Reserved.


#include "TestUI.h"
#include "../Manager/UIManager.h"
#include <Components/Button.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(TestUI)


// =============================================================
// 생성자
// =============================================================
void UTestUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();
}

// =============================================================
// 소멸자
// =============================================================
void UTestUI::BeginDestroy()
{
	if ( ButtonExit )
		ButtonExit->OnClicked.Clear();

	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UTestUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UTestUI::OnDisappeared()
{
	Super::OnDisappeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UTestUI::OnExitButtonClicked()
{
	GetUIManager().RemoveUI( this );
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UTestUI::_InitControls()
{
	_InitControl( ButtonExit, TEXT( "ButtonExit" ) );

	if ( ButtonExit )
		ButtonExit->OnClicked.AddDynamic( this, &UTestUI::OnExitButtonClicked );
}