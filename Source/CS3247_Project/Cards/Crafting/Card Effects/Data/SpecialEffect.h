// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "GameplayTagContainer.h"
#include "SpecialEffect.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API USpecialEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer SpecialEffects;

	USpecialEffect() : SpecialEffects({}) {}

	void AddSpecialEffect(const FGameplayTag EffectType) {
		this->SpecialEffects.AddTag(EffectType);
	}
};
