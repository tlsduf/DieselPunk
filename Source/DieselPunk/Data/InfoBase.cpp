// Copyright GuardiansW. All Rights Reserved.


#include "InfoBase.h"

#if WITH_EDITOR
#include <Engine.h>
#endif


#include UE_INLINE_GENERATED_CPP_BY_NAME(InfoBase)


void FInfoBase::OnDataTableChanged( const UDataTable* InDataTable, const FName InRowName )
{
	Super::OnDataTableChanged( InDataTable, InRowName );
#if WITH_EDITOR
	// 에디터에서 DataTable 수정시 InfoId 중복 및 유효성 검사
	if ( !InDataTable ) return;

	TMap<FInfoId, FInfoBase*> tableDatas;
	for ( const auto& [rowName, value] : InDataTable->GetRowMap() )
	{
		FInfoBase* info = ( FInfoBase* )( value );
		if ( !info ) continue;

		if ( info->InfoId == G_InvalidInfoId )
		{
			// InfoId == 0
			FText Title = FText::FromString( FString::Printf( TEXT( "%s Warning" ), *InDataTable->GetName() ) );
			FText Text = FText::FromString( FString::Printf( TEXT( "%s InfoId %d Must Not Be 0" ), *InRowName.ToString(), info->InfoId ) );
			EAppReturnType::Type ReturnType = FMessageDialog::Open( EAppMsgType::Ok, Text, &Title );
		}

		FInfoBase*& otherInfo = tableDatas.FindOrAdd( info->InfoId );

		if ( !otherInfo )
		{
			otherInfo = info;
			continue;
		}

		// InfoId 중복!
		FText Title = FText::FromString( FString::Printf( TEXT( "%s Error" ), *InDataTable->GetName() ) );
		FText Text = FText::FromString( FString::Printf( TEXT( "%s InfoId %d Is Duplicated!!" ), *InRowName.ToString(), info->InfoId ) );
		EAppReturnType::Type ReturnType = FMessageDialog::Open( EAppMsgType::Ok, Text, &Title );
	}
#endif
}