// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../UI/Texts/Localisable.h"
#include "../../../UI/Texts/Printable.h"
#include "Engine/DataAsset.h"
#include "CardIngredient.generated.h"

class UCard;
class UCardEffect;
/**
 * The abstract base class for all card ingredients in crafting.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardIngredient : public UDataAsset, public IPrintable, public ILocalisable {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Desc;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	double UseCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost;

	/**
	 * Create a new card effect based on the effects of this ingredient.
	 * @param[in] OwningCard The card that owns this effect.
	 * @return The new effect.
	 */
	virtual UCardEffect* Apply(UCard* OwningCard);

	/**
	 * Modify an existing card effect based on the effects of this ingredient.
	 * @param Current The current effect. 
	 * @return The new effect.
	 */
	virtual UCardEffect* ComposeTo(UCardEffect* Current);

	FORCEINLINE virtual void Merge(TArray<TObjectPtr<UCardEffect>>& Base,
		const TArray<TObjectPtr<UCardEffect>> Others) {
		Base.Append(Others);
	}

	virtual FString ToString() const override;

	virtual FText ToText() const override;

	virtual FText ToRichText() const override;
};
