// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include <fstream>

class DIESELPUNK_API FFstreamManager
{
private:
	static std::wofstream CustomOutStream;
	static std::wifstream CustomInStream;
public:
	static FString FilePath;
public:
	//바이너리 파일 쓰기
	static bool WriteDataBinary(FString InFileName, const TArray<FString>& InString);

	//바이너리 파일 읽기
	static bool ReadDataBinary(FString InFileName, TArray<FString>& OutString);

	//커스텀 바이너리 파일 오픈
	static bool OpenDataBinaryCustom(FString InFileName, std::ios_base::openmode InOpenMode);

	//커스텀 바이너리 파일 쓰기
	static bool WriteDataBinaryCustom(const TArray<FString>& InString, FString InDivideWord = TEXT("/"));

	//커스텀 바이너리 파일 닫기
	static bool CloseDataBinaryCustom();

	//읽은 전체 바이너리 파일을 스트링으로 분리
	static TArray<FString> SplitString(const FString& InString, FString InDivideWord = TEXT("/"));
	
	//Integer계열의 데이터 쓰기
	template<typename T>
	static bool WriteDataBinaryByInteger(FString InFilePath, const TArray<T>& InArrayInt);

	//Double계열의 데이터 쓰기
	template<typename T>
	static bool WriteDataBinaryByDouble(FString InFilePath, const TArray<T>& InArrayDbl);

	//Integer계열의 데이터 읽기
	template<typename T>
	static bool ReadDataBinaryByInteger(FString InFilePath, TArray<T>& OutArrayInt);

	//Double계열의 데이터 읽기
	template<typename T>
	static bool ReadDataBinaryByDouble(FString InFilePath, TArray<T>& OutArrayDbl);
};

//Integer계열의 데이터 쓰기
template <typename T>
bool FFstreamManager::WriteDataBinaryByInteger(FString InFilePath, const TArray<T>& InArrayInt)
{
	TArray<FString> outData;
	for(const T& integer : InArrayInt)
	{
		FString data = FString::Printf(TEXT("%d"), static_cast<int>(integer));
		outData.Add(data);
	}

	return WriteDataBinary(InFilePath, outData);
}

//Double계열의 데이터 쓰기
template <typename T>
bool FFstreamManager::WriteDataBinaryByDouble(FString InFilePath, const TArray<T>& InArrayDbl)
{
	TArray<FString> outData;
	for(const T& dbl : InArrayDbl)
	{
		FString data = FString::Printf(TEXT("%lf"), static_cast<double>(dbl));
		outData.Add(data);
	}

	return WriteDataBinary(InFilePath, outData);
}

//Integer계열의 데이터 읽기
template <typename T>
bool FFstreamManager::ReadDataBinaryByInteger(FString InFilePath, TArray<T>& OutArrayInt)
{
	TArray<FString> loadString;
	bool isSucced = ReadDataBinary(InFilePath, loadString);
	if(!isSucced)
		return false;
	
	for(const FString& str : loadString)
	{
		T data = FCString::Atoi(*str);
		OutArrayInt.Add(data);
	}

	return true;
}

//Double계열의 데이터 읽기
template <typename T>
bool FFstreamManager::ReadDataBinaryByDouble(FString InFilePath, TArray<T>& OutArrayDbl)
{
	TArray<FString> loadString;
	bool isSucced = ReadDataBinary(InFilePath, loadString);
	if(!isSucced)
		return false;
	
	for(const FString& str : loadString)
	{
		T data = FCString::Atod(*str);
		OutArrayDbl.Add(data);
	}

	return true;
}

