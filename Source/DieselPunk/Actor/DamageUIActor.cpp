// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageUIActor.h"
#include "../UI/HUD/DamageUI.h"

#include <Components/WidgetComponent.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DamageUIActor)

// Sets default values
ADamageUIActor::ADamageUIActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	WidgetComp = CreateDefaultSubobject< UWidgetComponent >( TEXT( "UI" ) );
	if ( WidgetComp )
	{
		WidgetComp->SetupAttachment( GetRootComponent() );
		WidgetComp->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		WidgetComp->SetGenerateOverlapEvents( false );
		WidgetComp->SetSimulatePhysics( false );
		WidgetComp->SetWidgetSpace( EWidgetSpace::Screen );
	}

	SetRootComponent(WidgetComp);
}

// 데미지UI 위젯을 생성한다.
void ADamageUIActor::CreateDamageUI()
{
	if( DamageUI.IsValid() )
		return;

	FString inPath = UtilPath::GetUIPath( TEXT("DamageUI") );
	UClass* widgetClass = ConstructorHelpersInternal::FindOrLoadClass( inPath, UUserWidget::StaticClass() );
	if(!widgetClass)
		return;
	
	UUserWidget* userWidget = CreateWidget<UUserWidget>( GetWorld(), widgetClass );
	if ( userWidget )
	{
		userWidget->AddToRoot();
		
		UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( userWidget );
		if ( userWidgetBase )
			userWidgetBase->OnCreated();
	}
	UDamageUI* myWidget = Cast<UDamageUI>(userWidget);
    if(myWidget)
    	myWidget->RemoveFromRoot();
	
    DamageUI = myWidget;
	
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

	// 랜덤 목표위치 set
	XVelocity = FMath::RandRange(-100, 100);
	YVelocity = FMath::RandRange(-100, 100);
	
	TWeakObjectPtr<ADamageUIActor> thisPtr = this;

	// XY축 움직임 애니메이션
	AnimatorParam XYAccelparam;
	XYAccelparam.StartValue = 1.f;
	XYAccelparam.EndValue = 0.f;
	XYAccelparam.DurationTime = LifeTime;
	XYAccelparam.AnimType = EAnimType::CubicIn;
	XYAccelparam.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->XYAccel = InCurValue;
	};
	XYAccelAnimator.SetParam(XYAccelparam);
	XYAccelAnimator.Start();

	// Z축 움직임 애니메이션
	AnimatorParam ZAccelparam;
	ZAccelparam.StartValue = 1.f;
	ZAccelparam.EndValue = 0.f;
	ZAccelparam.DurationTime = LifeTime;
	ZAccelparam.AnimType = EAnimType::QuadOut;
	ZAccelparam.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->ZAccel = InCurValue;
	};
	ZAccelAnimator.SetParam(ZAccelparam);
	ZAccelAnimator.Start();

	// LifeTime 후에 파괴
	GetWorld()->GetTimerManager().SetTimer(DestroyTHandle, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->SelfDestroy();
		},LifeTime, false);
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
	FVector ZVector = FVector( 0, 0, ZVelocity);
	currentLocation += (XYAccel * XYVector * InDeltaTime) + (ZAccel * ZVector * InDeltaTime);
	SetActorLocation(currentLocation);
}

// LifeTime 후 파괴됩니다.
void ADamageUIActor::SelfDestroy()
{
	// 초기화해야 할게 있나?
	DamageUI->Destruct();
	Destroy();
}
