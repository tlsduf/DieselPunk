// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillInteractInstallation.h"
#include "../../Character/CharacterPC.h"
#include "../../Character/CharacterTurret.h"

#include <GameFramework/PlayerController.h>

USkillInteractInstallation::USkillInteractInstallation()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillInteractInstallation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkillInteractInstallation::SkillStarted()
{
	Super::SkillStarted();
	
	FHitResult hit;
	TArray<const AActor*> ignore;
	ignore.Add(OwnerCharacter);
	
	if(CheckInteractive(hit, 99999, ignore))
	{
		if(Cast<ACharacterTurret>(hit.GetActor()) == nullptr)
			return;
		InteractiveInstallation = Cast<ACharacterTurret>(hit.GetActor());
		Distance = hit.Distance;
		IsValid = true;
	}
	else
		IsValid = false;
}

void USkillInteractInstallation::SkillOngoing()
{
	Super::SkillOngoing();
	FHitResult hit;
	TArray<const AActor*> ignore;
	ignore.Add(OwnerCharacter);
	
	if(CheckInteractive(hit, 99999, ignore))
	{
		if(Cast<ACharacterTurret>(hit.GetActor()) == nullptr)
			return;

		if(InteractiveInstallation != hit.GetActor())
			IsValid = false;
		else
			Distance = hit.Distance;
	}
	else
		IsValid = false;
}

void USkillInteractInstallation::SkillTriggered()
{
	Super::SkillTriggered();

	FHitResult hit;
	TArray<const AActor*> ignore;
	ignore.Add(OwnerCharacter);
	
	if(CheckInteractive(hit, 99999, ignore))
	{
		if(Cast<ACharacterTurret>(hit.GetActor()) == nullptr)
			return;

		if(InteractiveInstallation != hit.GetActor())
			IsValid = false;
		else
			Distance = hit.Distance;
	}
	else
		IsValid = false;

	//중간에 커서를 다른 곳으로 옮겼을 시 아무일 없게
	if(IsValid == false)
		return;

	//사거리 검사
	if(Distance > InteractiveRange)
		return;
	
	//1초간 홀드했을 때
	if(OwnerCharacterPC->GetSelectInstallation() == nullptr)
	{
		//포탑 수리
		LOG_SCREEN(FColor::Yellow, TEXT("Fix Turret"))
	}
	else
	{
		//포탑 판매
		LOG_SCREEN(FColor::Yellow, TEXT("Sold Turret"))
	}
}

void USkillInteractInstallation::SkillCanceled()
{
	Super::SkillCanceled();

	FHitResult hit;
	TArray<const AActor*> ignore;
	ignore.Add(OwnerCharacter);
	
	if(CheckInteractive(hit, 99999, ignore))
	{
		if(Cast<ACharacterTurret>(hit.GetActor()) == nullptr)
			return;

		if(InteractiveInstallation != hit.GetActor())
			IsValid = false;
		else
			Distance = hit.Distance;
	}
	else
		IsValid = false;

	//중간에 커서를 다른 곳으로 옮겼을 시 아무일 없게
	if(IsValid == false)
		return;

	//사거리 검사
	if(Distance > InteractiveRange)
		return;
	
	//한번 클릭했을 때
	if(OwnerCharacterPC->GetSelectInstallation() == nullptr)
	{
		//상호작용(탑승, 기믹 등)
		LOG_SCREEN(FColor::Yellow, TEXT("Interactive"))
	}
	else
	{
		//포탑 강화
		LOG_SCREEN(FColor::Yellow, TEXT("Upgrade Turret"))
	}
}

bool USkillInteractInstallation::CheckInteractive(FHitResult& InHitResult, int32 InRange,
	TArray<const AActor*> InIgnoreActor)
{
	return UtilCollision::GetViewMiddle(GetWorld(), Cast<APlayerController>(OwnerController), InHitResult, 99999, InIgnoreActor);
}

