// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Crafting/Card Effects/Data/CardEffect.h"

UCard::UCard() {
	this->Cost = 0;
	this->Durability = 0;
	this->Effects = {};
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

void UCard::GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability,
	TArray<UCardEffect*>& CardEffects) const {
	CardName = this->Name;
	Desc = Execute_ToRichText(this);
	UseCost = this->Cost;
	CardDurability = this->Durability;
	CardEffects = this->Effects;
}

