// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardIngredient.h"
#include "Engine/DataAsset.h"
#include "CardImpact.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardImpact : public UCardIngredient {
	GENERATED_BODY()

public:
	/**
	 * Create a new card effect based on the effects of this ingredient.
	 * @param[in] OwningCard The card that owns this effect.
	 * @return The new effects.
	 */
	virtual TArray<UCardEffect*> Apply(UCard* OwningCard);

	virtual UCardNode* WrapIntoNode(UActorComponent* CardCrafter) override;

	bool operator<(UCardImpact* Other) const;
	
	bool operator>(const UCardImpact& Other) const;

	bool operator<(const UCardImpact& Other) const;

	bool operator>=(const UCardImpact& Other) const;

	bool operator<=(const UCardImpact& Other) const;
};
