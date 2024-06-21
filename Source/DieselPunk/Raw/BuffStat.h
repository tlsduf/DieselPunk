// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Buff.h"

/**
 * 버프 클래스입니다.
 */

class UStatControlComponent;
struct FBuffDataTable;

class DIESELPUNK_API FBuffStat : public FBuff
{
protected:
	//초기 버프 데이터
	ECharacterStatType		StatContrlType			= ECharacterStatType::Hp;				//변경할 스탯
	bool			 		IsStore					= false;							//버프 종료 시 스탯 복구할 지
	EBuffValueType	 		BuffValueType			= EBuffValueType::Sum;				//버프 배율 타입(백분율/상수)
	double			 		Value					= 0.0;								//밸류

	//버프 데이터
	double	RealValue = 0.0;
	double	TotalValue = 0.0;
	TArray<double> CountValue;
	
public:
	FBuffStat(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable);
	virtual ~FBuffStat() override;
	virtual void _ReleaseBuff() override;
protected:
	virtual void TickBuffInitialize() override;
	virtual void ImmediatelyBuffInitialize() override;
	virtual void _ApplyBuff() override;
};
