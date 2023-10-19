// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Stat.h"
#include "../../Manager/DatatableManager.h"
#include "DieselPunk/Data/StatDataTable.h"
#include "Engine/DataTable.h"

//스탯을 초기화합니다.
void FStat::Initialize(const FString& InCharacterName)
{
	UDataTable* table = FDataTableManager::GetInstance()->GetData(EDataTableType::Stat);
	if(!table)
		return;
	
	FStatDataTable* data = table->FindRow<FStatDataTable>(FName(*InCharacterName), TEXT("FStat::Initialize"));
	if(!data)
		return;

	CharacterStat.FindOrAdd(ECharacterStatType::Level) = 1;
	CharacterStat.FindOrAdd(ECharacterStatType::Exp) = 0;
	
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
int32 FStat::GetStat(ECharacterStatType InStatType)
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
