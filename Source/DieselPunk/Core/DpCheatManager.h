// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <GameFramework/CheatManager.h>
#include "DpCheatManager.generated.h"


// =============================================================
// 치트 매니저
// 
// ` 콘솔 창을 이용한 치트를 이곳에서 정의하여 호출할 수 있습니다
// UFUNCTION( exec ) 키워드를 사용해주세요
// =============================================================
UCLASS( Within=PlayerController )
class DIESELPUNK_API UDpCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	// 생성자
	UDpCheatManager();

	// 소멸자
	~UDpCheatManager();

	// 테스트용 치트 - 단순 로그 출력
	UFUNCTION(exec)
	void TestLog( const FString& InMsg );

	// 테스트용 치트 - 그룹 데이터 출력
	UFUNCTION( exec )
	void TestDataTable( int32 InGroupId );

	// 테스트용 치트 - UI 생성
	UFUNCTION( exec )
	void TestUI( FString InPath );

	// 테스트용 치트 - PC 생성
	UFUNCTION( exec )
	void SpawnCharacterPC( int32 inInfoId );

	// 테스트용 치트 - NPC 생성
	UFUNCTION( exec )
	void SpawnCharacterNPC( int32 inInfoId );

	// 테스트용 치트 - 액터 삭제
	UFUNCTION( exec )
	void DestroyActor( int64 InObjId );

	// 테스트용 치트 - 버프 생성
	//UFUNCTION( exec )
	//void AddBuffForPlayer( int64 InObjId, int64 InBuffId );

	// 테스트용 치트 - 레벨 업
	UFUNCTION( exec )
	void LevelUp();

	// 테스트용 치트 - 풀HP
	UFUNCTION( exec )
	void GetHP();
};
