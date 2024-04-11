// Fill out your copyright notice in the Description page of Project Settings.


#include "Hand.h"
#include "../../Card/Card.h"
#include "../../Character/CharacterPC.h"
#include "../../Manager/ObjectManager.h"
#include "../../Character/CharacterPC.h"
#include "../../Component/StatControlComponent.h"
#include "../../Handler/DeckHandler.h"

#include <Components/SizeBox.h>
#include <Components/Image.h>
#include <Components/TextBlock.h>
#include <Blueprint/WidgetTree.h>
#include <Animation/WidgetAnimation.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(Hand)


// =============================================================
// 생성자
// =============================================================
void UHand::OnCreated()
{
	Super::OnCreated();
}

void UHand::Initailize(ACharacterPC* InPlayer)
{
	InPlayer->GetStatControlComponent()->GetSetStatDelegate().AddUObject(this, &UHand::ChangeCredit);
	InPlayer->GetDelegateChangeDeckCount().AddUObject(this, &UHand::ChangeDeckCount);
}

// =============================================================
// 틱
// =============================================================
void UHand::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

//카드들을 등록합니다
void UHand::RegisterHands(TArray<FCard*> InHands)
{
	for(int i = 0; i < InHands.Num(); ++i)
	{
		if(InHands[i] != nullptr)
			RegisterHand(i, &InHands[i]->GetCardInfo());
		else
			UnRegisterHand(i);
	}
}

//카드를 등록합니다.
void UHand::RegisterHand(int InIndex, const CardInfo* InCardInfo)
{
	UUserWidgetBase* card = nullptr;
	switch(InIndex)
	{
	case 0:
		card = Hand0;
		break;
	case 1:
		card = Hand1;
		break;
	case 2:
		card = Hand2;
		break;
	case 3:
		card = Hand3;
		break;
	case 4:
		card = Hand4;
		break;
	default:
		return;
	}

	UImage* image = Cast<UImage>((*card)[TEXT("CardImage")]);
	if(image == nullptr)
		return;

	card->SetVisibility(ESlateVisibility::Visible);
	FSlateBrush brush = image->GetBrush();
	brush.SetResourceObject(LoadObject<UTexture>(nullptr, *(InCardInfo->TexturePath[0])));
	image->SetBrush(brush);

	UTextBlock* text = Cast<UTextBlock>((*card)[TEXT("CardName")]);
	if(text == nullptr)
		return;
	if(InCardInfo->TexturePath[0].Find(TEXT("TestSmall")) != INDEX_NONE)
	{
		text->SetVisibility(ESlateVisibility::Visible);
		text->SetText(FText::FromString(InCardInfo->CardName));
	}
	else
	{
		text->SetVisibility(ESlateVisibility::Collapsed);
		UTextBlock* cost = Cast<UTextBlock>((*card)[TEXT("Cost")]);
		if(cost)
			cost->SetText(FText::FromString(FString::FromInt(InCardInfo->Cost)));
	}
}

//카드 등록 해제합니다. Visibility를 Hidden으로 변경합니다.
void UHand::UnRegisterHand(int InIndex)
{
	UUserWidgetBase* card = nullptr;
	switch(InIndex)
	{
	case 0:
		card = Hand0;
		break;
	case 1:
		card = Hand1;
		break;
	case 2:
		card = Hand2;
		break;
	case 3:
		card = Hand3;
		break;
	case 4:
		card = Hand4;
		break;
	default:
		return;
	}
	card->SetVisibility(ESlateVisibility::Hidden);
	UUserWidgetBase* cards[FDeckHandler::MaxHand];
	cards[0] = Hand0;
	cards[1] = Hand1;
	cards[2] = Hand2;
	cards[3] = Hand3;
	cards[4] = Hand4;

	bool isDraw = true;

	for(int i = 0; i < FDeckHandler::MaxHand; ++i)
	{
		if(cards[i]->GetVisibility() != ESlateVisibility::Hidden)
		{
			isDraw = false;
			break;
		}
	}

	if(isDraw)
		FObjectManager::GetInstance()->GetPlayer()->DrawCard();
}

UWidgetAnimation* UHand::PlayHandToHangerAnimation(int InIndex)
{
	UWidgetAnimation* anim = nullptr;
	switch(InIndex)
	{
	case 0:
		anim = Hand0ToHanger;
		break;
	case 1:
		anim = Hand1ToHanger;
		break;
	case 2:
		anim = Hand2ToHanger;
		break;
	case 3:
		anim = Hand3ToHanger;
		break;
	case 4:
		anim = Hand4ToHanger;
		break;
	default:
		return nullptr;
	}
	
	PlayAnimation(anim, 0.0f, 1, EUMGSequencePlayMode::Forward, 1, true);
	return anim; 
}

//드로우 애니메이션을 재생합니다.
void UHand::PlayDrawAnimation()
{
	PlayAnimation(DrawAnimation);
}

//카드의 사이즈를 변경합니다.
void UHand::ResizeHandCard(int InIndex, FVector2d InSize)
{
	UUserWidgetBase* card = nullptr;
	switch(InIndex)
	{
	case 0:
		card = Hand0;
		break;
	case 1:
		card = Hand1;
		break;
	case 2:
		card = Hand2;
		break;
	case 3:
		card = Hand3;
		break;
	case 4:
		card = Hand4;
		break;
	default:
		return;
	}
	
	USizeBox* sizebox = Cast<USizeBox>((*card)[TEXT("SizeBox")]);
	if(sizebox == nullptr)
		return;
	
	sizebox->SetRenderScale(InSize);
}

void UHand::ChangeCredit(TWeakObjectPtr<AActor> InCharacter, ECharacterStatType InStatType, int32 InValue)
{
	if(InStatType != ECharacterStatType::Cost)
		return;

	Cost = InValue;

	TextCost->SetText(FText::FromString(FString::Printf(TEXT("%d"), Cost)));
}

void UHand::ChangeDeckCount(int32 InValue)
{
	TextDeckCount->SetText(FText::FromString(FString::Printf(TEXT("%d"), InValue)));
}
