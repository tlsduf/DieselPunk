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

	FloorComponent->SetCollisionObjectType(ECC_WorldStatic);
}

// Called when the game starts or when spawned
void AFloorStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloorStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

