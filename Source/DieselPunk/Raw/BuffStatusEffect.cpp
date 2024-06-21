// Fill out your copyright notice in the Description page of Project Settings.

#include "BuffStatusEffect.h"
#include "../Component/StatControlComponent.h"
#include "../Data/BuffDataTable.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Character/CharacterBase.h"


FBuffStatusEffect::FBuffStatusEffect(TWeakObjectPtr<UStatControlComponent> InOwnerComp, const FBuffDataTable* InBuffTable)
	: FBuff(InOwnerComp, InBuffTable)
{
	if(!InBuffTable)
		return;

	//버프 초기 데이터
	PlaySectionName		= InBuffTable->BuffStatusEffectInfo.PlaySectionName;
	IsMove				= InBuffTable->BuffStatusEffectInfo.IsMove;
	IsAttack			= InBuffTable->BuffStatusEffectInfo.IsAttack;
}

FBuffStatusEffect::~FBuffStatusEffect()
{
}

void FBuffStatusEffect::_ReleaseBuff()
{
	ACharacterBase* character = Cast<ACharacterBase>(OwnerComp->GetOwner());
	if(!character)
		return;
	character->StopCharacterStatusEffectAnimMontage(0.2f);
	if(!IsMove)
	{
		character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
	if(!IsAttack)
	{
		character->SetCanRotate(true);
		character->SetCanAttack(true);
	}
}

void FBuffStatusEffect::_ApplyBuff()
{
	ACharacterBase* character = Cast<ACharacterBase>(OwnerComp->GetOwner());
	if(!character)
		return;
	if(PlaySectionName != NAME_None)
	{
		character->PlayCharacterStatusEffectAnimMontage(1.f, PlaySectionName);
	}
	if(!IsMove)
	{
		character->GetCharacterMovement()->SetMovementMode(MOVE_None);
	}
	if(!IsAttack)
	{
		character->SetCanRotate(false);
		character->SetCanAttack(false);
	}
}

