// Copyright GuardiansW. All Rights Reserved.


#include "DamageUI.h"
#include "../../Manager/UIManager.h"
#include <Components/TextBlock.h>

#include <string>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DamageUI)


void UDamageUI::SetDamage(float inDamage)
{
	int intDamage = inDamage;
	Damage = inDamage;
	if( DamageText )
		DamageText->SetText( FText::FromString( FString::FromInt(intDamage) ) );

	// 데미지 별 색상 set
	if(0 < Damage && Damage <= 14)
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1)));
	else if(14 < Damage && Damage <= 29)
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(0.5, 0.2, 0.2)));
	else if(29 < Damage && Damage <= 49)
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(0.5, 0.1, 0)));
	else if(49 < Damage && Damage <= 74)
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(0.5, 0.05, 0)));
	else if(74 < Damage )
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(0.4, 0, 0.2)));
	else
		DamageText->SetColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1)));
}

// =============================================================
// 생성자
// =============================================================
void UDamageUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();

	StartAnimator();
}

// =============================================================
// 소멸자
// =============================================================
void UDamageUI::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UDamageUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UDamageUI::OnDisappeared()
{
	Super::OnDisappeared();
}

void UDamageUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	AlphaAnimator.Update(InDeltaTime);
	FLinearColor linearColor = FLinearColor(GetColorAndOpacity().R, GetColorAndOpacity().G, GetColorAndOpacity().B, Alpha);
	SetColorAndOpacity(linearColor);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UDamageUI::_InitControls()
{
	_InitControl( DamageText, TEXT( "DamageText" ) );
}

void UDamageUI::StartAnimator()
{
	// XY 애니메이터
	AnimatorParam param;
	param.AnimType = EAnimType::CubicEaseIn;
	param.StartValue = 1.f;
	param.EndValue = 0.f;
	param.DurationTime = 1.5f;

	TWeakObjectPtr<UDamageUI> thisPtr = this;
	param.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->Alpha = InCurValue;
	};

	AlphaAnimator.Start(param);
}
