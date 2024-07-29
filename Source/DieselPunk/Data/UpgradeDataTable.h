// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "UpgradeDataTable.generated.h"

/**
 * 업그레이드에 필요한 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FUpgradeDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//업그레이드할 메시입니다.
	UPROPERTY(EditAnywhere)
	USkeletalMesh* UpgradeMesh = nullptr;

	//업그레이드할 애님 인스턴스 입니다.
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAnimInstance> UpgradeAnimInstance = nullptr;

	//업그레이드 스킬 이름입니다.
	UPROPERTY(EditAnywhere)
	TMap<EAbilityType, FName> UpgradeSkillNames;
};
