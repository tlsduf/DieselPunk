// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageUI.h"
#include <Components/TextBlock.h>

#include <string>

#include "Animation/AnimBoneCompressionCodec.h"

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

	InitWidget();
	AlphaAnimator.SetParam()
	AlphaAnimator.Start();
}

void UDamageUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// 데미지 텍스트 알파값 애니메이팅
	AlphaAnimator.Update(InDeltaTime);
	Alpha = AlphaAnimator.GetCurValue();
	FLinearColor linearColor = FLinearColor(GetColorAndOpacity().R, GetColorAndOpacity().G, GetColorAndOpacity().B, Alpha);
	SetColorAndOpacity(linearColor);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UDamageUI::InitWidget()
{
	if(Cast<UTextBlock>( GetWidgetFromName("DamageText")) != nullptr)
		DamageText = Cast<UTextBlock>( GetWidgetFromName("DamageText"));
}

