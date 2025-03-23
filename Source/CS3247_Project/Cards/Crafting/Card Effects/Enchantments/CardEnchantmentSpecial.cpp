// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentSpecial.h"

#include "../Data/CardEffect.h"
#include "../Data/SpecialEffect.h"

UCardEffect* UCardEnchantmentSpecial::ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) {
	Super::ComposeTo(OwningCard, Effect, Multiplier);
	Cast<USpecialEffect>(Effect->GetEffect(USpecialEffect::StaticClass()))->AddSpecialEffect(this->SpecialEffect);
	return Effect;
}

FString UCardEnchantmentSpecial::ToString_Implementation() const {
	return FString::Printf(TEXT("On played: %s"), *this->SpecialEffect.ToString());
}

FText UCardEnchantmentSpecial::ToText_Implementation() const {
	return FText::FromString(Execute_ToString(this));
}

FText UCardEnchantmentSpecial::ToRichText_Implementation() const {
	return Execute_ToText(this);
}

