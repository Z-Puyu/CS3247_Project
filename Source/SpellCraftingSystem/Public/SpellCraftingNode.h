// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellCraftingPin.h"
#include "Engine/DataAsset.h"
#include "SpellCraftingNode.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class SPELLCRAFTINGSYSTEM_API USpellCraftingNode : public UDataAsset {
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly)
    FText Name;

    FORCEINLINE virtual void ProcessEffects() { }
    
public:
    FORCEINLINE virtual void InitialisePins() { }
    
    FORCEINLINE virtual TArray<USpellCraftingNode*> Predecessors() const {
        return {};
    }
    
    FORCEINLINE virtual TArray<USpellCraftingNode*> Successors() const {
        return {};
    }
    
    FORCEINLINE virtual bool IsExecutable() const {
        return true;
    }
    
    void Execute();
};
