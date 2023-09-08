// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


// 제네릭하게 사용될 수 있는 스트링 데이터
class FDpUserData
{
private:
	FString Key;   // 키값
	FString Value; // 밸류값

public:
	// 생성자
	FDpUserData() : Key( TEXT("") ), Value( TEXT("") ) {}
	// 생성자
	FDpUserData( const FString& InKey, const FString& InValue ) : Key( InKey ), Value( InValue ) {}

public:
	// Getter
	int64 GetInteger64() const { return FCString::Atoi64( *Value ); }
	int32 GetInteger() const { return FCString::Atoi( *Value ); }
	float GetFloat() const { return FCString::Atof( *Value ); }
	double GetDouble() const { return FCString::Atod( *Value ); }
	const FString& GetString() const { return Value; }
	const FString& GetKey() const { return Key; }

	// Setter
	void SetValue( const FString& InValue ) { Value = InValue; }
	void SetInteger64( const int64& InValue ) { Value = FString::Printf( TEXT( "%ld" ), InValue ); }
	void SetInteger( const int32& InValue ) { Value = FString::Printf( TEXT( "%d" ), InValue ); }
	void SetFloat( const float& InValue ) { Value = FString::Printf( TEXT( "%f" ), InValue ); }
	void SetDouble( const double& InValue ) { Value = FString::Printf( TEXT( "%lf" ), InValue ); }
	void SetString( const FString& InValue ) { Value = InValue; }

	friend class FUserDataManager;
};