// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentMagic.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../Data/EnchantmentDamageEffect.h"
#include "../../../../UI/Texts/Text.h"

UCardEffect* UCardEnchantmentMagic::ComposeTo(UCardEffect* Effect) {
	const UDamageEffect* BaseDamage = Cast<UDamageEffect>(Effect->GetEffect(UDamageEffect::StaticClass()));
	UEnchantmentDamageEffect* EnchantmentDamage =
		Cast<UEnchantmentDamageEffect>(Effect->GetEffect(UEnchantmentDamageEffect::StaticClass()));
	const double ExtraDamageAmount = static_cast<double>(*BaseDamage) * (this->Strength / 100.0);
	const double CurrentDmg = EnchantmentDamage->Get(this->EnchantmentType);
	EnchantmentDamage->Set(this->EnchantmentType, CurrentDmg + ExtraDamageAmount);
	return Effect;
}

FString UCardEnchantmentMagic::ToString() const {
	return FString::Printf(TEXT("%d%% %s enchantment"), this->Strength,
		*this->EnchantmentType.GetTagName().ToString());	
}

FText UCardEnchantmentMagic::ToText() const {
	return FText::FromString(this->ToString());
}

FText UCardEnchantmentMagic::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0}% {1} enchantment")),
		UText::Bf(FString::FromInt(this->Strength)),
		UText::BfIt(this->EnchantmentType.ToString()));
}

