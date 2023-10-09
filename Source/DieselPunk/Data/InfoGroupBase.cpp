// Fill out your copyright notice in the Description page of Project Settings.

#include "InfoGroupBase.h"

#if WITH_EDITOR
#include <Engine.h>
#endif


#include UE_INLINE_GENERATED_CPP_BY_NAME(InfoGroupBase)


void FInfoGroupBase::OnDataTableChanged( const UDataTable* InDataTable, const FName InRowName )
{
	Super::OnDataTableChanged( InDataTable, InRowName );
#if WITH_EDITOR
	// 에디터에서 DataTable 수정시 Group 중복 및 유효성 검사
	// 사실 FInfoBase 의 OnDataTableChanged 를 호출시켜서 
	// 그곳에서 InfoId 체크를 진행하면 포문이 쓸데없이 한번 더 돌지만
	// 코드가 이뻐보이기 때문에 이렇게 사용하기로 했습니당
	if ( !InDataTable ) return;

	TMap<FInfoId, FInfoGroupBase*> tableDatas;
	for ( const auto& [rowName, value] : InDataTable->GetRowMap() )
	{
		FInfoGroupBase* info = ( FInfoGroupBase* )( value );
		if ( !info ) continue;

		if ( info->InfoId == G_InvalidInfoId )
		{
			// InfoId == 0
			FText Title = FText::FromString( FString::Printf( TEXT( "%s Warning" ), *InDataTable->GetName() ) );
			FText Text = FText::FromString( FString::Printf( TEXT( "%s Group %d Must Not Be 0" ), *InRowName.ToString(), info->GroupId ) );
			EAppReturnType::Type ReturnType = FMessageDialog::Open( EAppMsgType::Ok, Text, Title );
			continue;
		}

		FInfoGroupBase*& otherInfo = tableDatas.FindOrAdd( info->InfoId );
		if ( otherInfo )
			continue;

		otherInfo = info;
	}
#endif
}