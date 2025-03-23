// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "GameplayTagContainer.h"
#include "CardEnchantmentMagic.generated.h"

class UCardEffect;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentMagic : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="Damage.Magic"))
	FGameplayTag EnchantmentType;

	// The strength of the enchantment is in terms of percentage of impact amount.
	// On a hostile target, this translates to an additional damage;
	// On a friendly target, this translates to an additional magical aversion.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int Strength;
	
	virtual UCardEffect* ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) override;

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
};
