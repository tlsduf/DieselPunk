// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectManager.h"
#include "../Character/CharacterPc.h"
#include "../Character/CharacterNPC.h"
#include "../Actor/MonsterSpawner.h"
#include "FstreamManager.h"
#include "../Interface/ObjectPoolingInterface.h"

#include <GameFramework/PlayerController.h>
#include <Components/CapsuleComponent.h>

#include "DieselPunk/Character/CharacterMonster.h"
#include "DieselPunk/Character/CharacterTurret.h"


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


	// if(GetWorld())
	// {
	// 	FFstreamManager::OpenDataBinaryCustom(GetWorld()->GetMapName() + TEXT("_ObjectPoolingLog.bin"), std::ios::trunc);
	// 	//World->GetTimerManager().SetTimer(WritePoolingObjectHandle, this, &FObjectManager::WritePoolingObjectCount, 1.f, true);
	// 	auto delegateTimer = FTimerDelegate::CreateRaw(this, &FObjectManager::WritePoolingObjectCount);
	// 	World->GetTimerManager().SetTimer(WritePoolingObjectHandle, delegateTimer, 1.f, true);
	// }
}

void FObjectManager::Release()
{
	WritePoolingObjectHandle.Invalidate();
	for(TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(pair.Value.IsValid())
		{
			pair.Value->SetActorHiddenInGame(true);
			pair.Value->Destroy();
		}
	}
	Objects.Empty();

	// FFstreamManager::CloseDataBinaryCustom();
	//
	// for(const TPair<FString, TMap<UClass*, FPoolingInfo>>& mapPoolingInfo : PoolingObjectInfo)
	// {
	// 	TArray<FString> outData;
	// 	for(const TPair<UClass*, FPoolingInfo>& poolingInfo : mapPoolingInfo.Value)
	// 	{
	// 		outData.Add(FString::Printf(TEXT("%s:%d"), *poolingInfo.Value.UClassRefPath, poolingInfo.Value.Count / poolingInfo.Value.CheckCount));
	// 	}
	// 	FFstreamManager::WriteDataBinary(mapPoolingInfo.Key + TEXT("_ObjectPooling.bin"), outData);
	// }
}

