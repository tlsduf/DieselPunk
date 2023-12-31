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
class ACharacterNPC;

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
	TWeakObjectPtr<ACharacterNPC>		Nexus;
public:
	constexpr static int32 INVALID_UCLASS = -9999;			//생성 시 UCLASS의 오류
	constexpr static int32 OBJECT_SPAWN_FAILED = -9998;		//오브젝트 생성 실패
	constexpr static int32 INVALID_OBJECTID = -9997;		//잘못된 오브젝트 ID
	constexpr static int32 OBJECT_ALREADY_SPAWNED = -9996;	//이미 생성된 오브젝트
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
	void	DestroyActor(int32 InObjectId);

	//플레이어를 세팅합니다.
	void	SetPlayer(ACharacterPC* InPlayer);

	//반환받은 Id값이 정상인지 확인합니다.
	static bool	IsValidId(int32 InId);

	//ObjectManager를 통해 생성하지 않은(미리 월드에 배치해놓은) 액터를 추가합니다.
	int32	AddActor(AActor* InActor);
	
private:
	//오브젝트 ID를 설정합니다.
	void	SetObjectIdAt(AActor* InActor, int32 InObjectId);

	//캐릭터일 경우에 캡슐컴포넌트의 Half Height만큼 위로 올린 값을 반환합니다.
	FVector GetLocationByPawn(AActor* InActor, const FVector& InLocation);

public:
	//컨트롤 중인 플레이어를 가져옵니다.
	ACharacterPC* GetPlayer();

	ACharacterNPC* GetNexus();

	UWorld* GetWorld();
	
	//오브젝트ID를 받아 액터를 찾습니다.
	AActor* FindActor(int32 InObjectId);

	//액터를 찾는 함수포인터를 받아 액터의 Id를 찾습니다.
	int32	FindActorByPredicate(const std::function<bool(AActor*)>& InPredicate);

	//액터를 찾는 함수포인터를 받아 해당하는 액터의 Id어레이를 반환합니다.
	void	FindActorArrayByPredicate(TArray<int>& OutActors, const std::function<bool(AActor*)>& InPredicate);

	//로케이션과 액터의 Id어레이를 받아 가장 InLocation에 가까운 액터의 Id를 반환합니다.
	int32	GetNearestACtorByRangeAndIds(FVector InLocation, const TArray<int32>& InActorIds);
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
	
	//캐릭터일 경우에 캡슐 절반높이만큼 위로 올려스폰
	FVector location = GetLocationByPawn(actor, InSpawnParam.Location);
	spawnTransform = FTransform(InSpawnParam.Rotation, location);

	//콜백함수 호출
	if(InSpawnParam.CallBackSpawn)
		InSpawnParam.CallBackSpawn(actor);

	//오브젝트ID 등록
	int32 objId = FObjectIdGenerator::GenerateID();
	SetObjectIdAt(actor, objId);

	//스폰 마무리
	actor->FinishSpawning(spawnTransform);
	
	Objects.Add(objId, actor);

	return objId;
}
