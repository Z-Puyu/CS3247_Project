// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IngredientKey.generated.h"

class UCardIngredient;
/**
 * 
 */
USTRUCT(BlueprintType)
struct CS3247_PROJECT_API FIngredientKey {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCardIngredient> Ingredient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuid Id;

	FORCEINLINE friend int32 GetTypeHash(const FIngredientKey& Key) {
		return HashCombine(GetTypeHash(Key.Ingredient), GetTypeHash(Key.Id));
	}

	FORCEINLINE bool operator==(const FIngredientKey& Other) const {
		return this->Ingredient == Other.Ingredient && this->Id == Other.Id;
	};
};
