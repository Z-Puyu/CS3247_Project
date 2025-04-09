// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientBrancher.h"

#include "../Data/CardEffect.h"
#include "../../Nodes/BranchNode.h"

void UIngredientBrancher::Merge(UCard* OwningCard, TArray<UCardEffect*>& LeftEffects, const TArray<UCardEffect*>& RightEffects) const {
	this->AddCost(*OwningCard);
	this->ChangeDurability(*OwningCard);
	LeftEffects.Append(RightEffects);
}

UCardNode* UIngredientBrancher::WrapIntoNode(UActorComponent* CardCrafter) {
	UBranchNode* Node = NewObject<UBranchNode>(CardCrafter);
	Node->Brancher = this;
	return Node;
}
