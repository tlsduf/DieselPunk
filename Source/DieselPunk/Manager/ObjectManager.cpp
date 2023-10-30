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
	Objects.Empty();
}

void FObjectManager::Release()
{
	for(TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(pair.Value.IsValid())
		{
			pair.Value->SetActorHiddenInGame(true);
			pair.Value->Destroy();
		}
	}
	Objects.Empty();
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

AActor* FObjectManager::FindActor(int64 InObjectId)
{
	TWeakObjectPtr<AActor>* findActor = Objects.Find(InObjectId);
	
	if(findActor)
		return findActor->Get();
	
	return nullptr;
}

//액터를 찾는 함수포인터를 받아 액터를 찾습니다.
int32 FObjectManager::FindActorByPredicate(const std::function<bool(AActor*)>& InPredicate)
{
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(InPredicate(pair.Value.Get()))
			return pair.Key;
	}

	return INVALID_OBJECTID;
}

//액터를 찾는 함수포인터를 받아 해당하는 액터의 어레이를 반환합니다.
void FObjectManager::FindActorArrayByPredicate(TArray<int32>& OutActors,
	const std::function<bool(AActor*)>& InPredicate)
{
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(InPredicate(pair.Value.Get()))
			OutActors.Add(pair.Key);
	}
}

int32 FObjectManager::GetNearestACtorByRangeAndIds(FVector InLocation, const TArray<int32>& InActorIds)
{
	double dist = MAX_dbl;
	int32 returnId = -1;
	
	for(int32 id : InActorIds)
	{
		AActor* actor = FindActor(id);
		if(!actor)
			continue;

		double curDist = FVector::Distance(actor->GetActorLocation(), InLocation);
		if(curDist < dist)
		{
			dist = curDist;
			returnId = id;
		}
	}

	return returnId;
}

