// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellCraftingNode.h"
#include "SpellCraftingSourceNode.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCRAFTINGSYSTEM_API USpellCraftingSourceNode : public USpellCraftingNode {
    GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly, Instanced)
    TObjectPtr<USpellEffect> Effect;

    UPROPERTY(EditDefaultsOnly)
    TArray<USpellCraftingPin*> OutputPins;
    
protected:
    virtual void ProcessEffects() override;

public:
    virtual void InitialisePins() override;
    
    virtual TArray<USpellCraftingNode*> Successors() const override;
    
    virtual bool IsExecutable() const override;
};
