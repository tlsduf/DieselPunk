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
	IsSkill				= InBuffTable->BuffStatusEffectInfo.IsSkill;
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
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Move, true);
	}
	if(!IsAttack)
	{
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Attack, true);
	}
	if(!IsSkill)
	{
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Skill, true);
	}
	if(ReleaseCallFunc)
	{
		ReleaseCallFunc(character);
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
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Move, false);
	}
	if(!IsAttack)
	{
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Attack, false);
	}
	if(!IsSkill)
	{
		character->SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType::Skill, false);
	}
}

