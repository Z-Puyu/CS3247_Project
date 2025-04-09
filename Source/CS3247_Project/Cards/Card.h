// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UI/Texts/Localisable.h"
#include "Crafting/Card Effects/Data/CardEffect.h"
#include "Card.generated.h"

class UCardImpact;
struct FRecipeEdge;
class UCardIngredient;
class ILocalisable;
class UCardRecipe;
class UCardEffect;

#define DURABILITY_COEFFICIENT 100.0
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, DefaultToInstanced, EditInlineNew)
class CS3247_PROJECT_API UCard : public UObject, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn = "true"))
	bool bIsDefault;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double Durability;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<UCardEffect*> Effects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn = "true"))
	TObjectPtr<UCardRecipe> Recipe;
	
	UCard();
	
	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
	
	UFUNCTION(BlueprintCallable, Category = "Card Info")
	FORCEINLINE void GetCardData(int& UseCost, int& CardDurability, TArray<UCardEffect*>& CardEffects) const {
		UseCost = FMath::Max(1, FMath::Floor(this->Cost));
		CardDurability = FMath::CeilToInt32(this->Durability);
		CardEffects = this->Effects;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsHostile() const {
		return this->Effects.ContainsByPredicate([](const UCardEffect* E) -> bool { return E->IsHostile(); });
	}

	UFUNCTION(BlueprintCallable)
	TArray<UCardImpact*> TopThreeImpacts() const;

	FORCEINLINE bool operator==(const UCard& Other) const {
		return this->Recipe == Other.Recipe;
	}
	
	FORCEINLINE bool operator!=(const UCard& Other) const {
		return this->Recipe != Other.Recipe;
	}
	
	FORCEINLINE friend uint32 GetTypeHash(const UCard& Card) {
		return GetTypeHash(Card.Recipe);
	}
};
