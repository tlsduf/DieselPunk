// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectileBase.h"
#include "ProjectileGranades.generated.h"

/**
 *
 */
UCLASS()
class DIESELPUNK_API AProjectileGranade : public AProjectileBase
{
	GENERATED_BODY()

public:
	AProjectileGranade();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

};
