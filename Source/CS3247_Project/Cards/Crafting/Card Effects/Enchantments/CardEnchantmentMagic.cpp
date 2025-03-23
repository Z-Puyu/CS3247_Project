// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentMagic.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../Data/EnchantmentDamageEffect.h"
#include "../../../../UI/Texts/Text.h"

UCardEffect* UCardEnchantmentMagic::ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) {
	Effect = Super::ComposeTo(OwningCard, Effect, Multiplier);
	const UDamageEffect* BaseDamage = Cast<UDamageEffect>(Effect->GetEffect(UDamageEffect::StaticClass()));
	UEnchantmentDamageEffect* EnchantmentDamage =
		Cast<UEnchantmentDamageEffect>(Effect->GetEffect(UEnchantmentDamageEffect::StaticClass()));
	if (!IsValid(EnchantmentDamage)) {
		EnchantmentDamage = NewObject<UEnchantmentDamageEffect>(Effect);
		Effect->SetEffect(UEnchantmentDamageEffect::StaticClass(), EnchantmentDamage);
	}
	
	const double ExtraDamageAmount = static_cast<double>(*BaseDamage) * (this->Strength * Multiplier / 100.0);
	const double CurrentDmg = EnchantmentDamage->Get(this->EnchantmentType);
	EnchantmentDamage->Set(this->EnchantmentType, CurrentDmg + ExtraDamageAmount);
	return Effect;
}

FString UCardEnchantmentMagic::ToString_Implementation() const {
	return FString::Printf(TEXT("%d%% %s enchantment"), this->Strength,
		*this->EnchantmentType.GetTagName().ToString());	
}

FText UCardEnchantmentMagic::ToText_Implementation() const {
	return FText::FromString(Execute_ToString(this));
}

FText UCardEnchantmentMagic::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0}% {1} enchantment")),
		UText::Bf(FString::FromInt(this->Strength)),
		UText::BfIt(this->EnchantmentType.ToString()));
}

