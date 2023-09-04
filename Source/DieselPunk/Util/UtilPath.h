// Copyright GuardiansW. All Rights Reserved.
//
// 스텟 관련 편의 함수 모음


#pragma once


namespace UtilPath
{
	// 캐릭터 클래스의 경로를 반환한다. ( 레퍼런스 복사 + _C 형태 )
	FString GetCharacterPath( const FString& InPath );

	// UI의 경로를 반환한다. ( 레퍼런스 복사 + _C 형태 )
	FString GetUIPath( const FString& InPath );

	// 데이터 테이블의 레퍼런스 경로를 반환한다
	FString GetDataTablePath( const FString& InFileName );

	// 커브 플롯 데이터의 레퍼런스 경로를 반환한다
	FString GetCurveFloatPath( const FString& InFileName );

	// 발자국 연출 데이터 에셋의 레퍼런스 경로를 반환한다
	FString GetPhysicalSurfacePath( EPhysicalSurfaceType InType );

	// 데이터 에셋의 레퍼런스 경로를 반환한다
	FString GetDataAssetPath( const FString& InFileName );

	// Player 관련 데이터 에셋의 레퍼런스 경로를 반환한다
	FString GetPlayerDataAssetPath( const FString& InFileName );
	
	// /임시/스킬 및 스킬 액터의 경로를 반환한다. ( 레퍼런스 복사 + _C 형태 )
	FString GetSkillPath( const FString& InPath );
}