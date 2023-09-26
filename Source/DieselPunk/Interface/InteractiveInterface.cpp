// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveInterface.h"

///InteractiveTriggerVolume과 겹칠 시 호출합니다.
void IInteractiveInterface::OnBeginOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor)
{
	_OnBeginOverlapTriggerVolume(InOverlapActor, InOtherActor);
}

///InteractiveTriggerVolume과 겹치지 않을 시 호출합니다.
void IInteractiveInterface::OnEndOverlapTriggerVolume(AActor* InOverlapActor, AActor* InOtherActor)
{
	_OnEndOverlapTriggerVolume(InOverlapActor, InOtherActor);
}
