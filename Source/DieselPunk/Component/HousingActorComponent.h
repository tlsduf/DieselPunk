// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HousingActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UHousingActorComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	//피킹 사거리
	int32 Range;

	//네비게이션 인덱스
	TArray<TPair<int32, int32>> NavIndex;

	bool bMovementChangedFirst = true;

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
};
