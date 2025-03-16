// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientBrancher.h"

#include "../Data/CardEffect.h"
#include "../../Nodes/BranchNode.h"

void UIngredientBrancher::Merge(TArray<TObjectPtr<UCardEffect>>& Base, const TArray<TObjectPtr<UCardEffect>> Others) const {
	Base.Append(Others);
	for (const auto& Effect : Base) {
		Effect->EnchantmentDecay *= (1 - this->EnchantmentPowerDecay / 100.0);
	}
}

UCardNode* UIngredientBrancher::WrapIntoNode(UActorComponent* CardCrafter) {
	UBranchNode* Node = NewObject<UBranchNode>(CardCrafter);
	Node->Brancher = this;
	return Node;
}
