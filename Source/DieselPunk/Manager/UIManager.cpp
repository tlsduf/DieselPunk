// Fill out your copyright notice in the Description page of Project Settings.

#include "UIManager.h"

#include "../UI/UserWidgetBase.h"

#include <Blueprint/UserWidget.h>

Singleton_Defintion(FUIManager)

int32 FUIManager::Key = 0;

FUIManager::FUIManager()
{
	
}

FUIManager::~FUIManager()
{
	
}

void FUIManager::Initialize()
{
}

void FUIManager::Release()
{
}

TWeakObjectPtr<UUserWidgetBase> FUIManager::GetWidgetBase(int32 InKey)
{
	TWeakObjectPtr<UUserWidgetBase>* find = CachedWidget.Find(InKey);
	if(find == nullptr)
		return nullptr;

	if(find->IsValid())
		return *find;

	return nullptr;
}

int32 FUIManager::CreateWidgetBase(FString InAdditionalFilePath, FString InFileName, FString InWidgetName, AActor* InOwner, UUserWidgetBase* InOwningObject)
{
	return CreateWidgetBase(LoadClass<UUserWidgetBase>(nullptr, *UtilPath::GetUIDetailPath(*InAdditionalFilePath, *InFileName)), InWidgetName, InOwner, InOwningObject);
}

int32 FUIManager::CreateWidgetBase(UClass* InClass, FString InWidgetName, AActor* InOwner, UUserWidgetBase* InOwningObject)
{
	UUserWidgetBase* widget = nullptr;
	
	if(InOwningObject == nullptr)
		widget = Cast<UUserWidgetBase>(CreateWidget(Controller, InClass,*InWidgetName));
	else
		widget = Cast<UUserWidgetBase>(CreateWidget(InOwningObject, InClass,*InWidgetName));

	if(widget == nullptr)
		return WIDGET_CREATE_FAILED;
	
	widget->SetOwner(InOwner);
	widget->OnCreated();

	int32 key = Key++;
	CachedWidget.Add(key, widget);

	return key;
}
