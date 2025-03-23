// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "CardImpactHeal.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardImpactHeal : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Heal")
	int32 Value;
	
	virtual TArray<UCardEffect*> Apply(UCard* OwningCard) override;
	
	virtual FString ToString_Implementation() const override;
	
	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;
};
