// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentSpecial.h"

#include "../Data/CardEffect.h"
#include "../Data/SpecialEffect.h"

UCardEffect* UCardEnchantmentSpecial::ComposeTo(UCardEffect* Effect) {
	Cast<USpecialEffect>(Effect->GetEffect(USpecialEffect::StaticClass()))->AddSpecialEffect(this->SpecialEffect);
	return Effect;
}

FString UCardEnchantmentSpecial::ToString() const {
	return FString::Printf(TEXT("On played: %s"), *this->SpecialEffect.ToString());
}

FText UCardEnchantmentSpecial::ToText() const {
	return FText::FromString(this->ToString());
}

FText UCardEnchantmentSpecial::ToRichText() const {
	return FText::FromString(this->ToString());
}

