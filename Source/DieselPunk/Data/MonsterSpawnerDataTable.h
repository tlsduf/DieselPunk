// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "MonsterSpawnerDataTable.generated.h"

//한 스포너에 스폰시킬 몬스터 정보입니다.
USTRUCT(BlueprintType)
struct FMonsterSpawnInfo
{
	GENERATED_USTRUCT_BODY()
 
	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MonsterName = "";

	//지연시간입니다. 게임이 시작한 후 지연 시간만큼 흐른 뒤 해당 몬스터를 스폰합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DelayTime = 0.f;
};

/**
 * 몬스터 스포너의 데이터를 관리하기 위한 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FMonsterSpawnerDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//몬스터 스폰 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMonsterSpawnInfo> MonsterSpawnerInfo;
};
