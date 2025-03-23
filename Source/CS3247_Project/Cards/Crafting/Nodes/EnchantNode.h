// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardNode.h"
#include "../Card Effects/Enchantments/CardEnchantment.h"
#include "EnchantNode.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UEnchantNode : public UCardNode {
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UCardEnchantment> Enchantment;

	FORCEINLINE virtual FIngredientKey Unpack() const override { return FIngredientKey(this->Enchantment, this->Id); }
	
	virtual TArray<UCardEffect*> Build(UCard& OwningCard, double& ModifierPower) override;

	FORCEINLINE virtual FString ToString_Implementation() const override { return TEXT("[" + this->Enchantment->GetName() + "]"); }
};
