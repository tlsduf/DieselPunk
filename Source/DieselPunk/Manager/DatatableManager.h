// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include <Engine/DataTable.h>

enum class EDataTableType : uint8;

//게임 시작 시 데이터 테이블을 로드하고 관리합니다.
class DIESELPUNK_API FDataTableManager
{
	Singleton_Declare(FDataTableManager)
private:
	TMap<EDataTableType, UDataTable*> Datas;
private:
	void Initialize();
	void Release();

public:
	//데이터 테이블을 모두 로드합니다.
	void LoadDataTables();
	
	//변수 TableName의 데이터 테이블을 로드합니다.
	void LoadDataTable(const EDataTableType& InDataTableType);

	//테이블에 등록된 데이터뭉치를 가져옵니다.
	UDataTable* GetDataRow(const EDataTableType& InDataTableType);

	template<typename T>
	const T* GetData(const EDataTableType& InDataTableType, const FString& InRowName);
};

template <typename T>
const T* FDataTableManager::GetData(const EDataTableType& InDataTableType, const FString& InRowName)
{
	UDataTable** dataTablePtr = Datas.Find(InDataTableType);
	if(dataTablePtr == nullptr)
		return nullptr;
	return (*dataTablePtr)->FindRow<T>(FName(InRowName), TEXT("FDataTableManager::GetData()"));
}
