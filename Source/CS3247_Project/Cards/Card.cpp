// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Crafting/Card Effects/Data/CardEffect.h"
#include "Crafting/Card Effects/Impacts/CardImpact.h"
#include "Crafting/Recipe/CardRecipe.h"

UCard::UCard() {
	this->Cost = 0;
	this->Durability = 10;
	this->Effects = {};
	this->bIsDefault = false;
}

FText UCard::ToText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Effect : this->Effects) {
		Lines.Add(Effect->ToText().ToString());
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCard::ToRichText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Effect : this->Effects) {
		Lines.Add(Execute_ToRichText(Effect).ToString());
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

TArray<UCardImpact*> UCard::TopThreeImpacts() const {
	TArray<UCardImpact*> AllImpacts = this->Recipe.Get()->FetchImpacts();
	Algo::StableSort(AllImpacts);
	TArray<UCardImpact*> TopImpacts = {};
	for (int i = 0; i < FMath::Min(3, AllImpacts.Num()); i += 1) {
		TopImpacts.Add(AllImpacts[i]);
	}

	return TopImpacts;
}

