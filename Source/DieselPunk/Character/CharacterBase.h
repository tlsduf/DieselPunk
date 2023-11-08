// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Stat/Stat.h"
#include "CharacterBase.generated.h"

class UWidgetComponent;
class UStatusUIBase;

UCLASS()
class DIESELPUNK_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	//오브젝트 ID
	int32 ObjectId = -1;

	//스탯
	FStat Stat;

	//캐릭터 정보를 가져오기 위한 이름
	UPROPERTY(EditDefaultsOnly)
	FString CharacterName = "";

public:
	// 데미지 UI 액터
	UPROPERTY()
	class ADamageUIActor *DamageUIActor;
	
	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;
	
	// 데미지를 입으면 데미지ui액터를 생성합니다.
	void DisplayDamage(float inDamage);

	//스탯을 가져옵니다.
	const FStat& GetStat() const { return Stat; }

	//스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
	void ChangeStat(ECharacterStatType InStatType, int32 InValue);

public:
	//생성자
	ACharacterBase();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called before destroying the object.
	virtual void BeginDestroy() override;
	
	virtual void CreateStatusUI() {};
public:	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;

	const int32 GetObjectId() const { return ObjectId; }

	void SetObjectId(int32 InObjectId) { ObjectId = InObjectId; }
	
};
