// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellCraftingNode.h"
#include "SpellCraftingSplitterNode.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCRAFTINGSYSTEM_API USpellCraftingSplitterNode : public USpellCraftingNode {
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 2))
    int32 NumberOfOutputs;
    
    UPROPERTY()
    TObjectPtr<USpellCraftingPin> InputPin;
    
    UPROPERTY()
    TArray<USpellCraftingPin*> OutputPins;

public:
    virtual void InitialisePins() override;

    virtual TArray<USpellCraftingNode*> Successors() const override;

    virtual TArray<USpellCraftingNode*> Predecessors() const override;

    virtual bool IsExecutable() const override;

protected:
    virtual void ProcessEffects() override;
};
