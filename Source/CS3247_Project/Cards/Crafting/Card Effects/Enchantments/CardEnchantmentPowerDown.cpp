// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerDown.h"

UCardEffect* UCardEnchantmentPowerDown::Enchant(UCardEffect* Effect) {
	const double Ratio = FMath::Clamp(1 - this->Value / 100.0, 0.0, 1.0);
	Effect->BaseDamage *= Ratio;
	Effect->HealAmount *= Ratio;
	for (auto& ExtraDamage : Effect->ExtraDamageEffects) {
		Effect->ExtraDamageEffects[ExtraDamage.Key] *= Ratio;
	}
	
	return Effect;
}