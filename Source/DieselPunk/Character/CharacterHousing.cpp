// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterHousing.h"
#include "CharacterTurret.h"

#include "../Component/HousingActorComponent.h"
#include "../Manager/NavigationManager.h"
#include "../Manager/UIManager.h"
#include "../UI/HUD/InteractInstallation.h"

#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/CapsuleComponent.h>
#include <Materials/MaterialInstanceDynamic.h>
#include <Components/BoxComponent.h>
#include <Components/WidgetComponent.h>


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

	InteractInstallationWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWidgetComponent"));
	if (InteractInstallationWidgetComponent)
	{
		InteractInstallationWidgetComponent->SetupAttachment(GetRootComponent());
		InteractInstallationWidgetComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
		InteractInstallationWidgetComponent->SetGenerateOverlapEvents(false);
		InteractInstallationWidgetComponent->SetSimulatePhysics(false);
		InteractInstallationWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	}
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

	int32 uiKey = FUIManager::GetInstance()->CreateWidgetBase(TEXT(""), TEXT("WBP_InteractInstallation"), TEXT("InteractInstallation"));
	InteractInstallationUI = Cast<UInteractInstallation>(FUIManager::GetInstance()->GetWidgetBase(uiKey));

	if(!InteractInstallationWidgetComponent || !InteractInstallationUI.IsValid())
		return;

	InteractInstallationWidgetComponent->SetWidget(InteractInstallationUI.Get());
	InteractInstallationWidgetComponent->SetDrawSize(FVector2d(200.f, 150.f));
	InteractInstallationWidgetComponent->SetHiddenInGame(true);
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
		RunAi();
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
			Box->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel5, ECollisionResponse::ECR_Block);
			Box->SetCanEverAffectNavigation(true);
			Box->SetBoxExtent(FVector(GetGridSizeVertical() * FNavigationManager::GridSize / 2, GetGridSizeHorizontal() * FNavigationManager::GridSize / 2,
				GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
		}

		// 포탑 생성완료시 사거리를 생성합니다.
		if(auto turret = Cast<ACharacterTurret>(this))
			if(turret->TurretSearchAreaType == ESearchAreaType::Rectangle)
				turret->MakeSearchArea();
		
		// 포탑 생성완료시 모든 적의 경로를 재탐색합니다.
		UpdateSplinePathAll();
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
void ACharacterHousing::UpgradeInstallation()
{
	LOG_SCREEN(FColor::Yellow, TEXT("Upgrade Complete!"))
}

void ACharacterHousing::ShowInteractInstallationUI(bool InShow, bool InSelected)
{
	InteractInstallationWidgetComponent->SetHiddenInGame(!InShow);
	if(InShow)
		InteractInstallationUI->Selected(InSelected);
	else
		InteractInstallationUI->Selected(false);
}
