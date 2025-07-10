// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellCraftingNode.h"
#include "SpellCraftingCombinerNode.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SPELLCRAFTINGSYSTEM_API USpellCraftingCombinerNode : public USpellCraftingNode {
    GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly)
    int32 NumberOfInputs;
    
    UPROPERTY()
    TArray<USpellCraftingPin*> InputPins;

    UPROPERTY()
    TObjectPtr<USpellCraftingPin> OutputPin;

public:
    virtual void InitialisePins() override;

    virtual TArray<USpellCraftingNode*> Predecessors() const override;

    virtual TArray<USpellCraftingNode*> Successors() const override;

    virtual bool IsExecutable() const override;

protected:
    virtual void ProcessEffects() override;
};
