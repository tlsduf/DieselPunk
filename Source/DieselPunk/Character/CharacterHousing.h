// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterNPC.h"
#include "CharacterHousing.generated.h"

class UInteractInstallation;
class UHousingActorComponent;
class UMeshComponent;
class UMaterialInterface;
class UBoxComponent;

USTRUCT()
struct FUpgardeInfo
{
	GENERATED_BODY()

	//업그레이드할 스탯 정보를 불러오기 위한 ID값
	UPROPERTY(EditDefaultsOnly)
	int32 UpgradeID;

	//업그레이드할 스탯 정보를 불러오기 위한 이름
	UPROPERTY(EditDefaultsOnly)
	FString UpgradeName;
	
	//업그레이드할 메시
	UPROPERTY(EditDefaultsOnly)
	USkeletalMesh* UpgradeMesh;
};

UCLASS()
class DIESELPUNK_API ACharacterHousing : public ACharacterNPC
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

	UPROPERTY(EditAnywhere)
	UBoxComponent* Box;

	TWeakObjectPtr<UInteractInstallation> InteractInstallationUI;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UWidgetComponent> InteractInstallationWidgetComponent;

	static constexpr int32 MaxLv = 3;
	
public:
	ACharacterHousing();

	virtual void Tick(float DeltaTime) override;

	//터렛 생성
	bool CompleteHousingTurret();

	// AI 시작
	virtual void RunAi();

	void ChangeMaterialByHousingEffect(bool InRenderHousingEffect);

	void ChangeHousingMaterialParameterChange(bool InHousing);

	// 업그레이드시 처리
	virtual bool UpgradeInstallation(int32 InAceChance);

	void ShowInteractInstallationUI(bool InShow, bool InSelected);
protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
};
