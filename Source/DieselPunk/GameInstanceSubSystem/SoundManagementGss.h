// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SoundManagementGss.generated.h"

class UInitialActiveSoundParams;
class USoundConcurrency;
class USoundWave;
class USoundAttenuation;
/**
 * 
 */
UCLASS()
class DIESELPUNK_API USoundManagementGss : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, USoundWave*> SoundDatas;
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
public:
	bool PlaySound2D(FString InAssetName, float InVolumeMultiplier = 1.f, float InPitchMultiplier = 1.f, float InStartTime = 0.f,
		USoundConcurrency* InConcurrencySettings = nullptr, const AActor* InOwningActor = nullptr, bool InbIsUISound = true);
	
	bool PlaySoundAtLocation(FString InAssetName, FVector InLocation, FRotator InRotation, float InVolumeMultiplier = 1.f, float InPitchMultiplier = 1.f,
		float InStartTime = 0.f, USoundAttenuation* InAttenuationSettings = nullptr, USoundConcurrency* InConcurrencySettings = nullptr,
		const AActor* InOwningActor = nullptr, const UInitialActiveSoundParams* InInitialParams = nullptr);
private:
	void FindUIDirectroy(FString InPath, TArray<FString>& OutData);
};
