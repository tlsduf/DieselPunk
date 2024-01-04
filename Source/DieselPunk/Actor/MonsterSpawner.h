// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
*	스플라인으로 구성한 영역안의 랜덤 위치에서 몬스터를 소환하는 액터입니다.
*	
*/

#include "GameFramework/Actor.h"
#include "MonsterSpawner.generated.h"

class USplineComponent;

struct FWaveModuleInfo;
struct FWaveInfo;
struct FStageWaveInfo;
struct FSpawnInfo
{
	FString MonsterName = TEXT("");	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	float StartDelay = 0.f;			// 스폰을 시작하기 까지 시간입니다.
	FString BpPath = TEXT("");		//스폰할 몬스터의 Blueprint 경로입니다.
};

UCLASS()
class DIESELPUNK_API AMonsterSpawner : public AActor
{
	GENERATED_BODY()


	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	bool bDrawDebug = false;	

	/////////////////////////////////////////////////////////////////////
	// for info Management //
public:
	
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	int32 SpawnerNumber = 0;					// 스포너 이름 디폴트 0 (1, 2, 3 ~)
	
protected:
	int32 ObjectId = -1;					//오브젝트 ID
	
	/////////////////////////////////////////////////////////////////////
	// for Spline , Poligon , MakeRandLoc //
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> SplineComponent;		// 영역을 만들 스플라인 컴포넌트

	TArray<FVector> RectanglePoints;			// 스플라인으로 만들어진 직사각형의 꼭짓점을 담을 배열

	TArray<FVector> RandomLocation;				// 다각형 안의 랜덤 위치값을 담을 배열


	/////////////////////////////////////////////////////////////////////
	// for Spawning //
	
	FString WaveSetID = TEXT("");			//스폰할 웨이브 정보
	
	TArray<FSpawnInfo> SpawnInfo;			//스폰 몬스터 정보
	
	float SpawnerDeltaTime = 0.f;			//누적 시간
	
	TArray<int32> SpawnedMonsterID;			//스폰한 몬스터 IDs

	bool bDoSpawn = false;					//스폰해야하는지

	constexpr static double DistanceDifference = 150;	// 랜덤 스폰 거리 차이
	
public:	
	// Sets default values for this actor's properties
	AMonsterSpawner();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called change info in editor
	virtual void OnConstruction(const FTransform& InTransform)override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	const int32 GetObjectId() const { return ObjectId; }

	void SetObjectId(int32 InObjectId) { ObjectId = InObjectId; }
	
	// InWaveSetName에 해당하는 데이터테이블의 정보를 읽어 세팅하고, 스폰을 시작합니다.
	void StartSpawn(FString InWaveSetName);

	//생성한 몬스터 중 Destroy된 액터 삭제
	void RemoveDeadNPCFromArray();
	
	// 스포너가 소환한 몬스터가 다 파괴되었는지를 반환합니다.
	bool IsWaveCleared();

	// 몬스터를 다 소환했는지 반환합니다.
	bool bSpawnComplete() const { return SpawnInfo.IsEmpty(); };
private:
	// InWaveSetName에 해당하는 데이터테이블의 정보를 읽어 SpawnInfo를 세팅합니다.
	void _SetWaveSet(FString InWaveSetName);
	
	// InWaveModuleName에 해당하는 데이터테이블의 정보를 읽어 SpawnInfo를 세팅하고, InAddStartDelay만큼 스폰시간을 더합니다.
	void _SetWaveModule(FString InWaveModuleName, float InAddStartDelay);
	
	// SpawnInfo에 담긴 정보대로 몬스터를 스폰합니다.
	void SpawnMonster(float InDeltaTime);

private:
	// 스플라인 포인트를 기반으로 직사각형의 점을 PolygonPoints에 담습니다.
	void MakeRectangleBySplinePoints();
	
	// 스플라인 영역 안에 위치한 점을(점 사이의 거리 = DistanceDifference) RandomLocation 에 담습니다.
	void GetRandomLocation();
	
	// 스플라인 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
	bool IsInPolygon(double InX, double InY);
};
