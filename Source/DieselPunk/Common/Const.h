// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "Typedef.h"


// Const 상수값 모음


// =============================================================
// 공통으로 사용되는 상수 모음
// 별도의 namespace 가 없기 때문에 G_ 붙여주세요
// =============================================================
const static FObjId	 G_InvalidObjId  = 0;	// 유효하지 않은 오브젝트 식별자
const static FInfoId G_InvalidInfoId = 0;	// 유효하지 않은 데이터 식별자


// =============================================================
// UI 관련 상수 모음
// =============================================================
namespace UIConst
{
	const static int32 DefaultZ       = 0;   // 기본 Z Order
	const static int32 ScreenMessageZ = 80;  // 화면 메시지 Z Order
	const static int32 TopZ           = 100; // 최상단 Z Order
}