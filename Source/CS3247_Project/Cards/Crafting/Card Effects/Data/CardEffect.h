// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "../../../../UI/Texts/Localisable.h"
#include "../../../../UI/Texts/Printable.h"
#include "UObject/Object.h"
#include "CardEffect.generated.h"

/**
 * One complete card effect. It can consist of the following atomic effects:
 * - Mana Cost (always)
 * - Damage
 * - Healing
 * - Enchantment Damage
 * - Special Effects
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCardEffect : public UObject, public IPrintable, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	TMap<TSubclassOf<UAtomicCardEffect>, UAtomicCardEffect*> AtomicEffects;
	
	UCardEffect() : AtomicEffects({}) {}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UAtomicCardEffect* GetEffect(const TSubclassOf<UAtomicCardEffect> EffectType) const {
		return this->AtomicEffects.Contains(EffectType) ? this->AtomicEffects[EffectType] : nullptr;
	}

	FORCEINLINE void SetEffect(const TSubclassOf<UAtomicCardEffect>& EffectType,
		UAtomicCardEffect* Effect) {
		this->AtomicEffects.Add(EffectType, Effect);
	}

	bool IsHostile() const;

	virtual FString ToString_Implementation() const override;
	
	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;
};
