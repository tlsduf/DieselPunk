// Fill out your copyright notice in the Description page of Project Settings.


#include "StatControlComponent.h"
#include "../Character/CharacterBase.h"
#include "../Raw/Buff.h"

#include <GameFramework/CharacterMovementComponent.h>

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/Character/CharacterMonster.h"
#include "DieselPunk/Character/CharacterTurret.h"
#include "DieselPunk/Core/DPLevelScriptActor.h"
#include "DieselPunk/Data/BuffDataTable.h"
#include "DieselPunk/Data/StatDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"
#include "DieselPunk/Raw/BuffStat.h"
#include "DieselPunk/Raw/BuffStatusEffect.h"
#include "Engine/Level.h"

// Sets default values for this component's properties
UStatControlComponent::UStatControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatControlComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if(!Owner.IsValid())
		return;

	//특성 대입
	for(ENPCTraitType trait : InitHaveTrait)
	{
		Trait |= static_cast<uint8>(trait);
	}
	
	//스탯 초기화
	for(ECharacterStatType statType : TEnumRange<ECharacterStatType>())
	{
		if(statType == ECharacterStatType::Count)
			continue;

		Stat.FindOrAdd(statType) = 0.0;
	}
	
	DelegateChangeStat.AddUObject(this, &UStatControlComponent::SetStatDelegateFunction);

	for(const FName& name : ActorNames)
	{
		const FStatDataTable* table = FDataTableManager::GetInstance()->GetData<FStatDataTable>(EDataTableType::Stat, name);
		if(!table)
		{
			LOG_SCREEN(FColor::Red, TEXT("ActorNames의 이름: %s에 해당하는 데이터 테이블을 찾을 수 없습니다."), *name.ToString())
			continue;
		}
		
		FStatInfo statInfo;
		statInfo.FindOrAdd(ECharacterStatType::MaxHp) = table->Hp;		
		statInfo.FindOrAdd(ECharacterStatType::Hp) = table->Hp;
		statInfo.FindOrAdd(ECharacterStatType::Atk) = table->Atk;	
		statInfo.FindOrAdd(ECharacterStatType::AtkForFly) = table->AtkForFly;
		statInfo.FindOrAdd(ECharacterStatType::AtkSpeed) = table->AtkSpeed;
		statInfo.FindOrAdd(ECharacterStatType::Def) = table->Def;
		statInfo.FindOrAdd(ECharacterStatType::ArmorPen) = table->ArmorPen;
		statInfo.FindOrAdd(ECharacterStatType::CriticalPer) = table->CriticalPer;
		statInfo.FindOrAdd(ECharacterStatType::CriticalAtk) = table->CriticalAtk;
		statInfo.FindOrAdd(ECharacterStatType::MoveSpeed) = table->MoveSpeed;
		statInfo.FindOrAdd(ECharacterStatType::AtkMaxRange) = table->AtkMaxRange;
		statInfo.FindOrAdd(ECharacterStatType::AtkMaxRangeForFly) = table->AtkMaxRangeForFly;
		statInfo.FindOrAdd(ECharacterStatType::AtkMinRange) = table->AtkMinRange;
		statInfo.FindOrAdd(ECharacterStatType::Cost) = table->Cost;
		statInfo.FindOrAdd(ECharacterStatType::ShellFall) = table->ShellFall;

		StatInfos.Add(statInfo);
	}

	SetStat(ECharacterStatType::Level, 1);
	SetStat(ECharacterStatType::Exp, 0);
	SetStatForStatInfos(1);
	
}

void UStatControlComponent::SetStatDelegateFunction(TWeakObjectPtr<AActor> InActor, ECharacterStatType InStatType, int32 InValue)
{
	if(!InActor.IsValid())
		return;

	if(InStatType == ECharacterStatType::MoveSpeed)
	{
		ACharacterBase* charBase = Cast<ACharacterBase>(InActor);
		UActorComponent* comp = charBase->GetComponentByClass(UCharacterMovementComponent::StaticClass());
		if(comp == nullptr)
			return;

		UCharacterMovementComponent* movementComponent = Cast<UCharacterMovementComponent>(comp);
		movementComponent->MaxWalkSpeed = InValue;
		movementComponent->MaxWalkSpeedCrouched = InValue / 2;
	}
	else if(InStatType == ECharacterStatType::Level)
	{
		if(Cast<ACharacterTurret>(InActor))
			ChangeStatForLevelUp(InValue);
	}
	else if(InStatType == ECharacterStatType::Hp)
	{
		if(InValue <= 0)
		{
			ADPLevelScriptActor* level = Cast<ADPLevelScriptActor>(Owner->GetLevel()->GetLevelScriptActor());

			// monster 면 랙돌 아니면 Destroy
			if(ACharacterMonster* monster = Cast<ACharacterMonster>(Owner))
				monster->StartRagdollAndDestroy();
			else
				Owner->Destroy();
			
			// 레벨관리
			if(level)
				level->CheckWaveCleared();
		}
	}
}

