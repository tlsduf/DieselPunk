// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterInfo.h"
#include "../../Manager/DataTableManager.h"
#include "../../Util/UtilEnum.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterInfo)


GENERATED_INFO_PTR_CPP( FCharacterInfo, CharacterInfo );


// =============================================================
// 스텟 타입에 따른 밸류값을 반환한다.
// =============================================================
int64 FCharacterInfo::GetValueByStatType( EActorStatType InType ) const
{
	switch ( InType )
	{
	case EActorStatType::Hp:				return Hp;
	case EActorStatType::MaxHp:				return MaxHp;
	case EActorStatType::Armor:				return Armor;
	case EActorStatType::AttackDamage:		return AttackDamage;
	case EActorStatType::AttackSpeed:		return AttackSpeed;
	case EActorStatType::Resistance:		return Resistance;
	case EActorStatType::CriticalDamage:	return CriticalDamage;
	case EActorStatType::CriticalRate:		return CriticalRate;
	case EActorStatType::SkillCoolTime:		return SkillCoolTime;
	case EActorStatType::MoveSpeed:			return MoveSpeed;
	}

	FString enumStr = UtilEnum::EnumToString( InType );
	LOG_SCREEN_COLOR( FColor::Red, TEXT( "Does not Have %s" ), *enumStr );

	return 0;
}