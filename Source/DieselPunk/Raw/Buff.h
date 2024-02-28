// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

/**
 * 버프 클래스입니다.
 */

class UStatControlComponent;

class DIESELPUNK_API FBuff
{
protected:
	TWeakObjectPtr<UStatControlComponent> OwnerComp;

	//초기 버프 데이터
	ECharacterStatType	StatContrlType	= ECharacterStatType::Hp;	//변경할 스탯
	bool			 	IsStore			= false;					//버프 종료 시 스탯 복구할 지
	bool			 	IsTick			= false;					//버프가 틱으로 동작할건 지
	EBuffValueType	 	BuffValueType	= EBuffValueType::Constant;	//버프 배율 타입(백분율/상수)
	double			 	Value			= 0.0;						//밸류
	double			 	BuffTime		= 5.0;						//버프 적용 시간
	double			 	Frequency		= 1.0;						//틱 적용 빈도

	//버프 데이터
	double	TotalValue = 0.0;
	int32	Count = 0;
	double	DeltaTime = 0.0;
	
	
public:
	FBuff(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FString& InBuffName);
	virtual ~FBuff();
public:
	bool Tick(float InDeltaTime);
	void Initialize();
protected:
	void Release();
	void ApplyBuff();
};
