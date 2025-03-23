// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentComposite.h"

UCardEffect* UCardEnchantmentComposite::ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) {
	for (auto& Enchantment : this->Enchantments) {
		Effect = Enchantment.Get()->ComposeTo(OwningCard, Effect, Multiplier);	
	}
	
	return Effect;
}

