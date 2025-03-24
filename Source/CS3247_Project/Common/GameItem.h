// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameItemTag.h"
#include "Engine/DataAsset.h"
#include "GameItem.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class CS3247_PROJECT_API UGameItem : public UDataAsset {
	GENERATED_BODY()

public:
	UGameItem() : UGameItem(EGameItemTag::CardIngredient) {}

	explicit UGameItem(const EGameItemTag ItemType) : ItemType(ItemType) {}
	
	UPROPERTY(BlueprintReadOnly)
	EGameItemTag ItemType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Desc;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	TSoftObjectPtr<UTexture2D> Icon;
};
