// Fill out your copyright notice in the Description page of Project Settings.

#include "DpGameInstance.h"

#include <TimerManager.h>

#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"
#include "../Manager/UIManager.h"

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

void UDpGameInstance::LoadSingletons()
{
    FDataTableManager::GetInstance();
    FObjectManager::GetInstance();
    FNavigationManager::GetInstance();
    FUIManager::GetInstance();
}
