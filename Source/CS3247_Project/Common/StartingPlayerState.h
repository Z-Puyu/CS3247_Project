// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StartingPlayerState.generated.h"

class UCardRecipe;
class UGameItem;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UStartingPlayerState : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<UGameItem*, int32> StartingInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UCardRecipe*> StartingDeck;
};
