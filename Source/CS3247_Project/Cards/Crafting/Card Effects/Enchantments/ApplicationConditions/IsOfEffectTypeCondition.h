// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnchantmentApplicationCondition.h"
#include "IsOfEffectTypeCondition.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UIsOfEffectTypeCondition : public UEnchantmentApplicationCondition {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAtomicCardEffect> AllowedType;
	
	virtual bool IsSatisfiedBy(UAtomicCardEffect& Effect) const override;
};
