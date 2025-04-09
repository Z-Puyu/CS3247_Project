// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../UI/Texts/Localisable.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

class UResource;
class UCardImpact;
class UCardEffect;
class UDeckComponent;
struct FRecipeEdge;
class UCardIngredient;
class ILocalisable;
class UCard;
class UCardNode;
/**
 * 
 */
UCLASS(BlueprintType, BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UObject, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FName Name;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UCardNode> Source;

	UFUNCTION(BlueprintCallable)
	TMap<UResource*, int32> GetCosts() const;

	UFUNCTION(BlueprintCallable)
	UCard* Forge(UDeckComponent* PlayerDeckComponent, const bool bIsDefault = false);

	UFUNCTION(BlueprintCallable)
	TArray<FRecipeEdge> ToEdgeList();
	
	TArray<UCardImpact*> FetchImpacts() const;

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
	
	bool operator==(const UCardRecipe& Other) const;

	FORCEINLINE bool operator!=(const UCardRecipe& Other) const { return !(*this == Other); }

	friend int32 GetTypeHash(UCardRecipe& Recipe);
private:
	TArray<FRecipeEdge> Edges;
};
