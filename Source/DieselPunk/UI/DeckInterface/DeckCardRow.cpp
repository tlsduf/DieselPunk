// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckCardRow.h"
#include "../../Card/Card.h"

#include <Components/Button.h>
#include <Components/TextBlock.h>
#include <Engine/Texture.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DeckCardRow)


// =============================================================
// 생성자
// =============================================================
void UDeckCardRow::OnCreated()
{
	Super::OnCreated();
}

// =============================================================
// 틱
// =============================================================
void UDeckCardRow::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

//카드 등록을 해지합니다. SetVisibility를 Hidden으로 변경합니다.
void UDeckCardRow::UnRegisterCard(int InIndex)
{
	UButton* button = nullptr;
	UTextBlock* text = nullptr;
	switch(InIndex)
	{
	case 0:
		button = Card0;
		text = Text0;
		break;
	case 1:
		button = Card1;
		text = Text1;
		break;
	case 2:
		button = Card2;
		text = Text2;
		break;
	case 3:
		button = Card3;
		text = Text3;
		break;
	case 4:
		button = Card4;
		text = Text4;
		break;
	default:
		LOG_SCREEN(FColor::Red, TEXT("Invalid InIndex"))
		return;
	}
	button->SetVisibility(ESlateVisibility::Hidden);
	text->SetVisibility(ESlateVisibility::Hidden);
}

//카드를 등록합니다.
void UDeckCardRow::RegisterCard(int InIndex, const CardInfo* InCardInfo)
{
	UButton* button = nullptr;
	UTextBlock* text = nullptr;
	switch(InIndex)
	{
	case 0:
		button = Card0;
		text = Text0;
		break;
	case 1:
		button = Card1;
		text = Text1;
		break;
	case 2:
		button = Card2;
		text = Text2;
		break;
	case 3:
		button = Card3;
		text = Text3;
		break;
	case 4:
		button = Card4;
		text = Text4;
		break;
	default:
		LOG_SCREEN(FColor::Red, TEXT("Invalid InIndex"))
		return;
	}

	button->SetVisibility(ESlateVisibility::Visible);
	FButtonStyle style = button->GetStyle();
	style.Normal.SetResourceObject(LoadObject<UTexture>(nullptr, *(InCardInfo->TexturePath[0])));
	style.Hovered.SetResourceObject(LoadObject<UTexture>(nullptr, *(InCardInfo->TexturePath[0])));
	style.Pressed.SetResourceObject(LoadObject<UTexture>(nullptr, *(InCardInfo->TexturePath[0])));
	button->SetStyle(style);
			
	//TEST!///////////////////////////////////////////////////////////////////////////
	//테스트를 위한 코드입니다. 추후에 이미지 적용으로 변경됩니다.
	text->SetVisibility(ESlateVisibility::Visible);
	text->SetText(FText::FromString(InCardInfo->CardName));
	//TEXT!///////////////////////////////////////////////////////////////////////////
}
