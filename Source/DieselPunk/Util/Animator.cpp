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
{
	
}

// =============================================================
// 생성자
// =============================================================
Animator::Animator()
	: Param( AnimatorParam() )
	, StartValue( 0.f )
	, CurValue( 0.f )
	, EndValue( 0.f )
	, AccTime( 1.f )
	, DurationTime( 1.f )
{

}

// =============================================================
// 파라미터 Setter // 애니메이션이 실행 중이면 세팅하지 않습니다.
// =============================================================
void Animator::SetParam(const AnimatorParam& InParam)
{
	if(IsRunning())
		return;
	
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
	if ( AccTime >= DurationTime )
	{
		CurValue = StartValue + ((EndValue - StartValue) * ApplyEasing(1, Param.AnimType));
		return;
	}
	
	AccTime += InDeltaTime;
	
	const float Time = FMath::Clamp(AccTime / DurationTime, 0.0f, 1.0f);
	
	CurValue = StartValue + ((EndValue - StartValue) * ApplyEasing(Time, Param.AnimType));

	if(Param.DurationFunc)
		Param.DurationFunc( CurValue );
}

// =============================================================
// 애니메이터 시작
// =============================================================
void Animator::Start()
{
	AccTime = 0;
}

// =============================================================
// 애니메이션 중지
// =============================================================
void Animator::Stop()
{
	AccTime = DurationTime;
}

// =============================================================
// 애니메이션이 실행중인가?
// =============================================================
bool Animator::IsRunning()
{
	return (AccTime != DurationTime);
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