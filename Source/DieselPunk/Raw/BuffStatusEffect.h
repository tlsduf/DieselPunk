// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Buff.h"

/**
 * 버프 클래스입니다.
 */

class UStatControlComponent;
struct FBuffDataTable;

class DIESELPUNK_API FBuffStatusEffect : public FBuff
{
protected:
	//초기 버프 데이터
	FName PlaySectionName = NAME_None;
	bool IsMove = false;
	bool IsAttack = false;
	bool IsSkill = false;
	TFunction<void(AActor*)> ReleaseCallFunc = nullptr;
	
public:
	FBuffStatusEffect(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable);
	virtual ~FBuffStatusEffect() override;
	virtual void _ReleaseBuff() override;
protected:
	virtual void _ApplyBuff() override;
public:
	FORCEINLINE void SetReleaseCallFunction(TFunction<void(AActor*)> InReleaseCallFunc){ReleaseCallFunc = InReleaseCallFunc;}
};
