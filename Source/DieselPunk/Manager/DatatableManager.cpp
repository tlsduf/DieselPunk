// Fill out your copyright notice in the Description page of Project Settings.

#include "DatatableManager.h"
#include <Engine/DataTable.h>

Singleton_Defintion(FDataTableManager)

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
}

//변수 TableName의 데이터 테이블을 로드합니다.
void FDataTableManager::LoadDataTable(const EDataTableType& InDataTableType)
{
	//데이터 테이블을 로드하여 추가합니다.
	Datas.Add(InDataTableType,LoadObject<UDataTable>(nullptr, *UtilPath::GetDataTablePath(*UtilPath::EnumToString(InDataTableType))));
}

UDataTable* FDataTableManager::GetData(const EDataTableType& InDataTableType)
{
	UDataTable** data = Datas.Find(InDataTableType);
	if(data && *data)
		return *data;

	return nullptr;
}
