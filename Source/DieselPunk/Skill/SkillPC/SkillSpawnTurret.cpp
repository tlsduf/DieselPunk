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
		//터렛 스몰에 해당하는 경로 탐색을 위한 데이터 테이블 서치
		const FCharacterDataTable* dataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, TEXT("TurretSmall"));
		if(!dataTable)
		{
			LOG_SCREEN(FColor::Red, TEXT("TurretSmall에 해당하는 데이터테이블 정보가 존재하지 않습니다."))
			return;
		}

		//터렛 생성
		UClass* TurretClass = LoadClass<ACharacterTurret>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
		if(TurretClass)
		{
			FVector traceStartLocation = ownerPawn->GetActorLocation() + (ownerPawn->GetActorForwardVector() * 500) + FVector(0,0,300);
			FVector spawnLocation = UtilCollision::GetZTrace(traceStartLocation , -1).Location;
			
			FSpawnParam spawnParam;
			spawnParam.Rotation = FRotator::ZeroRotator;
			spawnParam.Location = spawnLocation;
			spawnParam.CallBackSpawn = nullptr;
			
			ControlTurretId = FObjectManager::GetInstance()->CreateActor<ACharacterTurret>(TurretClass, spawnParam);
		}
		
		bTaskOn = true;
	}
	else
	{
		ACharacterTurret* controlTurret = Cast<ACharacterTurret>(FObjectManager::GetInstance()->FindActor(ControlTurretId));
		if(!controlTurret)
		{
			LOG_SCREEN(FColor::Red, TEXT("ControlTurretId: %d에 해당하는 Turret이 존재하지 않습니다."), ControlTurretId)
			return;
		}

		//터렛이 생성될 수 있다면 터렛 생성
		if(!controlTurret->CompleteHousingTurret())
		{
			LOG_SCREEN(FColor::Yellow, TEXT("ControlTurretId: %d에 해당하는 Turret이 설치될 수 없습니다.."), ControlTurretId)
			return;
		}
		
		bTaskOn = false;
	}
}

