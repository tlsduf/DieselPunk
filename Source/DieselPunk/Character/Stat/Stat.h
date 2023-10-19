// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

class ACharacterBase;

class FStat
{
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FChangeStatDelegate, TWeakObjectPtr<ACharacterBase>, ECharacterStatType, int32)
private:
	TMap<ECharacterStatType, int32>	CharacterStat;
	TWeakObjectPtr<ACharacterBase>	Owner;
	FChangeStatDelegate				ChangeStatDelegate;
public:
	constexpr static int32 INVALID_STAT = -9999;
public:
	//스탯을 초기화합니다.
	void Initialize(const FString& InCharacterName);

	//스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
	void ChangeStat(ECharacterStatType InStatType, int32 InValue);

	//스탯을 반환합니다.
	int32 GetStat(ECharacterStatType InStatType);

	//스탯을 셋팅합니다. 캐릭터 생성시 이 함수를 통해 스탯을 세팅합니다. 인게임 도중에는 사용하지 않는 것을 추천합니다.
	void SetStat(ECharacterStatType InStatType, int32 InValue);

public:
	const FChangeStatDelegate& GetChangeStatDelegate() const
	{
		return ChangeStatDelegate;
	}
};
