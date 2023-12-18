// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
 * 레벨스트립트액터는 틱을 안합니다. 왜인지는 몰 루
 * 
 */






#include "Engine/LevelScriptActor.h"
#include "DPLevelScriptActor.generated.h"


struct FStageInfo
{
	bool bDefconUse = false;		// 현 웨이브 데프콘 사용 유무
	int32 DefconTime = 0;			// 현 웨이브 데프콘 시간
	FString WaveSetInfoID;			// 웨이브 ID. DT_WaveSet 와 행 이름이 동일해야합니다.
	bool SupplyInfo = false;		// 현 웨이브 서플라이 유무
};

UCLASS()
class DIESELPUNK_API ADPLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	FString StageName = TEXT("DefaultStageName");			// 스테이지 이름 (임시)

	TArray<FStageInfo> StageInfo;		// 스테이지 정보

	TArray<int32> MonsterSpawnerIDs;	// 몬스터스포너 ID

	FTimerHandle WaveTHandle;			// 웨이브 시작 타이머핸들

	bool bPlayingWave = false;			// 웨이브가 진행 중인지
	
	int32 WaveIndex = 0;				// 0부터 StageInfo.Num() 까지 
	
////////////////////////////////////////////////////////////////////////////////
	
	ADPLevelScriptActor();

	virtual void BeginPlay() override;
public:
	// EnteringMap 시 호출할 초기화함수
	void InitLevel();
	
	// LeavingMap 시 호출할 초기화함수
	void ResetLevel();
	
private:
	// 월드에 배치된 스포너들의 ID를 MonsterSpawnerIDs 에 저장합니다.
	void GetMonsterSpawnerIdInWorld();
	
	// StageWaveDataTable 정보를 받아서 StageInfo 에 저장합니다.
	void SetStageWaveInfo();

public:
	// 웨이브가 클리어됐는지 확인하고, 클리어되면 다음 웨이브를 실행합니다.
	void WaveClearEvent();
	
	// 스테이지의 웨이브를 실행합니다. // 다음 웨이브를 시작합니다.
	void StartStageAndNextWave();

private:
	// 각 스포너들의 웨이브를 실행합니다.
	void StartWave();
};
