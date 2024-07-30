// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretCard.h"

#include "AITestsCommon.h"
#include "../Data/CardDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Character/CharacterTurret.h"
#include "../Character/CharacterInstallation.h"
#include "DieselPunk/Component/HousingActorComponent.h"

FTurretCard::FTurretCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner)
	: FCard(InKey, InCardName, InOwner)
{
	const FCardDataTable* data = FDataTableManager::GetInstance()->GetData<FCardDataTable>(EDataTableType::Card, Info.CardName);
	Info.CardType = data->CardType;
	Info.Cost = data->Cost;
	MaxTier = data->MaxTier;
	CurrentTier = 1;
	ControlTurretId = -1;
	if(!data->Names.IsEmpty())
		CharacterName = data->Names[0];
}

FTurretCard::~FTurretCard()
{
}

//카드 사용 함수
void FTurretCard::_Activate(bool& OutSuccess, int32 InCost)
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
	UClass* TurretClass = nullptr;
	if(Info.CardType == ECardType::Turret)
		TurretClass = LoadClass<ACharacterTurret>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
	else if(Info.CardType == ECardType::Installation)
		TurretClass = LoadClass<ACharacterInstallation>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
	
	if(TurretClass)
	{
		FVector traceStartLocation = Owner->GetActorLocation() + (Owner->GetActorForwardVector() * 500) + FVector(0,0,300);
		FVector spawnLocation = UtilCollision::GetZTrace(TurretClass->GetWorld(), traceStartLocation , -1).Location;
			
		FSpawnParam spawnParam;
		spawnParam.Rotation = FRotator::ZeroRotator;
		spawnParam.Location = spawnLocation;
		spawnParam.CallBackSpawn = nullptr;

		if(Info.CardType == ECardType::Turret)
			ControlTurretId = FObjectManager::GetInstance()->CreateActor<ACharacterTurret>(TurretClass, spawnParam);
		else if(Info.CardType == ECardType::Installation)
			ControlTurretId = FObjectManager::GetInstance()->CreateActor<ACharacterInstallation>(TurretClass, spawnParam);
		
		OutSuccess = true;
	}
	AActor* actor = FObjectManager::GetInstance()->FindActor(ControlTurretId);
	if(!actor)
		return;

	UHousingActorComponent* housingComp = Cast<UHousingActorComponent>(actor->GetComponentByClass(UHousingActorComponent::StaticClass()));
	if(housingComp)
		FObjectManager::GetInstance()->OnOffFloorHousingMode(true, housingComp->GetInstallableTypes());
}

void FTurretCard::_Cancel()
{
	FObjectManager::GetInstance()->DestroyActor(ControlTurretId);
	FObjectManager::GetInstance()->OnOffFloorHousingMode(false);
	ControlTurretId = -1;
}

//카드 사용 완료 함수
void FTurretCard::_Complete(bool& OutSuccess, int32 InCost)
{
	if(InCost < Info.Cost)
	{
		LOG_SCREEN(FColor::White, TEXT("코스트가 부족합니다."))
		OutSuccess = false;
		return;
	}
	
	ACharacterHousing* controlTurret = Cast<ACharacterHousing>(FObjectManager::GetInstance()->FindActor(ControlTurretId));
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
	FObjectManager::GetInstance()->OnOffFloorHousingMode(false);
}

void FTurretCard::_RotateInstallation(double InRotateAngle)
{
	ACharacterHousing* controlTurret = Cast<ACharacterHousing>(FObjectManager::GetInstance()->FindActor(ControlTurretId));
	if(!controlTurret)
	{
		LOG_SCREEN(FColor::Red, TEXT("ControlTurretId: %d에 해당하는 Turret이 존재하지 않습니다."), ControlTurretId)
		return;
	}
	
	//FRotator rotator;
	//rotator.Pitch = 0.0;
	//rotator.Yaw = InRotateAngle;
	//rotator.Roll = 0.0;
	//controlTurret->AddActorWorldRotation(rotator);

	FRotator rotator = controlTurret->GetActorRotation();
	rotator.Yaw += InRotateAngle;
	controlTurret->SetActorRotation(rotator);

	controlTurret->ChangeGridSizeVerticalHorizontal();
	//controlTurret->UpdateBoxComponent();
}
