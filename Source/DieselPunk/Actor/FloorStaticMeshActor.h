// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorStaticMeshActor.generated.h"

class UBoxComponent;

UCLASS()
class DIESELPUNK_API AFloorStaticMeshActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> FloorComponent;
	
public:	
	// Sets default values for this actor's properties
	AFloorStaticMeshActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
