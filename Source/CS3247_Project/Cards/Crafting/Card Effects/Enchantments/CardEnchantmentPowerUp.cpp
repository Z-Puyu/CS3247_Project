// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerUp.h"

UCardEffect* UCardEnchantmentPowerUp::Enchant(UCardEffect* Effect) {
	const double Ratio = FMath::Max(1 + this->Value / 100.0, 1.0);
	Effect->BaseDamage *= Ratio;
	Effect->HealAmount *= Ratio;
	for (auto& ExtraDamage : Effect->ExtraDamageEffects) {
		Effect->ExtraDamageEffects[ExtraDamage.Key] *= Ratio;
	}
	
	return Effect;
}