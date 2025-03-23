// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpact.h"

#include "../../Nodes/ImpactNode.h"
#include "../../../Card.h"
#include "../Data/CardEffect.h"

TArray<UCardEffect*> UCardImpact::Apply(UCard* OwningCard) {
	Super::AddCost(*OwningCard);
	return {NewObject<UCardEffect>(OwningCard)};
}

UCardNode* UCardImpact::WrapIntoNode(UActorComponent* CardCrafter) {
	UImpactNode* Node = NewObject<UImpactNode>(CardCrafter);
	Node->Impact= this;
	return Node;
}
