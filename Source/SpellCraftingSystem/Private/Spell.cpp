// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Spell.h"
bool USpell::IsFeasible(UAttributeSetComponent* Caster, UAttributeSetComponent* Target) const {
    return true; 
}

void USpell::Apply(UAttributeSetComponent* Caster, UAttributeSetComponent* Target) {}

USpell* USpell::WithCastingCost(const FGameplayTag& Attribute, const double Cost) {
    if (this->CastingCosts.Contains(Attribute)) {
        this->CastingCosts[Attribute] += Cost;
    } else {
        this->CastingCosts.Add(Attribute, Cost);   
    }

    return this;   
}
