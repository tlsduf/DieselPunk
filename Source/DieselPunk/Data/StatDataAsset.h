// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StatDataTable.h"
#include "StatDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UStatDataAsset : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStatDataInfo> StatInfos;
};
