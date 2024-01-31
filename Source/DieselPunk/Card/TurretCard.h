// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Card.h"

/**
 * 터렛 카드입니다.
 */

class ACharacterPC;
class DIESELPUNK_API FTurretCard : public FCard
{
	int32 MaxTier;
	int32 CurrentTier;
	int32 ControlTurretId;
	FString CharacterName;
public:
	FTurretCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner);
	virtual ~FTurretCard() override;

private:
	//카드 사용 함수
	virtual void _Activate(bool& OutSuccess, int32 InCost) override;
	//카드 캔슬 함수
	virtual void _Cancel() override;
	//카드 사용 완료 함수
	virtual void _Complete(bool& OutSuccess, int32 InCost) override;
	//설치물 회전 함수
	virtual void _RotateInstallation(int32 InRotateAngle) override;
};
