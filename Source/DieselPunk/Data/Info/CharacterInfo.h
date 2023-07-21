// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include "../InfoBase.h"
#include "CharacterInfo.generated.h"


/**
 * 캐릭터별 초기 스텟 및 BP 경로 데이터 테이블
 */
USTRUCT()
struct DIESELPUNK_API FCharacterInfo : public FInfoBase
{
	GENERATED_USTRUCT_BODY()

	// Character 이름
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FString Name = TEXT( "" );

	// BP 경로
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FString Path = TEXT( "" );

	// 최대 체력
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 MaxHp = 100;

	// 체력
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 Hp = 100;

	// 공격력
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 AttackDamage = 0;

	// 공격 속도
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 AttackSpeed = 0;

	// 방어력
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 Armor = 0;

	// 마법 저항력
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 Resistance = 0;

	// 치명타 확률
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 CriticalRate = 0;

	// 치명타 피해
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 CriticalDamage = 0;

	// 스킬 쿨다운 감소
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 SkillCoolTime = 0;

	// 이동 속도
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int64 MoveSpeed = 100;

public:
	// 스텟 타입에 따른 밸류값을 반환한다.
	int64 GetValueByStatType( EActorStatType InType ) const;
};

GENERATED_INFO_PTR( FCharacterInfo );