// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/PathRouter.h"
#include "../Manager/ObjectManager.h"

#include <Components/SplineComponent.h>
#include <DrawDebugHelpers.h>


// =============================================================
// 생성자
// =============================================================
APathRouter::APathRouter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(SplineComponent);
	SplineComponent->SetClosedLoop(true);
	SplineComponent->PrimaryComponentTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void APathRouter::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);
	
	// 스플라인 디버그라인
	if(bDrawDebug)
	{

	}
}

// =============================================================
// Called change info in editor
// =============================================================
void APathRouter::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);

	// Set All Spline Point Type "Linear"
	for(int i = 0; i < SplineComponent->GetNumberOfSplinePoints(); ++i)
		SplineComponent->SetSplinePointType(i, ESplinePointType::Linear, true);
}

// =============================================================
// Called every frame
// =============================================================
void APathRouter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
