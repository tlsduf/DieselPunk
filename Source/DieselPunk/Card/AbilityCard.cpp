// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityCard.h"

#include "../Data/CardDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Character/CharacterTurret.h"
#include "DieselPunk/Actor/ProjectileBase.h"
#include "DieselPunk/Actor/SkillActor.h"
#include "GameFramework/PlayerController.h"

FAbilityCard::FAbilityCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner)
	: FCard(InKey, InCardName, InOwner)
{
	const FCardDataTable* data = FDataTableManager::GetInstance()->GetData<FCardDataTable>(EDataTableType::Card, Info.CardName);
	Info.CardType = data->CardType;
	Info.Cost = data->Cost;
	AbilityCardType = data->AbilityCardType;
	BlueprintName = data->Name;
}

FAbilityCard::~FAbilityCard()
{
}

//카드 사용 함수
void FAbilityCard::_Activate(bool& OutSuccess, int32 InCost)
{
	if(InCost < Info.Cost)
	{
		LOG_SCREEN(FColor::White, TEXT("코스트가 부족합니다."))
		OutSuccess = false;
		return;
	}

	OutSuccess = true;
}

//카드 사용 완료 함수
void FAbilityCard::_Complete(bool& OutSuccess)
{
	UClass* uclass = nullptr;

	if(AbilityCardType == EAbilityCardType::Projectile)
		uclass = LoadClass<AProjectileBase>( NULL, *UtilPath::GetAbilityBlueprintPath(*UtilPath::EnumToString(AbilityCardType), *BlueprintName));
	
	if(uclass)
	{
		TArray<const AActor*> ignore;
		ignore.Add(FObjectManager::GetInstance()->GetPlayer());
		FHitResult result;
		if(!UtilCollision::GetViewMiddle(FObjectManager::GetInstance()->GetWorld(), Cast<APlayerController>(FObjectManager::GetInstance()->GetPlayer()->GetController()),
			result, 99999, ignore))
		{
			OutSuccess = false;
			return;
		}
			
		FSpawnParam spawnParam;
		spawnParam.Rotation = FRotator::ZeroRotator;
		spawnParam.Location = result.Location;
		spawnParam.CallBackSpawn = nullptr;

		int32 id = FObjectManager::INVALID_OBJECTID;
		if(AbilityCardType == EAbilityCardType::Projectile)
			id = FObjectManager::GetInstance()->CreateActor<AProjectileBase>(uclass, spawnParam);

		if(FObjectManager::GetInstance()->IsValidId(id))
		{
			Cast<ASkillActor>(FObjectManager::GetInstance()->FindActor(id))->InitTransformOffset();
			OutSuccess = true;
		}
	}
}
