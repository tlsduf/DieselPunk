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
	Interact		UMETA( ToolTip = "설치물 인터렉션"),
	None			UMETA( ToolTip = "지정되지 않음"),
	Max
};
ENUM_RANGE_BY_COUNT( EAbilityType, EAbilityType::None );

// 콜리전 충돌 타입
UENUM( BlueprintType )
enum class ECollisionResponsesType : uint8
{
	OnHit		UMETA( ToolTip = "온힛 이벤트 전용" ),
	Overlap		UMETA( ToolTip = "오버랩 이벤트 전용" ),
	None        UMETA( ToolTip = "n초 뒤 파괴" )
};

// 투사체 종류 Player or Enemy
UENUM( BlueprintType )
enum class ECausorType : uint8
{
	Player		UMETA( ToolTip = "플레이어" ),
	Enemy		UMETA( ToolTip = "적" )
};

// 아군NPC 적군NPC
UENUM( BlueprintType )
enum class ENPCType : uint8
{
	Enemy		UMETA( ToolTip = "적" ),
	Alliance	UMETA( ToolTip = "동맹" ),
	Nexus		UMETA( ToolTip = "넥서스" )
};

// 데이터 테이블 종류
UENUM( BlueprintType )
enum class EDataTableType : uint8
{
	Stat					UMETA( ToolTip = "스탯 정보" ),
	Character				UMETA( ToolTip = "캐릭터 정보" ),
	Card					UMETA( ToolTip = "카드 정보" ),
	WaveModule				UMETA( ToolTip = "웨이브 모듈 정보" ),
	StageWave				UMETA( ToolTip = "스테이지 웨이브 정보" ),
	Buff					UMETA( ToolTip = "버프 정보" ),
	LevelBgm				UMETA( ToolTip = "레벨 BGM 정보" ),
	ProjectileSkillActor	UMETA( ToolTip = "발사체 스킬 액터 정보" ),
	NPCSkill				UMETA( ToolTip = "NPC 스킬 정보" ),
	SearchArea				UMETA( ToolTip = "탐색 범위 정보" ),
	Upgrade					UMETA( ToolTip = "업그레이드 정보" ),
	Count
};
ENUM_RANGE_BY_COUNT(EDataTableType, EDataTableType::Count);

// 스탯 타입
UENUM( BlueprintType )
enum class ECharacterStatType : uint8
{
	Level					UMETA( ToolTip = "레벨" ),
	Exp						UMETA( ToolTip = "경험치" ),
	MaxHp					UMETA( ToolTip = "최대체력" ),
	Hp						UMETA( ToolTip = "현재체력" ),
	Atk						UMETA( ToolTip = "공격력" ),
	AtkForFly				UMETA( ToolTip = "대공 공격력" ),
	AtkSpeed				UMETA( ToolTip = "공격속도" ),
	Def						UMETA( ToolTip = "방어력" ),
	ArmorPen				UMETA( ToolTip = "방어 관통력" ),
	CriticalPer				UMETA( ToolTip = "치명타 확률" ),
	CriticalAtk				UMETA( ToolTip = "치명타 공격력" ),
	MoveSpeed				UMETA( ToolTip = "이동속도" ),
	AtkMaxRange				UMETA( ToolTip = "최대사거리" ),
	AtkMaxRangeForFly		UMETA( ToolTip = "대공 최대사거리" ),
	AtkMinRange				UMETA( ToolTip = "최소사거리" ),
	Cost					UMETA( ToolTip = "코스트"),
	ShellFall				UMETA( ToolTip = "ShellFall"),
	Count
};
ENUM_RANGE_BY_COUNT(ECharacterStatType, ECharacterStatType::Count);

// 네비 노드 상태
UENUM( BlueprintType )
enum class ENavNodeState : uint8
{
	Passable				UMETA( ToolTip = "지나갈 수 있는 길" ),
	BlockedByBreakable		UMETA( ToolTip = "부서질 수 있는 메시에 의해 지나갈 수 없는 길(ex. 포탑)" ),
	BlockedByNonBreakable	UMETA( ToolTip = "부서질 수 없는 메시에 의해 지나갈 수 없는 길(ex. 환경)" ),
};

// 카드 타입
UENUM( BlueprintType )
enum class ECardType : uint8
{
	Turret			UMETA( ToolTip = "포탑" ),
	Installation	UMETA( ToolTip = "설치물" ),
	Ability			UMETA( ToolTip = "능력" ),
};

// 카드 정렬 타입
UENUM( BlueprintType )
enum class ECardSortType : uint8
{
	None,
	Order	UMETA( ToolTip = "획득 순" ),
	Name	UMETA( ToolTip = "이름 순" ),
	Cost	UMETA( ToolTip = "코스트 순" ),
};

