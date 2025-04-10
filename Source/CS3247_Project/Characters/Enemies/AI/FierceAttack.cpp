#include "FierceAttack.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../../../Common/BasicGameInstance.h"
#include "Kismet/GameplayStatics.h"


UFierceAttack::UFierceAttack() {
    this->DamageData = FEnemyAttack();

    static ConstructorHelpers::FClassFinder<UGameplayEffect> GameplayEffectClassFinder(
        TEXT("/Game/Assets/GameplayAbilities/GameplayEffects/GE_Damage")
    );
    this->GameplayEffectType = GameplayEffectClassFinder.Class;

    // Use the correct variable names
    this->CooldownRemaining = this->MaxCooldown;
}

float UFierceAttack::Evaluate(const UWorld* World, const FAiDecisionContext& Context) const {
    if (this->CooldownRemaining > 0) {
        return 0.0f;
    }

    UBasicGameInstance* GameInstance = Cast<UBasicGameInstance>(UGameplayStatics::GetGameInstance(World));
    const ABasicCharacter* Target = Context.TargetsData[0];
    const UAbilitySystemComponent* TargetAbilitySystem = Target->GetAbilitySystemComponent();
    const UBasicAttributeSet* TargetAttributes = Cast<UBasicAttributeSet>(
        TargetAbilitySystem->GetAttributeSet(UBasicAttributeSet::StaticClass()));

    int32 ActualDamage = this->DamageData.Value;
    if (GameInstance->ResistanceTypes.Contains(this->DamageData.DamageType)) {
        const int32 TargetResistance = TargetAbilitySystem->GetNumericAttribute(
            GameInstance->ResistanceTypes[this->DamageData.DamageType]);
        ActualDamage *= (100 - TargetResistance) / 100.0f;
    }

    return ActualDamage / TargetAttributes->GetHealth();
}
