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

//콜리전 타입에 대한 enum 입니다.
UENUM(BlueprintType)
enum class EActorCollisionShape : uint8
{
	Box			UMETA(ToolTip = "육면체 형태"),
	Sphere		UMETA(ToolTip = "구 형태"),
	Capsule		UMETA(ToolTip = "캡슐 형태")
};

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

// 데이터 테이블 종류
UENUM( BlueprintType )
enum class EDataTableType : uint8
{
	Stat		UMETA( ToolTip = "스탯" ),
};