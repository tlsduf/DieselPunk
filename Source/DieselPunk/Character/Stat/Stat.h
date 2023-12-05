// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

class ACharacterBase;

class FStat
{
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FChangeStatDelegate, TWeakObjectPtr<ACharacterBase>, ECharacterStatType, int32)
private:
	//캐릭터 스탯 정보
	TMap<ECharacterStatType, int32>	CharacterStat;

	//주인 클래스
	TWeakObjectPtr<ACharacterBase>	Owner;

	//스탯 변경시 호출될 델리게이트
	FChangeStatDelegate				ChangeStatDelegate;
public:
	constexpr static int32 INVALID_STAT = -9999;
public:
	//스탯을 초기화합니다.
	void Initialize(ACharacterBase* InOwner, const FString& InCharacterName);

	//스탯 클래스를 비웁니다.
	void Release();

	//스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
	void ChangeStat(ECharacterStatType InStatType, int32 InValue);

	//스탯을 반환합니다.
	const int32& GetStat(ECharacterStatType InStatType) const;

	//스탯을 셋팅합니다. 캐릭터 생성시 이 함수를 통해 스탯을 세팅합니다. 인게임 도중에는 사용하지 않는 것을 추천합니다.
	void SetStat(ECharacterStatType InStatType, int32 InValue);

public:
	const FChangeStatDelegate& GetChangeStatDelegate() const
	{
		return ChangeStatDelegate;
	}
};
