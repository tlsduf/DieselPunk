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
	int32			X = 0, Y = 0;
	FVector			Location = FVector::ZeroVector;
	ENavNodeState	NavNodeState = ENavNodeState::Passable;
	FDpNavNode*		Parent = nullptr;
	TArray<TPair<int32, int32>> Road;
};

class DIESELPUNK_API FNavigationManager
{
	Singleton_Declare(FNavigationManager)
private:
	TMap<int32, TMap<int32, FDpNavNode>> NavMap;

	TArray<TPair<int32, int32>> OpenList;
	TArray<TPair<int32, int32>> CloseList;

	double StartX, StartY;
public:
	//그리드 사이즈
	static constexpr int32 GridSize = 100;

private:
	void Initialize();
	void Release();

	//네비 노드 추가
	void AddNavNode(int32 InX, int32 InY, FDpNavNode InNavNode);

	//리스트 안에 존재 여부 반환
	bool IsInList(int32 InX, int32 InY, const TArray<TPair<int32, int32>>& InList);
	
	//네비 노드 Location 설정
	void BuildNavMapLocation();

	//그래프 생성
	void BuildNavGraph();

	//최단 경로 찾기
	bool _PathFinding(int32 InStartX, int32 InStartY, int32 InEndX, int32 InEndY);

	//두 인덱스 사이 거리 측정
	static double DistanceIndex(double InAx, double InAy, double InBx, double InBy);

	//경로 생성
	TArray<FDpNavNode*> CreatePath(int32 InStartX, int32 InStartY, int32 InEndX, int32 InEndY);

	void DrawDebugNavNode(int32 InX, int32 InY);

public:
	//디버그용 네비 맵 Draw 
	void DrawDebugNavMap();
	
	//네비 노드 생성
	void BuildNavMap(TWeakObjectPtr<AFloorStaticMeshActor> InFloorStaticMeshActor, TArray<FDpBox> InBoxes);
	
	//A-Star알고리즘을 통해 InStartLocation에서 InEndLocation까지의 최단거리 반환
	TArray<FVector> PathFinding(const FVector& InStartLocation, const FVector& InEndLocation);

	//터렛 설치 가능한지 검색
	bool IsPlacementTurret(FVector InLocation, int32 InGridSize);

	//터렛 설치
	bool PlacementTurret(FVector& InOutLocation, int32 InGridSize, TArray<TPair<int32, int32>>& OutIndex);

	//터렛 부서질 때 노드 복구
	void RestoreNavNodeByDestructedTurret(const TArray<TPair<int32, int32>>& InIndex);
};

