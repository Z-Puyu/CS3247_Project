// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackAction.h"

#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../../../Common/BasicGameInstance.h"
#include "Kismet/GameplayStatics.h"

UAttackAction::UAttackAction() {
	this->DamageData = FEnemyAttack();
	static ConstructorHelpers::FClassFinder<UGameplayEffect> GameplayEffectClassFinder(
			TEXT("/Game/Assets/GameplayAbilities/GameplayEffects/GE_Damage"));
	this->GameplayEffectType = GameplayEffectClassFinder.Class;
}

float UAttackAction::Evaluate(const UWorld* World, const FAiDecisionContext& Context) const {
	UBasicGameInstance* GameInstance = Cast<UBasicGameInstance>(UGameplayStatics::GetGameInstance(World));
	// You can only attack the player. Otherwise, something wild is happening.
	const ABasicCharacter* Target = Context.TargetsData[0];
	const UAbilitySystemComponent* TargetAbilitySystem = Target->GetAbilitySystemComponent();
	const UBasicAttributeSet* TargetAttributes = Cast<UBasicAttributeSet>(
		Target->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	int32 ActualDamage = this->DamageData.Value;
	if (GameInstance->ResistanceTypes.Contains(this->DamageData.DamageType)) {
		const int32 TargetResistance = TargetAbilitySystem->GetNumericAttribute(
			GameInstance->ResistanceTypes[this->DamageData.DamageType]);
		ActualDamage *= ((100 - TargetResistance) / 100.0);
	}
	
	return ActualDamage / TargetAttributes->GetHealth();
}
