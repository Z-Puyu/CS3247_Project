// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingEnchantmentNode.h"

#include "../Public/SpellEffect.h"

void USpellCraftingEnchantmentNode::InitialisePins() {
    Super::InitialisePins();
    this->InputPin->OwnerNode = this;
    this->OutputPin->OwnerNode = this;   
}

TArray<USpellCraftingNode*> USpellCraftingEnchantmentNode::Predecessors() const {
    TArray<USpellCraftingNode*> Predecessors;
    if (this->InputPin->IsConnected()) {
        Predecessors.Add(this->InputPin->ConnectedPin->OwnerNode);  
    }
    
    return Predecessors;
}

TArray<USpellCraftingNode*> USpellCraftingEnchantmentNode::Successors() const {
    TArray<USpellCraftingNode*> Successors;
    if (this->OutputPin->IsConnected()) {
        Successors.Add(this->OutputPin->ConnectedPin->OwnerNode); 
    }

    return Successors;
}

bool USpellCraftingEnchantmentNode::IsExecutable() const {
    return Super::IsExecutable() ? this->InputPin->IsExecutable() && this->OutputPin->IsExecutable() : false;
}

void USpellCraftingEnchantmentNode::ProcessEffects() {
    Super::ProcessEffects();
    for (const TPair<FGameplayTag, FModifier>& Effect : this->AdditionalEffects) {
        this->OutputPin->FetchDataFrom(this->InputPin)->AddModifier(Effect.Key, Effect.Value);
    }

    for (const TPair<FGameplayTag, int32>& Coefficient : this->EffectScalers) {
        this->OutputPin->FetchDataFrom(this->InputPin)->AddCoefficient(Coefficient.Key, Coefficient.Value);
    }
}
