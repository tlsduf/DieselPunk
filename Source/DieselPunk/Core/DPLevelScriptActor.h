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
	TArray<FString> WaveModuleInfoID;			// 웨이브 ID. DT_WaveSet 와 행 이름이 동일해야합니다.
	int32 CostReward = 0;			// 현 웨이브 코스트보상
};

UCLASS()
class DIESELPUNK_API ADPLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

	//웨이브가 시작했을 때 브로드캐스트하는 델리게이트 입니다. 순서대로 현재 웨이브 단계, 총 웨이브 단계, 이번 웨이브에 스폰될 몬스터 갯수입니다.
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FDelegateStartWave, int32, int32, int32)
	//웨이브가 클리어됐을 때 브로드캐스트하는 델리게이트 입니다.
	DECLARE_MULTICAST_DELEGATE(FDelegateClearWave)
	//웨이브가 시작했을 때 브로드캐스트하는 델리게이트 입니다. 데프콘 시간을 넘겨줍니다.
	DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateCountDefcon, int32)

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	FString StageName = TEXT("DefaultStageName");			// 스테이지 이름 (임시)

	TArray<FStageInfo> StageInfo;		// 스테이지 데이터테이블

	TArray<int32> MonsterSpawnerIDs;	// 맵에 배치된 MonsterSpawner ID를 어레이에 담아서 관리

	TArray<int32> PathRouterIDs;		// 맵에 배치된 PathRouter ID를 어레이에 담아서 관리
	
	FTimerHandle WaveTHandle;			// 웨이브 시작 타이머핸들

	bool bPlayingWave = false;			// 웨이브가 진행 중인지
	
	int32 WaveIndex = 0;				// 0부터 StageInfo.Num() 까지

	FDelegateStartWave DelegateStartWave;
	FDelegateClearWave DelegateClearWave;
	FDelegateCountDefcon DelegateCountDefcon;
	
////////////////////////////////////////////////////////////////////////////////

protected:
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

	// 각 스포너들의 웨이브를 실행합니다.
	void _StartWave();
	
public:
	// 웨이브가 클리어됐는지 확인하고, 클리어되면 특정 함수들을 실행합니다.
	void CheckWaveCleared();
	
	// 스테이지의 웨이브를 예약합니다. // 다음 웨이브를 예약합니다.
	// 스테이지의 웨이브를 시작합니다. // 다음 웨이브를 시작합니다.
	void StartWaveSequence();

	// 웨이브 클리어 이벤트를 실행합니다.
	void WaveClearEvent();

public:
	/////////////////////////////////////////////////////////////////////
	// Getter, Setter //
	
	const TArray<int32>& GetMonsterSpawnerIDs() { return MonsterSpawnerIDs; }
	const TArray<int32>& GetPathRouterIDs() { return PathRouterIDs; }

	FDelegateStartWave& GetDelegateStartWave(){return DelegateStartWave;}
	FDelegateClearWave& GetDelegateClearWave(){return DelegateClearWave;}
	FDelegateCountDefcon& GetDelegateCountDefcon(){return DelegateCountDefcon;}

	const TArray<int32>& GetMonsterSpawnerIds(){return MonsterSpawnerIDs;}

public:
	void ChangeReciveDecal();
};
