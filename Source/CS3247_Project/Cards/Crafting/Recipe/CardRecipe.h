// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

class UDeckComponent;
struct FRecipeEdge;
class UCardIngredient;
class ILocalisable;
class UCard;
class UCardNode;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UCardNode> Source;

	UFUNCTION(BlueprintCallable)
	UCard* Forge(UDeckComponent* PlayerDeckComponent) const;

	UFUNCTION(BlueprintCallable)
	TArray<FRecipeEdge> ToEdgeList();
	
	bool operator==(const UCardRecipe& Other) const;

	FORCEINLINE bool operator!=(const UCardRecipe& Other) const { return !(*this == Other); }

	friend int32 GetTypeHash(UCardRecipe& Recipe);
private:
	TArray<FRecipeEdge> Edges;
};
