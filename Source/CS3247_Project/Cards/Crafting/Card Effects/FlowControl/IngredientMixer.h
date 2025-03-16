// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReactantKey.h"
#include "../CardIngredient.h"
#include "IngredientMixer.generated.h"

class UCardImpact;
/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UIngredientMixer : public UCardIngredient {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int ModifierEffect;
	
	UCardImpact* Combine(const UCardImpact* Left, const UCardImpact* Right);

	virtual UCardNode* WrapIntoNode(UActorComponent* CardCrafter) override;
private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FReactantKey, TObjectPtr<UCardImpact>> Combinations;
};
