// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


// Typedef 모음
// 1. 추후 자료형 변경시 같은 타입들을 일괄 적용을 시키기 쉽도록 하기 위해 사용
// 
// 2. 전역적으로 사용하는 Typedef 및 Using 키워드 선언


typedef int64 FObjId;	// 오브젝트 고유 식별자	( 중복 불가능, 같은 몬스터라도 다른 아이디 )
typedef int32 FInfoId;	// 데이터 테이블 식별자 ( 중복 가능, 데이터 테이블에서 몬스터 정보 검색 용도 )

typedef std::function<void()> FSimpleCallback; // 기본적인 형태의 콜백 타입 void() 형태 함수