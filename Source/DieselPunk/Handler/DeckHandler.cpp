// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckHandler.h"

#include "../Card/TurretCard.h"
#include "../Data/CardDataTable.h"
#include "../Manager/DatatableManager.h"


FDeckHandler::FDeckHandler(TWeakObjectPtr<ACharacterPC> InOwner)
	: Owner(InOwner)
{
}

FDeckHandler::~FDeckHandler()
{
	for(FCard* card : Manager)
		delete card;
	Manager.Empty();
	Deck.Empty();
	Hand.Empty();
	Hanger.Empty();
}

//게임 시작 시 호출해야할 함수를 호출합니다.
void FDeckHandler::BeginPlay()
{
	FGenericPlatformMath::SRandInit(time(nullptr));
}

//스테이지 시작 시 덱을 초기화합니다.
void FDeckHandler::BeginPlayStage()
{
	Deck.Empty();
	Hand.Empty();
	Hand.SetNum(MaxHand);
	Hanger.Empty();

	//덱에 카드 추가
	for(FCard* card : Manager)
		Deck.Push(card);

	//카드 섞기
	ShuffleDeck();

	//카드 드로우
	Draw();
}

//카드를 정렬 방법에 따라 정렬합니다.
void FDeckHandler::SortCard(TArray<const FCard*>& OutCards, ECardSortType InSortType)
{
	switch (InSortType)
	{
	case ECardSortType::Order:
		OutCards.Sort([](const FCard& lhs, const FCard& rhs)
		{
			return lhs.GetCardInfo().GetTime <= rhs.GetCardInfo().GetTime;
		});
		break;
	case ECardSortType::Name:
		OutCards.Sort([](const FCard& lhs, const FCard& rhs)
		{
			return lhs.GetCardInfo().CardName <= rhs.GetCardInfo().CardName;
		});
		break;
	case ECardSortType::Cost:
		OutCards.Sort([](const FCard& lhs, const FCard& rhs)
		{
			return lhs.GetCardInfo().Cost <= rhs.GetCardInfo().Cost;
		});
		break;
	}
}

//덱 인터페이스에 출력하기 위한 카드를 반환합니다.
void FDeckHandler::GetDeckInterfaceCards(TArray<const FCard*>& OutCards, ECardFilterType InFilterType, ECardSortType InSortType)
{
	if(InFilterType != ECardFilterType::None)
		FilterType = InFilterType;

	if(InSortType != ECardSortType::None)
		SortType = InSortType;
	
	for(const FCard* card : Manager)
		if(FilterType == ECardFilterType::All || static_cast<uint8>(card->GetCardInfo().CardType) == static_cast<uint8>(FilterType))
			OutCards.Add(card);

	SortCard(OutCards, SortType);
}

//카드를 생성하고 추가합니다.
void FDeckHandler::AddCard(FString InCardName)
{
	const FCardDataTable* data = FDataTableManager::GetInstance()->GetData<FCardDataTable>(EDataTableType::Card, InCardName);
	if(data == nullptr)
		return;

	FCard* card = nullptr;
	
	switch (data->CardType)
	{
	case ECardType::Ability:
		card = new FTurretCard(InCardName, Owner);
		break;
	case ECardType::Turret:
		card = new FTurretCard(InCardName, Owner);
		break;
	case ECardType::Installation:
		card = new FTurretCard(InCardName, Owner);
		break;
	default:
		LOG_SCREEN(FColor::Red, TEXT("FDeckHandler::AddCard() : 등록되지 않은 ECardType입니다."))
		break;
	}

	if(card == nullptr)
		return;

	Manager.Push(card);
}

void FDeckHandler::DeleteCard(FString InCardName)
{
	for(TArray<FCard*>::TIterator iter = Manager.CreateIterator(); iter; ++iter)
	{
		if((*iter)->GetCardInfo().CardName == InCardName)
		{
			iter.RemoveCurrent();
			return;
		}
	}
}

//카드를 드로우 합니다. 패에 카드가 있을 경우 드로우하지 않습니다. 덱에 카드가 없을 때 행거의 카드를 가져와 리필합니다.
bool FDeckHandler::Draw()
{
	//패에 카드가 있으면 드로우 안함.
	for(const FCard* card : Hand)
		if(card != nullptr)
			return false;

	//드로우
	for(int i = 0; i < MaxHand; ++i)
	{
		//덱에 카드가 없을 경우 카드 리필
		if(Deck.IsEmpty())
			RefillDeck();
		
		Hand[i] = Deck.Pop();
	}
	return true;
}

//카드를 리플레이스 합니다. 패에 있는 카드를 버리고 다시 카드를 뽑습니다. 덱에 카드가 없을 때 행거의 카드를 가져와 리필합니다.
void FDeckHandler::Replace()
{
	//패에 남아있는 카드를 행거로 보냄
	for(int i = 0; i < MaxHand; ++i)
	{
		if(Hand[i] != nullptr)
		{
			Hanger.Push(Hand[i]);
			Hand[i] = nullptr;
		}
	}

	//드로우
	Draw();
}

//카드를 섞습니다.
void FDeckHandler::ShuffleDeck()
{
	Deck.Sort([](const FCard& lhs, const FCard& rhs)
	{
		return FMath::SRand() < 0.5f;
	});
}

//행거에서 덱의 카드를 보충합니다.
void FDeckHandler::RefillDeck()
{
	//덱에 카드가 없을 경우만 진행
	if(!Deck.IsEmpty())
		return;

	//행거의 모든 카드를 덱으로 보냄
	while(!Hanger.IsEmpty())
		Deck.Add(Hanger.Pop());

	//셔플
	ShuffleDeck();
}

//패에서 카드를 사용합니다.
void FDeckHandler::UseCard(int32 InUseCardNum)
{
	if(Hand[InUseCardNum] == nullptr)
		return;

	Hanger.Add(Hand[InUseCardNum]);

	Hand[InUseCardNum] = nullptr;
}
