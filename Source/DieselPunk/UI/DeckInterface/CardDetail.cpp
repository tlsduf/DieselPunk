// Fill out your copyright notice in the Description page of Project Settings.


#include "CardDetail.h"
#include "../../Card/Card.h"
#include "../../Character/CharacterPc.h"
#include "../../Handler/DeckHandler.h"
#include "../../Manager/ObjectManager.h"

#include <Blueprint/WidgetTree.h>
#include <Components/Button.h>
#include <Components/Image.h>
#include <Components/TextBlock.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(CardDetail)


// =============================================================
// 생성자
// =============================================================
void UCardDetail::OnCreated()
{
	Super::NativeConstruct();
	DeckHandler = FObjectManager::GetInstance()->GetPlayer()->GetDeckHandler();

	//SetVisibility(ESlateVisibility::Collapsed);
	PreviousCard->OnClicked.AddDynamic(this, &UCardDetail::PreviousCardButtonExecute);
	NextCard->OnClicked.AddDynamic(this, &UCardDetail::NextCardButtonExecute);
	PreviousTier->OnClicked.AddDynamic(this, &UCardDetail::PreviousTierButtonExecute);
	NextTier->OnClicked.AddDynamic(this, &UCardDetail::NextTierButtonExecute);
	Exit->OnClicked.AddDynamic(this, &UCardDetail::ExitCardDetail);
}

// =============================================================
// 틱
// =============================================================
void UCardDetail::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UCardDetail::OpenCardDetail(int32 InKey)
{
	if(Cards.IsEmpty())
	{
		Cards.Add(Tier0);
		Cards.Add(Tier1);
		Cards.Add(Tier2);
	}
	
	SetVisibility(ESlateVisibility::Visible);
	TierIndex = 0;

	int32 index = 0;
	const CardInfo* info = DeckHandler->FindCardInfo(InKey, index);
	MaxTier = info->TexturePath.Num();

	//티어에 맞게 버튼을 안보이게 합니다.
	PreviousTier->SetVisibility(ESlateVisibility::Collapsed);
	if(MaxTier == TierIndex + 1)
		NextTier->SetVisibility(ESlateVisibility::Collapsed);
	else
		NextTier->SetVisibility(ESlateVisibility::Visible);

	//양 끝단의 카드일 경우 버튼을 안보이게 합니다.
	if(index == 0)
		PreviousCard->SetVisibility(ESlateVisibility::Hidden);
	else
		PreviousCard->SetVisibility(ESlateVisibility::Visible);
	TArray<const FCard*> cards;
	DeckHandler->GetDeckInterfaceCards(cards);
	if(index == cards.Num() - 1)
		NextCard->SetVisibility(ESlateVisibility::Hidden);
	else
		NextCard->SetVisibility(ESlateVisibility::Visible);
	
	//카드 이미지, 텍스트 등록
	for(int i = 0; i < info->TexturePath.Num(); ++i)
	{
		Cards[i]->SetVisibility(ESlateVisibility::Visible);
		UImage* image = Cast<UImage>((*Cards[i])[TEXT("CardImage")]);
		if(image == nullptr)
			return;
		FSlateBrush brush = image->GetBrush();
		brush.SetResourceObject(LoadObject<UTexture>(nullptr, *info->TexturePath[i]));
		image->SetBrush(brush);
		
		UTextBlock* text = Cast<UTextBlock>((*Cards[i])[TEXT("CardName")]);
		if(text == nullptr)
			return;
		text->SetText(FText::FromString(info->CardName));
	}
	for(int i = info->TexturePath.Num(); i < 3; ++i)
	{
		Cards[i]->SetVisibility(ESlateVisibility::Collapsed);
	}

	CurrentKey = InKey;
}

void UCardDetail::PreviousCardButtonExecute()
{
	int32 index = 0;
	const CardInfo* info = DeckHandler->FindCardInfo(CurrentKey, index);

	TArray<const FCard*> cards;
	DeckHandler->GetDeckInterfaceCards(cards);

	OpenCardDetail(cards[--index]->GetCardInfo().Key);
}

void UCardDetail::NextCardButtonExecute()
{
	int32 index = 0;
	const CardInfo* info = DeckHandler->FindCardInfo(CurrentKey, index);

	TArray<const FCard*> cards;
	DeckHandler->GetDeckInterfaceCards(cards);

	OpenCardDetail(cards[++index]->GetCardInfo().Key);
}

void UCardDetail::PreviousTierButtonExecute()
{
	TierIndex--;

	int32 index = 0;
	const CardInfo* info = DeckHandler->FindCardInfo(CurrentKey, index);

	for(int i = 0; i < MaxTier; ++ i)
	{
		index = TierIndex + i;
		if(index >= MaxTier)
			index = index - MaxTier;
		
		UImage* image = Cast<UImage>((*Cards[i])[TEXT("CardImage")]);
		if(image == nullptr)
			return;
		FSlateBrush brush = image->GetBrush();
		brush.SetResourceObject(LoadObject<UTexture>(nullptr, *info->TexturePath[index]));
		image->SetBrush(brush);
		
		UTextBlock* text = Cast<UTextBlock>((*Cards[i])[TEXT("CardName")]);
		if(text == nullptr)
			return;
		text->SetText(FText::FromString(info->CardName));
	}

	if(TierIndex == 0)
		PreviousTier->SetVisibility(ESlateVisibility::Collapsed);
	if(TierIndex == MaxTier - 1)
		NextTier->SetVisibility(ESlateVisibility::Collapsed);
	else
		NextTier->SetVisibility(ESlateVisibility::Visible);
}

void UCardDetail::NextTierButtonExecute()
{
	TierIndex++;

	int32 index = 0;
	const CardInfo* info = DeckHandler->FindCardInfo(CurrentKey, index);

	for(int i = 0; i < MaxTier; ++ i)
	{
		index = TierIndex + i;
		if(index >= MaxTier)
			index = index - MaxTier;
		
		UImage* image = Cast<UImage>((*Cards[i])[TEXT("CardImage")]);
		if(image == nullptr)
			return;
		FSlateBrush brush = image->GetBrush();
		brush.SetResourceObject(LoadObject<UTexture>(nullptr, *info->TexturePath[index]));
		image->SetBrush(brush);
		
		UTextBlock* text = Cast<UTextBlock>((*Cards[i])[TEXT("CardName")]);
		if(text == nullptr)
			return;
		text->SetText(FText::FromString(info->CardName));
	}

	if(TierIndex == MaxTier - 1)
		NextTier->SetVisibility(ESlateVisibility::Collapsed);
	if(TierIndex == 0)
		PreviousTier->SetVisibility(ESlateVisibility::Collapsed);
	else
		PreviousTier->SetVisibility(ESlateVisibility::Visible);
}

void UCardDetail::ExitCardDetail()
{
	SetVisibility(ESlateVisibility::Collapsed);
}
