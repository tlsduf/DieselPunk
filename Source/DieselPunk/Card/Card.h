// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

/**
 * 카드의 베이스 클래스입니다.
 */

enum class ECardType : uint8;
class ACharacterPC;

struct CardInfo
{
	FString CardName;		//카드 이름
	ECardType CardType;		//카드 타입
	int32 Cost;				//카드 코스트
	FDateTime GetTime;		//획득 시간
};

class DIESELPUNK_API FCard
{
protected:
	TWeakObjectPtr<ACharacterPC> Owner;
	CardInfo Info;
	
public:
	FCard(const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner);
	virtual ~FCard();

public:
	//카드 사용 시 호출할 함수 바인딩
	void BindCardActivate();
	//카드 사용 완료 시 호출할 함수 바인딩
	void BindCardComplete();

	//바인딩을 위한 카드 사용 함수
	void Activate(bool& OutSuccess);
	//바인딩을 위한 카드 사용 완료 함수
	void Complete(bool& OutSuccess);

public:
	const CardInfo& GetCardInfo(){return Info;}

private:
	//카드 사용 함수
	virtual void _Activate(bool& OutSuccess){}
	//카드 사용 완료 함수
	virtual void _Complete(bool& OutSuccess){}
	
};