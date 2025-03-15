// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "GameplayTagContainer.h"
#include "CardImpactDamage.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardImpactDamage : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, meta=(Categories="Damage"))
	FGameplayTag DamageType;

	UPROPERTY(EditDefaultsOnly, meta=(Categories="Damage"))
	int32 Value;
	
	virtual UCardEffect* Apply(UCard* OwningCard) override;

	virtual FString ToString() const override;

	virtual FText ToText() const override;

	virtual FText ToRichText() const override;
};
