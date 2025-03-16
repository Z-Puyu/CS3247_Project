// Fill out your copyright notice in the Description page of Project Settings.


#include "EnchantNode.h"

TArray<TObjectPtr<UCardEffect>> UEnchantNode::Build(UCard* OwningCard) {
	TArray<TObjectPtr<UCardEffect>> SuccessorEffects = this->FirstSuccessor->Build(OwningCard);
	TArray<TObjectPtr<UCardEffect>> CardEffects = {};
	for (auto& CardEffect : SuccessorEffects) {
		CardEffects.Add(this->Enchantment.Get()->ComposeTo(CardEffect.Get()));
	}
	
	return CardEffects;
}
