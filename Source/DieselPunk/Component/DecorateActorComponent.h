// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <Components/ActorComponent.h>
#include "DecorateActorComponent.generated.h"


class UNiagaraSystem;


// =============================================================
// 데코레이터 베이스 데이터
// =============================================================
USTRUCT()
struct FDecorateData
{
	GENERATED_BODY()

	// 데코레이터 컴포넌트 발동 조건
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	EDecorateUseType UseType = EDecorateUseType::Spawn;

	// 발동 딜레이
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	float Delay = 0.f;
};


// =============================================================
// 스폰, 디스폰시의 연출등 엑터를 꾸며주는 베이스 컴포넌트
// =============================================================
UCLASS( ClassGroup = ( Custom ) )
class DIESELPUNK_API UDecorateActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 현재 활성화된 데코레이터 데이터 리스트
	TMap< FDecorateData*, FIntervalTimer > ActivatedDecoDatas;

public:	
	// Sets default values for this component's properties
	UDecorateActorComponent();

	// Called every frame
	virtual void TickComponent( float InDeltaTime, ELevelTick InTickType, FActorComponentTickFunction* InThisTickFunction ) override;

	// 데코레이터 컴포넌트를 시작한다
	virtual void StartDeco( EDecorateUseType InUseType ) {}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// 데코레이터 컴포넌트를 활성화한다.
	virtual void _Activate( FDecorateData* InData ) {}

	// 시작한 데코레이터 정보를 세팅한다.
	void _StartDeco( FDecorateData* InData );

	// 데코레이터 종료를 처리한다.
	void _EndDeco( FDecorateData* InData );
};


// =============================================================
// 파티클 데코레이터 데이터
// =============================================================
USTRUCT( BlueprintType )
struct FDecorateParticleData : public FDecorateData
{
	GENERATED_BODY()

	// 발동할 파티클
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	TSoftObjectPtr< UNiagaraSystem > Particle;

	// 파티클 오프셋 위치
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	FVector OffsetLocation = FVector::ZeroVector;

	// 파티클 회전값
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	FRotator Rotation = FRotator::ZeroRotator;

	// 파티클 스케일
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	float Scale = 1.f;

	// Actor 에 파티클을 부착할지 여부
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	bool Attach = false;

	// 부착할 소켓 이름
	UPROPERTY( EditAnywhere, Category = "Decorate", meta = ( EditCondition = "Attach" ) )
	FName SocketName = NAME_None;
};

// =============================================================
// 파티클 데코레이터 컴포넌트
// =============================================================
UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class DIESELPUNK_API UDecorateParticleComponent : public UDecorateActorComponent
{
	GENERATED_BODY()

	// 발동할 파티클
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	TArray< FDecorateParticleData > DecoDatas;

public:
	// 데코레이터 컴포넌트를 시작한다
	virtual void StartDeco( EDecorateUseType InUseType ) override;

protected:
	// 데코레이터 컴포넌트를 활성화한다.
	virtual void _Activate( FDecorateData* InData ) override;
};

// =============================================================
// 스케일 데코레이터 데이터
// =============================================================
USTRUCT( BlueprintType )
struct FDecorateScaleData : public FDecorateData
{
	GENERATED_BODY()

	// 시작시 스케일
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	float StartScale = 1.f;

	// 종료시 스케일
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	float EndScale = 1.f;

	// 지속 시간
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	float Duration = 1.f;
};

// =============================================================
// 스케일 데코레이터 컴포넌트
// =============================================================
UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class DIESELPUNK_API UDecorateScaleComponent : public UDecorateActorComponent
{
	GENERATED_BODY()

	// 스케일 데이터
	UPROPERTY( EditAnywhere, Category = "Decorate" )
	TArray< FDecorateScaleData > DecoDatas;

public:
	// Sets default values for this component's properties
	UDecorateScaleComponent() {}
};