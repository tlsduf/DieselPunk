// Fill out your copyright notice in the Description page of Project Settings.


#include "../Core/DPLevelScriptActor.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DatatableManager.h"
#include "../Data/StageWaveDataTable.h"
#include "../Actor/MonsterSpawner.h"
#include "../Character/CharacterPC.h"

#include <Kismet/GameplayStatics.h>

#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DieselPunk/Actor/FloorStaticMeshActor.h"
#include "DieselPunk/Data/WaveModuleDataTable.h"


//생성자
ADPLevelScriptActor::ADPLevelScriptActor()
{
	
}

void ADPLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	ChangeReciveDecal();
	InitLevel();
}

// =============================================================
// EnteringMap 시 호출할 초기화함수
// =============================================================
void ADPLevelScriptActor::InitLevel()
{
	// 월드에 배치된 스포너들의 ID를 MonsterSpawnerIDs 에 저장합니다.
	GetMonsterSpawnerIdInWorld();
	// 월드에 배치된 경유지들의 ID를 PathRouterIDs 에 저장합니다. (그냥 담기만 합니다. 정렬x)
	//GetPathRouterIDInWorld();
	
	// StageWaveDataTable 정보를 받아서 StageInfo 에 저장합니다.
	/*
	*	데프콘Info : 데프콘 정보(임시)
	*	WaveInfo_Array : 배열 순서대로 스폰위치1, 2, 3 … 웨이브 세팅
	*	서플라이Info : 서플라이 정보(임시)
	 */
	SetStageWaveInfo();
	
	WaveIndex = 0;
}

// =============================================================
// LeavingMap 시 호출할 초기화함수
// =============================================================
void ADPLevelScriptActor::ResetLevel()
{
}

// =============================================================
// 월드에 배치된 스포너들의 ID를 MonsterSpawnerIDs 에 저장합니다.
// =============================================================
void ADPLevelScriptActor::GetMonsterSpawnerIdInWorld()
{
	FObjectManager::GetInstance()->FindActorArrayByPredicate(MonsterSpawnerIDs, [](AActor* InActor)
	{
		if(Cast<AMonsterSpawner>(InActor))
			return true;
		return false;
	});
	
	// SpawnerNumber 중복되는지 판별
	for(int32 i = 0; i < MonsterSpawnerIDs.Num(); ++i)
	{
		for(int32 j = 0; j < MonsterSpawnerIDs.Num(); ++j)
		{
			if(i == j)
				continue;
			if( Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[i]))->GetSpawnerNumber() == Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[j]))->GetSpawnerNumber())
			{
				LOG_SCREEN(FColor::Red, TEXT("스포너 Alert: 중복되는 SpawnerNumber가 존재합니다. SpanwerNumber : %d 를 확인하세요."), Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[j]))->GetSpawnerNumber());
			}
		}
	}
	
	// SpawnerNumber 순으로 재정렬 (중복이 있어도 정렬함)
	MonsterSpawnerIDs.Sort([](const int32& A, const int32& B)
	{
		 return Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(A))->GetSpawnerNumber()
				< Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(B))->GetSpawnerNumber();
	});
}

// =============================================================
// StageWaveDataTable 정보를 받아서 StageInfo 에 저장합니다.
// =============================================================
void ADPLevelScriptActor::SetStageWaveInfo()
{
	const FStageWaveDataTable* StageWaveDataTable = FDataTableManager::GetInstance()->GetData<FStageWaveDataTable>(EDataTableType::StageWave, StageName);
	if(StageWaveDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("스테이지 Alert: %s의 변수 StageName: %s에 해당하는 데이터가 없습니다."), *GetName(), *StageName);
		return;
	}
	
	for(const FStageWaveInfo& inStageInfo : StageWaveDataTable->StageWaveInfo)
	{
		FStageInfo info;
		info.bDefconUse = inStageInfo.bDefconTimeUse;
		info.DefconTime = inStageInfo.DefconTime;
		info.WaveModuleInfoID = inStageInfo.WaveModuleInfoID;
		info.CostReward = inStageInfo.CostReward;
		
		StageInfo.Add(info);
	}
}

// =============================================================
// 웨이브가 클리어됐는지 확인하고, 클리어되면 특정 함수들을 실행합니다.
// =============================================================
void ADPLevelScriptActor::CheckWaveCleared()
{
	bool isWaveCleared = true;
	for(auto ID : MonsterSpawnerIDs)
	{
		if(AMonsterSpawner* monsterSpawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(ID)))
		{
			monsterSpawner->RemoveDeadNPCFromSpawnedMonsterID();
			isWaveCleared = (isWaveCleared && monsterSpawner->IsWaveCleared());
		}
	}

	// 웨이브가 클리어되면 다음 웨이브 바인딩
	if(isWaveCleared)
	{
		WaveClearEvent();
		WaveIndex++;
		bPlayingWave = false;
		StartWaveSequence();
	}
	
	LOG_SCREEN(FColor::Blue, TEXT("웨이브 클리어?  %hhd"), isWaveCleared);
}

