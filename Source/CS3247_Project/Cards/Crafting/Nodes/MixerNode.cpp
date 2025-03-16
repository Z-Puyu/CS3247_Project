// Fill out your copyright notice in the Description page of Project Settings.


#include "MixerNode.h"
#include "ImpactNode.h"

TArray<TObjectPtr<UCardEffect>> UMixerNode::Build(UCard* OwningCard) {
	UCardImpact* Impact1 = Cast<UImpactNode>(this->FirstSuccessor)->Impact;
	UCardImpact* Impact2 = Cast<UImpactNode>(this->SecondSuccessor)->Impact;
	return {this->Mixer->Combine(Impact1, Impact2)->Apply(OwningCard)};	
}
