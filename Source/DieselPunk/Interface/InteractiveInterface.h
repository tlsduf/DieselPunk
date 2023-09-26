// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 상호작용을 하기 위한 인터페이스 입니다.
 * InteractiveTriggerVolume과 함께 동작합니다.
 */
class DIESELPUNK_API IInteractiveInterface
{
	GENERATED_BODY()
protected:
	///자식 클래스에서 기능을 구현하기 위해 오버라이드 해야할 함수입니다.
	///InteractiveTriggerVolume과 겹칠 시 호출합니다.
	virtual void _OnBeginOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor) {}
	
	///자식 클래스에서 기능을 구현하기 위해 오버라이드 해야할 함수입니다.
	///InteractiveTriggerVolume과 겹치지 않을 시 호출합니다.
	virtual void _OnEndOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor) {}
public:
	///InteractiveTriggerVolume에 AddDynamic될 함수입니다. 오버라이드하면 안됩니다.
	///InteractiveTriggerVolume과 겹칠 시 호출합니다.
	UFUNCTION()
	virtual void OnBeginOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor);
	
	///InteractiveTriggerVolume에 AddDynamic될 함수입니다. 오버라이드하면 안됩니다.
	///InteractiveTriggerVolume과 겹치지 않을 시 호출합니다.
	UFUNCTION()
	virtual void OnEndOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor);
};
