// Fill out your copyright notice in the Description page of Project Settings.


#include "Animator.h"


// =============================================================
// 생성자
// =============================================================
Animator::Animator()
	: AnimType( EAnimType::Linear )
	, StartValue( 0.f )
	, CurValue( 0.f )
	, EndValue( 0.f )
	, AccTime( 1.f )
	, DurationTime( 1.f )
{

}

// =============================================================
// 파라미터 Setter [TODO] 애니메이션이 실행중일때 호출되면 어떻게 되는지? 예외처리를 해야하는지?
// =============================================================
void Animator::SetParam(const float inStartValue, const float inEndValue, const float inDurationTime, EAnimType inAnimType)
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
	CurValue = StartValue + ((EndValue - StartValue) * ApplyEasing(inTime, AnimType));
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


// =============================================================
// 시간, 애니메이션 타입에 따라 애니메이팅
// =============================================================
float Animator::ApplyEasing( float inTime, EAnimType inEaseFunction )
{
	// Currently we always use normalized distances
	const float Distance = 1.0f;

	// Currently we don't support custom start offsets;
	const float Start = 0.0f;
	float CurveValue = 0.0f;

	switch( inEaseFunction )
	{
	case EAnimType::Linear:
		CurveValue = Start + Distance * inTime;
		break;

	case EAnimType::QuadIn:
		CurveValue = Start + Distance * inTime * inTime;
		break;

	case EAnimType::QuadOut:
		CurveValue = Start + -Distance * inTime * (inTime - 2.0f);
		break;

	case EAnimType::QuadInOut:
		{
			if( inTime < 0.5f )
			{
				const float Scaled = inTime * 2.0f;
				CurveValue = Start + Distance * 0.5f * Scaled * Scaled;
			}
			else
			{
				const float Scaled = (inTime - 0.5f) * 2.0f;
				CurveValue = Start + -Distance * 0.5f * (Scaled * (Scaled - 2.0f) - 1.0f);
			}
		}
		break;

	case EAnimType::CubicIn:
		CurveValue = Start + Distance * inTime * inTime * inTime;
		break;

	case EAnimType::CubicOut:
		{
			const float Offset = inTime - 1.0f;
			CurveValue = Start + Distance * (Offset * Offset * Offset + 1.0f);
		}
		break;

	case EAnimType::CubicInOut:
		{
			float Scaled = inTime * 2.0f;
			if (Scaled < 1.0f)
			{
				CurveValue = Start + Distance / 2.0f * Scaled * Scaled * Scaled;
			}
			else
			{
				Scaled -= 2.0f;
				CurveValue = Start + Distance / 2.0f * (Scaled * Scaled * Scaled + 2.0f);
			}
		}
		break;

	default:
		// Unrecognized curve easing function type
		// checkf(0, TEXT("Unrecognized curve easing function type [%i] for FCurveHandle"), (int)inEaseFunction);
		break;
	}

	return CurveValue;
}