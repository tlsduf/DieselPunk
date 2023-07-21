// Copyright GuardiansW. All Rights Reserved.


#include "DecorateActorComponent.h"
#include "../Util/UtilEffect.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(DecorateActorComponent)


// =============================================================
// Sets default values for this component's properties
// =============================================================
UDecorateActorComponent::UDecorateActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// =============================================================
// Called every frame
// =============================================================
void UDecorateActorComponent::TickComponent(float InDeltaTime, ELevelTick InTickType, FActorComponentTickFunction* InThisTickFunction)
{
	Super::TickComponent( InDeltaTime, InTickType, InThisTickFunction );

	for ( auto iter = ActivatedDecoDatas.CreateIterator(); iter; ++iter )
	{
		TTuple< FDecorateData*, FIntervalTimer >& activatedDecoData = *iter;
		if ( !activatedDecoData.Key )
			continue;

		if ( activatedDecoData.Value.Repeat == 0 )
		{
			iter.RemoveCurrent();
			continue;
		}

		if ( !activatedDecoData.Value.Tick( InDeltaTime ) )
			continue;

		_Activate( activatedDecoData.Key );
	}
}

// =============================================================
// Called when the game starts
// =============================================================
void UDecorateActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

// =============================================================
// 발동된 데코레이터 정보를 세팅한다.
// =============================================================
void UDecorateActorComponent::_StartDeco( FDecorateData* InData )
{
	if ( !InData )
		return;

	if ( InData->Delay == 0.f )
		_Activate( InData );
	else
		ActivatedDecoDatas.Add( TTuple< FDecorateData*, FIntervalTimer >( InData, FIntervalTimer( InData->Delay, 1 ) ) );
}

// =============================================================
// 데코레이터 종료를 처리한다.
// =============================================================
void UDecorateActorComponent::_EndDeco( FDecorateData* InData )
{
	auto find = ActivatedDecoDatas.Find( InData );
	if ( !find )
		return;

	ActivatedDecoDatas.Remove( InData );
}


// =============================================================
// 파티클 데코레이터 컴포넌트
// =============================================================
// =============================================================
// 데코레이터 컴포넌트를 시작한다
// =============================================================
void UDecorateParticleComponent::StartDeco( EDecorateUseType InUseType )
{
	for ( FDecorateParticleData& particleData : DecoDatas )
	{
		if ( particleData.UseType != InUseType )
			continue;

		_StartDeco( &particleData );
	}
}

// =============================================================
// 데코레이터 컴포넌트를 활성화한다.
// =============================================================
void UDecorateParticleComponent::_Activate( FDecorateData* InData )
{
	if ( !InData )
		return;

	FDecorateParticleData* particleData = static_cast< FDecorateParticleData* >( InData );
	if ( !particleData )
		return;

	if ( !GetOwner() )
		return;

	// 파티클 내부에서 AutoDestroy 가 활성화 된 상태로 스폰해서 별도의 종료처리는 아직 없음
	if ( particleData->Attach )
	{
		UtilEffect::SpawnParticleComponentAttached(
			particleData->Particle,
			GetOwner()->GetRootComponent(),
			particleData->SocketName,
			particleData->OffsetLocation,
			particleData->Rotation,
			FVector( particleData->Scale )
		);
	}
	else
	{
		UtilEffect::SpawnParticleComponent(
			particleData->Particle,
			GetOwner()->GetActorLocation() + particleData->OffsetLocation,
			particleData->Rotation,
			FVector( particleData->Scale ),
			GetWorld()
		);
	}

	_EndDeco( InData );
}

// =============================================================
// 스케일 데코레이터 데이터
// =============================================================