// Fill out your copyright notice in the Description page of Project Settings.


#include "DpStartMenu.h"

#include "Components/Button.h"
#include "DieselPunk/Logic/PlayerControllerBase.h"
#include "Kismet/KismetSystemLibrary.h"

void UDpStartMenu::OnCreated()
{
	Super::OnCreated();

	if(StartButton)
		StartButton->OnClicked.AddDynamic(this, &UDpStartMenu::ClickedButtonStart);
	if(EndButton)
		EndButton->OnClicked.AddDynamic(this, &UDpStartMenu::ClickedButtonEnd);
	if(SettingButton)
		StartButton->OnClicked.AddDynamic(this, &UDpStartMenu::ClickedButtonSetting);
}

void UDpStartMenu::ClickedButtonStart()
{
	PlayerControllerBase->SetUIControlOff();
	PlayerControllerBase->SetVisibilityHud(ESlateVisibility::Visible);
	SetVisibility(ESlateVisibility::Collapsed);
}

void UDpStartMenu::ClickedButtonEnd()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), PlayerControllerBase.Get(), EQuitPreference::Quit, false);
}

void UDpStartMenu::ClickedButtonSetting()
{
}

void UDpStartMenu::SetPlayerControllerBase(APlayerControllerBase* InPlayerControllerBase)
{
	PlayerControllerBase = InPlayerControllerBase;
}

