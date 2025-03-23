// Fill out your copyright notice in the Description page of Project Settings.


#include "EnchantNode.h"

TArray<UCardEffect*> UEnchantNode::Build(UCard& OwningCard, double& ModifierPower) {
	TArray<UCardEffect*> SuccessorEffects = this->FirstSuccessor->Build(OwningCard, ModifierPower);
	TArray<UCardEffect*> CardEffects = {};
	for (const auto& CardEffect : SuccessorEffects) {
		CardEffects.Add(this->Enchantment.Get()->ComposeTo(&OwningCard, CardEffect, ModifierPower));
	}
	
	return CardEffects;
}
