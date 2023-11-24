// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

// =========================================
// 사용법
/*
*	헤더에					Animator AnimName;
	Tick함수에				AnimName.Update( DeltaTime );
	애니메이션 발동 위치에		AnimName.Start();

*	param setting
	
*/
// =========================================


// 애니메이션 타입
// 엔진에서 제공하는 ECurveEaseFunction 와 같은 구조. #include <Animation/CurveHandle.h> 에 정의됨.
enum class EAnimType : uint8
{
	Linear,				// Linear interpolation, with no easing
	QuadIn,				// Quadratic ease in
	QuadOut,			// Quadratic ease out
	QuadInOut,			// Quadratic ease in, quadratic ease out
	CubicIn,			// Cubic ease in
	CubicOut,			// Cubic ease out
	CubicInOut,			// Cubic ease in, cubic ease out
};

typedef std::function<void( float )> CallbackType;

// 애니메이터 파람
class AnimatorParam
{
public:
	float StartValue;				// 애니메이팅 시작값
	float EndValue;					// 애니메이팅 최종값
	
	float DurationTime;				// 애니메이터의 지속 시간 (= 종료 시간)
	
	EAnimType AnimType;				// 애니메이션 타입
	
	CallbackType DurationFunc;		// 값 반환 콜백함수

public:
	AnimatorParam();
};

// 특정 시간동안 시작값과 최종값 사이의 보간 애니메이션을 위한 애니메이터
class Animator
{
private:
	AnimatorParam Param;
	
	float StartValue;				// 애니메이팅 시작값
	float CurValue;					// 애니메이팅 현재값
	float EndValue;					// 애니메이팅 최종값
	
	float AccTime;					// 현재 시간
	float DurationTime;				// 애니메이터의 지속 시간 (= 종료 시간)
public:
	// 생성자
	Animator();

	// 파라미터 Setter // 애니메이션이 실행 중이면 세팅하지 않습니다.
	void SetParam(const AnimatorParam& InParam);
	
	// 애니메이션 업데이트
	void Update( float InDeltaTime );
	
	// 애니메이션 시작
	void Start();

	// 시간, 애니메이션 타입에 따라 애니메이팅
	// 엔진에서 제공하는 ApplyEasing 와 같은 구조. #include <Animation/CurveHandle.h> 에 정의됨.
	static float ApplyEasing(float inTime, EAnimType EaseType);
};