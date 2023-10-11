// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillUpgradeUI.h"
#include "../../Skill/SkillManager.h"
#include "../../Logic/PlayerControllerBase.h"
#include "../../Character/CharacterPC.h"

#include <Components/TextBlock.h>
#include <Components/Button.h>

#include <string>


#include UE_INLINE_GENERATED_CPP_BY_NAME(SkillUpgradeUI)


// =============================================================
// 난수값에 따라 위젯을 세팅합니다.
// =============================================================
void USkillUpgradeUI::SetControls()
{
	RandomNum = GetRandomNumber(0,5);

	// 텍스트 세팅
	SetText(RandomNum);

	// 함수 바인딩
	InButton_Left->OnClicked.AddDynamic(this, &USkillUpgradeUI::LeftButtonClick);
	InButton_Middle->OnClicked.AddDynamic(this, &USkillUpgradeUI::MiddleButtonClick);
	InButton_Right->OnClicked.AddDynamic(this, &USkillUpgradeUI::RightButtonClick);
}

// =============================================================
// 생성자
// =============================================================
void USkillUpgradeUI::OnCreated()
{
	Super::OnCreated();

	InitWidget();
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
void USkillUpgradeUI::InitWidget()
{
	if(Cast<UButton>( GetWidgetFromName("Button_Left")) != nullptr)
		InButton_Left = Cast<UButton>( GetWidgetFromName("Button_Left"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Left")) != nullptr)
		InText_Skill_Left = Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Left"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Left")) != nullptr)
		InText_SkillName_Left = Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Left"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Left")) != nullptr)
		InText_SkillUpgradeName_Left = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Left"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Left")) != nullptr)
		InText_SkillUpgradeExpl_Left = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Left"));

	if(Cast<UButton>( GetWidgetFromName("Button_Middle")) != nullptr)
		InButton_Middle = Cast<UButton>( GetWidgetFromName("Button_Middle"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Middle")) != nullptr)
		InText_Skill_Middle = Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Middle"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Middle")) != nullptr)
		InText_SkillName_Middle = Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Middle"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Middle")) != nullptr)
		InText_SkillUpgradeName_Middle = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Middle"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Middle")) != nullptr)
		InText_SkillUpgradeExpl_Middle = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Middle"));

	if(Cast<UButton>( GetWidgetFromName("Button_Right")) != nullptr)
		InButton_Right = Cast<UButton>( GetWidgetFromName("Button_Right"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Right")) != nullptr)
		InText_Skill_Right = Cast<UTextBlock>( GetWidgetFromName("Text_Skill_Right"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Right")) != nullptr)
		InText_SkillName_Right = Cast<UTextBlock>( GetWidgetFromName("Text_SkillName_Right"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Right")) != nullptr)
		InText_SkillUpgradeName_Right = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeName_Right"));
	if(Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Right")) != nullptr)
		InText_SkillUpgradeName_Right = Cast<UTextBlock>( GetWidgetFromName("Text_SkillUpgradeExpl_Right"));

	// 바인드된 함수 초기화
	InButton_Left->OnClicked.Clear();
	InButton_Middle->OnClicked.Clear();
	InButton_Right->OnClicked.Clear();
	
	// 텍스트 마우스 상호작용 비활성화
	InText_Skill_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillName_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeName_Left->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeExpl_Left->SetVisibility(ESlateVisibility::HitTestInvisible);

	InText_Skill_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillName_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeName_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeExpl_Middle->SetVisibility(ESlateVisibility::HitTestInvisible);

	InText_Skill_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillName_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeName_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
	InText_SkillUpgradeExpl_Right->SetVisibility(ESlateVisibility::HitTestInvisible);
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
	InButton_Left->OnClicked.Clear();
	InButton_Middle->OnClicked.Clear();
	InButton_Right->OnClicked.Clear();

	// 플레이어 컨트롤러에서 입력 및 UI컨트롤 함수 호출
	Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SkillUpgradeEventEnd();
}

// =============================================================
// 스킬 특성에따라 텍스트를 세팅합니다.
// =============================================================
void USkillUpgradeUI::SetText(int inNum)
{
	switch(inNum)
	{
	case 0 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("사격") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("탄의 데미지가\n5 상승한다.") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("사격") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("공격속도 상승") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("탄 발사속도 -0.025") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("마우스좌클릭") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("사격") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("스택 확률 상승") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("탄이 적중하였을 때\n스택이 쌓일 확률이\n10%p 상승한다.") ) );
		break;
	case 1 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("스택폭발") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("투사체의 데미지가\n10 상승한다.") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("스택폭발") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("스택 데미지 상승") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("스택 폭발 시\n각 스택 당 데미지가\n1 상승한다") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("마우스우클릭") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("스택폭발") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("쿨타임이\n0.2 줄어든다.") ) );
		break;
	case 2 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("Shift") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("전방돌격") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("대쉬거리 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("대쉬거리가\n25%p 늘어난다.") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("Shift") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("전방돌격") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("Shift") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("전방돌격") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("이동속도 증가") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("스킬사용 후의\n달리기 속도가 20 상승") ) );
		break;
	case 3 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("SkillQ") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("데미지 10 상승") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("SkillQ") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("SkillQ") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("특수파편수류탄") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("동시투척") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("던지는 수류탄의 개수\n1개 증가") ) );
		break;
	case 4 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("SkillE") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("탄의 데미지가\n10 상승한다.") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("SkillE") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("SkillE") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("지연폭발탄") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("스택 수 증가") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("쌓이는 스택 수가\n1 증가한다.") ) );
		break;
	case 5 :
		InText_Skill_Left->SetText( FText::FromString( TEXT("SkillR") ) );
		InText_SkillName_Left->SetText( FText::FromString( TEXT("공습") ) );
		InText_SkillUpgradeName_Left->SetText( FText::FromString( TEXT("데미지 상승") ) );
		InText_SkillUpgradeExpl_Left->SetText( FText::FromString( TEXT("폭파 데미지가\n10 상승한다.") ) );

		InText_Skill_Middle->SetText( FText::FromString( TEXT("SkillR") ) );
		InText_SkillName_Middle->SetText( FText::FromString( TEXT("공습") ) );
		InText_SkillUpgradeName_Middle->SetText( FText::FromString( TEXT("쿨타임 감소") ) );
		InText_SkillUpgradeExpl_Middle->SetText( FText::FromString( TEXT("쿨타임이\n0.5 줄어든다.") ) );

		InText_Skill_Right->SetText( FText::FromString( TEXT("SkillR") ) );
		InText_SkillName_Right->SetText( FText::FromString( TEXT("공습") ) );
		InText_SkillUpgradeName_Right->SetText( FText::FromString( TEXT("범위 증가") ) );
		InText_SkillUpgradeExpl_Right->SetText( FText::FromString( TEXT("폭파범위 30 증가") ) );
		break;
	default : break;
	}
}