// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Crafting/Card Effects/Data/CardEffect.h"

UCard::UCard() {
	this->Cost = 0;
	this->Durability = 0;
	this->Effects = {};
}

FText UCard::ToText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Effect : this->Effects) {
		Lines.Add(Effect.Get()->ToText().ToString());
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCard::ToRichText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Effect : this->Effects) {
		Lines.Add(Effect.Get()->ToRichText().ToString());
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

void UCard::GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability,
	TArray<UCardEffect*>& CardEffects) const {
	CardName = this->Name;
	Desc = this->ToRichText();
	UseCost = this->Cost;
	CardDurability = this->Durability;
	CardEffects = this->Effects;
}

