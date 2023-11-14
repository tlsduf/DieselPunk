// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorStaticMeshActor.h"
#include "../Manager/NavigationManager.h"

#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

// Sets default values
AFloorStaticMeshActor::AFloorStaticMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	FloorComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	SetRootComponent(FloorComponent);
}

// Called when the game starts or when spawned
void AFloorStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	//액터 안에있는 박스 컴포넌트를 모두 획득
	TArray<UBoxComponent*> boxComponents;
	GetComponents<UBoxComponent>(boxComponents);

	//박스 구조체 생성
	TArray<FDpBox> boxes;
	boxes.Reserve(boxComponents.Num());
	for(UBoxComponent* boxComp : boxComponents)
	{
		FDpBox box;
		box.Location = boxComp->GetComponentLocation();
		box.Extend = boxComp->GetScaledBoxExtent();
		box.BoxComp = boxComp;
		boxes.Add(box);
	}

	FNavigationManager::GetInstance()->BuildNavNode(this, boxes);
}

// Called every frame
void AFloorStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

