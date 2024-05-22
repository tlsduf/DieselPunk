// Fill out your copyright notice in the Description page of Project Settings.


#include "StatControlComponent.h"
#include "../Character/CharacterBase.h"
#include "../Raw/Buff.h"

#include <GameFramework/CharacterMovementComponent.h>

#include "DieselPunk/Character/CharacterTurret.h"
#include "DieselPunk/Data/StatDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"

// Sets default values for this component's properties
UStatControlComponent::UStatControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	ACharacterBase* owner = Cast<ACharacterBase>(Owner);
	if(owner)
	{
		ActorName = owner->GetCharacterName();
	}
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

	if(ActorName == TEXT(""))
	{
		LOG_SCREEN(FColor::Red, TEXT("%s의 ActorName이 등록되지 않았습니다. 데이터 테이블에서 스탯을 불러올 수 없습니다."), *Owner->GetName())
		return;
	}

	UDataTable* table = FDataTableManager::GetInstance()->GetDataRow(EDataTableType::Stat);
	if(!table)
	{
		LOG_SCREEN(FColor::Red, TEXT("스탯 데이터 테이블을 찾을 수 없습니다. %s."), *Owner->GetName())
		return;
	}

	FString actorName = ActorName;
	TArray<FName> names = table->GetRowNames().FilterByPredicate([actorName](const FName& name)
	{
		FString str = name.ToString();
		return INDEX_NONE != str.Find(actorName);
	});
	if(Cast<ACharacterTurret>(Owner))
	{
		for(const FName& name : names)
		{
			FString str = name.ToString();
			TArray<FString> split;
			str.ParseIntoArray(split, TEXT("_"));
		
			if(FStatDataTable* statTable = table->FindRow<FStatDataTable>(name, *name.ToString()))
			{
				FString numbering = split[split.Num() - 1];
				int32 strLv = -1;
				if(INDEX_NONE != numbering.Find(TEXT("Ace")))
				{
					FString lastLv = numbering.Mid(numbering.Len() - 1, 1);
					strLv = FCString::Atoi(*lastLv) + TURRET_MAX_LV - 1;
				}
				else
					strLv = FCString::Atoi(*numbering);
				StatDatas.Add(strLv, statTable);
			
			}
		}
	}
	else
	{
		for(int i = 0; i < names.Num(); ++i)
		{
			if(FStatDataTable* statTable = table->FindRow<FStatDataTable>(names[i], *names[i].ToString()))
			{
				StatDatas.Add(i + 1, statTable);
			}
		}
	}

	if(StatDatas.IsEmpty())
	{
		LOG_SCREEN(FColor::Red, TEXT("ActorName: %s에 해당하는 데이터 열이 없습니다. 데이터 테이블에서 스탯을 불러올 수 없습니다."), *Owner->GetName())
		return;
	}

	SetStat(ECharacterStatType::Level, 1);
	SetStat(ECharacterStatType::Exp, 0);

	SetStat(ECharacterStatType::MaxHp,			 		StatDatas[1]->Hp);
	SetStat(ECharacterStatType::Hp,				 		StatDatas[1]->Hp);
	SetStat(ECharacterStatType::Atk,			 		StatDatas[1]->Atk);
	SetStat(ECharacterStatType::AtkForFly,		 		StatDatas[1]->AtkForFly);
	SetStat(ECharacterStatType::AtkSpeed,		 		StatDatas[1]->AtkSpeed);
	SetStat(ECharacterStatType::Def,			 		StatDatas[1]->Def);
	SetStat(ECharacterStatType::ArmorPen,		 		StatDatas[1]->ArmorPen);
	SetStat(ECharacterStatType::CriticalPer,	 		StatDatas[1]->CriticalPer);
	SetStat(ECharacterStatType::CriticalAtk,	 		StatDatas[1]->CriticalAtk);
	SetStat(ECharacterStatType::MoveSpeed,		 		StatDatas[1]->MoveSpeed);
	SetStat(ECharacterStatType::AttackMaxRange,	 		StatDatas[1]->AttackMaxRange);
	SetStat(ECharacterStatType::AttackMaxRangeForFly,	StatDatas[1]->AttackMaxRangeForFly);
	SetStat(ECharacterStatType::AttackMinRange,	 		StatDatas[1]->AttacMinRange);
	SetStat(ECharacterStatType::Cost,			 		StatDatas[1]->Cost);
	SetStat(ECharacterStatType::AceChance,		 		StatDatas[1]->AceChance);
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
		ChangeStatForLevelUp(InValue);
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
	FStatDataTable* table = StatDatas[InLv];

	if(!table)
		return;
	
	SetStat(ECharacterStatType::Exp, 0);
	SetStat(ECharacterStatType::MaxHp,			 		table->Hp);
	SetStat(ECharacterStatType::Hp,				 		table->Hp);
	SetStat(ECharacterStatType::Atk,			 		table->Atk);
	SetStat(ECharacterStatType::AtkForFly,		 		table->AtkForFly);
	SetStat(ECharacterStatType::AtkSpeed,		 		table->AtkSpeed);
	SetStat(ECharacterStatType::Def,			 		table->Def);
	SetStat(ECharacterStatType::ArmorPen,		 		table->ArmorPen);
	SetStat(ECharacterStatType::CriticalPer,	 		table->CriticalPer);
	SetStat(ECharacterStatType::CriticalAtk,	 		table->CriticalAtk);
	SetStat(ECharacterStatType::MoveSpeed,		 		table->MoveSpeed);
	SetStat(ECharacterStatType::AttackMaxRange,	 		table->AttackMaxRange);
	SetStat(ECharacterStatType::AttackMaxRangeForFly,	table->AttackMaxRangeForFly);
	SetStat(ECharacterStatType::AttackMinRange,	 		table->AttacMinRange);
	SetStat(ECharacterStatType::Cost,			 		table->Cost);

	Stat[ECharacterStatType::Level] = Stat[ECharacterStatType::Level] > TURRET_MAX_LV ? TURRET_MAX_LV : Stat[ECharacterStatType::Level];
}


// Called every frame
void UStatControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	for(TMap<FString, FBuff*>::TIterator iter = Buffs.CreateIterator(); iter; ++iter)
	{
		if(iter->Value->Tick(DeltaTime))
			iter.RemoveCurrent();
	}
}

const int32& UStatControlComponent::GetStat(ECharacterStatType InStatType)
{
	const int32* stat = Stat.Find(InStatType);
	if(!stat)
		return INVALID_STAT;

	return *stat;
}

void UStatControlComponent::AddBuff(const FString& InBuffName)
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
		buff = new FBuff(this, InBuffName);
		Buffs.Add(InBuffName, buff);
	}
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
