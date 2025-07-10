// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Spell.generated.h"

class UAttributeSetComponent;
class USpellEffect;
/**
 * 
 */
UCLASS(BlueprintType)
class SPELLCRAFTINGSYSTEM_API USpell : public UObject {
    GENERATED_BODY()

private:
    TMap<FGameplayTag, double> CastingCosts;
    
    UPROPERTY()
    TObjectPtr<USpellEffect> EffectOnCaster;

    UPROPERTY()
    TObjectPtr<USpellEffect> EffectOnTarget;

public:
    bool IsFeasible(UAttributeSetComponent* Caster, UAttributeSetComponent* Target) const;
    
    void Apply(UAttributeSetComponent* Caster, UAttributeSetComponent* Target);

    FORCEINLINE USpell* WithEffectOnCaster(USpellEffect* Effect) {
        this->EffectOnCaster = Effect;
        return this;
    }

    FORCEINLINE USpell* WithEffectOnTarget(USpellEffect* Effect) {
        this->EffectOnTarget = Effect;
        return this;
    }

    USpell* WithCastingCost(const FGameplayTag& Attribute, const double Cost);
};
