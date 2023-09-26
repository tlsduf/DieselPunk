// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillUpgradeUI.h"
#include "../../Manager/UIManager.h"
#include "../../Skill/SkillManager.h"
#include "../../Logic/PlayerControllerBase.h"
#include "../../Character/CharacterPC.h"

#include <Components/TextBlock.h>
#include <Components/Button.h>

#include <string>


#include UE_INLINE_GENERATED_CPP_BY_NAME(SkillUpgradeUI)


// =============================================================
// UI를 생성한다.
// =============================================================
USkillUpgradeUI* USkillUpgradeUI::CreateUI()
{
	return GetUIManager().CreateUnmanagedUI< USkillUpgradeUI >( TEXT( "HUD/WBP_SkillUpgradeUI" ) );
}

// =============================================================
// 난수값에 따라 위젯을 세팅합니다.
// =============================================================
void USkillUpgradeUI::SetControls()
{
	RandomNum = GetRandomNumber(0,5);

	// 텍스트 세팅
	SetText(RandomNum);

	// 함수 바인딩
	Button_Left->OnClicked.AddDynamic(this, &USkillUpgradeUI::LeftButtonClick);
	Button_Middle->OnClicked.AddDynamic(this, &USkillUpgradeUI::MiddleButtonClick);
	Button_Right->OnClicked.AddDynamic(this, &USkillUpgradeUI::RightButtonClick);
}

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

// =============================================================
// 틱
// =============================================================
void USkillUpgradeUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void USkillUpgradeUI::_InitControls()
{
	_InitControl( Button_Left, TEXT( "Button_Left" ) );
	_InitControl( Text_Skill_Left, TEXT( "Text_Skill_Left" ) );
	_InitControl( Text_SkillName_Left, TEXT( "Text_SkillName_Left" ) );
	_InitControl( Text_SkillUpgradeName_Left, TEXT( "Text_SkillUpgradeName_Left" ) );
	_InitControl( Text_SkillUpgradeExpl_Left, TEXT( "Text_SkillUpgradeExpl_Left" ) );

	_InitControl( Button_Middle, TEXT( "Button_Middle" ) );
	_InitControl( Text_Skill_Middle, TEXT( "Text_Skill_Middle" ) );
	_InitControl( Text_SkillName_Middle, TEXT( "Text_SkillName_Middle" ) );
	_InitControl( Text_SkillUpgradeName_Middle, TEXT( "Text_SkillUpgradeName_Middle" ) );
	_InitControl( Text_SkillUpgradeExpl_Middle, TEXT( "Text_SkillUpgradeExpl_Middle" ) );

	_InitControl( Button_Right, TEXT( "Button_Right" ) );
	_InitControl( Text_Skill_Right, TEXT( "Text_Skill_Right" ) );
	_InitControl( Text_SkillName_Right, TEXT( "Text_SkillName_Right" ) );
	_InitControl( Text_SkillUpgradeName_Right, TEXT( "Text_SkillUpgradeName_Right" ) );
	_InitControl( Text_SkillUpgradeExpl_Right, TEXT( "Text_SkillUpgradeExpl_Right" ) );

	// 바인드된 함수 초기화
	Button_Left->OnClicked.Clear();
	Button_Middle->OnClicked.Clear();
	Button_Right->OnClicked.Clear();
	
	// 텍스트 마우스 상호작용 비활성화
	Text_Skill_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillName_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeName_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeExpl_Left->SetVisibility(ESlateVisibility::HitTestInvisible);

	Text_Skill_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillName_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeName_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeExpl_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);

	Text_Skill_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillName_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeName_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	Text_SkillUpgradeExpl_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
}

// =============================================================
// 왼쪽 버튼이 클릭되었을 때 호출되는 함수
// =============================================================
void USkillUpgradeUI::LeftButtonClick()
{
	switch(RandomNum)
	{
	case 0 :
		PlusSoldierMouseLMUpgradeTypeDamageUp();
		break;
	case 1 :
		PlusSoldierMouseRMUpgradeTypeDamageUp();
		break;
	case 2 :
		PlusSoldierShiftUpgradeTypeDashDistance();
		break;
	case 3 :
		PlusSoldierSkillQUpgradeTypeDamageUp();
		break;
	case 4 :
		PlusSoldierSkillEUpgradeTypeDamageUp();
		break;
	case 5 :
		PlusSoldierSkillRUpgradeTypeDamageUp();
		break;
	default : break;
	}
}

