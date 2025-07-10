// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingCombinerNode.h"

#include "../Public/SpellEffect.h"

void USpellCraftingCombinerNode::InitialisePins() {
    Super::InitialisePins();
    this->OutputPin = NewObject<USpellCraftingPin>(this)->WithName(FText::FromString(TEXT("Spell out")));
    this->OutputPin->OwnerNode = this;
    for (int i = 0; i < this->NumberOfInputs; i += 1) {
        FText PinName = FText::FromString(FString::Printf(TEXT("In %d"), i + 1));
        this->InputPins.Add(NewObject<USpellCraftingPin>(this)->WithName(PinName));
        this->InputPins[i]->OwnerNode = this;   
    }
}

TArray<USpellCraftingNode*> USpellCraftingCombinerNode::Predecessors() const {
    TArray<USpellCraftingNode*> Predecessors;
    for (const USpellCraftingPin* InputPin : this->InputPins) {
        if (!InputPin->IsConnected()) {
            continue;
        }
        
        Predecessors.Add(InputPin->ConnectedPin->OwnerNode);
    }

    return Predecessors;
}

TArray<USpellCraftingNode*> USpellCraftingCombinerNode::Successors() const {
    TArray<USpellCraftingNode*> Predecessors;
    if (this->OutputPin->IsConnected()) {
        Predecessors.Add(this->OutputPin->ConnectedPin->OwnerNode);   
    }

    return Predecessors;
}

bool USpellCraftingCombinerNode::IsExecutable() const {
    if (!Super::IsExecutable()) {
        return false;
    }

    if (!this->OutputPin->IsExecutable()) {
        return false;
    }

    for (const USpellCraftingPin* InputPin : this->InputPins) {
        if (!InputPin->IsExecutable()) {
            return false;       
        }
    }

    return true;
}

void USpellCraftingCombinerNode::ProcessEffects() {
    Super::ProcessEffects();
    this->OutputPin->MergeDataFrom(this->InputPins);
    // TODO: Add energy decay mechanics.
}
