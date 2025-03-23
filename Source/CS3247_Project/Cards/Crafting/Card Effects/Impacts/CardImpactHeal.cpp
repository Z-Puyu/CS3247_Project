// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactHeal.h"

#include "../../../../UI/Texts/Text.h"
#include "../Data/CardEffect.h"
#include "../Data/HealEffect.h"

TArray<UCardEffect*> UCardImpactHeal::Apply(UCard* OwningCard) {
	TArray<UCardEffect*> Effects = Super::Apply(OwningCard);
	for (const auto& Data : Effects) {
		UHealEffect* Heal = NewObject<UHealEffect>(Data);
		Heal->HealAmount = this->Value;
		Data->SetEffect(UHealEffect::StaticClass(), Heal);
	}
	
	return Effects;
}

FString UCardImpactHeal::ToString_Implementation() const {
	return FString::Printf(TEXT("Impact: heal %d HP"), this->Value);
}

FText UCardImpactHeal::ToText_Implementation() const {
	return FText::FromString(FString::Printf(TEXT("Heals %d HP"), this->Value));
}

FText UCardImpactHeal::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("Heals {0} HP")),
		UText::Green(FString::FromInt(this->Value)));
}
