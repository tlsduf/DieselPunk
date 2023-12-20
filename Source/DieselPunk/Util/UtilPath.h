#pragma once

//물리경로를 최소하기 위해 만든 파일 경로관련 함수들입니다.

namespace UtilPath
{
	template<typename T>
	FString EnumToString( T InValue )
	{
		UEnum* enumClass = StaticEnum<T>();
		if (!enumClass) return FString();

		return enumClass->GetNameStringByValue((int64)InValue);
	}

	template<typename T>
	T StringToEnum( const FString& InString, T InDefault = T::Max )
	{
		UEnum* enumClass = StaticEnum<T>();
		if (!enumClass)
			return InDefault;

		int32 index = enumClass->GetValueByName(FName(InString));
		return (index != INDEX_NONE) ? (T)index : InDefault;
	}

	//데이터 테이블 Path를 생성합니다.
	inline FString GetDataTablePath(const TCHAR* InTableName)
	{
		return FString::Printf(TEXT("/Script/Engine.DataTable'/Game/DieselPunk/Data/DataTable/DT_%s.DT_%s'"), InTableName, InTableName);
	}

	//캐릭터의 블루프린트 Path를 생성합니다.
	inline FString GetCharacterBlueprintPath(const TCHAR* InCharacterBlueprintName)
	{
		return FString::Printf(TEXT("/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/%s.%s_C'"), InCharacterBlueprintName, InCharacterBlueprintName);
	}

	//UI Path를 생성합니다.
	inline FString GetUIPath(const TCHAR* InUIName)
	{
		return FString::Printf(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/UI/Widgets/%s.%s_C'"), InUIName, InUIName);
	}

	//DeckInterFace UI Path를 생성합니다.
	inline FString GetDeckInterfaceUIPath(const TCHAR* InUIName)
	{
		return FString::Printf(TEXT("/Script/Engine.Texture2D'/Game/DieselPunk/UI/Widgets/DeckInterface/Textures/%s.%s'"), InUIName, InUIName);
	}

	//UI Detail Path를 생성합니다.
	inline FString GetUIDetailPath(const TCHAR* InAdditionalPath, const TCHAR* InUIName)
	{
		
		return FString::Printf(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/UI/Widgets/%s%s.%s_C'"), InAdditionalPath, InUIName, InUIName);
	}

	/*template<typename T>
	T* CreateUI( const TCHAR* InPath )
	{
		FString path = GetUIPath( InPath );
		UClass* widgetClass = ConstructorHelpersInternal::FindOrLoadClass( path, UUserWidget::StaticClass() );
		if ( !widgetClass )
		{
			return nullptr;
		}

		UUserWidget* userWidget = CreateWidget<UUserWidget>( GetWorld(), widgetClass );
		if ( userWidget )
		{
			userWidget->AddToRoot();

			UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( userWidget );
			if ( userWidgetBase )
				userWidgetBase->OnCreated();
		}
		T* myWidget = Cast<T>(userWidget);
		if(myWidget)
			myWidget->RemoveFromRoot();
		
		return myWidget;
	}*/
}