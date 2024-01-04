// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
*	스플라인으로 구성한 영역안의 랜덤 위치에서 몬스터를 소환하는 액터입니다.
*	
*/

#include "GameFramework/Actor.h"
#include "PathRouter.generated.h"

class USplineComponent;


UCLASS()
class DIESELPUNK_API APathRouter : public AActor
{
	GENERATED_BODY()


	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	bool bDrawDebug = false;	

	/////////////////////////////////////////////////////////////////////
	// for info Management //
public:
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	int32 PathRouterNumber = 0;				// 경유지 번호 디폴트 0 (1, 2, 3 ~)
	
	UPROPERTY(EditInstanceOnly, Category = "MYDP_Setting")
	int32 OriginSpawnerNumber = 0;			// 연결된 스포너 번호 디폴트 0 (1, 2, 3 ~)

protected:
	int32 ObjectId = -1;					// 오브젝트 ID
	
	/////////////////////////////////////////////////////////////////////
	// for Spline , Poligon , MakeRandLoc //
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> SplineComponent;		// 영역을 만들 스플라인 컴포넌트
	
	TArray<FVector> RectanglePoints;					// 스플라인으로 만들어진 직사각형의 꼭짓점을 담을 배열

	
public:	
	// Sets default values for this actor's properties
	APathRouter();
	
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

private:
	// 스플라인 포인트를 기반으로 직사각형의 점을 PolygonPoints에 담습니다.
	void MakeRectangleBySplinePoints();

public:
	TArray<FVector> GetRectanglePoints() { return RectanglePoints; }
};
