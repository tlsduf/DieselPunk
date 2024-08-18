// Fill out your copyright notice in the Description page of Project Settings.


#include "DPHud.h"

#include "Hand.h"
#include "HudFadeCanvas.h"
#include "InteractInstallation.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "DieselPunk/Actor/MonsterSpawner.h"
#include "DieselPunk/Character/CharacterNexus.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Core/DPLevelScriptActor.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "Engine/Level.h"

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
		dpLvScript->GetDelegateClearWave().AddUObject(this, &UDPHud::OnWaveCleared);
		dpLvScript->GetDelegateCountDefcon().AddUObject(this, &UDPHud::CountDefconTime);
		for(int32 id : dpLvScript->GetMonsterSpawnerIds())
		{
			if(AMonsterSpawner* spawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(id)))
			{
				spawner->GetDelegateDeadMonsterInSpawner().AddUObject(this, &UDPHud::OnMonsterInSpawnerDead);
			}
		}
	}

	ACharacterPC* player = FObjectManager::GetInstance()->GetPlayer();
	if(player)
	{
		player->GetStatControlComponent()->GetSetStatDelegate().AddUObject(this, &UDPHud::OnStatChanged);
		// 플레이어의 InitStat 보다 먼저 호출되기 때문에 -9999값이 반환됨 // CharacterPC의 CheckViewMiddleForInteractInstallationUI() 에서 호출
		//InitPlayerHpBar(player->GetStat(ECharacterStatType::Hp), player->GetStat(ECharacterStatType::MaxHp));
	}
	
	ACharacterNexus* nexus = FObjectManager::GetInstance()->GetNexus();
	if(nexus)
	{
		nexus->GetStatControlComponent()->GetSetStatDelegate().AddUObject(this, &UDPHud::OnStatChanged);
		// 넥서스가 맵에 선 배치되어있기 때문에 GetStat이 가능
		InitDieselCoreHpBar(nexus->GetStat(ECharacterStatType::Hp), nexus->GetStat(ECharacterStatType::MaxHp));
	}
	OnOffViewCard();
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

	HudFadeCanvas->OnWaveStarted();
}

void UDPHud::OnWaveCleared()
{
	HudFadeCanvas->OnWaveCleared();
}

void UDPHud::CountDefconTime(int32 InDefconTime)
{
	HudFadeCanvas->CountDefconTime(InDefconTime);
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

void UDPHud::InitPlayerHpBar(int32 InHp, int32 InMaxHp)
{
	PlayerHp = InHp;
	PlayerMaxHp = InMaxHp;

	double value = (double)PlayerHp / (double)PlayerMaxHp;

	PlayerHpBar->SetPercent(value);
}

void UDPHud::OnStatChanged(TWeakObjectPtr<AActor> InActor, ECharacterStatType InCharacterType, int32 InValue)
{
	ACharacterBase* charBase = Cast<ACharacterBase>(InActor);

	if(charBase->GetCharacterType() == ECharacterType::Player)
	{
		// Player 체력 UI
		if(InCharacterType == ECharacterStatType::Hp)
		{
			PlayerHp = InValue;
		}
		else if(InCharacterType == ECharacterStatType::MaxHp)
		{
			PlayerMaxHp = InValue;
		}

		double value = (double)PlayerHp / (double)PlayerMaxHp;

		PlayerHpBar->SetPercent(value);
		// Player 체력 <= 0 일 때, // ReSpawn
		if(InCharacterType == ECharacterStatType::Hp)
			if(InValue <= 0)
				HudFadeCanvas->OnMainPCDieScreen(10);
	}

	if(charBase->GetCharacterType() == ECharacterType::Nexus)
	{
		// Nexus 체력 UI
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

		// Nexus 체력 <= 0 일 때, // GameOver
		if(InCharacterType == ECharacterStatType::Hp)
			if(InValue <= 0)
				HudFadeCanvas->GameOverScreen();
	}
}

void UDPHud::OnOffViewCard()
{
	OnViewCard = !OnViewCard;
	Hand->OnOffViewCard(OnViewCard);
}

void UDPHud::SetViewCard(const CardInfo* InCardInfo)
{
	Hand->SetViewCard(InCardInfo);
}
