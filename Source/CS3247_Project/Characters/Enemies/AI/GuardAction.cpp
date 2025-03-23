// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAction.h"
#include "AiDecisionContext.h"
#include "../EnemyCharacter.h"
#include "../../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"

float UGuardAction::Evaluate(const FAiDecisionContext Context) const {
	const AEnemyCharacter* Self = Context.SelfData;
	const UBasicAttributeSet* AttributeSet = Cast<UBasicAttributeSet>(
		Self->GetAbilitySystemComponent()->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	const float RandomMultiplier = FMath::FRandRange(1 - this->RandomnessAllowance, 1 + this->RandomnessAllowance);
	return this->EvaluationCurve.GetRichCurveConst()->Eval(AttributeSet->GetHealth() / AttributeSet->GetMaxHealth()) * RandomMultiplier;
}
