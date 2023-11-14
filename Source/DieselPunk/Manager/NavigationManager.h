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
	FVector			Location;
	ENavNodeState	NavNodeState;
};

class DIESELPUNK_API FNavigationManager
{
	Singleton_Declare(FNavigationManager)
private:
	TMap<int32, TMap<int32, ENavNodeState>> NavNode;
public:
	//그리드 사이즈
	static constexpr int32 GridSize = 100;

private:
	void Initialize();
	void Release();

	//네비 노드 추가
	void AddNavNode(int32 InX, int32 InY, ENavNodeState InNavNodeState);
	
public:
	//네비 노드 생성
	void BuildNavNode(TWeakObjectPtr<AFloorStaticMeshActor> InFloorStaticMeshActor, TArray<FDpBox> InBoxes);
};

