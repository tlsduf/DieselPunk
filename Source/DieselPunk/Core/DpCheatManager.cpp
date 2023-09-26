// Fill out your copyright notice in the Description page of Project Settings.

#include "DpCheatManager.h"
#include "../Character/CharacterPC.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DataTableManager.h"
#include "../Manager/UIManager.h"
#include "../Data/Info/TestInfo.h"
//#include "../Util/UtilStat.h"
#include "../Util/UtilPath.h"
#include "../UI/TestUI.h"
//#include "../Handler/BuffHandler.h"


#include "DieselPunk/Util/UtilLevelCal.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpCheatManager)


// =============================================================
// 생성자
// =============================================================
UDpCheatManager::UDpCheatManager()
{

}

// =============================================================
// 소멸자
// =============================================================
UDpCheatManager::~UDpCheatManager()
{

}

// =============================================================
// 테스트용 치트 - 단순 로그 출력
// =============================================================
void UDpCheatManager::TestLog( const FString& InMsg )
{
	LOG_SCREEN( TEXT( "TestLog Cheat!! : %s" ), *InMsg );
}

// =============================================================
// 테스트용 치트 - 그룹 데이터 출력
// =============================================================
void UDpCheatManager::TestDataTable( int32 InGroupId )
{
	const TArray<const FTestInfo*>* testInfoGroup1 = GetDataTableManager().GetTestInfoGroup( InGroupId );
	if ( !testInfoGroup1 )
		return;

	for ( const FTestInfo* info : *testInfoGroup1 )
	{
		if ( !info )
			continue;

		LOG_SCREEN( TEXT( "%s" ), *info->TestString );
	}

	FTestInfoGroupPtr testInfoGroup2( InGroupId );
	if ( !testInfoGroup2 )
		return;

	for ( const FTestInfo* info : *testInfoGroup2 )
	{
		if ( !info )
			continue;

		LOG_SCREEN( TEXT( "%s" ), *info->TestString );
	}
}

// =============================================================
// 테스트용 치트 - UI 생성
// =============================================================
void UDpCheatManager::TestUI( FString InPath )
{
	UTestUI* testUI = GetUIManager().CreateUI< UTestUI >( InPath );

	GetUIManager().ShowUI( testUI );
}

// =============================================================
// 테스트용 치트 - PC 생성
// =============================================================
void UDpCheatManager::SpawnCharacterPC( FInfoId inInfoId )
{
	ACharacterPC* player = GetObjectManager().GetCurrentPlayer();
	if ( !player )
		return;

	FVector location = player->GetActorLocation();
	location += player->GetActorForwardVector() * 200.f;

	FActorSpawnParam spawnParam;
	spawnParam.InfoId = inInfoId;
	spawnParam.Location = location;

	FObjId objId = GetObjectManager().GeneratorObjId();

	GetObjectManager().SpawnActorDeferred( EObjectType::Pc, objId, spawnParam );
}

// =============================================================
// 테스트용 치트 - NPC 생성
// =============================================================
void UDpCheatManager::SpawnCharacterNPC( FInfoId inInfoId )
{
	ACharacterPC* player = GetObjectManager().GetCurrentPlayer();
	if ( !player )
		return;

	FVector location = player->GetActorLocation();
	location += player->GetActorForwardVector() * 200.f;

	FActorSpawnParam spawnParam;
	spawnParam.InfoId = inInfoId;
	spawnParam.Location = location;

	FObjId Objid = GetObjectManager().GeneratorObjId();

	GetObjectManager().SpawnActorDeferred( EObjectType::Npc, Objid, spawnParam );
}

// =============================================================
// 테스트용 치트 - 액터 삭제
// =============================================================
void UDpCheatManager::DestroyActor( FObjId InObjId )
{
	GetObjectManager().DestroyActor( InObjId );
}

/*void UGwCheatManager::AddBuffForPlayer(FObjId InObjId, int64 InBuffId)
{
	AActor* target = GetObjectManager().FindActor(InObjId);
	if(!target)
		return;

	ACharacterBase* targetCharacter = Cast<ACharacterBase>(target);
	if(!targetCharacter)
		return;

	BuffAdditionalData(FBuffStat) InAddi;
	InAddi.StatType = EActorStatType::Hp;
	InAddi.BuffValue = -10;
	InAddi.BuffPerValue = 1;
	InAddi.Restore = false;
	InAddi.TargetIsOwner = true;
	InAddi.BuffDot = true;

	InAddi.Interval = 1.f;
	
	
	targetCharacter->AddBuff(InBuffId, InAddi);
}*/


// =============================================================
// 테스트용 치트 - 레벨 업
// =============================================================
void UDpCheatManager::LevelUp()
{
	APlayerController* playerController = DpGetPlayerController();
	if ( !playerController )
		return;

	ACharacterPC* player = Cast<ACharacterPC>( playerController->GetCharacter() );
	if ( !player )
		return;

	player->Level = player->Level + 1;
	player->Exp = UtilLevelCal::MaxExpCal(player->Level - 1);
	player->MaxHealth = UtilLevelCal::MaxHealthCal(player->Level);
}