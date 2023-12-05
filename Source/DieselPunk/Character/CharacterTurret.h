// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterNPC.h"
#include "CharacterTurret.generated.h"

class UHousingActorComponent;
class UMeshComponent;
class UMaterialInterface;
class UBoxComponent;

UCLASS()
class DIESELPUNK_API ACharacterTurret : public ACharacterNPC
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHousingActorComponent* HousingActorComponent;
	
	//강조용 머터리얼
	TWeakObjectPtr<UMaterialInterface> HousingMaterial;
	
	//강조용 머터리얼 인스턴스 다이나믹
	TWeakObjectPtr<UMaterialInstanceDynamic> HousingDynamicMaterial;

	//기존 머터리얼
	TMap<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> OriginalMaterials;

	TWeakObjectPtr<UBoxComponent> Box;
	
public:
	ACharacterTurret();

	virtual void Tick(float DeltaTime) override;

	bool CompleteHousingTurret();

	void RunAi();

	void ChangeMaterialByHousingEffect(bool InRenderHousingEffect);

	void ChangeHousingMaterialParameterChange(bool InHousing);

protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
};
