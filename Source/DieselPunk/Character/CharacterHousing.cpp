// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterHousing.h"
#include "CharacterTurret.h"

#include "../Component/HousingActorComponent.h"
#include "../Manager/NavigationManager.h"
#include "../Manager/UIManager.h"
#include "../UI/HUD/InteractInstallation.h"
#include "../Component/StatControlComponent.h"
#include "../Data/StatDataTable.h"
#include "../Data/SearchAreaDataTable.h"
#include "../Manager/DatatableManager.h"

#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/CapsuleComponent.h>
#include <Materials/MaterialInstanceDynamic.h>
#include <Components/BoxComponent.h>
#include <Components/WidgetComponent.h>

#include "DieselPunk/Data/UpgradeDataTable.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/SkinnedAssetCommon.h"


struct FSearchAreaDataTable;
struct FStatDataTable;
// =============================================================
// 생성자
// =============================================================
ACharacterHousing::ACharacterHousing()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	HousingActorComponent = CreateDefaultSubobject<UHousingActorComponent>(TEXT("Housing Actor Component"));

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> material(TEXT("/Script/Engine.Material'/Game/DieselPunk/Material/M_Housing.M_Housing'"));
	if(material.Succeeded())
		HousingMaterial = material.Object;

	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	/*Box->bDynamicObstacle = true;
	FString inPath = FString::Printf(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/AI/BP_NavArea_High.BP_NavArea_High_C'"));
	UClass* NavArea = ConstructorHelpersInternal::FindOrLoadClass(inPath, UNavAreaBase::StaticClass() );
	Box->SetAreaClassOverride(NavArea);*/
	Box->SetupAttachment(GetCapsuleComponent());
	Box->bHiddenInGame = false;
}

