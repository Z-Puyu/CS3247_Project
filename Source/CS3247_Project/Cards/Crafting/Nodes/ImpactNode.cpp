// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpactNode.h"

#include "../Card Effects/Impacts/CardImpact.h"

TArray<TObjectPtr<UCardEffect>> UImpactNode::Build(UCard* OwningCard) {
	return {this->Impact.Get()->Apply(OwningCard)};
}
