// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>

#include "../Common/EffectStruct.h"
#include "DecoratorComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIESELPUNK_API UDecoratorComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	//오너 클래스
	TWeakObjectPtr<AActor> Owner;

	//기본적으로 재생할 이펙트들을 답아줍니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting")
	TArray<FEffectData> EffectDatas;

public:	
	// Sets default values for this component's properties
	UDecoratorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void StartEffect(EEffectPlayType InEffectPlayType, FName InBoneName = "");
	
	UFUNCTION(BlueprintCallable, Category="MYDP_Effect")
	void PlayWalkEffect(FName InBoneName);
};
