// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

/**
 * 버프 클래스입니다.
 */

class UStatControlComponent;
class ACharacterBase;
struct FBuffDataTable;

class DIESELPUNK_API FBuff
{
	//버프가 시작, 재시작될 때 브로드캐스트합니다.(재시작은 이미 생성된 버프가 다시 걸릴 때입니다.)
	DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateBuffStart, TWeakObjectPtr<UStatControlComponent>, FBuff*)
	
	//버프가 종료할 때 브로드캐스트합니다.
	DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateBuffEnd, TWeakObjectPtr<UStatControlComponent>, FBuff*)
protected:
	TWeakObjectPtr<UStatControlComponent> OwnerComp = nullptr;

	//초기 버프 데이터
	EBuffDuplicateTimeType	BuffDuplicateTimeType	= EBuffDuplicateTimeType::AddTime;	//버프 중첩 시 시간 타입
	double			 		BuffTime				= 5.0;								//버프 적용 시간
	double			 		Frequency				= 1.0;								//틱 적용 빈도
	bool			 		IsTick					= false;							//버프가 틱으로 동작할건 지

	//버프 데이터
	bool	FirstBuff = true;
	double	DeltaTime = 0.0;
	int32	Count = 0;

	FDelegateBuffStart	DelegateBuffStart;
	FDelegateBuffEnd	DelegateBuffEnd;
	
public:
	FBuff(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable);
	virtual ~FBuff();
public:
	bool Tick(float InDeltaTime);
	void Initialize();
	void Release();

	FORCEINLINE FDelegateBuffStart& GetDelegateBuffStart(){return DelegateBuffStart;}
	FORCEINLINE FDelegateBuffEnd& GetDelegateBuffEnd(){return DelegateBuffEnd;}
protected:
	virtual void TickBuffInitialize(){}
	virtual void ImmediatelyBuffInitialize(){}
	void ApplyBuff();
	virtual void _ApplyBuff()=0;
	virtual void _ReleaseBuff()=0;
};
