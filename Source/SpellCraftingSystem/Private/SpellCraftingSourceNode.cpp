// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingSourceNode.h"

void USpellCraftingSourceNode::ProcessEffects() {
    Super::ProcessEffects();
    for (USpellCraftingPin* OutputPin : this->OutputPins) {
        OutputPin->SetData(this->Effect);
    }
}

void USpellCraftingSourceNode::InitialisePins() {
    Super::InitialisePins();
    for (USpellCraftingPin* OutputPin : this->OutputPins) {
        OutputPin->OwnerNode = this;
    }
}

TArray<USpellCraftingNode*> USpellCraftingSourceNode::Successors() const {
    TArray<USpellCraftingNode*> Successors;
    for (const USpellCraftingPin* OutputPin : this->OutputPins) {
        if (OutputPin->IsConnected()) {
            Successors.Add(OutputPin->ConnectedPin->OwnerNode);
        }
    }

    return Successors;
}

bool USpellCraftingSourceNode::IsExecutable() const {
    if (!Super::IsExecutable()) {
        return false;
    }

    for (const USpellCraftingPin* OutputPin : this->OutputPins) {
        if (!OutputPin->IsConnected()) {
            return false;
        }
    }

    return true;
}
