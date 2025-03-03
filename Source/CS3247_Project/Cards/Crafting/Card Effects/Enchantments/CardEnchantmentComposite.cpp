// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentComposite.h"

UCardEffect* UCardEnchantmentComposite::Enchant(UCardEffect* Effect) {
	for (auto& Enchantment : this->Enchantments) {
		Effect = Enchantment.Get()->Enchant(Effect);	
	}
	
	return Effect;
}

