// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterSoldier.h"
#include "../Util/UtilCollision.h"

#include <DrawDebugHelpers.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterSoldier)

void ACharacterSoldier::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (DrawERange)
	{
		//*스킬e 범위 디버그
		DrawDebugSphere(GetWorld(),
			UtilCollision::GetUnderCursor().Location, 
			32, 16, FColor::Red, false, -1.f);
		DrawDebugSphere(GetWorld(),
			UtilCollision::GetUnderCursor().Location,
			500 + 30 * PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::WideRange], 64, FColor::Blue, false, -1.f); // 파란 디버그구
	} 
}

