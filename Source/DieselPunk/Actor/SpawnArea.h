// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
*	스플라인으로 구성한 영역안의 랜덤 위치에서 몬스터를 소환하는 액터입니다.
*	
*/

#include "GameFramework/Actor.h"
#include "SpawnArea.generated.h"

class USplineComponent;
class UStaticMesh;
class UInstancedStaticMeshComponent;

struct FMonsterSpawnInfo;
struct FSpawnInfo1
{
	FString MonsterName = TEXT("");	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	float DelayTime = 0.f;			//지연시간입니다. 게임이 시작한 후 지연 시간만큼 흐른 뒤 해당 몬스터를 스폰합니다.
	FString BpPath = TEXT("");		//스폰할 몬스터의 Blueprint 경로입니다.
};

UCLASS()
class DIESELPUNK_API ASpawnArea : public AActor
{
	GENERATED_BODY()

public:
	constexpr static int32 DistanceDifference = 50;	// 랜덤 스폰 거리 차이
	
protected:
	/////////////////////////////////////////////////////////////////////
	// for info Management //
	
	int32 ObjectId = -1;					//오브젝트 ID
	
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	FString SpawnerName = TEXT("");			// [TODO] 스포너 이름 (Spawner1, 2, 3 ~)

	/////////////////////////////////////////////////////////////////////
	// for Spline , Poligon , MakeRandLoc //
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> SplineComponent;		// 영역을 만들 스플라인 컴포넌트
	
	TArray<FVector> PolygonPoints;			// 스플라인으로 만들어진 다각형의 꼭짓점을 담을 배열

	TArray<FVector> RandomLocation;			// 다각형 안의 랜덤 위치값을 담을 배열


	/////////////////////////////////////////////////////////////////////
	// for Spawning //
	
	//UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	//FString WaveSetID = TEXT("");			// [TODO] WaveSetDataTable의 행 이름
	
	TArray<FSpawnInfo1> SpawnInfo;			//스폰 몬스터 정보
	
	float SpawnerDeltaTime = 0.f;			//누적 시간
	
	TArray<int32> SpawnMonsterId;			//스폰한 몬스터 IDs

	bool bDoSpawn = false;					//스폰해야하는지
	
public:	
	// Sets default values for this actor's properties
	ASpawnArea();
	
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
	
	// SpawnerName에 해당하는 데이터테이블의 정보를 읽어 세팅하고, 스폰을 시작합니다.
	void SetSpawnerName(FString InSpawnerName);
	
	// 스포너가 소환한 몬스터가 다 파괴되었는지를 반환합니다.
	bool IsWaveCleared();
protected:
	// SpawnInfo에 담긴 정보대로 몬스터를 스폰합니다.
	void SpawnMonster(float InDeltaTime);

private:
	// 스플라인 영역 안의 랜덤 위치값을 배열로 반환합니다.
	void GetRandomLocation();
	
	// 스플라인 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
	bool IsInPolygon(double InX, double InY);

	// 거리가 InRange인 랜덤 위치값을 반환합니다.
	FVector MakeRandomLocation(const FVector& InLocation, double InRange);
};
