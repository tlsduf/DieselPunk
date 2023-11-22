// Fill out your copyright notice in the Description page of Project Settings.

#include "DpGameInstance.h"

#include <TimerManager.h>
#include <Modules/ModuleManager.h>
#include <PropertyEditorModule.h>

#include "../Manager/DatatableManager.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpGameInstance)


UDpGameInstance::UDpGameInstance()
{
    LoadSingletons();
}

UDpGameInstance::~UDpGameInstance()
{
    FNavigationManager::GetInstance()->DestroyInstance();
    FObjectManager::GetInstance()->DestroyInstance();
    FDataTableManager::GetInstance()->DestroyInstance();
}

void UDpGameInstance::LoadSingletons()
{
    FDataTableManager::GetInstance();
    FObjectManager::GetInstance();
    FNavigationManager::GetInstance();
}
