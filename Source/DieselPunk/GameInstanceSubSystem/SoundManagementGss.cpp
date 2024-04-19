// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundManagementGss.h"

#include "AssetRegistry/AssetData.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "HAL/FileManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundWave.h"

void USoundManagementGss::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TArray<FString> outData;
	FindUIDirectroy(TEXT("DieselPunk/Sound"), outData);

	for(int32 i = 0; i < outData.Num(); i += 2)
	{
		USoundWave* sound = LoadObject<USoundWave>(nullptr, *outData[i + 1]);
		if(sound)
			SoundDatas.Add(outData[i], sound);
	}
}

void USoundManagementGss::Deinitialize()
{
	Super::Deinitialize();
}

bool USoundManagementGss::PlaySound2D(FString InAssetName, float InVolumeMultiplier, float InPitchMultiplier, float InStartTime,
		USoundConcurrency* InConcurrencySettings, const AActor* InOwningActor, bool InbIsUISound)
{
	USoundWave** sound = SoundDatas.Find(InAssetName);
	if(sound == nullptr)
		return false;
	
	UGameplayStatics::PlaySound2D(GetWorld(), *sound, InVolumeMultiplier, InPitchMultiplier, InStartTime, InConcurrencySettings, InOwningActor, InbIsUISound);

	return true;
}

bool USoundManagementGss::PlaySoundAtLocation(FString InAssetName, FVector InLocation, FRotator InRotation,
	float InVolumeMultiplier, float InPitchMultiplier, float InStartTime, USoundAttenuation* InAttenuationSettings,
	USoundConcurrency* InConcurrencySettings, const AActor* InOwningActor,
	const UInitialActiveSoundParams* InInitialParams)
{
	USoundWave** sound = SoundDatas.Find(InAssetName);
	if(sound == nullptr)
		return false;

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), *sound, InLocation, InRotation, InVolumeMultiplier, InPitchMultiplier, InStartTime, InAttenuationSettings, InConcurrencySettings, InOwningActor, InInitialParams);

	return true;
}


void USoundManagementGss::FindUIDirectroy(FString InPath, TArray<FString>& OutData)
{
	//폴더 내 모든 에셋 탐색
	FAssetRegistryModule& assetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));

	TArray<FAssetData> assetList;
	FARFilter Filter;
	FString assetPath = TEXT("/Game/") + InPath;
	Filter.PackagePaths.Add(*assetPath);

	assetRegistryModule.Get().GetAssets(Filter, assetList);

	for(const FAssetData& data : assetList)
	{
		FString assetName = data.AssetName.ToString();
		OutData.Add(assetName);
		
		FString classPath = data.GetObjectPathString();
		classPath = TEXT("/Script/Engine.SoundWave'") + classPath + TEXT("'");
		OutData.Add(classPath);
	}

	//폴더 내 다른 폴더 탐색
	FString folderPath = FPaths::ProjectContentDir() + InPath + TEXT("/*");
	TArray<FString> files;
	IFileManager::Get().FindFiles(files, *folderPath, true, true);
	for(FString& file : files)
	{
		if(!file.Contains(TEXT(".")))
			FindUIDirectroy(InPath + TEXT("/") + file, OutData);
	}
}
