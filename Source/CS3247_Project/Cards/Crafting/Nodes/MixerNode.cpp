// Fill out your copyright notice in the Description page of Project Settings.


#include "MixerNode.h"
#include "ImpactNode.h"
#include "../Card Effects/Impacts/CardImpactRawPower.h"

TArray<UCardEffect*> UMixerNode::Build(UCard& OwningCard, double& ModifierPower) {
	UCardImpact* Impact1 = Cast<UImpactNode>(this->FirstSuccessor)->Impact;
	UCardImpact* Impact2 = Cast<UImpactNode>(this->SecondSuccessor)->Impact;
	if (UCardImpact* Result = this->Mixer->Combine(Impact1, Impact2)) {
		this->Impact = Result;
		return {Result->Apply(&OwningCard)};
	}

	const int32 LeftCost = this->FirstSuccessor->Unpack().Ingredient->AggregateWorth();
	const int32 RightCost = this->SecondSuccessor->Unpack().Ingredient->AggregateWorth();
	const int32 AvgCost = (LeftCost + RightCost) / 2;
	const int32 RawPower = FMath::RandRange(AvgCost, FMath::Max(LeftCost, RightCost));
	UCardImpactRawPower* RawPowerImpact = NewObject<UCardImpactRawPower>();
	RawPowerImpact->RawPower = RawPower;
	this->Impact = RawPowerImpact;
	return {RawPowerImpact->Apply(&OwningCard)};	
}
