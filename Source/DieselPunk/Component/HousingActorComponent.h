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
	int32 Range;
	int32 GridSize;

public:	
	// Sets default values for this component's properties
	UHousingActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool IsArrangeTurret();
	
public:
	void CompleteHousingTurret();
};
