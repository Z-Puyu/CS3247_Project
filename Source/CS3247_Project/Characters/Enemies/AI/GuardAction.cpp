// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAction.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"

UGuardAction::UGuardAction() : Amount(0), bIsReflexive(false), bIsAoe(false) {
	static ConstructorHelpers::FClassFinder<UGameplayEffect> GameplayEffectClassFinder(
			TEXT("/Game/Assets/GameplayAbilities/GameplayEffects/GE_Defend"));
	this->GameplayEffectType = GameplayEffectClassFinder.Class;
}

float UGuardAction::Evaluate(const UWorld* World, const FAiDecisionContext& Context) const {
	const ABasicCharacter* Target = this->IsReflexive() ? Context.SelfData : Context.TargetsData[0];
	const UBasicAttributeSet* AttributeSet = Cast<UBasicAttributeSet>(
		Target->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	return AttributeSet->GetHealth() / AttributeSet->GetMaxHealth();
}
