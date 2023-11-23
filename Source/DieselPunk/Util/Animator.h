// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

// =========================================
// 사용법
/*
	헤더에					Animator AnimName; 선언
	Tick함수에				AnimName.Update( DeltaTime ); 선언
	애니메이션 발동 위치에		AnimName.Start(); 선언
							AnimName.GetCurValue(); 값 활용
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


// 특정 시간동안 시작값과 최종값 사이의 보간 애니메이션을 위한 애니메이터
class Animator
{
private:
	EAnimType AnimType;				// 애니메이션 타입
	
	float StartValue;				// 애니메이팅 시작값
	float CurValue;					// 애니메이팅 현재값 
	float EndValue;					// 애니메이팅 최종값

	float AccTime;					// 현재 시간
	float DurationTime;				// 애니메이터의 지속 시간 (= 종료 시간)
	
public:
	// 생성자
	Animator();

	// 파라미터 Setter [TODO] 애니메이션이 실행중일때 호출되면 어떻게 되는지? 예외처리를 해야하는지?
	void SetParam(const float inStartValue, const float inEndValue, const float inDurationTime , EAnimType inAnimType);
	
	// 애니메이션 업데이트
	void Update( float InDeltaTime );
	
	// 파라미터 값에 따라 CurValue 설정 //inTime 은 0.f ~ 1.f
	void CalCurValue(float inTime);
	
	// 애니메이션 시작
	void Start();
	
	// CurValue 반환
	float GetCurValue();

	// 시간, 애니메이션 타입에 따라 애니메이팅
	// 엔진에서 제공하는 ApplyEasing 와 같은 구조. #include <Animation/CurveHandle.h> 에 정의됨.
	static float ApplyEasing(float inTime, EAnimType EaseType);
};