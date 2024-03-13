// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshActorForProto.h"

#include <Components/StaticMeshComponent.h>

// Sets default values
AStaticMeshActorForProto::AStaticMeshActorForProto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMeshComponent);

	StaticMeshComponent->SetCollisionObjectType(ECC_WorldStatic);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AStaticMeshActorForProto::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AStaticMeshActorForProto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

