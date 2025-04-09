#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "HealAllAction.generated.h"

/**
 * Heals all allies in AlliesData.
 */
UCLASS()
class CS3247_PROJECT_API UHealAllAction : public UEnemyAction
{
    GENERATED_BODY()

public:
    UHealAllAction();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Amount;

    virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;
    virtual FORCEINLINE bool IsHostile() const override { return false; }
    virtual FORCEINLINE bool IsAoe() const override { return true; }

    virtual FGameplayEffectDescriptor ToGameplayEffect() const override
    {
        return FGameplayEffectDescriptor(
            false,
            this->GameplayEffectType,
            FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Healing")),
            FGameplayTag::EmptyTag,
            this->Amount);
    }

protected:
    // If reflexive, this effect is always applied to the enemy itself regardless of which target it chooses.
    UPROPERTY(EditDefaultsOnly)
    bool bIsReflexive = false;
};
