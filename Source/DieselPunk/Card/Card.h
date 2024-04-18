// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

/**
 * 카드의 베이스 클래스입니다.
 */

enum class ECardType : uint8;
class ACharacterPC;

struct CardInfo
{
	FString CardName;				//카드 이름
	FString CardUIName;				//UI에 표시될 카드 이름
	FText CardUIDescription;		//UI에 표시될 카드 설명
	ECardType CardType;				//카드 타입
	int32 Cost;						//카드 코스트
	FDateTime GetTime;				//획득 시간
	int32 Key;						//카드 키
	TArray<FString> TexturePath;	//카드 텍스쳐
};

class DIESELPUNK_API FCard
{
protected:
	TWeakObjectPtr<ACharacterPC> Owner;
	CardInfo Info;
public:
	FCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner);
	virtual ~FCard();

public:
	//카드 사용 시 호출할 함수 바인딩
	void BindCardActivate();
	//카드 캔슬 시 호출할 함수 바인딩
	void BindCardCancel();
	//카드 사용 완료 시 호출할 함수 바인딩
	void BindCardComplete();
	//회전 입력 시 호출할 함수 바인딩
	void BindRotateInstallation();

	//바인딩을 위한 카드 사용 함수
	void Activate(bool& OutSuccess, int32 InCost);
	//바인딩을 위한 카드 캔슬 함수
	void Cancel();
	//바인딩을 위한 카드 사용 완료 함수
	void Complete(bool& OutSuccess, int32 InCost);
	//바인딩을 위한 설치물 회전 함수
	void RotateInstallation(int32 RotateAngle);

public:
	const CardInfo& GetCardInfo() const {return Info;}

private:
	//카드 사용 함수
	virtual void _Activate(bool& OutSuccess, int32 InCost){}
	//카드 캔슬 함수
	virtual void _Cancel(){}
	//카드 사용 완료 함수
	virtual void _Complete(bool& OutSuccess, int32 InCost){}
	//설치물 회전 함수
	virtual void _RotateInstallation(int32 InRotateAngle){}
	
};