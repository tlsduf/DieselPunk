// Fill out your copyright notice in the Description page of Project Settings.

#include "BuffStat.h"
#include "../Component/StatControlComponent.h"
#include "../Data/BuffDataTable.h"


FBuffStat::FBuffStat(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable)
	: FBuff(InOwnerComp, InBuffTable)
{
	if(!InBuffTable)
		return;

	//버프 초기 데이터
	StatContrlType			= InBuffTable->BuffStatInfo.StatContrlType;
	IsStore					= InBuffTable->BuffStatInfo.IsStore;
	BuffValueType			= InBuffTable->BuffStatInfo.BuffValueType;
	Value					= InBuffTable->BuffStatInfo.Value;

	//버프 데이터
	TotalValue = 0.0;
	Count = 0;
	CountValue.Empty();
}

FBuffStat::~FBuffStat()
{
}

void FBuffStat::TickBuffInitialize()
{
	FBuff::TickBuffInitialize();

	if(BuffDuplicateTimeType == EBuffDuplicateTimeType::AddTime)
	{
		for(int i = CountValue.Num(); i < Count; ++i)
		{
			if(BuffValueType == EBuffValueType::Sum)
				CountValue.Add(Value);
			else if(BuffValueType == EBuffValueType::Mulitple)
				CountValue.Add(OwnerComp->GetStat(StatContrlType) * Value);
		}
	}
	else if(BuffDuplicateTimeType == EBuffDuplicateTimeType::ResetTime)
	{
		CountValue.Empty();
		for(int i = CountValue.Num(); i < Count; ++i)
		{
			if(BuffValueType == EBuffValueType::Sum)
				CountValue.Add(Value);
			else if(BuffValueType == EBuffValueType::Mulitple)
				CountValue.Add(OwnerComp->GetStat(StatContrlType) * Value);
		}
	}
}

void FBuffStat::ImmediatelyBuffInitialize()
{
	FBuff::ImmediatelyBuffInitialize();
	
	if(BuffValueType == EBuffValueType::Sum)
		CountValue.Add(Value);
	else if(BuffValueType == EBuffValueType::Mulitple)
		CountValue.Add(OwnerComp->GetStat(StatContrlType) * Value);
}

void FBuffStat::_ReleaseBuff()
{
	if(IsStore)
	{
		OwnerComp->SetStat(StatContrlType, OwnerComp->GetStat(StatContrlType) - TotalValue);
	}
}

void FBuffStat::_ApplyBuff()
{
	TArray<double>::TIterator beginIter = CountValue.CreateIterator();
	OwnerComp->SetStat(StatContrlType, OwnerComp->GetStat(StatContrlType) + *beginIter);
	TotalValue += *beginIter;
	beginIter.RemoveCurrent();
}

