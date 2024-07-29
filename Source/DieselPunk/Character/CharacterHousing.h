// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterNPC.h"
#include "CharacterHousing.generated.h"

class UInteractInstallation;
class UHousingActorComponent;
class UMeshComponent;
class UMaterialInterface;
class UBoxComponent;

struct FUpgradeData
{
	//업그레이드할 메시입니다.
	USkeletalMesh* UpgradeMesh = nullptr;

	//업그레이드 스킬 이름입니다.
	TMap<EAbilityType, FName> UpgradeSkillNames;
};

UCLASS()
class DIESELPUNK_API ACharacterHousing : public ACharacterNPC
{
	GENERATED_BODY()
	
	DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateUpgrade, ACharacterNPC*, int32)
protected:
	
	
	/////////////////////////////////////////////////////////////////////
	// for Upgrade //
	TArray<FSearchAreaData> SearchAreaDatasForUpgrade;

	TArray<FUpgradeData> UpgradeDatas;
	
	FDelegateUpgrade DelegateUpgrade;
	
	/////////////////////////////////////////////////////////////////////
	// for Housing //
	//포탑의 세로 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHousingActorComponent* HousingActorComponent = nullptr;
	
	//강조용 머터리얼
	TWeakObjectPtr<UMaterialInterface> HousingMaterial = nullptr;
	
	//강조용 머터리얼 인스턴스 다이나믹
	TWeakObjectPtr<UMaterialInstanceDynamic> HousingDynamicMaterial = nullptr;

	//기존 머터리얼
	TMap<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> OriginalMaterials;

	UPROPERTY(EditAnywhere)
	UBoxComponent* Box = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSizeVertical = 1;

	//포탑의 가로 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSizeHorizontal = 1;
	
	
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
	virtual bool UpgradeInstallation();

	void OnHousingUpgraded(ACharacterNPC* InCharacter, int32 InIndex);

	virtual void UpgradeSkill(const TMap<EAbilityType, FName>& InUpgradeSkillNames) {}

	void UpdateBoxComponent();
	
	FDelegateUpgrade& GetDelegateUpgrade(){return DelegateUpgrade;}

	
	int32 GetGridSizeVertical() const { return GridSizeVertical; }
	
	int32 GetGridSizeHorizontal() const { return GridSizeHorizontal; }
	
	
protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
public:
	void ChangeGridSizeVerticalHorizontal();
};
