// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilPath.h"
#include "UtilEnum.h"


// =============================================================
// 캐릭터 클래스의 경로를 반환한다. ( 레퍼런스 복사 + _C 형태 )
// 
// Character 폴더 기준으로 레퍼런스 경로를 구현한다.
// ex) .../Character/NPC/BP_Test 인 경우 NPC/BP_Test 만 입력하면 동작함
// =============================================================
FString UtilPath::GetCharacterPath( const FString& InPath )
{
	FString bpName = TEXT( "" );
	FString folderPath = TEXT( "" );
	bool useFolder = InPath.Split( TEXT( "/" ), &folderPath, &bpName, ESearchCase::CaseSensitive, ESearchDir::FromEnd );

	FString resourcePath;

	if ( useFolder )
		resourcePath = FString::Printf( TEXT( "/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/%s/%s.%s'" ), *folderPath, *bpName, *bpName );
	else
		resourcePath = FString::Printf( TEXT( "/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/%s.%s'" ), *InPath, *InPath );

	resourcePath.RemoveAt( resourcePath.Len() - 1 );

	return FString::Printf( TEXT( "%s_C'" ), *resourcePath );
}

// =============================================================
// UI의 경로를 반환한다. ( 레퍼런스 복사 + _C 형태 )
// 
// Widgets 폴더 기준으로 레퍼런스 경로를 구현한다.
// ex) .../Widgets/HUD/BP_Test 인 경우 HUD/BP_Test 만 입력하면 동작함
// =============================================================
FString UtilPath::GetUIPath( const FString& InPath )
{
	FString bpName = TEXT( "" );
	FString folderPath = TEXT( "" );
	bool useFolder = InPath.Split( TEXT( "/" ), &folderPath, &bpName, ESearchCase::CaseSensitive, ESearchDir::FromEnd );

	FString resourcePath;

	if( useFolder )
		resourcePath = FString::Printf( TEXT( "/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/UI/Widgets/%s/%s.%s'" ), *folderPath, *bpName, *bpName );
	else
		resourcePath = FString::Printf( TEXT( "/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/UI/Widgets/%s.%s'" ), *InPath, *InPath );

	resourcePath.RemoveAt( resourcePath.Len() - 1 );

	return FString::Printf( TEXT( "%s_C'" ), *resourcePath );
}

// =============================================================
// 데이터 테이블의 레퍼런스 경로를 반환한다
// 
// 파일 이름을 넣어주세요
// Game/Data/DataTable 폴더에 없는 경우 찾을 수 없습니다
// =============================================================
FString UtilPath::GetDataTablePath( const FString& InFileName )
{
	FString resourcePath = FString::Printf( TEXT( "/Script/Engine.DataTable'/Game/DieselPunk/Data/DataTable/%s.%s'" ), *InFileName, *InFileName );
	return resourcePath;
}

// =============================================================
// 커브 플롯의 레퍼런스 경로를 반환한다
// 
// 파일 이름을 넣어주세요
// Game/Data/Curve 폴더에 없는 경우 찾을 수 없습니다
// =============================================================
FString UtilPath::GetCurveFloatPath( const FString& InFileName )
{
	FString resourcePath = FString::Printf( TEXT( "/Script/Engine.CurveFloat'/Game/DieselPunk/Data/Curve/%s.%s'" ), *InFileName, *InFileName );
	return resourcePath;
}

// =============================================================
// 발자국 연출 데이터 에셋의 레퍼런스 경로를 반환한다
// 
// 파일 이름을 넣어주세요
// Game/Data/DataAsset/Footstep 폴더에 없는 경우 찾을 수 없습니다
// =============================================================
FString UtilPath::GetPhysicalSurfacePath( EPhysicalSurfaceType InType )
{
	FString fileName = FString::Printf( TEXT( "DA_Footstep_%s" ), *ENUM_TO_STRING( EPhysicalSurfaceType, InType ) );
	FString resourcePath = FString::Printf( TEXT( "/Script/Engine.GwDataAssetForFootstep'/Game/DieselPunk/Data/DataAsset/Footstep/%s.%s'" ), *fileName, *fileName );

	return resourcePath;
}

// =============================================================
// 데이터 에셋의 레퍼런스 경로를 반환한다
// 
// 파일 이름을 넣어주세요
// Game/Data/DataAsset 폴더에 없는 경우 찾을 수 없습니다
// =============================================================
FString UtilPath::GetDataAssetPath( const FString& InFileName )
{
	FString resourcePath = FString::Printf( TEXT( "/Script/Engine.DataAsset'/Game/DieselPunk/Data/DataAsset/%s.%s'" ), *InFileName, *InFileName );
	return resourcePath;
}