//액터 포인터를 받아 액터를 파괴합니다.
void FObjectManager::DestroyActor(AActor* InActor)
{
	//넘겨받은 액터 포인터가 존재하는 지 확인합니다.
	int32 removeObjectId = INVALID_OBJECTID;
	for(const TPair<int32, TWeakObjectPtr<AActor>>& pair : Objects)
	{
		if(pair.Value == InActor)
		{
			removeObjectId = pair.Key;
			break;
		}
	}

	if(removeObjectId == INVALID_OBJECTID)
		return;

	if(ACharacterTurret* turret = Cast<ACharacterTurret>(InActor))
		UpdateSplinePathAllEnemy();
	
	if(InActor->GetClass()->ImplementsInterface(UObjectPoolingInterface::StaticClass()))
	{
		//PoolingObject에 추가합니다.
		Cast<IObjectPoolingInterface>(InActor)->Release();
		PoolingObject.FindOrAdd(InActor->GetClass()).Add(InActor);
		InActor->SetActorHiddenInGame(true);
	}
	else
	{
		//액터를 Detroy합니다.
		InActor->SetActorHiddenInGame(true);
		InActor->Destroy();
	}

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

	if(ACharacterTurret* turret = Cast<ACharacterTurret>(*actorPtr))
		UpdateSplinePathAllEnemy();
	
	//액터를 Detroy합니다.
	if((*actorPtr).IsValid())
	{
		if((*actorPtr)->GetClass()->ImplementsInterface(UObjectPoolingInterface::StaticClass()))
		{
			//PoolingObject에 추가합니다.
			Cast<IObjectPoolingInterface>((*actorPtr))->Release();
			PoolingObject.FindOrAdd((*actorPtr)->GetClass()).Add((*actorPtr));
			(*actorPtr)->SetActorHiddenInGame(true);
		}
		else
		{
			(*actorPtr)->SetActorHiddenInGame(true);
			(*actorPtr)->Destroy();
		}
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

//ObjectManager를 통해 생성하지 않은(미리 월드에 배치해놓은) 액터를 추가합니다.
int32 FObjectManager::AddActor(AActor* InActor)
{
	if(InActor == nullptr)
		return INVALID_OBJECTID;

	//이미 스폰되어 있는지 검사
	TWeakObjectPtr<AActor> actor = nullptr;
	for(const TPair<int32, TWeakObjectPtr<AActor>>& object : Objects)
	{
		if(object.Value.IsValid() && object.Value.Get() == InActor)
			actor = object.Value;
	}
	
	if(actor != nullptr)
	{
		TWeakObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(actor);
		if(character != nullptr)
			return character->GetObjectId();
		TWeakObjectPtr<AMonsterSpawner> spawnArea = Cast<AMonsterSpawner>(actor);
		if(spawnArea != nullptr)
			return spawnArea->GetObjectId();
		return OBJECT_ALREADY_SPAWNED;
	}
	
	//오브젝트ID 등록
	int32 objId = FObjectIdGenerator::GenerateID();
	SetObjectIdAt(InActor, objId);

	Objects.Add(objId, InActor);
	
	return objId;
}

//캐릭터 베이스의 오브젝트 ID를 설정합니다.
void FObjectManager::SetObjectIdAt(AActor* InActor, int32 InObjectId)
{
	if(InActor->GetClass()->ImplementsInterface(UDpManagementTargetInterFace::StaticClass()))
	{
		IDpManagementTargetInterFace* interfaceManagement = Cast<IDpManagementTargetInterFace>(InActor);
		interfaceManagement->SetObjectId(InObjectId);
	}
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
			if(nexus != nullptr && nexus->GetNPCType() == ENPCType::Nexus)
			{
				Nexus = nexus;
				return Nexus.Get();
			}
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

void FObjectManager::WritePoolingObjectCount()
{
	TMap<UClass*, int32> actorCount;
	for(TPair<int32, TWeakObjectPtr<AActor>> actor : Objects)
	{
		if(actor.Value->GetClass()->ImplementsInterface(UObjectPoolingInterface::StaticClass()))
		{
			actorCount.FindOrAdd(actor.Value->GetClass())++;
		}
	}
	
	TArray<FString> outData;
	FString data = FString::Printf(TEXT("%lf"), GetWorld()->TimeSeconds);
	outData.Add(data);
	
	for(const TPair<UClass*, int32>& count : actorCount)
	{
		data = FString::Printf(TEXT("%s:%d"), *count.Key->GetPathName(), count.Value);
		outData.Add(data);
		
		FPoolingInfo& info = PoolingObjectInfo.FindOrAdd(GetWorld()->GetMapName()).FindOrAdd(count.Key);
		info.UClassRefPath = TEXT("/Script/Engine.Blueprint'") + count.Key->GetPathName() + TEXT("'");
		info.Count += count.Value;;
		info.CheckCount++;
	}

	FFstreamManager::WriteDataBinaryCustom(outData, TEXT("|"));
}

void FObjectManager::ReAllocatePoolingObject(FString InWorldName)
{
	TArray<FString> datas;
	if(FFstreamManager::ReadDataBinary(InWorldName + TEXT("_ObjectPooling.bin"), datas))
	{
		for(int i = 1; i < datas.Num(); ++i)
		{
			FString uClassName, countStr;
			datas[i].Split(TEXT(":"), &uClassName, &countStr);
			
			FString uClassFullName = TEXT("/Script/Engine.Blueprint'") + uClassName + TEXT("'");
			UClass* uClass = LoadClass<AActor>(nullptr, *uClassFullName);

			int32 count = FCString::Atoi(*countStr);
			for(int j = 0; j < count; ++j)
			{
				AActor* actor = World->SpawnActor(uClass);
				TArray<TWeakObjectPtr<AActor>>& actors = PoolingObject.FindOrAdd(uClass);
				actors.Add(actor);
			}
		}
	}
}

//모든 Enemy타입 경로 재설정 //터렛 설치, 파괴, 판매 시 호출 //#navi #splineUpdate #enemy
void FObjectManager::UpdateSplinePathAllEnemy()
{
	//NPCType == Enemy 인 NPC배열을 반환
	TArray<int32> monstersIDs;
	FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterMonster>(InActor))
			if(npc->GetNPCType() == ENPCType::Enemy)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
	{
		Cast<ACharacterMonster>(FindActor(ID))->UpdateSplinePath();
	}
	LOG_SCREEN(FColor::Red, TEXT("모든 적 경로 재탐색"))
}

