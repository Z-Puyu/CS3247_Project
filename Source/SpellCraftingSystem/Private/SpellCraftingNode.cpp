// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingNode.h"

#include "../Public/SpellCraftingSystem.h"

void USpellCraftingNode::Execute() {
    if (!this->IsExecutable()) {
        UE_LOG(LogCraftingSystem, Error, TEXT("Node %s is not executable"), *this->Name.ToString());
        return;
    }

    this->ProcessEffects();  
}