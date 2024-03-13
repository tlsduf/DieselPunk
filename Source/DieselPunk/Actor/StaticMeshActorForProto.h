// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticMeshActorForProto.generated.h"

class UBoxComponent;

UCLASS()
class DIESELPUNK_API AStaticMeshActorForProto : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
public:	
	// Sets default values for this actor's properties
	AStaticMeshActorForProto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
