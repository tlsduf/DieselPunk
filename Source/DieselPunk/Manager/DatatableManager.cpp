// Fill out your copyright notice in the Description page of Project Settings.

#include "DatatableManager.h"

Singleton_Defintion(FDataTableManager)

FDataTableManager::FDataTableManager()
{
	
}

FDataTableManager::~FDataTableManager()
{
	
}


void FDataTableManager::Initialize()
{
	LoadDataTables();
}

void FDataTableManager::Release()
{
	Datas.Empty();
}

//데이터 테이블을 모두 로드합니다.
void FDataTableManager::LoadDataTables()
{
	if(!Datas.IsEmpty())
		Datas.Empty();
	LoadDataTable(EDataTableType::Stat);
	LoadDataTable(EDataTableType::Character);
	LoadDataTable(EDataTableType::MonsterSpawner);
	LoadDataTable(EDataTableType::Card);
	LoadDataTable(EDataTableType::StageWave);
}

//변수 TableName의 데이터 테이블을 로드합니다.
void FDataTableManager::LoadDataTable(const EDataTableType& InDataTableType)
{
	//데이터 테이블을 로드하여 추가합니다.
	Datas.Add(InDataTableType,LoadObject<UDataTable>(nullptr, *UtilPath::GetDataTablePath(*UtilPath::EnumToString(InDataTableType))));
}

//테이블에 등록된 데이터뭉치를 가져옵니다.
UDataTable* FDataTableManager::GetDataRow(const EDataTableType& InDataTableType)
{
	UDataTable** data = Datas.Find(InDataTableType);
	if(data && *data)
		return *data;

	return nullptr;
}
