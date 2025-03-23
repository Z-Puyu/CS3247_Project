// Fill out your copyright notice in the Description page of Project Settings.


#include "MixerNode.h"
#include "ImpactNode.h"

TArray<UCardEffect*> UMixerNode::Build(UCard& OwningCard, double& ModifierPower) {
	const UCardImpact* Impact1 = Cast<UImpactNode>(this->FirstSuccessor)->Impact;
	const UCardImpact* Impact2 = Cast<UImpactNode>(this->SecondSuccessor)->Impact;
	return {this->Mixer->Combine(&OwningCard, Impact1, Impact2)->Apply(&OwningCard)};	
}