// =============================================================
// 스테이지의 웨이브를 (예약/시작)합니다. 다음 웨이브를 (에약/시작)합니다.
// =============================================================
void ADPLevelScriptActor::StartWaveSequence()
{
	//WaveIndex 가 StageInfo배열의 개수보다 크면 예외처리 << 의미:설정한 웨이브가 끝남
	if(StageInfo.Num() <= WaveIndex)
		return;

	if(bPlayingWave)
		return;
	
	if(StageInfo[WaveIndex].bDefconUse)
	{
		if(GetWorld()->GetTimerManager().IsTimerActive(WaveTHandle))
		{
			GetWorld()->GetTimerManager().ClearTimer(WaveTHandle);
			_StartWave();
		}
		else
		{
			TWeakObjectPtr<ADPLevelScriptActor> thisPtr = this;
			GetWorld()->GetTimerManager().SetTimer(WaveTHandle, [thisPtr](){
					if(thisPtr.IsValid())
						thisPtr->_StartWave();
				},StageInfo[WaveIndex].DefconTime, false);
			//Hud Event
			DelegateCountDefcon.Broadcast(StageInfo[WaveIndex].DefconTime);
		}
	}
	else
	{
		_StartWave();
	}
}

// =============================================================
// 웨이브 클리어 이벤트를 실행합니다.
// =============================================================
void ADPLevelScriptActor::WaveClearEvent()
{
	//WaveIndex 가 StageInfo배열의 개수보다 크면 예외처리
	if(StageInfo.Num() <= WaveIndex)
		return;

	// 플레이어에게 코스트를 지급합니다.
	ACharacterPC* playerPawn = Cast<ACharacterPC>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (playerPawn == nullptr)
		return;
	playerPawn->ChangeStat(ECharacterStatType::Cost, StageInfo[WaveIndex].CostReward);

	//Hud Event
	DelegateClearWave.Broadcast();
}

void ADPLevelScriptActor::ChangeReciveDecal()
{
	UWorld* world = GetWorld();
	if(world)
	{
		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(world, AActor::StaticClass(), actors);
		for(AActor* actor : actors)
		{
			if(Cast<AFloorStaticMeshActor>(actor))
				continue;
			if(actor)
			{
				TArray<UActorComponent*> components;
				actor->GetComponents(components);
				for(UActorComponent* comp : components)
				{
					if(UPrimitiveComponent* primitiveComp = Cast<UPrimitiveComponent>(comp))
					{
						primitiveComp->SetReceivesDecals(false);
					}
				}
			}
		}
	}
}

// =============================================================
// 각 스포너들의 웨이브를 실행합니다. [TODO] 스포너 이름
// =============================================================
void ADPLevelScriptActor::_StartWave()
{
	if(StageInfo.Num() <= WaveIndex)
		return;
	
	if(bPlayingWave)
	{
		LOG_SCREEN(FColor::Red, TEXT("%d 번째 웨이브 진행중"), WaveIndex + 1);
		return;
	}
	else
	{
		LOG_SCREEN(FColor::Red, TEXT("%d 번째 웨이브 시작"), WaveIndex + 1);
	}
	bPlayingWave = true;

	for(int32 i = 0; i < MonsterSpawnerIDs.Num(); ++i)
	{
		AMonsterSpawner* monsterSpawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[i]));
		if(monsterSpawner && monsterSpawner->IsSpawnComplete() && monsterSpawner->IsWaveCleared())
			monsterSpawner->StartSpawn(StageInfo[WaveIndex].WaveModuleInfoID[i]);
	}

	int32 count = 0;
	for(const FString& waveName : StageInfo[WaveIndex].WaveModuleInfoID)
	{
		const FWaveModuleDataTable* moduleInfo = FDataTableManager::GetInstance()->GetData<FWaveModuleDataTable>(EDataTableType::WaveModule, waveName);
		if(!moduleInfo)
			continue;

		for(const FWaveModuleInfo& waveInfo : moduleInfo->WaveModuleInfo)
			count += waveInfo.bDoRep ? waveInfo.SpawnCount * waveInfo.Reps : waveInfo.SpawnCount;
	}

	//Hud Event
	DelegateStartWave.Broadcast(WaveIndex, StageInfo.Num(), count);
}

