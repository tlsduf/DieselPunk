// Fill out your copyright notice in the Description page of Project Settings.


#include "DPHud.h"

#include "InteractInstallation.h"

void UDPHud::OnCreated()
{
	Super::OnCreated();
	InteractionUI->SetVisibility(ESlateVisibility::Hidden);
}

void UDPHud::SetViewInteractionUI(bool InView)
{
	if(!InteractionUI)
		return;
	
	if(InView)
		InteractionUI->SetVisibility(ESlateVisibility::Visible);
	else
		InteractionUI->SetVisibility(ESlateVisibility::Hidden);
}

void UDPHud::SelectedInteractionUI(bool InSelected)
{
	if(!InteractionUI)
		return;

	InteractionUI->Selected(InSelected);
}
