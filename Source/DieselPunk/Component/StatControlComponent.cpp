// Fill out your copyright notice in the Description page of Project Settings.


#include "StatControlComponent.h"
#include "../Character/CharacterBase.h"
#include "../Raw/Buff.h"

#include <GameFramework/CharacterMovementComponent.h>

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
	StatData = FDataTableManager::GetInstance()->GetData<FStatDataTable>(EDataTableType::Stat, ActorName);

	if(!StatData)
	{
		LOG_SCREEN(FColor::Red, TEXT("ActorName: %s에 해당하는 데이터 열이 없습니다. 데이터 테이블에서 스탯을 불러올 수 없습니다."), *Owner->GetName())
		return;
	}

	SetStat(ECharacterStatType::Level, 1);
	SetStat(ECharacterStatType::Exp, 0);

	SetStat(ECharacterStatType::MaxHp,			 StatData->StatInfos[0].Hp);
	SetStat(ECharacterStatType::Hp,				 StatData->StatInfos[0].Hp);
	SetStat(ECharacterStatType::HpRecoverySpeed, StatData->StatInfos[0].HpRecoverySpeed);
	SetStat(ECharacterStatType::Atk,			 StatData->StatInfos[0].Atk);
	SetStat(ECharacterStatType::AtkSpeed,		 StatData->StatInfos[0].AtkSpeed);
	SetStat(ECharacterStatType::Def,			 StatData->StatInfos[0].Def);
	SetStat(ECharacterStatType::ArmorPen,		 StatData->StatInfos[0].ArmorPen);
	SetStat(ECharacterStatType::CriticalPer,	 StatData->StatInfos[0].CriticalPer);
	SetStat(ECharacterStatType::CriticalAtk,	 StatData->StatInfos[0].CriticalAtk);
	SetStat(ECharacterStatType::MoveSpeed,		 StatData->StatInfos[0].MoveSpeed);
	SetStat(ECharacterStatType::JumpCount,		 StatData->StatInfos[0].JumpCount);
	SetStat(ECharacterStatType::Luck,			 StatData->StatInfos[0].Luck);
	SetStat(ECharacterStatType::CoolDown,		 StatData->StatInfos[0].CoolDown);
	SetStat(ECharacterStatType::AttackMaxRange,	 StatData->StatInfos[0].AttackMaxRange);
	SetStat(ECharacterStatType::AttackMinRange,	 StatData->StatInfos[0].AttacMinRange);
	SetStat(ECharacterStatType::Cost,			 StatData->StatInfos[0].Cost);
	SetStat(ECharacterStatType::AceChance,		 StatData->AceChance);
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
	if(InLv >= StatData->StatInfos.Num())
		return;
	
	SetStat(ECharacterStatType::Exp, 0);
	SetStat(ECharacterStatType::MaxHp,			 		StatData->StatInfos[InLv].Hp);
	SetStat(ECharacterStatType::Hp,				 		StatData->StatInfos[InLv].Hp);
	SetStat(ECharacterStatType::HpRecoverySpeed, 		StatData->StatInfos[InLv].HpRecoverySpeed);
	SetStat(ECharacterStatType::Atk,			 		StatData->StatInfos[InLv].Atk);
	SetStat(ECharacterStatType::AtkForFly,		 		StatData->StatInfos[InLv].AtkForFly);
	SetStat(ECharacterStatType::AtkSpeed,		 		StatData->StatInfos[InLv].AtkSpeed);
	SetStat(ECharacterStatType::Def,			 		StatData->StatInfos[InLv].Def);
	SetStat(ECharacterStatType::ArmorPen,		 		StatData->StatInfos[InLv].ArmorPen);
	SetStat(ECharacterStatType::CriticalPer,	 		StatData->StatInfos[InLv].CriticalPer);
	SetStat(ECharacterStatType::CriticalAtk,	 		StatData->StatInfos[InLv].CriticalAtk);
	SetStat(ECharacterStatType::MoveSpeed,		 		StatData->StatInfos[InLv].MoveSpeed);
	SetStat(ECharacterStatType::JumpCount,		 		StatData->StatInfos[InLv].JumpCount);
	SetStat(ECharacterStatType::Luck,			 		StatData->StatInfos[InLv].Luck);
	SetStat(ECharacterStatType::CoolDown,		 		StatData->StatInfos[InLv].CoolDown);
	SetStat(ECharacterStatType::AttackMaxRange,	 		StatData->StatInfos[InLv].AttackMaxRange);
	SetStat(ECharacterStatType::AttackMaxRangeForFly,	StatData->StatInfos[InLv].AttackMaxRangeForFly);
	SetStat(ECharacterStatType::AttackMinRange,	 		StatData->StatInfos[InLv].AttacMinRange);
	SetStat(ECharacterStatType::Cost,			 		StatData->StatInfos[InLv].Cost);
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
