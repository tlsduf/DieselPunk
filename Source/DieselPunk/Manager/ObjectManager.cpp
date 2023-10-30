// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectManager.h"

#include "../Character/CharacterPc.h"
#include <GameFramework/PlayerController.h>

Singleton_Defintion(FObjectManager)

//생성자
FObjectManager::FObjectManager()
	: World(nullptr), Controller(nullptr), Player(nullptr) 
{
	
}

//소멸자
FObjectManager::~FObjectManager()
{
	
}

void FObjectManager::Initialize()
{
}

void FObjectManager::Release()
{
}

//액터 포인터를 받아 액터를 파괴합니다.
void FObjectManager::DestroyActor(AActor* InActor)
{
	//넘겨받은 액터 포인터가 존재하는 지 확인합니다.
	int32 removeObjectId = -1;
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(pair.Value == InActor)
			removeObjectId = pair.Key;
	}

	//액터를 Detroy합니다.
	InActor->SetActorHiddenInGame(true);
	InActor->Destroy();

	//오브젝트를 관리하는 맵에서 삭제합니다.
	Objects.Remove(removeObjectId);
}

//오브젝트ID를 받아 액터를 파괴합니다.
void FObjectManager::DestroyActor(int64 InObjectId)
{
	//넘겨받은 ObjectID로 액터를 찾습니다.
	TWeakObjectPtr<AActor>* actorPtr = Objects.Find(InObjectId);
	if(!actorPtr)
		return;

	//액터를 Detroy합니다.
	if((*actorPtr).IsValid())
	{
		(*actorPtr)->SetActorHiddenInGame(true);
		(*actorPtr)->Destroy();
	}
	
	//오브젝트를 관리하는 맵에서 삭제합니다.
	Objects.Remove(InObjectId);
}

void FObjectManager::SetPlayer(ACharacterPC* InPlayer)
{
	if(!InPlayer)
	{
		LOG_SCREEN(FColor::Red, TEXT("FObjectManager::SetPlayer(ACharacterPC* InPlayer) : InPlayer is nullptr!"))
		return;
	}

	World = InPlayer->GetWorld();
	Controller = Cast<APlayerController>(InPlayer->GetController());
	Player = InPlayer;
}

void FObjectManager::SetObjectIdAtCharacterBase(AActor* InActor, int32 InObjectId)
{
	ACharacterBase* charBase = Cast<ACharacterBase>(InActor);
	if(charBase)
		charBase->SetObjectId(InObjectId);
}

//컨트롤 중인 플레이어를 가져옵니다.
ACharacterPC* FObjectManager::GetPlayer()
{
	//플레이어 변수가 있다면 해당 플레이어를 반환
	if(Player.IsValid() && Player == Controller->GetCharacter())
		return Player.Get();

	FWorldContext* world = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	World = world->World();

	//Player Controller를 찾습니다.
	for(FConstPlayerControllerIterator iter = World->GetPlayerControllerIterator(); iter; ++iter)
	{
		if(iter->IsValid())
		{
			Controller = iter->Get();
			break;
		}
	}

	if(!Controller.IsValid())
		return nullptr;
	
	Player = Cast<ACharacterPC>(Controller->GetCharacter());
	return Player.Get();
}

//액터를 찾는 함수포인터를 받아 액터를 찾습니다.
AActor* FObjectManager::FindActorByPredicate(const std::function<bool(AActor*)>& InPredicate)
{
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(InPredicate(pair.Value.Get()))
			return pair.Value.Get();
	}

	return nullptr;
}

//액터를 찾는 함수포인터를 받아 해당하는 액터의 어레이를 반환합니다.
void FObjectManager::FindActorArrayByPredicate(TArray<TWeakObjectPtr<AActor>>& OutActors,
	const std::function<bool(AActor*)>& InPredicate)
{
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(InPredicate(pair.Value.Get()))
			OutActors.Add(pair.Value);
	}
}

