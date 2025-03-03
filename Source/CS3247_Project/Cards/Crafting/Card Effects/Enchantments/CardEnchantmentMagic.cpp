// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentMagic.h"

UCardEffect* UCardEnchantmentMagic::Enchant(UCardEffect* Effect) {
	const double ExtraDamageAmount = Effect->BaseDamage.DamageValue * this->Strength / 100.0;
	if (Effect->ExtraDamageEffects.Contains(this->EnchantmentType)) {
		Effect->ExtraDamageEffects[this->EnchantmentType] += ExtraDamageAmount;
	}

	return Effect;
}

