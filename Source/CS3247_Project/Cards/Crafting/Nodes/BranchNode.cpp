// Fill out your copyright notice in the Description page of Project Settings.


#include "BranchNode.h"

TArray<UCardEffect*> UBranchNode::Build(UCard& OwningCard, double& ModifierPower) {
	TArray<UCardEffect*> CardEffects = this->FirstSuccessor->Build(OwningCard, ModifierPower);
	CardEffects.Append(this->SecondSuccessor->Build(OwningCard, ModifierPower));
	ModifierPower *= (1 - this->Brancher->EnchantmentPowerDecay / 100.0);
	return CardEffects;
}
