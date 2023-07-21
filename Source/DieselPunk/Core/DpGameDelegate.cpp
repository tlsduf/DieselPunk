// Fill out your copyright notice in the Description page of Project Settings.


#include "DpGameDelegate.h"


FDpGameDelegate& FDpGameDelegate::Get()
{
	static FDpGameDelegate Singleton;
	return Singleton;
}

void FDpGameDelegate::Clear()
{
	FDpGameDelegate::Get().DelegateActorSpawned.Clear();
	FDpGameDelegate::Get().DelegateActorDespawned.Clear();
	FDpGameDelegate::Get().DelegateUserWidgetCreated.Clear();
	FDpGameDelegate::Get().DelegateUserWidgetShowed.Clear();
	FDpGameDelegate::Get().DelegateUserWidgetRemoved.Clear();
	FDpGameDelegate::Get().DelegateWorldMoveFinished.Clear();
}