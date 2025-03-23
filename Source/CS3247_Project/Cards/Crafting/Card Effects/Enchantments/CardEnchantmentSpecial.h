// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "GameplayTagContainer.h"
#include "CardEnchantmentSpecial.generated.h"

class UCardEffect;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentSpecial : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories = "SpecialCardEffect"))
	FGameplayTag SpecialEffect;

	virtual UCardEffect* ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) override;

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
};
