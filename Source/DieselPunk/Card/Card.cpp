// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"

#include "../Character/CharacterPC.h"
#include "../Data/CardDataTable.h"
#include "../Manager/DatatableManager.h"

FCard::FCard(const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner)
	: Owner(InOwner)
{
	Info.CardName = InCardName;
}

FCard::~FCard()
{
}

//카드 사용 시 호출할 함수 바인딩
void FCard::BindCardActivate()
{
	if(!Owner.IsValid())
		return;
	
	if(Owner->GetDelegateCardActivate().IsBound())
		Owner->GetDelegateCardActivate().Unbind();
	Owner->GetDelegateCardActivate().BindRaw(this, &FCard::Activate);
}

//카드 사용 완료 시 호출할 함수 바인딩
void FCard::BindCardComplete()
{
	if(!Owner.IsValid())
		return;
	
	if(Owner->GetDelegateCardComplete().IsBound())
		Owner->GetDelegateCardComplete().Unbind();
	Owner->GetDelegateCardComplete().BindRaw(this, &FCard::Complete);
}

//바인딩을 위한 카드 사용 함수
void FCard::Activate(bool& OutSuccess)
{
	_Activate(OutSuccess);
}

//바인딩을 위한 카드 사용 완료 함수
void FCard::Complete(bool& OutSuccess)
{
	_Complete(OutSuccess);
}
