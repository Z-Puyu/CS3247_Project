// Fill out your copyright notice in the Description page of Project Settings.

#include "HealAllAction.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"


UHealAllAction::UHealAllAction() : Amount(0), bIsReflexive(false)
{
    static ConstructorHelpers::FClassFinder<UGameplayEffect> GameplayEffectClassFinder(
        TEXT("/Game/Assets/GameplayAbilities/GameplayEffects/GE_Healing"));
    this->GameplayEffectType = GameplayEffectClassFinder.Class;
}

float UHealAllAction::Evaluate(const UWorld* World, const FAiDecisionContext& Context) const
{
    // If no allies, there's nothing to heal
    if (Context.TargetsData.Num() == 0)
    {
        return 0.f;
    }

    float TotalMissingHP = 0.f;
    float TotalMaxHP = 0.f;

    for (ABasicCharacter* Ally : Context.TargetsData)
    {
        if (!Ally) { continue; }

        const UBasicAttributeSet* AttrSet = Cast<UBasicAttributeSet>(
            Ally->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass())
        );
        if (!AttrSet) { continue; }

        float CurrentHP = AttrSet->GetHealth();
        float MaxHP = AttrSet->GetMaxHealth();

        TotalMissingHP += (MaxHP - CurrentHP);
        TotalMaxHP += MaxHP;
    }

    if (TotalMaxHP <= 0.f)
    {
        return 0.f;
    }


    float MissingRatio = TotalMissingHP / TotalMaxHP;

    return MissingRatio;

}
