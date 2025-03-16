// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardIngredient.h"
#include "CardEnchantment.generated.h"
/**
 * An enchantment ingredient for card crafting.
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UCardEnchantment : public UCardIngredient {
	GENERATED_BODY()

public:
	/**
	 * Modify an existing card effect based on the effects of this ingredient.
	 * @param Current The current effect. 
	 * @return The new effect.
	 */
	virtual UCardEffect* ComposeTo(UCardEffect* Current);

	virtual UCardNode* WrapIntoNode(UActorComponent* CardCrafter) override;
};
