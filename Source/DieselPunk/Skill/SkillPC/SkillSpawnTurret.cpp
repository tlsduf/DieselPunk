// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSpawnTurret.h"
#include "../../Manager/ObjectManager.h"
#include "../../Manager/DatatableManager.h"
#include "../../Data/CharacterDataTable.h"
#include "../../Character/CharacterTurret.h"

#include <DrawDebugHelpers.h>

USkillSpawnTurret::USkillSpawnTurret()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSpawnTurret::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkillSpawnTurret::SkillStarted()
{
	Super::SkillStarted();
	auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);
	
	if(bTaskOn == false)
	{
		if(ownerPawn->ExecuteCardActivate())
			bTaskOn = true;
	}
	else
	{
		if(ownerPawn->ExecuteCardComplete())
		{
			ExpectedUnBind = true;
			bTaskOn = false;
		}
	}
}

void USkillSpawnTurret::SkillCompleted()
{
	Super::SkillCompleted();

	if(ExpectedUnBind)
	{
		auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);
		ownerPawn->RestoreSkillBind();
		ExpectedUnBind = false;
	}
}

void USkillSpawnTurret::SpawnCancel()
{
	bTaskOn = false;
}

