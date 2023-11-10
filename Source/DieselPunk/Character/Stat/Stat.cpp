// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Stat.h"
#include "../../Manager/DatatableManager.h"
#include "../../Data/StatDataTable.h"
#include "../CharacterBase.h"

//스탯을 초기화합니다.
void FStat::Initialize(ACharacterBase* InOwner, const FString& InCharacterName)
{
	if(InOwner == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("스탯의 Owner가 nullptr입니다."))
		return;
	}
	Owner = InOwner;

	//데이터 테이블에서 스탯 정보 획득
	const FStatDataTable* data = FDataTableManager::GetInstance()->GetData<FStatDataTable>(EDataTableType::Stat, *InCharacterName);
	if(data == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("캐릭터: %s의 변수 CharacterName: %s에 해당하는 데이터가 없습니다. CharacterName을 데이터 테이블에 맞게 설정해주세요"), *Owner->GetName(), *InCharacterName)
		return;
	}

	CharacterStat.FindOrAdd(ECharacterStatType::Level) = 1;
	CharacterStat.FindOrAdd(ECharacterStatType::Exp) = 0;

	CharacterStat.FindOrAdd(ECharacterStatType::MaxHp)				= data->Hp;
	CharacterStat.FindOrAdd(ECharacterStatType::Hp)					= data->Hp;
	CharacterStat.FindOrAdd(ECharacterStatType::HpRecoverySpeed)	= data->HpRecoverySpeed;
	CharacterStat.FindOrAdd(ECharacterStatType::Atk)				= data->Atk;
	CharacterStat.FindOrAdd(ECharacterStatType::AtkSpeed)			= data->AtkSpeed;
	CharacterStat.FindOrAdd(ECharacterStatType::Def)				= data->Def;
	CharacterStat.FindOrAdd(ECharacterStatType::ArmorPen)			= data->ArmorPen;
	CharacterStat.FindOrAdd(ECharacterStatType::CriticalPer)		= data->CriticalPer;
	CharacterStat.FindOrAdd(ECharacterStatType::CriticalAtk)		= data->CriticalAtk;
	CharacterStat.FindOrAdd(ECharacterStatType::MoveSpeed)			= data->MoveSpeed;
	CharacterStat.FindOrAdd(ECharacterStatType::JumpCount)			= data->JumpCount;
	CharacterStat.FindOrAdd(ECharacterStatType::Luck)				= data->Luck;
	CharacterStat.FindOrAdd(ECharacterStatType::CoolDown)			= data->CoolDown;
}

//스탯 클래스를 비웁니다.
void FStat::Release()
{
	Owner = nullptr;
	CharacterStat.Empty();
	ChangeStatDelegate.Clear();
}

//스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
void FStat::ChangeStat(ECharacterStatType InStatType, int32 InValue)
{
	int32* stat = CharacterStat.Find(InStatType);
	if(!stat)
		return;

	*stat = *stat + InValue;

	if(ChangeStatDelegate.IsBound())
		ChangeStatDelegate.Broadcast(Owner, InStatType, InValue);
}

//스탯을 반환합니다.
const int32& FStat::GetStat(ECharacterStatType InStatType)
{
	int32* stat = CharacterStat.Find(InStatType);
	if(!stat)
		return INVALID_STAT;

	return *stat;
}

//스탯을 셋팅합니다. 캐릭터 생성시 이 함수를 통해 스탯을 세팅합니다. 인게임 도중에는 사용하지 않는 것을 추천합니다.
void FStat::SetStat(ECharacterStatType InStatType, int32 InValue)
{
	int32* stat = CharacterStat.Find(InStatType);
	if(!stat)
		return;

	int32 changeStat = InValue - *stat;
	*stat = InValue;

	if(ChangeStatDelegate.IsBound())
		ChangeStatDelegate.Broadcast(Owner, InStatType, changeStat);
}
