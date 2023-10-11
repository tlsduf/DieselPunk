// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UWidgetComponent;
class UStatusUIBase;

UCLASS()
class DIESELPUNK_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// 데미지 UI 액터
	UPROPERTY()
	class ADamageUIActor *DamageUIActor;
	
	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;
	
	//데미지를 입으면 데미지ui액터를 생성합니다.
	void DisplayDamage(float inDamage);

	ACharacterBase();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called before destroying the object.
	virtual void BeginDestroy() override;

	// 상태 UI 위젯을 생성한다.
	virtual void CreateStatusUI() {};

public:	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;
	
	
};