// 카드 정렬 타입
UENUM( BlueprintType )
enum class ECardFilterType : uint8
{
	Turret			UMETA( ToolTip = "포탑" ),
	Installation	UMETA( ToolTip = "설치물" ),
	Ability			UMETA( ToolTip = "능력" ),
	All				UMETA( ToolTip = "전체" ),
	None,
};

// 어빌리티 카드 타입
UENUM( BlueprintType )
enum class EAbilityCardType : uint8
{
	Projectile	UMETA( ToolTip = "공격" ),
	Mine		UMETA( ToolTip = "지뢰" ),
	StatBuff	UMETA( ToolTip = "스탯 강화" ),
	None,
};

// 어빌리티 카드 타입
UENUM( BlueprintType )
enum class EEffectPlayType : uint8
{
	Start	UMETA( ToolTip = "시작 시" ),
	Tick	UMETA( ToolTip = "적용 시 스탯버프 액터에" ),
	Hit		UMETA( ToolTip = "적용 시 타겟에" ),
	End		UMETA( ToolTip = "종료 시" ),
	Spawn	UMETA( ToolTip = "스폰 시"),
	Death	UMETA( ToolTip = "사망 시"),
	Walk	UMETA( ToolTip = "걸을 때 마다"),
	Shot	UMETA( ToolTip = "발사체를 쏠 때 마다"),
	None,
};

// 스탯 버프 대상 타입
UENUM( BlueprintType )
enum class ECharacterType : uint8
{
	None = 0,
	Player = 1			UMETA( ToolTip = "플레이어" ),
	Monster = 2			UMETA( ToolTip = "몬스터" ),
	Turret = 4			UMETA( ToolTip = "터렛" ),
	Installation = 8	UMETA( ToolTip = "설치물" ),
};

// 총괄 범위타입 원 파생, 사각형 파생
// 원 파생 : 원, 도넛, 피자, 도넛 피자
UENUM( BlueprintType )
enum class ESearchAreaType : uint8
{
	Circle			UMETA( ToolTip = "원 파생 범위" ),
	Rectangle		UMETA( ToolTip = "사각형 파생 범위 " ),
	Arc				UMETA( ToolTip = "호 파생 범위")
};

// 버프 밸류 적용 타입
UENUM( BlueprintType )
enum class EBuffValueType : uint8
{
	Mulitple	UMETA(ToolTip = "곱연산, Value의 값을 현재 스탯에 곱한 후, 해당 값을 더합니다."),
	Sum			UMETA(ToolTip = "합연산, Value의 값을 현재 스탯에 더합니다."),
};

// NPC 특성 타입
UENUM( BlueprintType )
enum class ENPCTraitType : uint8
{
	None			= 0,
	Fly				= 1	UMETA( ToolTip = "상수" ),
};

// 발사체 타격 타입
UENUM( BlueprintType )
enum class EProjectileType : uint8
{
	TargetAttack	UMETA( ToolTip = "발사체 없음, 무조건 타격" ),
	Straight		UMETA( ToolTip = "직사포" ),
	Parabola		UMETA( ToolTip = "곡사포" ),
	Throwing		UMETA( ToolTip = "던지기" ),
	SuicideBomb		UMETA( ToolTip = "자폭" ),
	Melee			UMETA( ToolTip = "근접 공격" )
};

// 스킬 거리 타입
UENUM( BlueprintType )
enum class ESkillDistanceType : uint8
{
	RangedAttack	UMETA( ToolTip = "원거리" ),
	MeleeAttack		UMETA( ToolTip = "근거리" )
};

// 버프 중첩 시간 타입 
UENUM(BlueprintType)
enum class EBuffDuplicateTimeType : uint8
{
	AddTime		UMETA(ToolTip = "버프 중첩 시 시간이 더해집니다. ex)3초 남은 점화에 동일한 5초의 점화가 적용될 시 8초 동안 점화됩니다."),
	ResetTime	UMETA(ToolTip = "버프 중첩 시 시간이 초기화됩니다.. ex)3초 남은 점화에 동일한 5초의 점화가 적용될 시 5초 동안 점화됩니다.")
};

// 버프 타입 
UENUM(BlueprintType)
enum class EBuffType : uint8
{
	Stat			UMETA(ToolTip = "스탯 버프"),
	StatusEffect	UMETA(ToolTip = "상태이상")
};

// 버프 상태이상 기능 타입 
UENUM(BlueprintType)
enum class EBuffStatusEffectRoleType : uint8
{
	Move = 0	UMETA(ToolTip = "이동 불가"),
	Attack		UMETA(ToolTip = "기본 공격 불가"),
	Skill		UMETA(ToolTip = "스킬 사용 불가"),
	Max
};

// 바닥 타입
UENUM(BlueprintType)
enum class EFloorType : uint8
{
	Plane = 0	UMETA(ToolTip = "평면"),
	Runway		UMETA(ToolTip = "경사로"),
	Stair		UMETA(ToolTip = "계단"),
	Prop		UMETA(ToolTip = "건물, 설치물 등")
};