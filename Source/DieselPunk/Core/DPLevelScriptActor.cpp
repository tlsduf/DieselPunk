// Fill out your copyright notice in the Description page of Project Settings.


#include "../Core/DPLevelScriptActor.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DatatableManager.h"
#include "../Data/StageWaveDataTable.h"
#include "../Actor/MonsterSpawner.h"
#include "../Actor/PathRouter.h"


//생성자
ADPLevelScriptActor::ADPLevelScriptActor()
{
	
}

void ADPLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

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
	GetPathRouterIDInWorld();
	
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
			if( Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[i]))->SpawnerNumber
				== Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[j]))->SpawnerNumber)
				LOG_SCREEN(FColor::Red, TEXT("스포너 Alert: 중복되는 SpawnerNumber가 존재합니다. SpanwerNumber : %d 를 확인하세요."), Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[j]))->SpawnerNumber);
		}
	}
	
	// SpawnerNumber 순으로 재정렬 (중복이 있어도 정렬함)
	MonsterSpawnerIDs.Sort([](const int32& A, const int32& B)
	{
		 return Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(A))->SpawnerNumber
				< Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(B))->SpawnerNumber;
	});
}

// =============================================================
// 월드에 배치된 경유지들의 ID를 PathRouterIDs 에 저장합니다. (그냥 담기만 합니다. 정렬x)
// =============================================================
void ADPLevelScriptActor::GetPathRouterIDInWorld()
{
	FObjectManager::GetInstance()->FindActorArrayByPredicate(PathRouterIDs, [](AActor* InActor)
	{
		if(Cast<APathRouter>(InActor))
			return true;
		return false;
	});
	
	// SpawnerNumber 중복되는지 판별
	for(int32 i = 0; i < PathRouterIDs.Num(); ++i)
	{
		for(int32 j = 0; j < PathRouterIDs.Num(); ++j)
		{
			if(i == j)
				continue;
			
			auto a = Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(PathRouterIDs[i]));
			auto b = Cast<APathRouter>(FObjectManager::GetInstance()->FindActor(PathRouterIDs[j]));
			if( a->PathRouterNumber == b->PathRouterNumber && a->OriginSpawnerNumber == b->OriginSpawnerNumber)
				LOG_SCREEN(FColor::Red, TEXT("경유지 Alert: 스포너%d 와 연결된 경유지 중, 중복되는 PathRouterNumber가 존재합니다. PathRouterNumber : %d 를 확인하세요."), a->OriginSpawnerNumber, a->PathRouterNumber);
		}
	}
}

// =============================================================
// StageWaveDataTable 정보를 받아서 StageInfo 에 저장합니다.
// =============================================================
void ADPLevelScriptActor::SetStageWaveInfo()
{
	const FStageWaveDataTable* StageWaveDataTable = FDataTableManager::GetInstance()->GetData<FStageWaveDataTable>(EDataTableType::StageWave, StageName);
	if(StageWaveDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("스테이지 Alert: %s의 변수 StageName: %s에 해당하는 데이터가 없습니다."), *GetName(), *StageName)
		return;
	}
	
	for(const FStageWaveInfo& inStageInfo : StageWaveDataTable->StageWaveInfo)
	{
		FStageInfo info;
		info.bDefconUse = inStageInfo.bDefconTimeUse;
		info.DefconTime = inStageInfo.DefconTime;
		info.WaveSetInfoID = inStageInfo.WaveSetInfoID;
		info.SupplyInfo = inStageInfo.SupplyInfo;
		
		StageInfo.Add(info);
	}
}

// =============================================================
// 웨이브가 클리어됐는지 확인하고, 클리어되면 다음 웨이브를 실행합니다.
// =============================================================
void ADPLevelScriptActor::WaveClearEvent()
{
	bool isWaveCleared = true;
	for(auto ID : MonsterSpawnerIDs)
	{
		AMonsterSpawner* monsterSpawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(ID));
		if(monsterSpawner)
		{
			monsterSpawner->RemoveDeadNPCFromArray();
			isWaveCleared = (isWaveCleared && monsterSpawner->IsWaveCleared());
		}
	}

	// 웨이브가 클리어되면 다음 웨이브 바인딩
	if(isWaveCleared)
	{
		WaveIndex++;
		BindStartWave();
	}
	
	LOG_SCREEN(FColor::Blue, TEXT("웨이브 클리어?  %hhd"), isWaveCleared);
}

// =============================================================
// 스테이지의 웨이브를 바인딩합니다
// =============================================================
void ADPLevelScriptActor::BindStartWave()
{
	//WaveIndex 가 StageInfo배열의 개수보다 크면 예외처리
	if(StageInfo.Num() <= WaveIndex)
		return;

	if(bPlayingWave)
		return;
	
	if(StageInfo[WaveIndex].bDefconUse)
	{
		if(GetWorld()->GetTimerManager().IsTimerActive(WaveTHandle))
		{
			GetWorld()->GetTimerManager().ClearTimer(WaveTHandle);
			StartWave();
			return;
		}
		TWeakObjectPtr<ADPLevelScriptActor> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(WaveTHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->StartWave();
			},StageInfo[WaveIndex].DefconTime, false);
	}
}

// =============================================================
// 스테이지의 웨이브를 시작합니다
// =============================================================
void ADPLevelScriptActor::CallStartWave()
{
	//WaveIndex 가 StageInfo배열의 개수보다 크면 예외처리
	if(StageInfo.Num() <= WaveIndex)
		return;

	if(bPlayingWave)
		return;
	
	if( !StageInfo[WaveIndex].bDefconUse)
		StartWave();
}

// =============================================================
// 각 스포너들의 웨이브를 실행합니다. [TODO] 스포너 이름
// =============================================================
void ADPLevelScriptActor::StartWave()
{
	if(StageInfo.Num() <= WaveIndex)
		return;

	LOG_SCREEN(FColor::Red, TEXT("!!! %d 번째 웨이브 시작 !!!"), WaveIndex + 1);

	for(int32 i = 0; i < MonsterSpawnerIDs.Num(); ++i)
	{
		AMonsterSpawner* monsterSpawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(MonsterSpawnerIDs[i]));
		if(monsterSpawner && monsterSpawner->bSpawnComplete() && monsterSpawner->IsWaveCleared())
			monsterSpawner->StartSpawn(StageInfo[WaveIndex].WaveSetInfoID[i]);
	}
}

