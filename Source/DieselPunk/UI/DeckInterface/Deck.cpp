// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "DeckCardRow.h"
#include "../../Handler/DeckHandler.h"
#include "../../Card/Card.h"
#include "../../Manager/UIManager.h"

#include <Components/ScrollBox.h>

#include "CardDetail.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(Deck)


// =============================================================
// 생성자
// =============================================================
void UDeck::OnCreated()
{
	Super::NativeConstruct();
	CardDetail->OnCreated();
	CardDetail->SetVisibility(ESlateVisibility::Collapsed);
}

void UDeck::BeginDestroy()
{
	if(SBox != nullptr)
		SBox->ClearChildren();
	
	for(TWeakObjectPtr<UUserWidget> widget : CardRows)
		if(widget.IsValid())
			widget->Destruct();
	CardRows.Empty();

	RemoveFromParent();
	
	Super::BeginDestroy();
}

// =============================================================
// 틱
// =============================================================
void UDeck::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

//카드를 등록합니다.
void UDeck::RegisterCards(TArray<const FCard*> InCards)
{
	int32 num = (InCards.Num() % FDeckHandler::MaxHand == 0) ? InCards.Num() / FDeckHandler::MaxHand : InCards.Num() / FDeckHandler::MaxHand + 1;
	if(SBox == nullptr)
		return;

	for(int i = 0; i < num; ++i)
	{
		//들어온 카드보다 만들어져있는 카드 열이 정다면 카드 열을 추가로 생성합니다.
		if(i >= CardRows.Num())
		{
			FString widgetName = FString::Printf(TEXT("CardRow_%d"), i);
			int32 key = FUIManager::GetInstance()->CreateWidgetBase(TEXT("DeckInterface/Blueprint/"), TEXT("WBP_DeckCardRow"), widgetName, this);
			UDeckCardRow* row = Cast<UDeckCardRow>(FindWidgetBase(key)); 
			row->SetDeck(this);
			SBox->AddChild(row);
			CardRows.Push(row);
		}

		//카드 열이 접혀있다면 다시 Visible로 바꿉니다.
		if(CardRows[i]->GetIsEnabled() == false)
			CardRows[i]->SetIsEnabled(true);
		if(CardRows[i]->GetVisibility() == ESlateVisibility::Collapsed)
			CardRows[i]->SetVisibility(ESlateVisibility::Visible);

		//카드에 정보를 등록합니다.
		for(int j = 0; j < FDeckHandler::MaxHand; ++j)
		{
			int index = FDeckHandler::MaxHand * i + j;

			if(index < InCards.Num())
				CardRows[i]->RegisterCard(j, &InCards[index]->GetCardInfo());
			else
				CardRows[i]->UnRegisterCard(j);
		}
	}
	//들어온 카드 정보보다 열이 많다면 불필요한 열을 접습니다.
	for(int i = num; i < CardRows.Num(); ++i)
	{
		CardRows[i]->SetIsEnabled(false);
		CardRows[i]->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UDeck::CreateCardDetail(int32 InKey)
{
	CardDetail->OpenCardDetail(InKey);
}
