// Fill out your copyright notice in the Description page of Project Settings.


#include "BranchNode.h"

TArray<UCardEffect*> UBranchNode::Build(UCard& OwningCard, double& ModifierPower) {
	TArray<UCardEffect*> CardEffects = this->FirstSuccessor->Build(OwningCard, ModifierPower);
	this->Brancher->Merge(&OwningCard, CardEffects, this->SecondSuccessor->Build(OwningCard, ModifierPower)); 
	ModifierPower *= (1 - this->Brancher->EnchantmentPowerDecay / 100.0);
	return CardEffects;
}

/*TArray<UCardEffect*> UBranchNode::Preview(double& ModifierPower) {
	TArray<UCardEffect*> CardEffects = this->FirstSuccessor->Preview(ModifierPower);
	this->Brancher->Merge(CardEffects, this->SecondSuccessor->Preview(ModifierPower));
	ModifierPower *= (1 - this->Brancher->EnchantmentPowerDecay / 100.0);
	return CardEffects;
}*/
