// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectCreater.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DatatableManager.h"
#include "../Data/CharacterDataTable.h"
#include "../Character/CharacterBase.h"

#include <Components/SkeletalMeshComponent.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(ObjectCreater)

// Sets default values
AObjectCreater::AObjectCreater()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PreviewMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Preview Mesh"));
	if(PreviewMesh)
	{
		PreviewMesh->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		PreviewMesh->SetGenerateOverlapEvents( false );
		PreviewMesh->SetSimulatePhysics( false );
	}
}
/** Overridable native event for when play begins for this actor. */
void AObjectCreater::BeginPlay()
{
	Super::BeginPlay();
	
	Spawn();
}

// =============================================================
// 캐릭터를 스폰합니다.
// =============================================================
void AObjectCreater::Spawn()
{
	//해당하는 경로 탐색을 위한 데이터 테이블 서치
	const FCharacterDataTable* dataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, CharacterName);
	if(!dataTable)
	{
		Destroy();
		return;
	}
	//캐릭터 생성
	UClass* CharName = LoadClass<ACharacterBase>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
	if(CharName)
	{
		FSpawnParam spawnParam;
		spawnParam.Rotation = FRotator::ZeroRotator;
		spawnParam.Location = GetActorLocation();
		spawnParam.CallBackSpawn = nullptr;
			
		FObjectManager::GetInstance()->CreateActor<ACharacterBase>(CharName, spawnParam);
	}

	Destroy();
}

