// Fill out your copyright notice in the Description page of Project Settings.

#include "Buff.h"
#include "../Component/StatControlComponent.h"
#include "../Data/BuffDataTable.h"


FBuff::FBuff(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable)
	: OwnerComp(InOwnerComp)
{
	if(!InBuffTable)
		return;

	//버프 초기 데이터
	BuffDuplicateTimeType	= InBuffTable->BuffDuplicateTime;
	BuffTime				= InBuffTable->BuffTime;
	Frequency				= InBuffTable->Frequency;
	IsTick					= BuffTime != Frequency;

	//버프 데이터
	DeltaTime = 0.0;
	FirstBuff = true;
}

FBuff::~FBuff()
{
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
			--Count;
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
	//틱으로 작동할 경우
	if(IsTick)
	{
		//시간이 더해질 때
		if(BuffDuplicateTimeType == EBuffDuplicateTimeType::AddTime)
		{
			int32 localCount = Frequency != 0 ? static_cast<int32>(BuffTime / Frequency) : 0;
			Count += localCount;
		}
		//시간이 초기화될 때
		else if(BuffDuplicateTimeType == EBuffDuplicateTimeType::ResetTime)
		{
			int32 localCount = Frequency != 0 ? static_cast<int32>(BuffTime / Frequency) : 0;
			Count = localCount;
		}
		TickBuffInitialize();
	}
	//틱으로 작동하지 않을 경우
	else
	{
		if(BuffDuplicateTimeType == EBuffDuplicateTimeType::AddTime)
			BuffTime += BuffTime;
		if(BuffDuplicateTimeType == EBuffDuplicateTimeType::ResetTime)
			DeltaTime = 0.f;
		
		if(FirstBuff)
		{
			ImmediatelyBuffInitialize();
			
			ApplyBuff();
			FirstBuff = false;
		}
	}

	if(DelegateBuffStart.IsBound())
		DelegateBuffStart.Broadcast(OwnerComp, this);
}

void FBuff::Release()
{
	_ReleaseBuff();
	if(DelegateBuffEnd.IsBound())
		DelegateBuffEnd.Broadcast(OwnerComp, this);
}

void FBuff::ApplyBuff()
{
	_ApplyBuff();
}

