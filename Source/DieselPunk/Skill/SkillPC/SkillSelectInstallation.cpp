// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSelectInstallation.h"
#include "../../Character/CharacterPC.h"
#include "../../Character/CharacterTurret.h"
#include <GameFramework/PlayerController.h>


USkillSelectInstallation::USkillSelectInstallation()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSelectInstallation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkillSelectInstallation::SkillTriggered()
{
	Super::SkillTriggered();
	
	FHitResult hit;
	TArray<const AActor*> ignore;
	ignore.Add(OwnerCharacter);
	
	if(UtilCollision::GetViewMiddle(GetWorld(), Cast<APlayerController>(OwnerController), hit, 99999, ignore))
	{
		//선택한 액터가 터렛이 아닐 경우 리턴
		if(Cast<ACharacterHousing>(hit.GetActor()) == nullptr)
		{
			OwnerCharacterPC->SetSelectInstallation(nullptr);
			return;
		}
		
		//선택 동작
		const ACharacterHousing* oldInstallation = OwnerCharacterPC->GetSelectInstallation();

		//이미 선택된 설치물에 E를 누름
		if(oldInstallation == hit.GetActor())
		{
			//원래 선택한 설치물 등록 해제
			OwnerCharacterPC->SetSelectInstallation(nullptr);
		}
		else
		{
			//새롭게 선택한 설치물 등록
			OwnerCharacterPC->SetSelectInstallation(Cast<ACharacterHousing>(hit.GetActor()));
		}
	}
	else
	{
		//허공에 E를 눌렀을 때에는 등록 취소
		OwnerCharacterPC->SetSelectInstallation(nullptr);
	}
}

