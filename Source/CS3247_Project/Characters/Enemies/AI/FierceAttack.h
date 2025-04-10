#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "../EnemyAttack.h"
#include "FierceAttack.generated.h"

UCLASS()
class CS3247_PROJECT_API UFierceAttack : public UEnemyAction
{
    GENERATED_BODY()

private:
    int32 CooldownRemaining = 0;
    int32 MaxCooldown = 3; // <-- Semicolon added

public:
    UFierceAttack();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FEnemyAttack DamageData;

    virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;

    FORCEINLINE virtual bool IsHostile() const override { return true; }
    FORCEINLINE virtual bool IsAoe() const override { return false; }
    FORCEINLINE virtual bool IsReflexive() const override { return false; }

    virtual FORCEINLINE FGameplayEffectDescriptor ToGameplayEffect() const override {
        return FGameplayEffectDescriptor(
            false,
            this->GameplayEffectType,
            FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Damage")),
            this->DamageData.DamageType,
            this->DamageData.Value
        );
    }
};
