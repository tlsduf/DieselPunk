// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterHousing.h"
#include "../Common/EffectStruct.h"
#include "CharacterInstallation.generated.h"

struct FCachedCharacter
{
	TWeakObjectPtr<ACharacterBase> Character;
	TMap<ECharacterStatType, int32> StatValue;
};

class USphereComponent;

UCLASS()
class DIESELPUNK_API ACharacterInstallation : public ACharacterHousing
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> Sphere;

	//설치물 파괴, 판매 등 설치물이 없어졌을 경우 스탯을 복구할 것인가
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	bool Restore = true;
	
	// 적용 대상
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	ECharacterType TargetType = ECharacterType::None;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	int32 Range = 100;

	//적용시킬 스탯 타입 및 밸류
	UPROPERTY(EditDefaultsOnly, Category="MYDP_StatChange", meta=(AllowPrivateAccess="true"))
	TMap<ECharacterStatType, int32> CharacterStatValue;

	//End의 경우 버프가 끝났을 때 적용 대상위치에서 이펙트가 실행됩니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	TArray<FEffectData> Effects;

	TArray<FCachedCharacter> CachedCharacters;

	float TimeCount = 0.f;
	
public:
	ACharacterInstallation();

	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void RunAi() override;
	
	// 오버랩시 호출해서 효과 적용
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);

	UFUNCTION()
	void EndOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex);

protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;

	void Buff(FCachedCharacter& InOutCharacter);
	
	void StartEffect(EEffectPlayType InEffectPlayType, FTransform InTransform);
};
