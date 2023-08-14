// Copyright GuardiansW. All Rights Reserved.


#include "ObjectManager.h"
#include "../Character/CharacterPC.h"
#include "../Character/CharacterNPC.h"
#include "../Core/DpGameDelegate.h"
#include "../Data/Info/CharacterInfo.h"
#include "../Util/UtilEffect.h"
#include "../Util/UtilPath.h"
#include <GameFramework/Actor.h>
#include <GameFramework/PlayerController.h>
#include <UObject/UObjectGlobals.h>
#include <TimerManager.h>

// =============================================================
// 생성자
// =============================================================
FObjectManager::FObjectManager()
:
IdGenerator( 10000, 1000000 ),
Player( nullptr ),
UpdateInterval( 1.f )
{
	
}

// =============================================================
// 소멸자
// =============================================================
FObjectManager::~FObjectManager()
{

}

// =============================================================
// 초기화
// =============================================================
void FObjectManager::InitSingleton()
{
	FDpGameDelegate::Get().GetDelegateWorldMoveFinished().AddRaw( this, &FObjectManager::OnWorldMoveFinished );
}

// =============================================================
// 데이터 정리
// =============================================================
void FObjectManager::ClearSingleton()
{
	for ( auto& actorPair : Objects )
	{
		FActorPtr& actorPtr = actorPair.Value;
		if ( !actorPtr.IsValid() )
			continue;

		DestroyActor( actorPtr.Get() );
	}

	Objects.Empty();
	IdGenerator.Reset();
	UpdateInterval.Reset();
	Player = nullptr;
}

// =============================================================
// Tick
// =============================================================
void FObjectManager::Tick(float InDeltaTime)
{
	if ( UpdateInterval.Tick( InDeltaTime ) )
	{

	}
}

// =============================================================
// GetStatId ( FTickableGameObject 필수 인터페이스 )
// =============================================================
TStatId FObjectManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FObjectManager, STATGROUP_Tickables);
}

// =============================================================
// 월드 이동이 완료되었음을 알린다.
// =============================================================
void FObjectManager::OnWorldMoveFinished()
{
	ACharacterPC* player = GetCurrentPlayer();
	if ( !player )
		return;
	
	if ( Player == player )
		return;

	FObjId ObjId = GeneratorObjId();
	player->SetObjId( ObjId );
	Player = player;
	Objects.Add( ObjId, player );

	UtilEffect::ActivateDecorator( player, EDecorateUseType::Spawn );
}

// =============================================================
// 매니저가 관리하지 않던 액터를 매니저에 등록한다.
// 
// 추후 삭제 될 수 있음
// =============================================================
void FObjectManager::RegisterObject( FObjId InObjId, AActor* InActor )
{
	if ( !InActor )
		return;

	if ( FindActor( InObjId ) )
		return;

	Objects.Add( InObjId, InActor );
}

// =============================================================
// 캐릭터를 스폰한다.
// 
// 새로운 타입의 오브젝트가 생성되는 경우 아래 조건문에서 함수를 연결하도록 합시다
// =============================================================
AActor* FObjectManager::SpawnActorDeferred( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam )
{
	TRACE_CPUPROFILER_EVENT_SCOPE( FObjectManager::SpawnActorDeferred );

	// 중복 체크, 만약 있다면 액터 갱신
	AActor* newActor = FindActor( InObjId );
	if ( newActor )
	{
		newActor->SetActorLocationAndRotation( InParam.Location, InParam.Rotation );
		return newActor;
	}

	newActor = _SpawnActorDeferred( InType, InObjId, InParam );
	if ( !newActor )
		return nullptr;

	Objects.Add( InObjId, newActor );

	FDpGameDelegate::Get().GetDelegateActorSpawned().Broadcast( newActor, InObjId );

	return newActor;
}

// =============================================================
// 액터를 스폰하되 관리하지 않는다.
// =============================================================
AActor* FObjectManager::SpawnUnmanagedActor( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam )
{
	TRACE_CPUPROFILER_EVENT_SCOPE( FObjectManager::SpawnUnmanagedActor );

	// 관리 대상이 아니기 때문에 중복 체크도 필요가 없을 것
	// 일단 관리하려는 녀석들만 델리게이트 브로드캐스트
	return _SpawnActorDeferred( InType, InObjId, InParam );
}

