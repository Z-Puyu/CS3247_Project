// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellEffect.h"

USpellEffect* USpellEffect::AddModifier(const FGameplayTag& Attribute, const FModifier& Modifier) {
    if (this->Modifiers.Contains(Attribute)) {
        this->Modifiers[Attribute] += Modifier;
    } else {
        this->Modifiers.Add(Attribute, Modifier);  
    }

    return this; 
}

USpellEffect* USpellEffect::AddCoefficient(const FGameplayTag& Attribute, const int32 Coefficient) {
    if (this->Modifiers.Contains(Attribute)) {
        this->Modifiers[Attribute] *= FMath::Max(0, Coefficient + 100) / 100.0;
    }

    return this;
}

USpellEffect* USpellEffect::CloneTo(USpellEffect* Effect) {
    for (const TPair<FGameplayTag, FModifier>& Modifier : this->Modifiers) {
        Effect->AddModifier(Modifier.Key, Modifier.Value);
    }

    return Effect;
}

void USpellEffect::Merge(USpellEffect* Effect) {
    for (const TPair<FGameplayTag, FModifier>& Modifier : Effect->Modifiers) {
        this->AddModifier(Modifier.Key, Modifier.Value);
    }  
}