// =============================================================
// 중간 버튼이 클릭되었을 때 호출되는 함수
// =============================================================
void USkillUpgradeUI::MiddleButtonClick()
{
	switch(RandomNum)
	{
	case 0 :
		PlusSoldierMouseLMUpgradeTypeCastSpeedUp();
		break;
	case 1 :
		PlusSoldierMouseRMUpgradeTypeStackingDamageUp();
		break;
	case 2 :
		PlusSoldierShiftUpgradeTypeCoolDown();
		break;
	case 3 :
		PlusSoldierSkillQUpgradeTypeCoolDown();
		break;
	case 4 :
		PlusSoldierSkillEUpgradeTypeCoolDown();
		break;
	case 5 :
		PlusSoldierSkillRUpgradeTypeCoolDown();
		break;
	default : break;
	}
}

// =============================================================
// 오른쪽 버튼이 클릭되었을 때 호출되는 함수
// =============================================================
void USkillUpgradeUI::RightButtonClick()
{
	switch(RandomNum)
	{
	case 0 :
		PlusSoldierMouseLMUpgradeTypeStackingPercentage();
		break;
	case 1 :
		PlusSoldierMouseRMUpgradeTypeCoolDown();
		break;
	case 2 :
		PlusSoldierShiftUpgradeTypeSpeedUp();
		break;
	case 3 :
		PlusSoldierSkillQUpgradeTypeAddProjectile();
		break;
	case 4 :
		PlusSoldierSkillEUpgradeTypeStackUp();
		break;
	case 5 :
		PlusSoldierSkillRUpgradeTypeWideRange();
		break;
	default : break;
	}
}

// =============================================================
// 공통적인 후처리 Task를 처리하는 함수
// =============================================================
void USkillUpgradeUI::AfterClick()
{
	// 바인드된 함수 초기화
	Button_Left->OnClicked.Clear();
	Button_Middle->OnClicked.Clear();
	Button_Right->OnClicked.Clear();

	// 플레이어 컨트롤러에서 입력 및 UI컨트롤 함수 호출
	Cast<APlayerControllerBase>(DpGetPlayerController())->SkillUpgradeEventEnd();
}

// =============================================================
// 스킬 특성에따라 텍스트를 세팅합니다.
// =============================================================
void USkillUpgradeUI::SetText(int inNum)
{
	switch(inNum)
	{
	case 0 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("사격") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("탄의 데미지가\n5 상승한다.") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("사격") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("공격속도 상승") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("탄 발사속도 -0.025") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("사격") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("스택 확률 상승") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("탄이 적중하였을 때\n스택이 쌓일 확률이\n10%p 상승한다.") ) );
		break;
	case 1 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("스택폭발") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("투사체의 데미지가\n10 상승한다.") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("스택폭발") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("스택 데미지 상승") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("스택 폭발 시\n각 스택 당 데미지가\n1 상승한다") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("스택폭발") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("쿨타임이\n0.2 줄어든다.") ) );
		break;
	case 2 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("Shift") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("전방돌격") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("대쉬거리 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("대쉬거리가\n25%p 늘어난다.") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("Shift") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("전방돌격") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("Shift") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("전방돌격") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("이동속도 증가") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("스킬사용 후의\n달리기 속도가 20 상승") ) );
		break;
	case 3 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("SkillQ") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("데미지 10 상승") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("SkillQ") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("SkillQ") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("동시투척") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("던지는 수류탄의 개수\n1개 증가") ) );
		break;
	case 4 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("SkillE") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("탄의 데미지가\n10 상승한다.") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("SkillE") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("SkillE") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("스택 수 증가") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("쌓이는 스택 수가\n1 증가한다.") ) );
		break;
	case 5 :
		Text_Skill_Left->SetText( FText::FromString( TEXT("SkillR") ) );
		Text_SkillName_Left->SetText( FText::FromString( TEXT("공습") ) );
		Text_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		Text_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("폭파 데미지가\n10 상승한다.") ) );

		Text_Skill_Middle->SetText( FText::FromString( TEXT("SkillR") ) );
		Text_SkillName_Middle->SetText( FText::FromString( TEXT("공습") ) );
		Text_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		Text_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		Text_Skill_Right->SetText( FText::FromString( TEXT("SkillR") ) );
		Text_SkillName_Right->SetText( FText::FromString( TEXT("공습") ) );
		Text_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("범위 증가") ) );
		Text_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("폭파범위 30 증가") ) );
		break;
	default : break;
	}
}