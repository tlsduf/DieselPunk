// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillInteractInstallation.h"
#include "../../Character/CharacterPC.h"
#include "../../Character/CharacterTurret.h"
#include "../../Data/CardDataTable.h"
#include "../../Manager/DatatableManager.h"
#include "../../Manager/ObjectManager.h"

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
	
	InteractiveInstallation = OwnerCharacterPC->GetSelectInstallation();
	IsValid = InteractiveInstallation.IsValid();
	if(IsValid)
		Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	else
	{
		InteractiveInstallation = OwnerCharacterPC->GetLookInstallation();
		IsValid = InteractiveInstallation.IsValid();
		if(IsValid)
			Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	}
}

void USkillInteractInstallation::SkillOngoing()
{
	Super::SkillOngoing();

	InteractiveInstallation = OwnerCharacterPC->GetSelectInstallation();
	IsValid = InteractiveInstallation.IsValid();
	if(IsValid)
		Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	else
	{
		InteractiveInstallation = OwnerCharacterPC->GetLookInstallation();
		IsValid = InteractiveInstallation.IsValid();
		if(IsValid)
			Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	}
}

void USkillInteractInstallation::SkillTriggered()
{
	Super::SkillTriggered();
	
	InteractiveInstallation = OwnerCharacterPC->GetSelectInstallation();
	IsValid = InteractiveInstallation.IsValid();
	if(IsValid)
		Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	else
	{
		InteractiveInstallation = OwnerCharacterPC->GetLookInstallation();
		IsValid = InteractiveInstallation.IsValid();
		if(IsValid)
			Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	}

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
		LOG_SCREEN(FColor::Yellow, TEXT("Fix Turret: %s"), *InteractiveInstallation->GetName())

		//최대 체력으로 복구
		int32 hp = InteractiveInstallation->GetStat(ECharacterStatType::MaxHp) - InteractiveInstallation->GetStat(ECharacterStatType::Hp);
		InteractiveInstallation->ChangeStat(ECharacterStatType::Hp, hp);
	}
	else
	{
		//포탑 판매
		LOG_SCREEN(FColor::Yellow, TEXT("Sold Turret: %s"), *InteractiveInstallation->GetName())

		//ToDo: 포탑 판매 시 일정 금액 돌려받기
		UDataTable* table = FDataTableManager::GetInstance()->GetDataRow(EDataTableType::Card);

		TArray<FCardDataTable*> rows;
		table->GetAllRows<FCardDataTable>(TEXT("FCardDataTable"), rows);

		FCardDataTable* findRow = nullptr;
		for(FCardDataTable* row : rows)
		{
			if(row->Names[0] == InteractiveInstallation->GetCharacterName())
			{
				findRow = row;
				break;
			}
		}

		if(findRow == nullptr)
			return;
		
		int32 cost = findRow->Cost * 0.7f;
		OwnerCharacterPC->ChangeStat(ECharacterStatType::Cost, cost);
		
		//포탑 삭제
		FObjectManager::GetInstance()->DestroyActor(InteractiveInstallation->GetObjectId());
	}
}

void USkillInteractInstallation::SkillCanceled()
{
	Super::SkillCanceled();
	
	InteractiveInstallation = OwnerCharacterPC->GetSelectInstallation();
	IsValid = InteractiveInstallation.IsValid();
	if(IsValid)
		Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	else
	{
		InteractiveInstallation = OwnerCharacterPC->GetLookInstallation();
		IsValid = InteractiveInstallation.IsValid();
		if(IsValid)
			Distance = FVector::Distance(InteractiveInstallation->GetActorLocation(), OwnerCharacterPC->GetActorLocation());
	}

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
		LOG_SCREEN(FColor::Yellow, TEXT("Interactive Turret: %s"), *InteractiveInstallation->GetName())
	}
	else
	{
		//포탑 강화

		//터렛 가져오기
		TArray<int32> ids;
		FObjectManager::GetInstance()->FindActorArrayByPredicate(ids, [](AActor* actor)
		{
			return Cast<ACharacterTurret>(actor) != nullptr;
		});

		TArray<ACharacterHousing*> turrets;
		for(int32 id : ids)
		{
			//자기자신 제외
			if(InteractiveInstallation->GetObjectId() == id)
				continue;
			ACharacterHousing* installation = Cast<ACharacterHousing>(FObjectManager::GetInstance()->FindActor(id));
			
			//같은 포탑,레벨 종류 추가
			if(InteractiveInstallation->GetCharacterName() == installation->GetCharacterName()
				&& InteractiveInstallation->GetStat(ECharacterStatType::Level) == installation->GetStat(ECharacterStatType::Level))
				turrets.Add(installation);
		}

		//포탑 갯수 확인
		if(turrets.Num() < 2)
		{
			LOG_SCREEN(FColor::Yellow, TEXT("%s 포탑 강화에 필요한 포탑 갯수가 부족합니다."), *InteractiveInstallation->GetName())
			return;
		}

		//가장 먼저 설치된 순으로 정렬
		turrets.Sort([](ACharacterHousing& lhs, ACharacterHousing& rhs)
		{
			return lhs.GetCreateTime() < rhs.GetCreateTime();
		});

		//포탑 업그레이드
		if(InteractiveInstallation->UpgradeInstallation())
		{
			//재료 포탑 제거
			FObjectManager::GetInstance()->DestroyActor(turrets[0]->GetObjectId());
			FObjectManager::GetInstance()->DestroyActor(turrets[1]->GetObjectId());
			LOG_SCREEN(FColor::Yellow, TEXT("Upgrade Turret: %s"), *InteractiveInstallation->GetName())
		}
	}
}

