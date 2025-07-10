// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingSplitterNode.h"

#include "../Public/SpellEffect.h"

void USpellCraftingSplitterNode::InitialisePins() {
    Super::InitialisePins();
    this->InputPin = NewObject<USpellCraftingPin>(this)->WithName(FText::FromString(TEXT("Spell in")));
    this->InputPin->OwnerNode = this;
    for (int i = 0; i < this->NumberOfOutputs; i += 1) {
        FText PinName = FText::FromString(FString::Printf(TEXT("Out %d"), i + 1));
        this->OutputPins.Add(NewObject<USpellCraftingPin>(this)->WithName(PinName));
        this->OutputPins[i]->OwnerNode = this;   
    }
}

TArray<USpellCraftingNode*> USpellCraftingSplitterNode::Successors() const {
    TArray<USpellCraftingNode*> Successors;
    for (const USpellCraftingPin* OutputPin : this->OutputPins) {
        if (!OutputPin->IsConnected()) {
            continue;
        }
        
        Successors.Add(OutputPin->ConnectedPin->OwnerNode);
    }

    return Successors;
}

TArray<USpellCraftingNode*> USpellCraftingSplitterNode::Predecessors() const {
    TArray<USpellCraftingNode*> Predecessors;
    if (this->InputPin->IsConnected()) {
        Predecessors.Add(this->InputPin->ConnectedPin->OwnerNode);   
    }

    return Predecessors;
}

bool USpellCraftingSplitterNode::IsExecutable() const {
    if (!Super::IsExecutable()) {
        return false;
    }

    if (!this->InputPin->IsExecutable()) {
        return false;
    }

    for (const USpellCraftingPin* OutputPin : this->OutputPins) {
        if (!OutputPin->IsExecutable()) {
            return false;       
        }
    }

    return true;
}

void USpellCraftingSplitterNode::ProcessEffects() {
    Super::ProcessEffects();
    for (USpellCraftingPin* OutputPin : this->OutputPins) {
        OutputPin->CloneDataFrom(this->InputPin);
        // TODO: Add energy decay mechanics.
    }
}
