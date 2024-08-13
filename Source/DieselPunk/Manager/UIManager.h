// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

class APlayerController;
class UUserWidgetBase;

class DIESELPUNK_API FUIManager
{
	Singleton_Declare(FUIManager)
private:
	TMap<int32, TWeakObjectPtr<UUserWidgetBase>> CachedWidget;
	APlayerController* Controller;

	static int32 Key;
	constexpr static int32 WIDGET_CREATE_FAILED = -9999;			//생성 시 UCLASS의 오류
private:
	void Initialize();
	void Release();
public:
	void SetController(APlayerController* InController){Controller = InController;}
	TWeakObjectPtr<UUserWidgetBase> GetWidgetBase(int32 InKey);
	int32 CreateWidgetBase(FString InAdditionalFilePath, FString InFileName, FString InWidgetName, AActor* InOwner, UUserWidgetBase* InOwningObject = nullptr);
	int32 CreateWidgetBase(UClass* InClass, FString InWidgetName, AActor* InOwner, UUserWidgetBase* InOwningObject = nullptr);
};

#define FindWidgetBase(InKey) FUIManager::GetInstance()->GetWidgetBase(InKey)