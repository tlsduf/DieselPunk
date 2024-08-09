// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NavigationData.h"
#include "../Util/SplineConstructor.h"
#include "Navigation/PathFollowingComponent.h"

#include "DPNavigationComponent.generated.h"

class ACharacterBase;

constexpr int AddForce_ScaleValue = 100;	//Character 에게 AddForce를 해줄 노말벡터에 곱해지는 스케일값
constexpr int JOIN_DIST = 50;	// 경로에 합류하는 거리
constexpr int RESearch_DIST = 500;	// 경로를 재탐색하는 거리

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UDPNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 커스텀 몬스터 크기 테스트
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Navi")
	float testCapsuleRadius = 150;

private:
	TWeakObjectPtr<ACharacterBase> Owner = nullptr;
	
	UPROPERTY(transient)
	TObjectPtr<ANavigationData> MyNavData;	// 경로탐색에 활용되는 NavigationData

	TArray<FVector> MyPathPoints;	// 몬스터의 PathPoint를 담을 배열
	
	FSplinePath SplinePath;			// MyPathPoints를 기반으로 생성된 Curve Spline

	FVector ForceDirection = FVector::ZeroVector;
	
	
	// inStartLoc to inEndLoc 경로탐색 // 기존의 경로탐색 로직을 그대로 따라합니다.(아마도)
	FNavPathSharedPtr SearchPathTo(const FVector& inStartLoc, const FVector& inEndLoc);
	
	// FPathFindingQuery Set
	FPathFindingQuery BuildPathFindingQuery(const FVector& inStartLoc, const FVector& inEndLoc) const;

public:
	// 전체 경로를 탐색합니다. // 몬스터 스폰시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	int32 UpdatePath(FVector inGoalLoc, TArray<FVector> inGoalLocArray);
	
	// 경로위에 포탑이 있다면 해당 포탑의 ID를 반환합니다.
	int32 GetTurretIdOnPath();
	
	// MyPathPoints를 기반으로 곡선경로 스플라인을 생성합니다.
	void MakeSplinePath();

	// 스플라인 경로를 따라가게 AddForce 해줍니다.
	void AddForceAlongSplinePath();
	
	// 스플라인 경로를 따라가게 MoveTo 해줍니다.(Unreal AI-MoveTo사용)
	FVector MoveToAlongSplinePath();

	// 경로 DrawDebug
	void DrawDebugSpline();

	//액터와 가장 가까운 스플라인의 점 사이의 거리를 반환합니다.
	bool bFarAwayActorToSpline();
	
	FVector GetForceDirection(){return ForceDirection;}

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
