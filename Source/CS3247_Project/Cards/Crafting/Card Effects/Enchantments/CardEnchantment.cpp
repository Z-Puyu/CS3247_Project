// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantment.h"

#include "../../Nodes/EnchantNode.h"


UCardEffect* UCardEnchantment::ComposeTo(UCard* OwningCard, UCardEffect* Current, double Multiplier) {
	this->AddCost(*OwningCard);
	this->ChangeDurability(*OwningCard);
	return Current;
}

UCardNode* UCardEnchantment::WrapIntoNode(UActorComponent* CardCrafter) {
	UEnchantNode* Node = NewObject<UEnchantNode>(CardCrafter);
	Node->Enchantment = this;
	return Node;
}
