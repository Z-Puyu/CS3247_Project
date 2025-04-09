// Fill out your copyright notice in the Description page of Project Settings.


#include "CardIngredient.h"
#include "../Card Effects/Data/CardEffect.h"
#include "../../../Cards/Card.h"
#include "../../../Items/Resources/Resource.h"

UCardNode* UCardIngredient::WrapIntoNode(UActorComponent* CardCrafter) {
	return nullptr;
}

int32 UCardIngredient::AggregateWorth() const {
	int32 TotalWorth = 0;
	for (auto& Entry : this->CraftCost) {
		TotalWorth += Entry.Key->Worth * Entry.Value;
	}

	return TotalWorth;
}

FString UCardIngredient::ToString_Implementation() const {
	return this->Name.ToString();
}

FText UCardIngredient::ToText_Implementation() const {
	return FText::FromString(Execute_ToString(this));
}

FText UCardIngredient::ToRichText_Implementation() const {
	return Execute_ToText(this);
}
