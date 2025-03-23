// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientMixer.h"

#include "ReactantKey.h"
#include "../../Card Effects/Impacts/CardImpact.h"
#include "../../Nodes/MixerNode.h"
#include "../Impacts/CardImpactRawPower.h"

UCardImpact* UIngredientMixer::Combine(UCard* OwningCard, const UCardImpact* Left, const UCardImpact* Right) {
	OwningCard->Cost += (this->UseCost + Left->UseCost + Right->UseCost);
	const FReactantKey Key = FReactantKey(Left->Id, Right->Id);
	if (this->Combinations.Contains(Key)) {
		// If the combination is legal, just return the new effect.
		return this->Combinations[Key];
	}

	// Otherwise, each cost is worth one possible raw power.
	const int32 LeftCost = Left->CraftCost;
	const int32 RightCost = Right->CraftCost;
	const int32 AvgCost = (LeftCost + RightCost) / 2;
	const int32 RawPower = FMath::RandRange(AvgCost, FMath::Max(LeftCost, RightCost));
	UCardImpactRawPower* RawPowerImpact = NewObject<UCardImpactRawPower>();
	RawPowerImpact->RawPower = RawPower;
	return RawPowerImpact;
}

UCardNode* UIngredientMixer::WrapIntoNode(UActorComponent* CardCrafter) {
	UMixerNode* Node = NewObject<UMixerNode>(CardCrafter);
	Node->Mixer = this;
	return Node;
}
