// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierRM.h"
#include "..\..\Character\CharacterPC.h"

USkillSoldierRM::USkillSoldierRM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierRM::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierRM::SkillStarted()
{
	Super::SkillStarted();

	ZoomIn();
}
void USkillSoldierRM::SkillCompleted()
{
	Super::SkillCompleted();

	ZoomOut();
}

void USkillSoldierRM::ZoomIn()
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
	{
		return;
	}
	
	ownerPawn->SetThisSpeed(400);
	ownerPawn->MyTargetArmLength = 100.0f;
	ownerPawn->MyTargetArmLocation = FVector(0, 50, 80);
	ownerPawn->MyCameraLocation = FVector(0, 0, 0);

	ownerPawn->CanZoom = true;
}

void USkillSoldierRM::ZoomOut()
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
	{
		return;
	}
	
	ownerPawn->SetThisSpeed(600);
	ownerPawn->MyTargetArmLength = 400.0f;
	ownerPawn->MyTargetArmLocation = FVector(0, 0, 55);
	ownerPawn->MyCameraLocation = FVector(0, 0, 55);

	ownerPawn->CanZoom = true;
}