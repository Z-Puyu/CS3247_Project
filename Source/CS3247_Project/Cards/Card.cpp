// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Crafting/Card Effects/CardEffect.h"

UCard::UCard() {
	this->Cost = 0;
	this->Durability = 0;
	this->Effects = {};
}

FText UCard::GetDescription() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	for (auto& Effect : this->Effects) {
		Sb.Appendf(TEXT("%s\n"), *Effect->ToRichText());
	}
	
	return FText::FromString(Sb.ToString());
}

void UCard::GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability,
	TArray<UCardEffect*>& CardEffects) const {
	CardName = this->Name;
	Desc = this->GetDescription();
	UseCost = this->Cost;
	CardDurability = this->Durability;
	CardEffects = this->Effects;
}