void UStatControlComponent::BeginDestroy()
{
	Super::BeginDestroy();
	
	Stat.Empty();
	DelegateChangeStat.Clear();
}

void UStatControlComponent::SetStat(ECharacterStatType InStatType, int32 InValue)
{
	int32* stat = Stat.Find(InStatType);
	if(!stat || *stat == InValue)
		return;
	
	*stat = InValue;

	if(DelegateChangeStat.IsBound())
		DelegateChangeStat.Broadcast(Owner, InStatType, *stat);
}

void UStatControlComponent::ChangeStatForLevelUp(int32 InLv)
{
	if(!StatInfos.IsValidIndex(InLv - 1))
		return;

	SetStat(ECharacterStatType::Exp, 0);
	SetStatForStatInfos(InLv);

	Stat[ECharacterStatType::Level] = Stat[ECharacterStatType::Level] > TURRET_MAX_LV ?
		TURRET_MAX_LV : Stat[ECharacterStatType::Level];
	
	//if(ACharacterTurret* turret = Cast<ACharacterTurret>(Owner))
	//	turret->UpgradeSkill(table->UpgradeSkillNames);
}


// Called every frame
void UStatControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	for(TMap<FName, FBuff*>::TIterator iter = Buffs.CreateIterator(); iter; ++iter)
	{
		if(iter->Value->Tick(DeltaTime))
		{
			iter->Value->Release();
			delete iter->Value;
			iter->Value = nullptr;
			iter.RemoveCurrent();
		}
	}
}

const int32& UStatControlComponent::GetStat(ECharacterStatType InStatType)
{
	const int32* stat = Stat.Find(InStatType);
	if(!stat)
		return INVALID_STAT;

	return *stat;
}

void UStatControlComponent::AddBuff(const FName& InBuffName)
{
	FBuff** findTemp = Buffs.Find(InBuffName);
	
	FBuff* buff = nullptr;
	if(findTemp != nullptr)
	{
		buff = *findTemp;
		buff->Initialize();
	}
	else
	{
		const FBuffDataTable* buffData = FDataTableManager::GetInstance()->GetData<FBuffDataTable>(EDataTableType::Buff, InBuffName.ToString());
		if(!buffData)
			return;

		switch (buffData->BuffType)
		{
		case EBuffType::Stat:
			buff = new FBuffStat(this, buffData);
			break;
		case EBuffType::StatusEffect:
			buff = new FBuffStatusEffect(this, buffData);
			break;
		}
		if(buff)
		{
			buff->Initialize();
			Buffs.Add(InBuffName, buff);
		}
	}
}

FBuff* UStatControlComponent::GetBuff(const FName& InBuffName)
{
	FBuff** buffPtr = Buffs.Find(InBuffName);
	if(buffPtr && *buffPtr)
		return *buffPtr;
	return nullptr;
}

void UStatControlComponent::AddTrait(ENPCTraitType InTraitType)
{
	if(InTraitType == ENPCTraitType::None)
		return;

	Trait |= static_cast<uint8>(InTraitType);
}

void UStatControlComponent::RemoveTrait(ENPCTraitType InTraitType)
{
	if(InTraitType == ENPCTraitType::None)
		return;

	Trait &= !static_cast<uint8>(InTraitType);
}

bool UStatControlComponent::IsTrait(ENPCTraitType InTraitType)
{
	return Trait & static_cast<uint8>(InTraitType);
}

void UStatControlComponent::SetStatForStatInfos(int32 InIndex)
{
	if(StatInfos.IsValidIndex(InIndex - 1))
	{
		for(const auto& [key, value] : StatInfos[InIndex - 1])
		{
			SetStat(key, value);
		}
	}
}
