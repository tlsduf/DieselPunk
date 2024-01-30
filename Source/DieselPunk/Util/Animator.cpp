// Fill out your copyright notice in the Description page of Project Settings.


#include "Animator.h"


// =============================================================
// 애니메이터 파람 생성자
// =============================================================
AnimatorParam::AnimatorParam()
	: StartValue( 0.f )
	, EndValue( 0.f )
	, DurationTime( 1.f )
	, AnimType( EAnimType::Linear )
	, DurationFunc(nullptr)
	, CompleteFunc(nullptr)
{
	
}

// =============================================================
// 생성자
// =============================================================
Animator::Animator()
	: Param( AnimatorParam() )
	, bIsRunning( false )
	, StartValue( 0.f )
	, CurValue( 0.f )
	, EndValue( 0.f )
	, AccTime( 1.f )
	, DurationTime( 1.f )
{

}

// =============================================================
// 파라미터 Setter // 애니메이션이 실행 중이면 중지 및 초기화를 하고 다시 세팅합니다.
// =============================================================
void Animator::SetParam(const AnimatorParam& InParam)
{
	if( bIsRunning )
		Stop();
	
	Param = InParam;
	StartValue = InParam.StartValue;
	EndValue = InParam.EndValue;
	AccTime = InParam.DurationTime;
	DurationTime = InParam.DurationTime;
}

// =============================================================
// 애니메이션 업데이트
// =============================================================
void Animator::Update(float InDeltaTime)
{
	// 애니메이션 작동 판별
	if( !bIsRunning )
		return;

	AccTime += InDeltaTime;
	
	// 애니메이션 종료 작업
	if ( AccTime >= DurationTime )
	{
		bIsRunning = false;
		if( Param.CompleteFunc )
			Param.CompleteFunc( CurValue );
		return;
	}

	float elapsedTime = DurationTime < AccTime ? DurationTime : AccTime;
	
	CurValue = ApplyEasing(Param.AnimType, elapsedTime * 1000.f, StartValue, EndValue - StartValue, DurationTime * 1000.f);

	if( Param.DurationFunc )
		Param.DurationFunc( CurValue );
}

// =============================================================
// 애니메이터 시작
// =============================================================
void Animator::Start()
{
	bIsRunning = true;
	AccTime = 0;
}

// =============================================================
// 애니메이션 정지 및 초기화 (Stop을 호출하면 SetParam 과정을 다시 해준뒤, Start 해야합니다.)
// =============================================================
void Animator::Stop()
{
	bIsRunning = false;
	Param = AnimatorParam();
	SetParam(Param);
}

// =============================================================
// 시간, 애니메이션 타입에 따라 애니메이팅
// =============================================================
float Animator::ApplyEasing(EAnimType EaseType, float InAccTime, float InStartValue, float InDiffValue, float InEndTime)
{
	// Currently we always use normalized distances
	const float Distance = 1.0f;

	// Currently we don't support custom start offsets;
	const float Start = 0.0f;
	float CurveValue = 0.0f;

	switch( EaseType )
	{
	case EAnimType::Linear:
		return InDiffValue * InAccTime / InEndTime + InStartValue;

	case EAnimType::QuadIn:
		InAccTime /= InEndTime;
		return InDiffValue * InAccTime * InAccTime + InStartValue;

	case EAnimType::QuadOut:
		InAccTime /= InEndTime;
		return -InDiffValue * InAccTime * (InAccTime - 2.f) + InStartValue;

	case EAnimType::QuadInOut:
		InAccTime /= InEndTime / 2.f;
		if (InAccTime < 1.f)
		{
			return InDiffValue / 2.f * InAccTime * InAccTime + InStartValue;
		}
		else
		{
			InAccTime--;
			return -InDiffValue / 2.f * (InAccTime * (InAccTime - 2.f) - 1.f) + InStartValue;
		}

	case EAnimType::QuadOutIn:
		if (InAccTime < InEndTime / 2)
		{
			float accTime = InAccTime * 2.f;
			float startValue = InStartValue;
			float diffValue = InDiffValue / 2.f;
			float endValue = InEndTime;
			accTime /= endValue;
			return -diffValue * accTime * (accTime - 2.f) + startValue;
		}
		else
		{
			float accTime = (InAccTime * 2.f) - InEndTime;
			float startValue = InStartValue + InDiffValue / 2.f;
			float diffValue = InDiffValue / 2.f;
			float endValue = InEndTime;
			accTime /= endValue;
			return diffValue * accTime * accTime + startValue;
		}
		
	case EAnimType::CubicIn:
		InAccTime /= InEndTime;
		return InDiffValue * InAccTime * InAccTime * InAccTime + InStartValue;
	
	case EAnimType::CubicOut:
		InAccTime = InAccTime / InEndTime - 1.f;
		return InDiffValue * (InAccTime * InAccTime * InAccTime + 1.f) + InStartValue;

	case EAnimType::CubicInOut:
		InAccTime /= InEndTime / 2.f;
		if (InAccTime < 1.f)
		{
			return InDiffValue / 2.f * InAccTime * InAccTime * InAccTime + InStartValue;
		}
		else
		{
			InAccTime -= 2.f;
			return InDiffValue / 2.f * (InAccTime * InAccTime * InAccTime + 2.f) + InStartValue;
		}

	case EAnimType::CubicOutIn:
		if (InAccTime < InEndTime / 2.f)
		{
			float accTime = InAccTime * 2.f;
			float startValue = InStartValue;
			float diffValue = InDiffValue / 2.f;
			float endValue = InEndTime;
			accTime = accTime / endValue - 1.f;
			return diffValue * (accTime * accTime * accTime + 1.f) + startValue;
		}
		else
		{
			float accTime = (InAccTime * 2.f) - InEndTime;
			float startValue = InStartValue + InDiffValue / 2.f;
			float diffValue = InDiffValue / 2.f;
			float endValue = InEndTime;
			accTime /= endValue;
			return diffValue * accTime * accTime * accTime + startValue;
		}

	default:
		// Unrecognized curve easing function type
		// checkf(0, TEXT("Unrecognized curve easing function type [%i] for FCurveHandle"), (int)inEaseFunction);
		break;
	}

	return CurveValue;
}