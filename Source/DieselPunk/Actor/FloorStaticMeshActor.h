// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorStaticMeshActor.generated.h"

class UBoxComponent;

UCLASS()
class DIESELPUNK_API AFloorStaticMeshActor : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category="MYDP_Setting")
	TObjectPtr<UStaticMeshComponent> FloorComponent = nullptr;

	UPROPERTY(EditAnywhere, Category="MYDP_Setting")
	TObjectPtr<UDecalComponent> DecalComponent = nullptr;
	
	//강조용 머터리얼
	TWeakObjectPtr<UMaterialInterface> DecalMaterial = nullptr;
	
	//강조용 머터리얼 인스턴스 다이나믹
	TWeakObjectPtr<UMaterialInstanceDynamic> DecalDynamicMaterial = nullptr;

	bool HousingMode = false;

	bool ProgressAlpha = false;
	
	double DecalAlpha = 0.f;

	UPROPERTY(EditAnywhere, Category="MYDP_Setting")
	double DecalAlphaAnimTime = 0.2;

	double AlphaMultiplyValue = 5.0;

	UPROPERTY(EditAnywhere, Category="MYDP_Setting")
	EFloorType FloorType = EFloorType::Plane;
	
public:	
	// Sets default values for this actor's properties
	AFloorStaticMeshActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnOffDecalMaterial(bool InHousingMode, const TArray<EFloorType>& InInstallableFloorTypes);

	FORCEINLINE const EFloorType& GetFloorType(){return FloorType;}

};
