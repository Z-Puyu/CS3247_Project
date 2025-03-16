// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientMixer.h"

#include "ReactantKey.h"
#include "../../Card Effects/Impacts/CardImpact.h"
#include "../../Nodes/MixerNode.h"

UCardImpact* UIngredientMixer::Combine(const UCardImpact* Left, const UCardImpact* Right) {
	const FReactantKey Key = FReactantKey(Left->Id, Right->Id);
	if (this->Combinations.Contains(Key)) {
		return this->Combinations[Key];
	}

	return nullptr;
}

UCardNode* UIngredientMixer::WrapIntoNode(UActorComponent* CardCrafter) {
	UMixerNode* Node = NewObject<UMixerNode>(CardCrafter);
	Node->Mixer = this;
	return Node;
}
