// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardEnchantment.h"
#include "CardEnchantmentComposite.generated.h"

class UCardEffect;
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UCardEnchantmentComposite : public UCardEnchantment {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Inner Enchantments")
	TArray<TSoftObjectPtr<UCardEnchantment>> Enchantments;
	
	virtual UCardEffect* ComposeTo(UCardEffect* Effect) override;
};
