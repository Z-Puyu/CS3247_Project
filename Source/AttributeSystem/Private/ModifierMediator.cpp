// Fill out your copyright notice in the Description page of Project Settings.


#include "ModifierMediator.h"

void UModifierMediator::Add(const FGameplayTag& Target, const FModifier& Modifier) {
	if (this->Modifiers.Contains(Target)) {
		this->Modifiers[Target] += Modifier;
	} else {
		this->Modifiers.Add(Target, Modifier);
	}
}

int32 UModifierMediator::QueryBonus(const FGameplayTag& Attribute, const int32 Base) {
	const FModifier Modifier = this->Modifiers.FindOrAdd(Attribute, FModifier::Zero);
	const double Exact = Modifier.Offset + Base * Modifier.Multiplier / 100.0 + Modifier.Shift;
	return FMath::RoundToInt32(Exact);
}

int32 UModifierMediator::QueryValue(const FGameplayTag& Attribute, const int32 Base) {
	const FModifier Modifier = this->Modifiers.FindOrAdd(Attribute, FModifier::Zero);
	const double Exact = (Base + Modifier.Offset) * (Modifier.Multiplier + 100) / 100.0 + Modifier.Shift;
	return FMath::RoundToInt32(Exact);
}

int32 UModifierMediator::ProjectValue(const FGameplayTag& Attribute, const FModifier& Modifier, const int32 Base) {
	const FModifier ProjectedModifier = this->Modifiers.FindOrAdd(Attribute, FModifier::Zero) + Modifier;
	const double Exact = (Base + ProjectedModifier.Offset) * (ProjectedModifier.Multiplier + 100) / 100.0 +
		ProjectedModifier.Shift;
	return FMath::RoundToInt32(Exact);
}
