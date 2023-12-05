// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectManager.h"
#include "../Character/CharacterPc.h"
#include "../Character/CharacterNPC.h"

#include <GameFramework/PlayerController.h>
#include <Components/CapsuleComponent.h>

Singleton_Defintion(FObjectManager)

//생성자
FObjectManager::FObjectManager()
	: World(nullptr), Controller(nullptr), Player(nullptr), Nexus(nullptr)
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
void FObjectManager::DestroyActor(int32 InObjectId)
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

//플레이어를 세팅합니다.
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

//반환받은 Id값이 정상인지 확인합니다.
bool FObjectManager::IsValidId(int32 InId)
{
	if((InId == INVALID_UCLASS) || (InId == INVALID_OBJECTID) || (InId == OBJECT_SPAWN_FAILED) || (InId == OBJECT_ALREADY_SPAWNED))
		return false;

	return true;
}

int32 FObjectManager::AddActor(AActor* InActor)
{
	if(InActor == nullptr)
		return INVALID_OBJECTID;

	//이미 스폰되어 있는지 검사
	TWeakObjectPtr<AActor> actor = nullptr;
	for(const TPair<int32, TWeakObjectPtr<AActor>>& object : Objects)
	{
		if(object.Value.IsValid() || object.Value.Get() == InActor)
			actor = object.Value;
	}
	
	if(actor != nullptr)
	{
		TWeakObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(actor);
		if(character != nullptr)
			return character->GetObjectId();
		return OBJECT_ALREADY_SPAWNED;
	}
	
	//오브젝트ID 등록
	int32 objId = FObjectIdGenerator::GenerateID();
	SetObjectIdAtCharacterBase(InActor, objId);

	Objects.Add(objId, InActor);
	
	return objId;
}

//캐릭터 베이스의 오브젝트 ID를 설정합니다.
void FObjectManager::SetObjectIdAtCharacterBase(AActor* InActor, int32 InObjectId)
{
	ACharacterBase* charBase = Cast<ACharacterBase>(InActor);
	if(charBase)
		charBase->SetObjectId(InObjectId);
}

//캐릭터일 경우에 캡슐컴포넌트의 Half Height만큼 위로 올린 값을 반환합니다.
FVector FObjectManager::GetLocationByPawn(AActor* InActor, const FVector& InLocation)
{
	ACharacter* character = Cast<ACharacter>(InActor);

	FVector outLocation = InLocation;
	if(character)
		outLocation.Z += character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

	return outLocation;
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

ACharacterNPC* FObjectManager::GetNexus()
{
	if(Nexus.IsValid())
		return Nexus.Get();

	for(TPair<int32, TWeakObjectPtr<AActor>>& object : Objects)
	{
		if(object.Value.IsValid())
		{
			ACharacterNPC* nexus = Cast<ACharacterNPC>(object.Value);
			if(nexus != nullptr && nexus->NPCType == ENPCType::Nexus)
			Nexus = nexus;
			return Nexus.Get();
		}
	}
	return nullptr;
}

UWorld* FObjectManager::GetWorld()
{
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	World = world->World();

	return World.Get();
}

//오브젝트ID를 받아 액터를 찾습니다.
AActor* FObjectManager::FindActor(int32 InObjectId)
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

//로케이션과 액터의 Id어레이를 받아 가장 InLocation에 가까운 액터의 Id를 반환합니다.
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

