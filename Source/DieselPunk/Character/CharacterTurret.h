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

	// bPiercing 가 ture면 지형을 무시하고 공격합니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bPierceWall = true;
	
public:
	ACharacterTurret();

	virtual void Tick(float DeltaTime) override;

	virtual void RunAi() override;

	virtual void SetTarget() override;

	// 포탑의 초기 바라보는 방향을 설정합니다.
	void InitializeForwardVector();

	// inLocation까지 트레이스를 하여 맵 구성요소(ex 벽)이 있는지 탐색하고, 있으면 true 반환
	bool IsOverWall(FVector inLocation);
	
	//업그레이드 시 스킬이 변경될 경우 이 함수를 호출합니다.
	virtual void UpgradeSkill(const TMap<EAbilityType, FName>& InUpgradeSkillNames) override;
protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
};
