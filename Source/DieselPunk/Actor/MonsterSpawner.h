// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
*	박스로 구성한 영역안의 랜덤 위치에서 몬스터를 소환하는 액터입니다.
*	
*/

#include "GameFramework/Actor.h"
#include "../Interface/DpManagementTargetInterFace.h"
#include "MonsterSpawner.generated.h"

class USplineComponent;
class UBoxComponent;
class APathRouter;

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
class DIESELPUNK_API AMonsterSpawner : public AActor, public IDpManagementTargetInterFace
{
	GENERATED_BODY()

	UPROPERTY()
	USceneComponent* SceneRoot = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *Mesh;
	
	UPROPERTY(EditDefaultsOnly, Category = "MYDP_Setting")
	bool DebugOnOff = false;	

	/////////////////////////////////////////////////////////////////////
	// for info Management //

	// 스포너 이름 디폴트 0 (1, 2, 3 ~)
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	int32 SpawnerNumber = 0;
	
	TMap<FVector, TArray<FVector>> PathMap;		// 몬스터가 스폰될 위치를 Key로 하여, 투영에 의해 결정된 총 목적지 배열을 담습니다.
	
	//연결된 라우터(다음 경로)
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	TObjectPtr<APathRouter> NextPathRouter;		

	int32 PathRouterNodeNum = 0;							// 연결된 라우터의 순서입니다. 이것을 Key로 하여 PathRouterNodes에 등록합니다.
	TMap<int32, TObjectPtr<APathRouter>> PathRouterNodes;	// 연결된 라우터를 모두 등록합니다.
	
protected:
	
	/////////////////////////////////////////////////////////////////////
	// for box , Polygon , MakeRandLoc //

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> BoxComponent;		// 영역을 만들 박스 컴포넌트
	
	const double BoxScale = 150;			// 박스크기

	TArray<FVector> RectanglePoints;			// 박스의 꼭짓점을 담을 배열

	TArray<FVector> RandomLocation;				// 박스 안의 랜덤 위치값을 담을 배열


	/////////////////////////////////////////////////////////////////////
	// for Spawning //
	
	TArray<FSpawnInfo> SpawnInfo;			//스폰 몬스터 정보
	
	float SpawnerDeltaTime = 0.f;			//누적 시간
	
	TArray<int32> SpawnedMonsterID;			//스폰한 몬스터 IDs

	bool bDoSpawn = false;					//스폰해야하는지

	constexpr static double DistanceDifference = 150;	// 랜덤 스폰 거리 차이

protected:
	// Sets default values for this actor's properties
	AMonsterSpawner();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called change info in editor
	virtual void OnConstruction(const FTransform& InTransform)override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// InWaveModuleName에 해당하는 데이터테이블의 정보를 읽어 세팅하고, 스폰을 시작합니다.
	void StartSpawn(const FString& InWaveModuleName);

	//생성한 몬스터 중 Destroy된 액터 삭제
	void RemoveDeadNPCFromSpawnedMonsterID();
	
	// 스포너가 소환한 몬스터가 다 파괴되었는지를 반환합니다.
	bool IsWaveCleared() const { return SpawnInfo.IsEmpty() && SpawnedMonsterID.IsEmpty(); }

	// 몬스터를 다 소환했는지 반환합니다.
	bool IsSpawnComplete() const { return SpawnInfo.IsEmpty(); }

private:
	/////////////////////////////////////////////////////////////////////
	// DT정보 Set, 스폰 //
	
	// InWaveModuleName에 해당하는 데이터테이블의 정보를 읽어 SpawnInfo를 세팅하고
	void _SetWaveModule(const FString& InWaveModuleName);
	
	// SpawnInfo에 담긴 정보대로 몬스터를 스폰합니다.
	void SpawnMonster(float InDeltaTime);

	/////////////////////////////////////////////////////////////////////
	// PathRouter(경유지) 등록, 위치투영을 위한 비율값 세팅 //
	
	// 연결된 PathRouter를 모두 번호를 부여하며 등록합니다. // 재귀시작함수 입니다.
	void RegistPathRouter(TMap<int32, TObjectPtr<APathRouter>>& inPathRouterNodes);
	
	// 스폰시 해당'몬스터'의 Proportion을 설정합니다.
	FVector2D SetProportion(const FVector& inLoc);

	/////////////////////////////////////////////////////////////////////
	// 사각 영역 생성, 사각 내부 점 생성 //
	
	// 박스컴포넌트를 기반으로 직사각형의 점을 PolygonPoints에 담습니다.
	void MakeRectangleBySplinePoints();
	
	// 사각 영역 안에 위치한 점을(점 사이의 거리 = DistanceDifference) RandomLocation 에 담습니다.
	void GetRandomLocation();
	
	// 사각 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
	bool IsInPolygon(const double& InX, const double& InY);


public:
	/////////////////////////////////////////////////////////////////////
	// Getter, Setter //
	int32 GetSpawnerNumber() const { return SpawnerNumber; };
};
