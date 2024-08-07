// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>
#include "StatControlComponent.generated.h"

struct FStatDataTable;
class FBuff;

typedef TMap<ECharacterStatType, int32> FStatInfo;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UStatControlComponent : public UActorComponent
{
	GENERATED_BODY()
	
	//스탯 변경 시 호출될 이벤트
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FSetStatDelegate, TWeakObjectPtr<AActor>, ECharacterStatType, int32)
protected:
	// 액터의 테이블 이름들을 지정합니다. 순서대로 레벨을 의미합니다. 인덱스0이 1레벨 정보 아이디입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_EssentialSetting")
	TArray<FName> ActorNames;
	
	//오너 클래스
	TWeakObjectPtr<AActor> Owner;

	//스탯 정보
	FStatInfo Stat;

	//스탯 변경 시 호출될 델리게이트
	FSetStatDelegate DelegateChangeStat;

	TMap<FName, FBuff*> Buffs;

	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting")
	TArray<ENPCTraitType> InitHaveTrait;
	
	uint8 Trait = 0;

	TArray<FStatInfo> StatInfos;
public:
	constexpr static int32 INVALID_STAT = -9999;
public:	
	// Sets default values for this component's properties
	UStatControlComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetStatDelegateFunction(TWeakObjectPtr<AActor> InActor, ECharacterStatType InStatType, int32 InValue);

public:
	virtual void BeginDestroy() override;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetStat(ECharacterStatType InStatType, int32 InValue);

	void ChangeStatForLevelUp(int32 InLv);

	const int32& GetStat(ECharacterStatType InStatType);

	void AddBuff(const FName& InBuffName);

	FBuff* GetBuff(const FName& InBuffName);

	//특성을 추가합니다.
	void AddTrait(ENPCTraitType InTraitType);

	//특성을 삭제합니다.
	void RemoveTrait(ENPCTraitType InTraitType);

	//특성을 가지고 있는 지 확인합니다.
	bool IsTrait(ENPCTraitType InTraitType);

	FSetStatDelegate& GetSetStatDelegate(){return DelegateChangeStat;}

	const TArray<FName>& GetActorNames(){return ActorNames;}

	void SetStatForStatInfos(int32 InIndex);

	const TArray<FStatInfo>& GetStatInfos(){return StatInfos;}
};
