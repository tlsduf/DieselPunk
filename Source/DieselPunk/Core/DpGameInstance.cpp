// Fill out your copyright notice in the Description page of Project Settings.

#include "DpGameInstance.h"

#include <TimerManager.h>

#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"
#include "../Manager/UIManager.h"
#include "DieselPunk/Data/LevelBgmDataTable.h"
#include "DieselPunk/GameInstanceSubSystem/SoundManagementGss.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpGameInstance)


UDpGameInstance::UDpGameInstance()
{
    LoadSingletons();
}

UDpGameInstance::~UDpGameInstance()
{
    FUIManager::GetInstance()->DestroyInstance();
    FNavigationManager::GetInstance()->DestroyInstance();
    FObjectManager::GetInstance()->DestroyInstance();
    FDataTableManager::GetInstance()->DestroyInstance();
}

void UDpGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
    Super::OnWorldChanged(OldWorld, NewWorld);

    if(!NewWorld)
        return;

    const FLevelBgmDataTable* table = FDataTableManager::GetInstance()->GetData<FLevelBgmDataTable>(EDataTableType::LevelBgm, NewWorld->GetName());
    if(table == nullptr)
        return;
    
    TWeakObjectPtr<UDpGameInstance> thisPtr = this;
    TWeakObjectPtr<UWorld> newWorldPtr = NewWorld;
    GetWorld()->GetTimerManager().SetTimerForNextTick([thisPtr, newWorldPtr, table]()
    {
        if(!thisPtr.IsValid())
            return;
        USoundManagementGss* gss = thisPtr->GetSubsystem<USoundManagementGss>();
        LOG_SCREEN(FColor::White, TEXT("%s"), *newWorldPtr->GetName())
        if(gss)
            gss->PlaySound2D(table->AssetName, table->VolumeMultiplier, table->PitchMultiplier);
    });
}

void UDpGameInstance::LoadSingletons()
{
    FDataTableManager::GetInstance();
    FObjectManager::GetInstance();
    FNavigationManager::GetInstance();
    FUIManager::GetInstance();
}
