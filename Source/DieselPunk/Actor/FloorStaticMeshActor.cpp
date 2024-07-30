// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorStaticMeshActor.h"
#include "../Manager/NavigationManager.h"

#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

#include "Components/DecalComponent.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AFloorStaticMeshActor::AFloorStaticMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	SetRootComponent(FloorComponent);

	FloorComponent->SetCollisionObjectType(ECC_WorldStatic);

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	DecalComponent->SetupAttachment(FloorComponent);
	DecalComponent->SetVisibility(false);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> decalMaterial(TEXT("/Script/Engine.Material'/Game/DieselPunk/Material/M_FloorDecal.M_FloorDecal'"));
	if(decalMaterial.Succeeded())
		DecalMaterial = decalMaterial.Object;
}

// Called when the game starts or when spawned
void AFloorStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	DecalDynamicMaterial = UMaterialInstanceDynamic::Create(DecalMaterial.Get(), this);
	if(DecalDynamicMaterial.IsValid())
	{
		DecalComponent->SetDecalMaterial(DecalDynamicMaterial.Get());
	}

	AlphaMultiplyValue = 1.0 / DecalAlphaAnimTime;

	FObjectManager::GetInstance()->AddFloor(this);
}

// Called every frame
void AFloorStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(ProgressAlpha)
	{
		if(HousingMode)
		{
			DecalAlpha += DeltaTime;
			if(DecalAlpha >= DecalAlphaAnimTime)
			{
				DecalAlpha = DecalAlphaAnimTime;
				ProgressAlpha = false;
			}
		}
		else
		{
			DecalAlpha -= DeltaTime;
			if(DecalAlpha <= 0.f)
			{
				DecalAlpha = 0.f;
				ProgressAlpha = false;
				DecalComponent->SetVisibility(false);
			}
		}
		DecalDynamicMaterial->SetScalarParameterValue(FName(TEXT("Alpha")), DecalAlpha * AlphaMultiplyValue);
	}
}

void AFloorStaticMeshActor::OnOffDecalMaterial(bool InHousingMode, const TArray<EFloorType>& InInstallableFloorTypes)
{
	if(HousingMode == InHousingMode)
		return;

	HousingMode = InHousingMode;
	
	if(HousingMode)
	{
		DecalComponent->SetVisibility(true);
		if(InInstallableFloorTypes.Contains(FloorType))
			DecalDynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), FVector(0.f, 1.f, 1.f));
		else
			DecalDynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), FVector(1.f, 0.f, 0.f));
		
		ProgressAlpha = true;
		DecalAlpha = 0.f;
	}
	else
	{
		ProgressAlpha = true;
		DecalAlpha = DecalAlphaAnimTime;
	}
}

