// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "Misc/EnumRange.h"

// Enum 값 정의 모음

// PlayerCharacter의 Ability를 호출할때 key로 사용합니다.
UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	MouseLM			UMETA( ToolTip = "마우스 왼쪽클릭"),
	MouseRM			UMETA( ToolTip = "마우스 오른쪽클릭"),
	Shift			UMETA( ToolTip = "쉬프트"),
	SkillQ			UMETA( ToolTip = "Q 스킬"),
	SkillE			UMETA( ToolTip = "E 스킬"),
	SkillR			UMETA( ToolTip = "R 스킬"),
	None			UMETA( ToolTip = "지정되지 않음"),
};
ENUM_RANGE_BY_COUNT( EAbilityType, EAbilityType::None );

// 콜리전 충돌 타입
UENUM( BlueprintType )
enum class ECollisionResponsesType : uint8
{
	OnHit		UMETA( ToolTip = "온힛 이벤트 전용" ),
	Overlap		UMETA( ToolTip = "오버랩 이벤트 전용" ),
};

// 투사체 종류 Player or Enemy
UENUM( BlueprintType )
enum class EProjectileOwnerType : uint8
{
	Player		UMETA( ToolTip = "플레이어" ),
	Enemy		UMETA( ToolTip = "적" )
};

// 적 종류 Minions , Elite, Boss
UENUM( BlueprintType )
enum class EEnemyType : uint8
{
	Minions		UMETA( ToolTip = "일반" ),
	Elite		UMETA( ToolTip = "엘리트" ),
	Boss		UMETA( ToolTip = "보스" )
};

// 아군NPC 적군NPC
UENUM( BlueprintType )
enum class ENPCType : uint8
{
	Enemy		UMETA( ToolTip = "적군" ),
	Alliance	UMETA( ToolTip = "아군" ),
	Nexus		UMETA( ToolTip = "넥서스" )
};

// 데이터 테이블 종류
UENUM( BlueprintType )
enum class EDataTableType : uint8
{
	Stat			UMETA( ToolTip = "스탯 정보" ),
	Character		UMETA( ToolTip = "캐릭터 정보" ),
	MonsterSpawner	UMETA( ToolTip = "몬스터 스포너 정보" )
};

// 스탯 타입
UENUM( BlueprintType )
enum class ECharacterStatType : uint8
{
	Level				UMETA( ToolTip = "레벨" ),
	Exp					UMETA( ToolTip = "경험치" ),
	MaxHp				UMETA( ToolTip = "최대체력" ),
	Hp					UMETA( ToolTip = "현재체력" ),
	HpRecoverySpeed		UMETA( ToolTip = "체력 회복 속도" ),
	Atk					UMETA( ToolTip = "공격력" ),
	AtkSpeed			UMETA( ToolTip = "공격속도" ),
	Def					UMETA( ToolTip = "방어력" ),
	ArmorPen			UMETA( ToolTip = "방어 관통력" ),
	CriticalPer			UMETA( ToolTip = "치명타 확률" ),
	CriticalAtk			UMETA( ToolTip = "치명타 공격력" ),
	MoveSpeed			UMETA( ToolTip = "이동속도" ),
	JumpCount			UMETA( ToolTip = "점프 횟수" ),
	Luck				UMETA( ToolTip = "행운" ),
	CoolDown			UMETA( ToolTip = "스킬 쿨타임 감소" ),
};
