// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HousingActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UHousingActorComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	//피킹 사거리
	int32 Range;

	//네비게이션 인덱스
	TArray<TPair<int32, int32>> NavIndex;

	bool bMovementChangedFirst = true;

	//아래로 라인트레이싱 하기 위한 본 이름들을 설정합니다. 발쪽 Bone을 다리 갯수만큼 넣어주면 됩니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Installation")
	TArray<FName> BoneNamesForLineTracing;

	//설치 가능한 최대 기울기(이 이상의 기울기를 넘어갈 경우 설치가 불가능해집니다.)
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Installation")
	float MaxInstallableSlope = 23.f;

	bool IsHouseable = false;
	
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Housing")
	TArray<EFloorType> InstallableTypes;

public:	
	// Sets default values for this component's properties
	UHousingActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION()
	void EventMovementChanged(ACharacter* InCharacter, EMovementMode InPrevMovementMode, uint8 InPreviousCustomMode);

private:
	bool IsArrangeTurret();
	
public:
	bool CompleteHousingTurret();

public:
	bool CheckHouseable();
	
	const TArray<EFloorType>& GetInstallableTypes(){return InstallableTypes;}
};
