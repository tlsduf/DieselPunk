// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"

#include "../Character/CharacterPC.h"
#include "../Data/CardDataTable.h"
#include "../Manager/DatatableManager.h"

FCard::FCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner)
	: Owner(InOwner)
{
	Info.Key = InKey;
	Info.CardName = InCardName;
	Info.GetTime = FDateTime::Now();
	const FCardDataTable* data = FDataTableManager::GetInstance()->GetData<FCardDataTable>(EDataTableType::Card, Info.CardName);
	for(const FString& name : data->ImageNames)
		Info.TexturePath.Add(UtilPath::GetDeckInterfaceUIPath(*name));
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

void FCard::BindCardCancel()
{
	if(!Owner.IsValid())
		return;
	
	if(Owner->GetDelegateCardCancel().IsBound())
		Owner->GetDelegateCardCancel().Unbind();
	Owner->GetDelegateCardCancel().BindRaw(this, &FCard::Cancel);
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

void FCard::BindRotateInstallation()
{
	if(!Owner.IsValid())
	return;
	
	if(Owner->GetDelegateRotateInstallation().IsBound())
		Owner->GetDelegateRotateInstallation().Unbind();
	Owner->GetDelegateRotateInstallation().BindRaw(this, &FCard::RotateInstallation);
}

//바인딩을 위한 카드 사용 함수
void FCard::Activate(bool& OutSuccess, int32 InCost)
{
	_Activate(OutSuccess, InCost);
}

//바인딩을 위한 카드 사용 완료 함수
void FCard::Complete(bool& OutSuccess, int32 InCost)
{
	_Complete(OutSuccess, InCost);
}

void FCard::Cancel()
{
	_Cancel();
}

void FCard::RotateInstallation(int32 RotateAngle)
{
	_RotateInstallation(RotateAngle);
}