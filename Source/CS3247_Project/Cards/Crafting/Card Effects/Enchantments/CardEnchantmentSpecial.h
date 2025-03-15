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

	virtual UCardEffect* ComposeTo(UCardEffect* Effect) override;

	virtual FString ToString() const override;

	virtual FText ToText() const override;

	virtual FText ToRichText() const override;
};