// =============================================================
// 액터를 찾아 반환한다.
// =============================================================
AActor* FObjectManager::FindActor( FObjId InObjId )
{
	const FActorPtr* actorPtr = Objects.Find( InObjId );
	if ( !actorPtr || !actorPtr->IsValid() )
		return nullptr;

	return actorPtr->Get();
}

// =============================================================
// 캐릭터를 찾아 반환한다.
// =============================================================
ACharacterBase* FObjectManager::FindCharacter( FObjId InObjId )
{
	const FActorPtr* actorPtr = Objects.Find( InObjId );
	if( !actorPtr || !actorPtr->IsValid() )
		return nullptr;

	ACharacterBase* character = Cast<ACharacterBase>( actorPtr->Get() );
	if ( !character )
		return nullptr;

	return character;
}

// =============================================================
// 오브젝트를 삭제한다.
// =============================================================
void FObjectManager::DestroyActor( FObjId InObjId )
{
	AActor* actor = FindActor( InObjId );
	if ( !actor )
		return;

	UtilEffect::ActivateDecorator( actor, EDecorateUseType::Despawn );

	DestroyActor( actor );

	Objects.Remove( InObjId );
}

// =============================================================
// 액터를 삭제처리 한다.
// =============================================================
void FObjectManager::DestroyActor( AActor* InActor )
{
	if ( !InActor )
		return;

	InActor->ForEachComponent( true, [] ( UActorComponent* InComp )
	{
		if ( !InComp )
			return;

		InComp->Deactivate();
	} );

	if ( ACharacterBase* character = Cast<ACharacterBase>( InActor ) )
	{
		// ACharacterBase 정리 로직 ex) 컴포넌트들

		if ( ACharacterPC* characterPC = Cast<ACharacterPC>( character ) )
		{
			// ACharacterPC 정리 로직
		}
		else if ( ACharacterNPC* characterNPC = Cast<ACharacterNPC>( character ) )
		{
			// ACharacterNPC 정리 로직
		}
	}

	FDpGameDelegate::Get().GetDelegateActorDespawned().Broadcast( InActor );

	InActor->SetActorHiddenInGame( true );
	InActor->Destroy();
}

// =============================================================
// 현재 내 캐릭터를 반환한다.
// =============================================================
ACharacterPC* FObjectManager::GetCurrentPlayer()
{
	if ( Player.IsValid() )
		return Player.Get();

	APlayerController* playerController = DpGetPlayerController();
	if ( !playerController )
		return nullptr;

	ACharacterPC* player = Cast<ACharacterPC>( playerController->GetCharacter() );
	if ( !player )
		return nullptr;

	return player;
}

// =============================================================
// 모든 Actor 에 대해 Predicate 함수를 수행한다
// =============================================================
void FObjectManager::ForEachActor( const TFunction<void( AActor* )>& InPred )
{
	if ( !InPred )
		return;

	for ( auto& [objId, actorPtr] : Objects )
	{
		if( !actorPtr.IsValid() ) 
			continue;

		InPred( actorPtr.Get() );
	}
}

// =============================================================
// Predicate 함수가 True 인 모든 Actor를 반환한다.
// 임시 객체가 불필요하게 복사생성 되지 않도록 인자의 OutObjectList 를 사용
// =============================================================
void FObjectManager::GetActorsByPredicate( TArray<AActor*>& OutObjectList, const TFunction<bool( AActor* )>& InPred )
{
	if ( !InPred )
		return;

	for ( auto& [objId, actorPtr] : Objects )
	{
		if ( !actorPtr.IsValid() )
			continue;

		if ( !InPred( actorPtr.Get() ) )
			continue;

		OutObjectList.Add( actorPtr.Get() );
	}
}

// =============================================================
// 현재 플레이어로부터 가장 가까운 Actor 를 반환한다.
// =============================================================
AActor* FObjectManager::GetNearestActor()
{
	AActor* nearestActor = nullptr;

	if ( !Player.IsValid() )
		return nearestActor;

	float minDistance = FLT_MAX;
	for ( auto& [objId, actorPtr] : Objects )
	{
		if ( !actorPtr.IsValid() )
			continue;

		AActor* actor = actorPtr.Get();
		float distance = FVector::Dist( actor->GetActorLocation(), Player.Get()->GetActorLocation() );
		if ( minDistance < distance )
			continue;

		minDistance = distance;
		nearestActor = actor;
	}
	return nearestActor;
}

