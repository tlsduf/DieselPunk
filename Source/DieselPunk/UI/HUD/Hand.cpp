// Fill out your copyright notice in the Description page of Project Settings.


#include "Hand.h"
#include "../../Card/Card.h"
#include "../../Character/CharacterPC.h"
#include "../../Manager/ObjectManager.h"
#include "../../Character/CharacterPC.h"

#include <Components/SizeBox.h>
#include <Components/Image.h>
#include <Components/TextBlock.h>
#include <Blueprint/WidgetTree.h>
#include <Animation/WidgetAnimation.h>

#include "DieselPunk/Handler/DeckHandler.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(Hand)


// =============================================================
// 생성자
// =============================================================
void UHand::OnCreated()
{
	Super::OnCreated();

	ACharacterPC* player = FObjectManager::GetInstance()->GetPlayer();
	player->GetStat().GetChangeStatDelegate().AddUObject(this, &UHand::ChangeCredit);
	player->GetDelegateChangeDeckCount().AddUObject(this, &UHand::ChangeDeckCount);
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
		RegisterHand(i, &InHands[i]->GetCardInfo());
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
	text->SetText(FText::FromString(InCardInfo->CardName));
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
	FObjectManager::GetInstance()->GetPlayer()->DrawCard();
}

void UHand::PlayHandToHangerAnimation(int InIndex)
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
		return;
	}

	PlayAnimation(anim, 0.0f, 1, EUMGSequencePlayMode::Forward, 1, true);
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

void UHand::ChangeCredit(TWeakObjectPtr<ACharacterBase> InCharacter, ECharacterStatType InStatType, int32 InValue)
{
	if(InStatType != ECharacterStatType::Cost)
		return;

	Cost += InValue;

	TextCost->SetText(FText::FromString(FString::Printf(TEXT("%d"), Cost)));
}

void UHand::ChangeDeckCount(int32 InValue)
{
	TextDeckCount->SetText(FText::FromString(FString::Printf(TEXT("%d"), InValue)));
}
