// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpactNode.h"

#include "../Card Effects/Impacts/CardImpact.h"

TArray<UCardEffect*> UImpactNode::Build(UCard& OwningCard, double& ModifierPower) {
	return this->Impact.Get()->Apply(&OwningCard);
}
