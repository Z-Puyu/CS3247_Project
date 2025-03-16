// Fill out your copyright notice in the Description page of Project Settings.


#include "AtomicCardEffect.h"
void UAtomicCardEffect::ScaleStrength(const double Ratio) {}

FString UAtomicCardEffect::ToString_Implementation() const {
	return this->GetName();
}

FText UAtomicCardEffect::ToText_Implementation() const {
	return FText::FromString(Execute_ToString(this));
}

FText UAtomicCardEffect::ToRichText_Implementation() const {
	return Execute_ToText(this);
}

void UAtomicCardEffect::OffsetStrength(const double Offset) {}
