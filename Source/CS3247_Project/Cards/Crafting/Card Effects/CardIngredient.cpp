// Fill out your copyright notice in the Description page of Project Settings.


#include "CardIngredient.h"
#include "../Card Effects/Data/CardEffect.h"
#include "../../../Cards/Card.h"

UCardNode* UCardIngredient::WrapIntoNode(UActorComponent* CardCrafter) {
	return nullptr;
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
