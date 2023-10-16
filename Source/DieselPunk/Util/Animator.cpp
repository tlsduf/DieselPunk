// Fill out your copyright notice in the Description page of Project Settings.


#include "Animator.h"


// =============================================================
// 디폴트 생성자
// =============================================================
Animator::Animator()
	: AnimType( ECurveEaseFunction::Linear )
	, StartValue( 0.f )
	, CurValue( 0.f )
	, EndValue( 0.f )
	, AccTime( 1.f )
	, DurationTime( 1.f )
{

}

// =============================================================
// 생성자
// =============================================================
Animator::Animator(const float inStartValue, const float inEndValue, const float inDurationTime, ECurveEaseFunction inAnimType)
	: AnimType( inAnimType )
	, StartValue( inStartValue )
	, CurValue( 0.f )
	, EndValue( inEndValue )
	, AccTime( inDurationTime )
	, DurationTime( inDurationTime )
{

}

// =============================================================
// 파라미터 Setter [TODO] 애니메이션이 실행중일때 호출되면 어떻게 되는지? 예외처리를 해야하는지?
// =============================================================
void Animator::SetParam(const float inStartValue, const float inEndValue, const float inDurationTime, ECurveEaseFunction inAnimType)
{
	AnimType = inAnimType;
	StartValue = inStartValue;
	EndValue = inEndValue;
	AccTime = inDurationTime;
	DurationTime = inDurationTime;
}

// =============================================================
// 애니메이션 업데이트
// =============================================================
void Animator::Update(float InDeltaTime)
{
	if ( AccTime >= DurationTime )
	{
		CalCurValue(1);
		return;
	}
	
	AccTime += InDeltaTime;
	
	const float Time = FMath::Clamp(AccTime / DurationTime, 0.0f, 1.0f);
	CalCurValue(Time);
}

// =============================================================
// 파라미터 값에 따라 CurValue 설정 //inTime 은 0.f ~ 1.f
// =============================================================
void Animator::CalCurValue(float inTime)
{
	CurValue = StartValue + ((EndValue - StartValue) * AnimCurve.ApplyEasing(inTime, AnimType));
}

// =============================================================
// 애니메이터 시작
// =============================================================
void Animator::Start()
{
	AccTime = 0;
}

// =============================================================
// CurValue 반환
// =============================================================
float Animator::GetCurValue()
{
	return CurValue;
}
