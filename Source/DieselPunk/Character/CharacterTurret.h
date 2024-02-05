// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterHousing.h"
#include "CharacterTurret.generated.h"

class UHousingActorComponent;
class UMeshComponent;
class UMaterialInterface;
class UBoxComponent;

UCLASS()
class DIESELPUNK_API ACharacterTurret : public ACharacterHousing
{
	GENERATED_BODY()

public:
	// DamageImmunity 가 True 면 데미지를 안 입게 했습니다. TakeDamage 함수에서 활용합니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	ESearchAreaType TurretSearchAreaType = ESearchAreaType::Circle;

	TArray<FVector> RectanglePoints;			// 사각형 공격탐지범위 (현재는 포탑사거리 x 포탑그리드 크기)

	// bPiercing 가 ture면 지형을 무시하고 공격합니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bPierceWall = true;
	
public:
	ACharacterTurret();

	virtual void Tick(float DeltaTime) override;

	virtual void RunAi() override;

	// 터렛의 조건에 따라 타겟을 결정합니다.
	void SetTurretTarget();

	// 포탑의 사각형 탐색범위를 생성합니다. 
	void MakeSearchArea();
	
	// inLocation이 유효 범위 안에 있으면 True 반환
	bool InValidSearchArea(FVector inLocation);

	// inLocation까지 트레이스를 하여 맵 구성요소(ex 벽)이 있는지 탐색하고, 없으면 true 반환
	bool InValidOverWall(FVector inLocation);

	// 다각형 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
	bool IsInPolygon(double InX, double InY);

	// 사정거리 DrawDebug
	void DrawDebugSearchArea();
protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
};