// =============================================================
// 현재 액터로부터 가장 가까운 Actor 를 반환한다.
// =============================================================
AActor* FObjectManager::GetNearestActor(AActor* InThisActor)
{
	AActor* nearestActor = nullptr;

	if ( !Player.IsValid() )
		return nearestActor;

	float minDistance = FLT_MAX;
	for ( auto& [objId, actorPtr] : Objects )
	{
		if ( !actorPtr.IsValid() )
			continue;

		AActor* actor = actorPtr.Get();
		float distance = FVector::Dist( actor->GetActorLocation(), InThisActor->GetActorLocation() );
		if ( minDistance < distance )
			continue;

		minDistance = distance;
		nearestActor = actor;
	}
	return nearestActor;
}

// =============================================================
// 캐릭터를 스폰한다.
// 
// 새로운 타입의 오브젝트가 생성되는 경우 아래 조건문에서 함수를 연결하도록 합시다
// =============================================================
AActor* FObjectManager::_SpawnActorDeferred( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam )
{
	TRACE_CPUPROFILER_EVENT_SCOPE( FObjectManager::_SpawnActorDeferred );

	AActor* newActor = nullptr;

	switch ( InType )
	{
	case EObjectType::Pc:
	newActor = _SpawnPC( InType, InObjId, InParam );
	break;
	case EObjectType::Npc:
	case EObjectType::Monster:
	newActor = _SpawnNPC( InType, InObjId, InParam );
	break;
	}

	if ( !newActor )
		return nullptr;

	if ( InParam.InitFunc )
		InParam.InitFunc( newActor );

	newActor->FinishSpawning( FTransform( InParam.Rotation, InParam.Location ) );

	UtilEffect::ActivateDecorator( newActor, EDecorateUseType::Spawn );

	return newActor;
}

// =============================================================
// PC를 스폰한다.
// =============================================================
ACharacterPC* FObjectManager::_SpawnPC( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam )
{
	FCharacterInfoPtr characterInfo( InParam.InfoId );
	if( !characterInfo )
		return nullptr;

	FString resourcePath = UtilPath::GetCharacterPath( characterInfo->Path );
	UClass* classInfo = LoadClass<ACharacterPC>( NULL, *resourcePath );
	if ( !classInfo )
	{
		LOG_SCREEN_COLOR( FColor::Red, TEXT( "Fail Spawn PC !! ( Path : %s )" ), *resourcePath );
		return nullptr;
	}

	ACharacterPC* newActor = DpGetWorld()->SpawnActorDeferred<ACharacterPC>( classInfo, FTransform( InParam.Rotation, InParam.Location ), nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn );
	if ( !newActor )
		return nullptr;

	newActor->SetObjId( InObjId );
	newActor->SetInfoId( InParam.InfoId );

	return newActor;
}

// =============================================================
// NPC를 스폰한다.
// =============================================================
ACharacterNPC* FObjectManager::_SpawnNPC( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam )
{
	FCharacterInfoPtr characterInfo( InParam.InfoId );
	if ( !characterInfo )
		return nullptr;

	FString resourcePath = UtilPath::GetCharacterPath( characterInfo->Path );
	UClass* classInfo = LoadClass<ACharacterNPC>( NULL, *resourcePath );
	if ( !classInfo )
	{
		LOG_SCREEN_COLOR( FColor::Red, TEXT( "Fail Spawn NPC !! ( Path : %s )" ), *resourcePath );
		return nullptr;
	}

	ACharacterNPC* newActor = DpGetWorld()->SpawnActorDeferred<ACharacterNPC>( classInfo, FTransform( InParam.Rotation, InParam.Location ), nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn );
	if ( !newActor )
		return nullptr;

	newActor->SetObjId( InObjId );
	newActor->SetInfoId( InParam.InfoId );
	
	return newActor;
}

// =============================================================
// 플레이어를 세팅한다.
// =============================================================
void FObjectManager::_SetPlayer( ACharacterPC* InPlayer )
{
	if ( !InPlayer )
	{
		LOG_SCREEN_COLOR( FColor::Red, TEXT( "Player is nullptr!!" ) );
		return;
	}

	Player = InPlayer;
	Objects.Add( InPlayer->GetObjId(), InPlayer );
}
