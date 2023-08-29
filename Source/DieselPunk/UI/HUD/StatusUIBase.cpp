// Copyright GuardiansW. All Rights Reserved.


#include "StatusUIBase.h"
#include "../../Character/CharacterBase.h"
#include "../../Character/Stat.h"
#include "../../Manager/UIManager.h"
#include "../../Data/Info/CharacterInfo.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>
#include <Components/Image.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(StatusUIBase)


// =============================================================
// 캐릭터 정보를 업데이트한다.
// =============================================================
void UStatusUIBase::UpdateTarget( FInfoId InInfoId )
{
	FCharacterInfoPtr characterInfo( InInfoId );
	if ( !characterInfo )
		return;

	if( TextName )
		TextName->SetText( FText::FromString( characterInfo->Name ) );
}

// =============================================================
// UI를 초기화한다.
// =============================================================
void UStatusUIBase::InitStatus( ACharacterBase* InOwner )
{
	if ( !InOwner )
		return;

	Character = InOwner;

	MaxHp = Character->GetStat( EActorStatType::MaxHp );
	CurHp = Character->GetStat( EActorStatType::Hp );

	_UpdateHp( CurHp, MaxHp );
	UpdateTarget( Character->GetInfoId() );

	auto ftrBind = [ this ] ( EActorStatType InType, const FTR_STAT_FUNC& InFunc )
	{
		FtrStatFunc.FindOrAdd( InType, InFunc );
	};

	ftrBind( EActorStatType::Hp,    &UStatusUIBase::_SetHp    );
	ftrBind( EActorStatType::MaxHp, &UStatusUIBase::_SetMaxHp );

	Character->GetStats().GetEventStatChanged().AddUObject( this, &UStatusUIBase::OnStatChanged );
}

// =============================================================
// 생성자
// =============================================================
void UStatusUIBase::OnCreated()
{
	Super::OnCreated();

	_InitControls();
}

// =============================================================
// 소멸자
// =============================================================
void UStatusUIBase::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 틱
// =============================================================
void UStatusUIBase::NativeTick( const FGeometry& MyGeometry, float InDeltaTime )
{
	Super::NativeTick( MyGeometry, InDeltaTime );

	HpAnimator.Update( InDeltaTime );
}

// =============================================================
// 스텟 변화량을 처리한다.
// =============================================================
void UStatusUIBase::OnStatChanged( FObjId InObjId, EActorStatType InStatType, int64 InOldValue, int64 InNewValue )
{
	if ( !FtrStatFunc.Find( InStatType ) )
		return;

	FtrStatFunc[ InStatType ]( *this, InOldValue, InNewValue );
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UStatusUIBase::_InitControls()
{
	_InitControl( TextName     , TEXT( "TextName"      ) );
	_InitControl( ProgressBarHP, TEXT( "ProgressBarHP" ) );
	_InitControl( ImageIcon    , TEXT( "ImageIcon"     ) );
}

// =============================================================
// 현재 Hp 변화를 처리한다.
// =============================================================
void UStatusUIBase::_UpdateHp( int64 InCurHp, int64 InMaxHp )
{
	float curPercent = ( float )CurHp / ( float )MaxHp;
	curPercent = FMath::Clamp( curPercent, 0.f, 1.f );

	float destPercent = ( float )InCurHp / ( float )InMaxHp;
	destPercent = FMath::Clamp( destPercent, 0.f, 1.f );

	//if ( ProgressBarHP )
	//	ProgressBarHP->SetPercent( curPercent );

	if( HpAnimator.IsRunning() )
		HpAnimator.Stop();

	AnimatorParam param;
	param.AnimType = EAnimType::Linear;
	param.StartValue = curPercent;
	param.EndValue = destPercent;
	param.DurationTime = DA_UI( HpAnimSpeed );
	param.DurationFunc = [ this ] ( float InValue )
	{
		//if ( ProgressBarHP )
		//	ProgressBarHP->SetPercent( InValue );
	};
	param.CompleteFunc = [ this ] ( float InValue )
	{
		//if ( ProgressBarHP )
		//	ProgressBarHP->SetPercent( InValue );
	};

	HpAnimator.Start( param );

	CurHp = InCurHp;
	MaxHp = InMaxHp;
}

// =============================================================
// Hp 를 설정한다.
// =============================================================
void UStatusUIBase::_SetHp( int64 InOldValue, int64 InNewValue )
{
	_UpdateHp( InNewValue, MaxHp );
}

// =============================================================
// Max Hp 를 설정한다.
// =============================================================
void UStatusUIBase::_SetMaxHp( int64 InOldValue, int64 InNewValue )
{
	_UpdateHp( CurHp, InNewValue );
}
