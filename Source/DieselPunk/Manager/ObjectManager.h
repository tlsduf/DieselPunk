// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../Core/SingletonBase.h"
#include <Tickable.h>


class AActor;
class ACharacterBase;
class ACharacterNPC;
class ACharacterPC;


struct FActorSpawnParam
{
	// FinishSpawning 함수가 실행되기 전 호출 할 이벤트
	// ( 별도의 초기화 로직이 필요한 경우 람다로 연결해서 사용 )
	// ex) spawnParam.InitFunc = []( AActor* ) { AActor->SetActorLocation( vector ); }
	typedef std::function<void( AActor* )> CallbackType;

	FInfoId			InfoId		= G_InvalidInfoId;
	FVector			Location	= FVector::ZeroVector;
	FRotator		Rotation	= FRotator::ZeroRotator;

	CallbackType	InitFunc	= nullptr;
};


// 오브젝트 관리자 : 월드의 모든 오브젝트는 해당 클래스가 관리하도록
// Tick 을 사용하는 Singleton 클래스는 FTickableGameObject 을 상속받아서 Tick 을 override 해서 쓰면 됨
class FObjectManager : public TSingletonBase<FObjectManager>, public FTickableGameObject
{
private:
	typedef TWeakObjectPtr<AActor> FActorPtr;
	typedef TWeakObjectPtr<ACharacterPC> FCharacterPcPtr;

private:
	TIdGenerator<FObjId>	IdGenerator;	// 오브젝트 고유 아이디 생성기
	
	TMap<FObjId, FActorPtr>	Objects;		// 관리하는 오브젝트 목록
	FCharacterPcPtr			Player;			// 현재 플레이어 액터

	FIntervalTimer			UpdateInterval;	// 업데이트 주기

public:
	// 생성자
	FObjectManager();

	// 소멸자
	virtual ~FObjectManager();

	// 초기화
	virtual void InitSingleton() override;

	// 데이터 정리
	virtual void ClearSingleton() override;

	// Tick
	virtual void Tick(float InDeltaTime) override;

	// GetStatId ( FTickableGameObject 인터페이스 )
	virtual TStatId GetStatId() const override;

	// 월드 이동이 완료되었음을 알린다.
	void OnWorldMoveFinished();

	// 매니저가 관리하지 않던 액터를 매니저에 등록한다.
	void RegisterObject( FObjId InObjId, AActor* InActor );

	// 액터를 스폰한다.
	AActor* SpawnActorDeferred( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam );

	// 액터를 스폰하되 관리하지 않는다.
	AActor* SpawnUnmanagedActor( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam );

	// 액터를 스폰한다.
	template<typename Type>
	Type* SpawnActorDeferredByClass( UClass* InClass, FObjId InObjId, const FActorSpawnParam& InParam, bool InManaged = true );

	// 액터를 찾아 반환한다.
	AActor* FindActor( FObjId InObjId );

	// 캐릭터를 찾아 반환한다.
	ACharacterBase* FindCharacter( FObjId InObjId );

	// 오브젝트를 삭제한다.
	void DestroyActor( FObjId InObjId );

	// 액터를 삭제처리 한다.
	void DestroyActor( AActor* InActor );

	// 현재 내 캐릭터를 반환한다.
	ACharacterPC* GetCurrentPlayer();

	// 오브젝트 고유 아이디를 반환한다.
	FORCEINLINE FObjId GeneratorObjId() { return IdGenerator++; }

	// 모든 Actor 에 대해 Predicate 함수를 수행한다
	void ForEachActor( const TFunction<void( AActor* )>& InPred );

	// Predicate 함수가 True 인 모든 Actor를 반환한다.
	void GetActorsByPredicate( TArray<AActor*>& OutObjectList, const TFunction<bool( AActor* )>& InPred );

	// 현재 플레이어로부터 가장 가까운 Actor 를 반환한다.
	AActor* GetNearestActor();

	// 현재 액터부터 가장 가까운 Actor 를 반환한다.
	AActor* GetNearestActor(AActor* InThisActor);

	// 모든 Type 오브젝트에 대해 Predicate 함수를 수행한다.
	template<typename Type>
	void ForEach( const TFunction<void( Type* )>& InPred );

	// 모든 Type 오브젝트에 대해 Predicate 함수를 수행한다.
	template<typename Type>
	void GetObjectsByPredicate( TArray<Type*>& OutObjectList, const TFunction<bool( Type* )>& InPred );

private:
	// 액터를 스폰한다.
	AActor* _SpawnActorDeferred( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam );

	// PC를 스폰한다.
	ACharacterPC* _SpawnPC( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam );

	// NPC를 스폰한다.
	ACharacterNPC* _SpawnNPC( EObjectType InType, FObjId InObjId, const FActorSpawnParam& InParam );

	// 플레이어를 세팅한다.
	void _SetPlayer( ACharacterPC* InPlayer );
};

GENERATE_SINGLETON_GETTER( ObjectManager )

// =============================================================
// 모든 Type 오브젝트에 대해 Predicate 함수를 수행한다.
// 사용예시 -
// GetObjectManager().ForEach<ACharacterBase>( [ this ] ( ACharacterBase* InCharacter )
// {
//		Character->Func();
//		or
//		Func(Character);
// });
// =============================================================
template<typename Type>
void FObjectManager::ForEach( const TFunction<void( Type* )>& InPred )
{
	ForEachActor( [ InPred ] ( AActor* InActor )
	{
		if ( !InPred )
			return;

		Type* object = Cast< Type >( InActor );
		if ( !object )
			continue;

		InPred( object );
	} );
}

// =============================================================
// 모든 Type 오브젝트에 대해 Predicate 함수를 수행한다.
// 임시 객체가 불필요하게 복사생성 되지 않도록 인자의 OutObjectList 를 사용
// 사용예시 -
// TArray<ACharacterBase*> characterList;
// GetObjectManager().GetObjectsByPredicate<ACharacterBase>( characterList, [ this ] ( ACharacterBase* InCharacter )
// {
//		return Character->Func();
//		or
//		return Func(Character);
// });
// =============================================================
template<typename Type>
void FObjectManager::GetObjectsByPredicate( TArray<Type*>& OutObjectList, const TFunction<bool( Type* )>& InPred )
{
	if ( !InPred )
		return;

	for ( auto& [objId, actorPtr] : Objects )
	{
		if ( !actorPtr.IsValid() )
			continue;

		Type* object = Cast< Type >( InActor );
		if ( !object )
			continue;

		if ( !InPred( object ) )
			continue;

		OutObjectList.Add( actorPtr.Get() );
	}
}

// =============================================================
// 액터를 스폰한다.
// =============================================================
template<typename Type>
Type* SpawnActorDeferredByClass( UClass* InClass, FObjId InObjId, const FActorSpawnParam& InParam, bool InManaged )
{
	if ( !InClass )
		return nullptr;

	Type* newActor = DpGetWorld()->SpawnActorDeferred<Type>( InClass, FTransform( InParam.Rotation, InParam.Location ), nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn );

	if ( !newActor )
		return nullptr;

	if ( InParam.InitFunc )
		InParam.InitFunc( newActor );

	newActor->FinishSpawning( FTransform( InParam.Rotation, InParam.Location ) );

	UtilEffect::ActivateDecorator( newActor, EDecorateUseType::Spawn );

	if ( InManaged )
	{
		Objects.Add( InObjId, newActor );

		// 일단 관리하려는 녀석들만 델리게이트 브로드캐스트
		FGwGameDelegate::Get().GetDelegateActorSpawned().Broadcast( newActor, InObjId );
	}

	return newActor;
}