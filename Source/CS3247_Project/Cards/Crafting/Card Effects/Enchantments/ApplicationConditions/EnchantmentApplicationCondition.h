// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnchantmentApplicationCondition.generated.h"

class UAtomicCardEffect;
/**
 * 
 */
UCLASS(Abstract, DefaultToInstanced, EditInlineNew, BlueprintType)
class CS3247_PROJECT_API UEnchantmentApplicationCondition : public UObject {
	GENERATED_BODY()

public:
	FORCEINLINE virtual bool IsSatisfiedBy(UAtomicCardEffect& Effect) const { return true; }
};
