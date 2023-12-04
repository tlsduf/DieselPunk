// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include <GameFramework/Actor.h>
#include "ObjectCreater.generated.h"


UCLASS()
class DIESELPUNK_API AObjectCreater : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	USkeletalMeshComponent* PreviewMesh;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	FString CharacterName;
	
public:	
	// Sets default values for this actor's properties
	AObjectCreater();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;

	// 캐릭터를 스폰합니다.
	void Spawn();
};
