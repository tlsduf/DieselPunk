// Fill out your copyright notice in the Description page of Project Settings.

#include "Buff.h"
#include "../Component/StatControlComponent.h"
#include "../Data/BuffDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"


FBuff::FBuff(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FString& InBuffName)
	: OwnerComp(InOwnerComp)
{
	const FBuffDataTable* data = FDataTableManager::GetInstance()->GetData<FBuffDataTable>(EDataTableType::Buff, InBuffName);
	if(!data)
	{
		UE_LOG(LogLoad, Error, TEXT("InBuffName: %s에 해당하는 데이터 열이 없습니다. 데이터 테이블에서 버프를 불러올 수 없습니다."), *InBuffName)
		return;
	}

	//버프 초기 데이터
	StatContrlType	= data->CharacterStatType;
	IsStore			= data->IsStore;
	IsTick			= data->IsTick;
	BuffValueType	= data->BuffValueType;
	Value			= data->Value;
	BuffTime		= data->BuffTime;
	Frequency		= data->Frequency;

	//버프 데이터
	TotalValue = 0.0;
	Count = 0;
	DeltaTime = 0.0;

	Initialize();
}

FBuff::~FBuff()
{
	Release();
}

bool FBuff::Tick(float InDeltaTime)
{
	DeltaTime += InDeltaTime;

	if(IsTick)
	{
		if(DeltaTime >= Frequency)
		{
			DeltaTime = 0.f;
			ApplyBuff();
			if(Count <= 0)
				return true;
		}
	}

	if(DeltaTime >= BuffTime)
		return true;

	return false;
}

void FBuff::Initialize()
{
	if(IsTick)
	{
		Count += static_cast<int32>(BuffTime / Frequency);
	}
	else
	{
		ApplyBuff();
	}
}

void FBuff::Release()
{
	if(IsStore)
	{
		OwnerComp->SetStat(StatContrlType, OwnerComp->GetStat(StatContrlType) - TotalValue);
	}
}

void FBuff::ApplyBuff()
{
	OwnerComp->SetStat(StatContrlType, OwnerComp->GetStat(StatContrlType) + Value);
	TotalValue += Value;
	if(IsTick)
		--Count;
}

