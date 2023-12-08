// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
/**
 * Deck을 관리하는 핸들러입니다.
 */

class FCard;
class ACharacterPC;
class UUserWidget;
class FDeckHandler
{
	TArray<FCard*> Deck;
	TArray<FCard*> Hand;
	TArray<FCard*> Hanger;
	TArray<FCard*> Manager;
	TWeakObjectPtr<ACharacterPC> Owner;
	int32 Cost;

	UPROPERTY()
	UUserWidget* DeckInterface;
public:
	static constexpr int32 MaxHand = 5;
public:
	FDeckHandler(TWeakObjectPtr<ACharacterPC> InOwner);
	~FDeckHandler();
public:
	//게임 시작 시 호출해야할 함수를 호출합니다.
	void BeginPlay();

	//스테이지 시작 시 덱을 초기화합니다.
	void BeginPlayStage();
private:
//덱 인터페이스에서 사용할 함수입니다.
	//카드를 정렬 방법에 따라 정렬합니다.
	void SortCard(ECardSortType InSortType);
public:
	//가지고 있는 카드를 반환합니다.
	const TArray<FCard*>& GetAllCards() const {return Manager;}
	const TArray<FCard*>& GetHands() const {return Hand;}
public:
//관리단계에서 카드를 관리하기 위한 함수입니다. 구매/판매/획득 시 사용합니다. 
	//카드를 생성하고 추가합니다.
	void AddCard(FString InCardName);

	//카드를 삭제합니다.
	void DeleteCard(FString InCardName);
	
//인게임에서 카드를 사용하기 위한 함수들입니다.
	//카드를 드로우 합니다. 패에 카드가 있을 경우 드로우하지 않습니다. 덱에 카드가 없을 때 행거의 카드를 가져와 리필합니다.
	bool Draw();

	//카드를 리플레이스 합니다. 패에 있는 카드를 버리고 다시 카드를 뽑습니다. 덱에 카드가 없을 때 행거의 카드를 가져와 리필합니다.
	void Replace();

	//카드를 섞습니다.
	void ShuffleDeck();

	//행거에서 덱의 카드를 보충합니다.
	void RefillDeck();

	//패에서 카드를 사용합니다.
	void UseCard(int32 InUseCardNum);
};
