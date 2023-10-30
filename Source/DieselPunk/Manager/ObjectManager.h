// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


struct FSpawnParam
{
	FRotator Rotation;
	FVector Location;
	std::function<void(AActor*)> CallBackSpawn;
};

class FObjectIdGenerator
{
private:
	inline static int32 Min = 10;
	inline static int32 Max = 10000;
	inline static int32 CurrentID = Min;
public:
	static int32 GenerateID()
	{
		int32 out = CurrentID++;
		if(CurrentID > Max)
			CurrentID = Min;
		return out;
	}
};

class ACharacterPC;

/**
 * 오브젝트 생성, 삭제 등을 관리합니다.
 */
class DIESELPUNK_API FObjectManager
{
	Singleton_Declare(FObjectManager)
private:
	TMap<int32, TWeakObjectPtr<AActor>> Objects;
	TWeakObjectPtr<UWorld>				World;
	TWeakObjectPtr<APlayerController>	Controller;
	TWeakObjectPtr<ACharacterPC>		Player;
public:
	constexpr static int32 INVALID_UCLASS = -9999;			//생성 시 UCLASS의 오류
	constexpr static int32 OBJECT_SPAWN_FAILED = -9998;		//오브젝트 생성 실패
private:
	void Initialize();
	void Release();
public:
	//액터를 생성합니다.
	template<typename T>
	int32	CreateActor(UClass* InClass, const FSpawnParam& InSpawnParam);

	//액터 포인터를 받아 액터를 파괴합니다.
	void	DestroyActor(AActor* InActor);
	
	//오브젝트ID를 받아 액터를 파괴합니다.
	void	DestroyActor(int64 InObjectId);

	//플레이어를 세팅합니다.
	void	SetPlayer(ACharacterPC* InPlayer);
private:
	void	SetObjectIdAtCharacterBase(AActor* InActor, int32 InObjectId);

public:
	//컨트롤 중인 플레이어를 가져옵니다.
	ACharacterPC* GetPlayer();
	
	//오브젝트ID를 받아 액터를 찾습니다.
	AActor* FindActor(int64 InObjectId) { return Objects.Find(InObjectId)->Get(); }

	//액터를 찾는 함수포인터를 받아 액터를 찾습니다.
	AActor* FindActorByPredicate(const std::function<bool(AActor*)>& InPredicate);

	//액터를 찾는 함수포인터를 받아 해당하는 액터의 어레이를 반환합니다.
	void	FindActorArrayByPredicate(TArray<TWeakObjectPtr<AActor>>& OutActors, const std::function<bool(AActor*)>& InPredicate);
};

template <typename T>
int32 FObjectManager::CreateActor(UClass* InClass, const FSpawnParam& InSpawnParam)
{
	if(!InClass)
		return INVALID_UCLASS;

	//현재 월드 업데이트
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	World = world->World();

	//트랜스폼 생성
	FTransform spawnTransform(InSpawnParam.Rotation, InSpawnParam.Location);

	//액터 생성
	AActor* actor = World->SpawnActorDeferred<T>(InClass, spawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	if(!actor)
		return OBJECT_SPAWN_FAILED;

	//콜백함수 호출
	if(InSpawnParam.CallBackSpawn)
		InSpawnParam.CallBackSpawn(actor);

	//오브젝트ID 등록
	int32 objId = FObjectIdGenerator::GenerateID();
	SetObjectIdAtCharacterBase(actor, objId);

	//스폰 마무리
	actor->FinishSpawning(spawnTransform);
	
	Objects.Add(objId, actor);

	return objId;
}
