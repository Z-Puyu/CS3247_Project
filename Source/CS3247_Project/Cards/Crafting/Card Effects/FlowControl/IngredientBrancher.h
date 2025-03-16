// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IngredientMixer.h"
#include "IngredientBrancher.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UIngredientBrancher : public UIngredientMixer {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	int32 EnchantmentPowerDecay;
	
	void Merge(TArray<TObjectPtr<UCardEffect>>& Base, const TArray<TObjectPtr<UCardEffect>> Others) const;

	virtual UCardNode* WrapIntoNode(UActorComponent* CardCrafter) override;
};
