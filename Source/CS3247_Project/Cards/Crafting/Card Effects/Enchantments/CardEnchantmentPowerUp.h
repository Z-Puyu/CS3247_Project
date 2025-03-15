// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "CardEnchantmentPowerUp.generated.h"

class UAtomicCardEffect;
class UCardEffect;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentPowerUp : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Modifier")
	int Value;
	
	virtual UCardEffect* ComposeTo(UCardEffect* Effect) override;

	virtual FString ToString() const override;

	virtual FText ToText() const override;

	virtual FText ToRichText() const override;
private:
	bool IsApplicableTo(const UAtomicCardEffect* Effect) const;
};
