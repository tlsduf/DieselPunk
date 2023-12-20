// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretCard.h"

#include "../Data/CardDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Character/CharacterTurret.h"

FTurretCard::FTurretCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner)
	: FCard(InKey, InCardName, InOwner)
{
	const FCardDataTable* data = FDataTableManager::GetInstance()->GetData<FCardDataTable>(EDataTableType::Card, Info.CardName);
	Info.CardType = data->CardType;
	Info.Cost = data->Cost;
	MaxTier = data->MaxTier;
	CurrentTier = 1;
	CharacterName = data->CharacterName;
}

FTurretCard::~FTurretCard()
{
}

//카드 사용 함수
void FTurretCard::_Activate(bool& OutSuccess)
{
	//터렛 스몰에 해당하는 경로 탐색을 위한 데이터 테이블 서치
	const FCharacterDataTable* dataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, CharacterName);
	if(!dataTable)
	{
		LOG_SCREEN(FColor::Red, TEXT("TurretSmall에 해당하는 데이터테이블 정보가 존재하지 않습니다."))
		OutSuccess = false;
		return;
	}

	//터렛 생성
	UClass* TurretClass = LoadClass<ACharacterTurret>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
	if(TurretClass)
	{
		FVector traceStartLocation = Owner->GetActorLocation() + (Owner->GetActorForwardVector() * 500) + FVector(0,0,300);
		FVector spawnLocation = UtilCollision::GetZTrace(traceStartLocation , -1).Location;
			
		FSpawnParam spawnParam;
		spawnParam.Rotation = FRotator::ZeroRotator;
		spawnParam.Location = spawnLocation;
		spawnParam.CallBackSpawn = nullptr;
			
		ControlTurretId = FObjectManager::GetInstance()->CreateActor<ACharacterTurret>(TurretClass, spawnParam);
		OutSuccess = true;
	}
}

//카드 사용 완료 함수
void FTurretCard::_Complete(bool& OutSuccess)
{
	ACharacterTurret* controlTurret = Cast<ACharacterTurret>(FObjectManager::GetInstance()->FindActor(ControlTurretId));
	if(!controlTurret)
	{
		LOG_SCREEN(FColor::Red, TEXT("ControlTurretId: %d에 해당하는 Turret이 존재하지 않습니다."), ControlTurretId)
		OutSuccess = false;
		return;
	}

	//터렛이 생성될 수 있다면 터렛 생성
	if(!controlTurret->CompleteHousingTurret())
	{
		LOG_SCREEN(FColor::Yellow, TEXT("ControlTurretId: %d에 해당하는 Turret이 설치될 수 없습니다.."), ControlTurretId)
		OutSuccess = false;
		return;
	}
	OutSuccess = true;
}
