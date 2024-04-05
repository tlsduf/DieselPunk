// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

class UBoxComponent;
class AFloorStaticMeshActor;
enum class ENavNodeState : uint8;

struct FDpBox
{
	FVector Location;
	FVector Extend;
	TWeakObjectPtr<UBoxComponent> BoxComp;
};

struct FDpNavNode
{
	int32					X = 0, Y = 0;
	FVector					Location = FVector::ZeroVector;
	ENavNodeState			NavNodeState = ENavNodeState::Passable;
	TArray<ENavNodeState>	IsGoNodeState;
	FDpNavNode*				Parent = nullptr;
	TWeakObjectPtr<AActor>	BuildActor = nullptr;
	TArray<TPair<int32, int32>> Road;
};

class DIESELPUNK_API FNavigationManager
{
	Singleton_Declare(FNavigationManager)
private:
	TMap<int32, TMap<int32, FDpNavNode>> NavMap;
public:
	//그리드 사이즈
	static constexpr int32 GridSize = 100;
	static constexpr int32 Character_MaxHalfGrid = 3;

private:
	void Initialize();
	void Release();

	bool LoadMapNode();

	//네비 노드 추가
	void AddNavNode(int32 InX, int32 InY, FDpNavNode InNavNode);
	
	//네비 노드 Location 설정
	void BuildNavMapLocation();

	//그래프 생성
	void BuildNavGraph();

	//두 인덱스 사이 거리 측정
	static double DistanceIndex(double InAx, double InAy, double InBx, double InBy);

	//포탑이 설치될 때 IsGoNodeState갱신
	void SetBlockedByBreakableIsGoNodeState(int32 InMinX, int32 InMaxX, int32 InMinY, int32 InMaxY);

	//원 안에 있는 지 판별
	bool IsInCircle(double InMiddleX, double InMiddleY, double InRadius, double InX, double InY);
public:
	//디버그용 네비 맵 Draw 
	void DrawDebugNavMap();
	void DrawDebugNavNode(int32 InX, int32 InY, FColor InColor = FColor::White);
	void DrawNonPassableNavNode(int32 InGridSize);
	void DrawDebugAllNavNode_IsGoNodeState();
	
	//네비 노드 생성
	void BuildNavMap(TWeakObjectPtr<AFloorStaticMeshActor> InFloorStaticMeshActor, TArray<FDpBox> InBoxes);
	void BuildNavMap(TArray<AActor*> InFloorStaticMeshActors);

	//터렛 설치 가능한지 검색
	bool IsPlacementTurret(FVector InLocation, int32 InGridSizeVertical, int32 InGridSizeHorizontal);

	//터렛 설치
	bool PlacementTurret(FVector& InOutLocation, int32 InGridSizeVertical, int32 InGridSizeHorizontal, TArray<TPair<int32, int32>>& OutIndex, TWeakObjectPtr<AActor> InTurret);

	//터렛 부서질 때 노드 복구
	void RestoreNavNodeByDestructedTurret(const TArray<TPair<int32, int32>>& InIndex);

	//해당 인덱스가 범위 내에 Blocked노드가 있는지 판별
	bool IsInBlockedInRange(int32 InX, int32 InY, int32 InRange);
};