void ACharacterHousing::UpdateBoxComponent()
{
	Box->SetBoxExtent(FVector(GetGridSizeVertical() * FNavigationManager::GridSize / 2, GetGridSizeHorizontal() * FNavigationManager::GridSize / 2,
				GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterHousing::BeginPlay()
{
	Super::BeginPlay();
	
	//Material Instance Dynamic 생성
	HousingDynamicMaterial = UMaterialInstanceDynamic::Create(HousingMaterial.Get(), this);

	//터렛이 가지고 있는 모든 메쉬 컴포넌트 추출
	TArray<USkeletalMeshComponent*> meshSkeltalComponents;
	GetComponents<USkeletalMeshComponent>(meshSkeltalComponents);

	//스켈레탈 메시, 스태틱 메시 추출
	for(UMeshComponent* meshComponent : meshSkeltalComponents)
	{
		if(meshComponent->GetName() == FString(TEXT("StaticMeshComponent_0")))
			continue;
		
		TArray<TWeakObjectPtr<UMaterialInterface>>& material = OriginalMaterials.FindOrAdd(meshComponent);
		for(int i = 0; i < meshComponent->GetNumMaterials(); ++i)
			material.Add(meshComponent->GetMaterial(i));
	}
	
	TArray<UStaticMeshComponent*> meshStaticComponents;
	GetComponents<UStaticMeshComponent>(meshStaticComponents);

	//스켈레탈 메시, 스태틱 메시 추출
	for(UMeshComponent* meshComponent : meshStaticComponents)
	{
		if(meshComponent->GetName() == FString(TEXT("StaticMeshComponent_0")))
			continue;
		
		TArray<TWeakObjectPtr<UMaterialInterface>>& material = OriginalMaterials.FindOrAdd(meshComponent);
		for(int i = 0; i < meshComponent->GetNumMaterials(); ++i)
			material.Add(meshComponent->GetMaterial(i));
	}

	//배치용 머터리얼로 변경
	ChangeMaterialByHousingEffect(true);
	

	//캡슐 콜리전 끄기
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	UActorComponent* actor = GetComponentByClass(UBoxComponent::StaticClass());
	if(actor != nullptr)
	{
		Box = Cast<UBoxComponent>(actor);
		if(Box != nullptr)
		{
			Box->SetGenerateOverlapEvents(false);
			Box->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
			Box->SetCanEverAffectNavigation(false);
			Box->SetBoxExtent(FVector(GetGridSizeVertical() * FNavigationManager::GridSize / 2, GetGridSizeHorizontal() * FNavigationManager::GridSize / 2,
				GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
		}
	}

	for(const FName& name : StatControlComponent->GetActorNames())
	{
		const FSearchAreaDataTable* searchAreaTable = FDataTableManager::GetInstance()->GetData<FSearchAreaDataTable>(EDataTableType::SearchArea, name);
		if(!searchAreaTable)
		{
			LOG_SCREEN(FColor::Red, TEXT("ActorNames의 이름: %s에 해당하는 데이터 테이블을 찾을 수 없습니다."), *name.ToString())
			continue;
		}
		FSearchAreaData searchAreaData;
		searchAreaData.SearchAreaType = searchAreaTable->SearchAreaType;
		searchAreaData.RectangleWidth = searchAreaTable->RectangleWidth;
		searchAreaData.ArcAngle = searchAreaTable->ArcAngle;
		searchAreaData.CircleHeight = searchAreaTable->CircleHeight;
		searchAreaData.AtkMaxRange = searchAreaTable->AtkMaxRange;
		searchAreaData.AtkMaxRangeForFly = searchAreaTable->AtkMaxRangeForFly;
		searchAreaData.AtkMinRange = searchAreaTable->AtkMinRange;

		SearchAreaDatasForUpgrade.Add(searchAreaData);

		const FUpgradeDataTable* upgradeTable = FDataTableManager::GetInstance()->GetData<FUpgradeDataTable>(EDataTableType::Upgrade, name);
		if(!upgradeTable)
		{
			LOG_SCREEN(FColor::Red, TEXT("ActorNames의 이름: %s에 해당하는 데이터 테이블을 찾을 수 없습니다."), *name.ToString())
			continue;
		}
		FUpgradeData upgradeData;
		upgradeData.UpgradeMesh = upgradeTable->UpgradeMesh;
		upgradeData.UpgradeSkillNames = upgradeTable->UpgradeSkillNames;

		UpgradeDatas.Add(upgradeData);
	}

	DelegateUpgrade.AddUObject(this, &ACharacterHousing::OnHousingUpgraded);
}

// =============================================================
// 소멸자
// =============================================================
void ACharacterHousing::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// Tick
// =============================================================
void ACharacterHousing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// =============================================================
// 터렛 생성
// =============================================================
bool ACharacterHousing::CompleteHousingTurret() 
{
	if(HousingActorComponent->CompleteHousingTurret())
	{
		float spawnTime = PlaySpawnAnim();
		if(spawnTime > 0)
		{
			// 스폰 애니메이션이 완료되었을 때의 처리
			TWeakObjectPtr<ACharacterHousing> thisPtr = this;
			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, [thisPtr](){
					if(thisPtr.IsValid())
					{
						if(thisPtr.IsValid())
						{
							thisPtr->GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
							thisPtr->RunAi();
						}
					}
				},spawnTime, false);
		}
		else
		{
			RunAi();
		}
		//RunAi();
		ChangeMaterialByHousingEffect(false);

		GetCapsuleComponent()->SetGenerateOverlapEvents(true);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECollisionResponse::ECR_Block);

		if(Box != nullptr)
		{
			Box->SetGenerateOverlapEvents(true);
			Box->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel6, ECollisionResponse::ECR_Block);
			Box->SetCanEverAffectNavigation(true);
			Box->SetBoxExtent(FVector(GetGridSizeVertical() * FNavigationManager::GridSize / 2, GetGridSizeHorizontal() * FNavigationManager::GridSize / 2,
				GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
		}

		// 포탑 생성완료시 사거리를 생성합니다.
		if(auto turret = Cast<ACharacterTurret>(this))
		{
			turret->InitializeForwardVector();
			turret->MakeSearchArea();
		}
		
		// 포탑 생성완료시 모든 적의 경로를 재탐색합니다.
		FObjectManager::GetInstance()->UpdateSplinePathAllEnemy();
		return true;
	}
	return false;
}

void ACharacterHousing::RunAi()
{
	SetActorTickEnabled(true);
}

// =============================================================
// 
// =============================================================
void ACharacterHousing::ChangeMaterialByHousingEffect(bool InRenderHousingEffect)
{
	
	if(InRenderHousingEffect)
	{
		for(TPair<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> pair : OriginalMaterials)
			for(int i = 0; i < pair.Value.Num(); ++i)
				pair.Key->SetMaterial(i, HousingDynamicMaterial.Get());
	}
	else
	{
		for(TPair<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> pair : OriginalMaterials)
		{
			for(int i = 0; i < pair.Value.Num(); ++i)
				pair.Key->SetMaterial(i, pair.Value[i].Get());
		}
	}
	
}

// =============================================================
// 
// =============================================================
void ACharacterHousing::ChangeHousingMaterialParameterChange(bool InHousing)
{
	
	if(InHousing)
		HousingDynamicMaterial->SetScalarParameterValue(FName(TEXT("IsHousing")), 1);
	else
		HousingDynamicMaterial->SetScalarParameterValue(FName(TEXT("IsHousing")), 0);
	
}

// 터렛 업그레이드시 처리
bool ACharacterHousing::UpgradeInstallation()
{
	int32 lv = GetStat(ECharacterStatType::Level);
	lv++;

	if(lv > TURRET_MAX_LV)
	{
		LOG_SCREEN(FColor::Yellow, TEXT("Upgrade Failed! Turret is Already Max Level"));
		return false;
	}
	int32 upgradeIdx = lv;
	if(lv == TURRET_MAX_LV)
	{
		int32 randAce = FMath::RandRange(0,StatControlComponent->GetStatInfos().Num() - TURRET_MAX_LV);
		upgradeIdx += randAce;
	}

	StatControlComponent->SetStat(ECharacterStatType::Level, upgradeIdx);
	
	if(DelegateUpgrade.IsBound())
		DelegateUpgrade.Broadcast(this, upgradeIdx);
	
	LOG_SCREEN(FColor::Yellow, TEXT("Upgrade Complete!"))
	return true;
}

void ACharacterHousing::OnHousingUpgraded(ACharacterNPC* InCharacter, int32 InIndex)
{
	if(SearchAreaDatasForUpgrade.IsValidIndex(InIndex - 1))
	{
		//탐색 범위 적용
		SearchAreaData.SearchAreaType = SearchAreaDatasForUpgrade[InIndex - 1].SearchAreaType;
		SearchAreaData.RectangleWidth = SearchAreaDatasForUpgrade[InIndex - 1].RectangleWidth;
		SearchAreaData.ArcAngle = SearchAreaDatasForUpgrade[InIndex - 1].ArcAngle;
		SearchAreaData.CircleHeight = SearchAreaDatasForUpgrade[InIndex - 1].CircleHeight;
		SearchAreaData.AtkMaxRange = SearchAreaDatasForUpgrade[InIndex - 1].AtkMaxRange;
		SearchAreaData.AtkMaxRangeForFly = SearchAreaDatasForUpgrade[InIndex - 1].AtkMaxRangeForFly;
		SearchAreaData.AtkMinRange = SearchAreaDatasForUpgrade[InIndex - 1].AtkMinRange;
	}

	if(UpgradeDatas.IsValidIndex(InIndex - 1))
	{
		//메시 적용
		if(UpgradeDatas[InIndex - 1].UpgradeMesh != nullptr)
		{
			GetMesh()->SetSkeletalMeshAsset(UpgradeDatas[InIndex - 1].UpgradeMesh);
			TArray<FSkeletalMaterial> materials = UpgradeDatas[InIndex - 1].UpgradeMesh->GetMaterials();
			for(int i = 0; i < GetMesh()->GetMaterials().Num(); ++i)
			{
				if(i < materials.Num())
					GetMesh()->SetMaterial(i, materials[i].MaterialInterface);
				else
					GetMesh()->SetMaterial(i, nullptr);
			}
		}

		//스킬 적용
		UpgradeSkill(UpgradeDatas[InIndex - 1].UpgradeSkillNames);
	}
}

void ACharacterHousing::ChangeGridSizeVerticalHorizontal()
{
	int32 temp = GridSizeHorizontal;
	GridSizeHorizontal = GridSizeVertical;
	GridSizeVertical = temp;
}