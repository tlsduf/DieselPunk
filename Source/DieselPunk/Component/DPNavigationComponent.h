// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NavigationData.h"
#include "../Util/SplineConstructor.h"
#include "Navigation/PathFollowingComponent.h"

#include "DPNavigationComponent.generated.h"

class ACharacterBase;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UDPNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<ACharacterBase> Owner = nullptr;
	
	UPROPERTY(transient)
	TObjectPtr<ANavigationData> MyNavData;	// 경로탐색에 활용되는 NavigationData

	TArray<FVector> MyPathPoints;	// 몬스터의 PathPoint를 담을 배열
	
	FSplinePath SplinePath;			// MyPathPoints를 기반으로 생성된 Curve Spline
	
	// inStartLoc to inEndLoc 경로탐색 // 기존의 경로탐색 로직을 그대로 따라합니다.(아마도)
	FNavPathSharedPtr SearchPathTo(const FVector inStartLoc, const FVector inEndLoc);
	
	// FPathFindingQuery Set
	FPathFindingQuery BuildPathFindingQuery(const FVector inStartLoc, const FVector inEndLoc) const;

public:
	// 전체 경로를 탐색합니다. // 몬스터 스폰시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	void UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray);

	// 생성된 경로(곡선경로 아님 MyPathPoints) 위에 포탑이 있는지 확인합니다.
	// 포탑이 있다면, 그 포탑의 ID를 반환하고,
	// MyPathPoints를 포탑이 최종목적지가 되도록 포탑의 위치를 추가하고, 뒤의 value들을 제거합니다.
	// index 0부터 순차적으로 탐색하고, 첫 포탑 반환시 탐색을 종료합니다.
	int32 GetTurretIdOnPath();
	
	// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
	void MakeSplinePath();

	// 스플라인 경로를 따라가게 AddForce 해줍니다.
	void AddForceAlongSplinePath();

	// 경로 DrawDebug
	void DrawDebugSpline();

public:	
	// Sets default values for this component's properties
	UDPNavigationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
