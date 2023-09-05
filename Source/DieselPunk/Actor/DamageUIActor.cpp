// Copyright GuardiansW. All Rights Reserved.


#include "DamageUIActor.h"
#include "../Manager/UIManager.h"
#include "../UI/HUD/DamageUI.h"

#include <Components/WidgetComponent.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DamageUIActor)

// Sets default values
ADamageUIActor::ADamageUIActor()
{
	WidgetComp = CreateDefaultSubobject< UWidgetComponent >( TEXT( "StatusUI" ) );
	if ( WidgetComp )
	{
		WidgetComp->SetupAttachment( GetRootComponent() );
		WidgetComp->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		WidgetComp->SetGenerateOverlapEvents( false );
		WidgetComp->SetSimulatePhysics( false );
		WidgetComp->SetWidgetSpace( EWidgetSpace::Screen );
	}
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// 데미지UI 위젯을 생성한다.
void ADamageUIActor::CreateDamageUI()
{
	if( DamageUI.IsValid() )
		return;

	DamageUI = GetUIManager().CreateUnmanagedUI< UDamageUI >( TEXT( "HUD/DamageUI" ) );
	if ( !WidgetComp || !DamageUI.IsValid() )
		return;

	WidgetComp->SetWidget( DamageUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );

	// 데미지를 어떻게 받아올까
	DamageUI->SetDamage(Damage);
}

void ADamageUIActor::SetDamage(float inDamage)
{
	Damage = inDamage;
}

/** Overridable native event for when play begins for this actor. */
void ADamageUIActor::BeginPlay()
{
	Super::BeginPlay();

	CreateDamageUI();
	StartAnimator();
	GetWorldTimerManager().SetTimer(DestroyTHandle, this, &ADamageUIActor::SelfDestroy, LifeTime, false);
}

void ADamageUIActor::Tick(float InDeltaTime)
{
	Super::Tick(InDeltaTime);

	// AccelAnimator 업데이트
	XYAccelAnimator.Update(InDeltaTime);
	ZAccelAnimator.Update(InDeltaTime);

	// 위치 업데이트
	FVector currentLocation = GetActorLocation();
	FVector XYVector = FVector(XVelocity,YVelocity,0);
	FVector ZVector = FVector(0,0,ZVelocity);
	currentLocation += (XYAccel * XYVector * InDeltaTime) + (ZAccel * ZVector * InDeltaTime);
	SetActorLocation(currentLocation);
}

// AccelAnimator 애니메이터
void ADamageUIActor::StartAnimator()
{
	// XY 애니메이터
	AnimatorParam XYparam;
	XYparam.AnimType = EAnimType::CubicEaseIn;
	XYparam.StartValue = 1.f;
	XYparam.EndValue = 0.f;
	XYparam.DurationTime = LifeTime;

	TWeakObjectPtr<ADamageUIActor> thisPtr = this;
	XYparam.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->XYAccel = InCurValue;
	};

	XYAccelAnimator.Start(XYparam);

	// Z 애니메이터
	AnimatorParam Zparam;
	Zparam.AnimType = EAnimType::QuadraticEaseOut;
	Zparam.StartValue = 1.f;
	Zparam.EndValue = 0.f;
	Zparam.DurationTime = LifeTime;

	TWeakObjectPtr<ADamageUIActor> thisPtr2 = this;
	Zparam.DurationFunc = [thisPtr2](float InCurValue)
	{
		if(thisPtr2.IsValid())
			thisPtr2->ZAccel = InCurValue;
	};

	ZAccelAnimator.Start(Zparam);
}

// LifeTime 후 파괴됩니다.
void ADamageUIActor::SelfDestroy()
{
	// 초기화해야 할게 있나?
	Destroy();
}
