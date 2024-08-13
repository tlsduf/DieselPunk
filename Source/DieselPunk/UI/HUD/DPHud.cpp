// Fill out your copyright notice in the Description page of Project Settings.


#include "DPHud.h"

#include "HudFadeCanvas.h"
#include "InteractInstallation.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "DieselPunk/Actor/MonsterSpawner.h"
#include "DieselPunk/Character/CharacterNexus.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Core/DPLevelScriptActor.h"
#include "DieselPunk/Manager/ObjectManager.h"

void UDPHud::OnCreated()
{
	Super::OnCreated();
	InteractionUI->SetVisibility(ESlateVisibility::Hidden);
	HudFadeCanvas->InitUIVisibility(0);

	ULevel* level = GetWorld()->GetCurrentLevel();
	if(!level)
		return;
	
	if(ADPLevelScriptActor* dpLvScript = Cast<ADPLevelScriptActor>(level->GetLevelScriptActor()))
	{
		dpLvScript->GetDelegateStartWave().AddUObject(this, &UDPHud::OnWaveStarted);
		for(int32 id : dpLvScript->GetMonsterSpawnerIds())
		{
			if(AMonsterSpawner* spawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(id)))
			{
				spawner->GetDelegateDeadMonsterInSpawner().AddUObject(this, &UDPHud::OnMonsterInSpawnerDead);
			}
		}
	}

	ACharacterNexus* nexus = FObjectManager::GetInstance()->GetNexus();
	if(nexus)
	{
		nexus->GetStatControlComponent()->GetSetStatDelegate().AddUObject(this, &UDPHud::OnStatChanged);
		InitDieselCoreHpBar(nexus->GetStat(ECharacterStatType::Hp), nexus->GetStat(ECharacterStatType::MaxHp));
	}
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

void UDPHud::OnWaveStarted(int32 InCurrentWaveIndex, int32 InMaxWaveCount, int32 InMaxMonster)
{
	FText text = FText::FromString(FString::Printf(TEXT("%d"), InCurrentWaveIndex + 1));
	CurrentWaveText->SetText(text);

	text = FText::FromString(FString::Printf(TEXT("%d"), InMaxWaveCount));
	MaxWaveText->SetText(text);

	text = FText::FromString(FString::Printf(TEXT("%d"), InMaxMonster));
	MaxMonsterText->SetText(text);
	CurrentMonsterText->SetText(text);
}

void UDPHud::OnMonsterInSpawnerDead()
{
	FText text = CurrentMonsterText->GetText();
	int32 count = _wtoi(*text.ToString());
	--count;
	
	text = FText::FromString(FString::Printf(TEXT("%d"), count));
	CurrentMonsterText->SetText(text);
}

void UDPHud::InitDieselCoreHpBar(int32 InHp, int32 InMaxHp)
{
	DieselCoreHp = InHp;
	DieselCoreMaxHp = InMaxHp;

	double value = (double)DieselCoreHp / (double)DieselCoreMaxHp;

	DieselCoreHpBar->SetPercent(value);
}

void UDPHud::OnStatChanged(TWeakObjectPtr<AActor> InActor, ECharacterStatType InCharacterType, int32 InValue)
{
	if(InCharacterType == ECharacterStatType::Hp)
	{
		DieselCoreHp = InValue;
	}
	else if(InCharacterType == ECharacterStatType::MaxHp)
	{
		DieselCoreMaxHp = InValue;
	}

	double value = (double)DieselCoreHp / (double)DieselCoreMaxHp;

	DieselCoreHpBar->SetPercent(value);
}
