// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerUp.h"

#include "../Data/CardEffect.h"
#include "CS3247_Project/UI/Texts/Text.h"

UCardEffect* UCardEnchantmentPowerUp::ComposeTo(UCard* OwningCard, UCardEffect* Effect, double Multiplier) {
	Effect = Super::ComposeTo(OwningCard, Effect, Multiplier);
	const double Ratio = FMath::Max(1 + this->Value * Multiplier / 100.0, 1.0);
	for (const auto& Entry : Effect->AtomicEffects) {
		if (this->IsApplicableTo(Entry.Value)) {
			Entry.Value->ScaleStrength(Ratio);
		}
	}
	
	return Effect;
}

FString UCardEnchantmentPowerUp::ToString_Implementation() const {
	return FString::Printf(TEXT("%d%% power up"), this->Value);
}

FText UCardEnchantmentPowerUp::ToText_Implementation() const {
	return FText::FromString(FString::Printf(TEXT("Subsequent effects become %d%% stronger"), this->Value));
}

FText UCardEnchantmentPowerUp::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("Subsequent effects become {0}% stronger")),
		UText::Green(FString::FromInt(this->Value)));
}

bool UCardEnchantmentPowerUp::IsApplicableTo(const UAtomicCardEffect* Effect) const {
	return true;
}
