// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactHeal.h"

#include "../../../../UI/Texts/Text.h"
#include "../Data/CardEffect.h"
#include "../Data/HealEffect.h"

UCardEffect* UCardImpactHeal::Apply(UCard* OwningCard) {
	UCardEffect* Data = Super::Apply(OwningCard);
	UHealEffect* Heal = NewObject<UHealEffect>(Data);
	Heal->HealAmount = this->Value;
	Data->SetEffect(UHealEffect::StaticClass(), Heal);
	return Data;
}

FString UCardImpactHeal::ToString() const {
	return FString::Printf(TEXT("Impact: heal %d HP"), this->Value);
}

FText UCardImpactHeal::ToText() const {
	return FText::FromString(FString::Printf(TEXT("Heals %d HP"), this->Value));
}

FText UCardImpactHeal::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("Heals {0} HP")),
		UText::Green(FString::FromInt(this->Value)));
}
