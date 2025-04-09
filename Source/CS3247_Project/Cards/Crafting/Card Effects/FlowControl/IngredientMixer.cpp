// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientMixer.h"

#include "IngredientCombination.h"
#include "ReactantKey.h"
#include "../../Card Effects/Impacts/CardImpact.h"
#include "../../Nodes/MixerNode.h"

UCardImpact* UIngredientMixer::Combine(UCardImpact* Left, UCardImpact* Right) const {
	TArray<FIngredientCombination*> ValidCombinations;
	this->Combinations.LoadSynchronous()->GetAllRows(TEXT("ContextString"), ValidCombinations);
	for (const auto& Combi : ValidCombinations) {
		const bool IsMatch = Combi->First == Left && Combi->Second == Right ||
			Combi->First == Right && Combi->Second == Left;
		if (IsMatch) {
			return Combi->Result.LoadSynchronous();
		}	
	}
	return nullptr;
}

UCardNode* UIngredientMixer::WrapIntoNode(UActorComponent* CardCrafter) {
	UMixerNode* Node = NewObject<UMixerNode>(CardCrafter);
	Node->Mixer = this;
	return Node;
}
