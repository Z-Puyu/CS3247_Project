// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SpellCraftingNode.h"
#include "../../AttributeSystem/Public/Modifier.h"
#include "SpellCraftingEnchantmentNode.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCRAFTINGSYSTEM_API USpellCraftingEnchantmentNode : public USpellCraftingNode {
    GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<USpellCraftingPin> InputPin;
    
    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<USpellCraftingPin> OutputPin;

    UPROPERTY(EditDefaultsOnly)
    TMap<FGameplayTag, FModifier> AdditionalEffects;

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = -100))
    TMap<FGameplayTag, int32> EffectScalers;

public:
    virtual void InitialisePins() override;

    virtual TArray<USpellCraftingNode*> Predecessors() const override;

    virtual TArray<USpellCraftingNode*> Successors() const override;

    virtual bool IsExecutable() const override;

protected:
    virtual void ProcessEffects() override;
};
