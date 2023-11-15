// Fill out your copyright notice in the Description page of Project Settings.

#include "FstreamManager.h"

//바이너리 파일 쓰기
bool FFstreamManager::WriteDataBinary(FString InFileName, const TArray<FString>& InString)
{
	std::wofstream fout;
	FString filePath = FPaths::GameDevelopersDir();
	filePath += FString::Printf(TEXT("Data/%s"), *InFileName);
	fout.open(*filePath, std::ios::binary | std::ios::trunc);

	if(fout.is_open())
	{
		for(const FString& data : InString)
		{
			FString outData = data;
			outData += TEXT("/");
			fout.write(*outData, outData.Len());
		}
		FString endString = TEXT("\0");
		fout.write(*endString, 1);
		fout.close();
		return true;
	}
	return false;
}

//바이너리 파일 읽기
bool FFstreamManager::ReadDataBinary(FString InFileName, TArray<FString>& OutString)
{
	std::wifstream fin;
	FString filePath = FPaths::GameDevelopersDir();
	filePath += FString::Printf(TEXT("Data/%s"), *InFileName);
	fin.open(*filePath, std::ios::binary);
	wchar_t* buffer = nullptr;

	bool fileIsOpen = fin.is_open();
	if(fin.is_open())
	{
		fin.seekg(0, fin.end);
		int length = static_cast<int>(fin.tellg());
		fin.seekg(0, fin.beg);

		buffer = new wchar_t[length];
		fin.read(buffer, length);
		fin.close();

		FString loadString = buffer;
		OutString = SplitString(loadString);

		delete[] buffer;

		return true;
	}
	return false;
}

//읽은 전체 바이너리 파일을 스트링으로 분리
TArray<FString> FFstreamManager::SplitString(const FString& InString)
{
	FString storeString;
	TArray<FString> outString;

	for(size_t i = 0; i < InString.Len(); ++i)
	{
		if(InString[i] == TEXT('/'))
		{
			outString.Add(storeString);
			storeString = "";
		}
		else
			storeString += InString[i];
	}

	return outString;
}