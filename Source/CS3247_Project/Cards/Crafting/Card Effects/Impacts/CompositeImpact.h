// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardImpact.h"
#include "CompositeImpact.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCompositeImpact : public UCardImpact {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, meta=(Categories="Inner Impacts"))
	TArray<UCardImpact*> InnerImpacts;

	virtual TArray<UCardEffect*> Apply(UCard* OwningCard) override;

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
};
