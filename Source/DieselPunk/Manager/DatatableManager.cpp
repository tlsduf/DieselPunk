// Fill out your copyright notice in the Description page of Project Settings.

#include "DatatableManager.h"

#include "DieselPunk/Data/DPTableRowBase.h"

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
	for(EDataTableType tableType : TEnumRange<EDataTableType>())
		LoadDataTable(tableType);
}

//변수 TableName의 데이터 테이블을 로드합니다.
void FDataTableManager::LoadDataTable(const EDataTableType& InDataTableType)
{
	//데이터 테이블을 로드하여 추가합니다.
	UDataTable* table = LoadObject<UDataTable>(nullptr, *UtilPath::GetDataTablePath(*UtilPath::EnumToString(InDataTableType)));

	if(table)
	{
		Datas.Add(InDataTableType, table);
		TArray<FDPTableRowBase*> datas;
		table->GetAllRows<FDPTableRowBase>(table->GetName(), datas);

		for(FDPTableRowBase* data : datas)
		{
			if(CachedDatas.Find(data->DataID) == nullptr)
				CachedDatas.Add(data->DataID, data);
		}
	}
}

//테이블에 등록된 데이터뭉치를 가져옵니다.
UDataTable* FDataTableManager::GetDataRow(const EDataTableType& InDataTableType)
{
	UDataTable** data = Datas.Find(InDataTableType);
	if(data && *data)
		return *data;

	return nullptr;
}