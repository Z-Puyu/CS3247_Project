// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Modifier.h"
#include "UObject/Object.h"
#include "SpellEffect.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class SPELLCRAFTINGSYSTEM_API USpellEffect : public UObject {
    GENERATED_BODY()

private:
    TMap<FGameplayTag, FModifier> Modifiers;

public:
    USpellEffect* AddModifier(const FGameplayTag& Attribute, const FModifier& Modifier);
    
    USpellEffect* AddCoefficient(const FGameplayTag& Attribute, const int32 Coefficient);

    USpellEffect* CloneTo(USpellEffect* Effect);

    void Merge(USpellEffect* Effect);
};
