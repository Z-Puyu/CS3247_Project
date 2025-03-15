// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEnchantmentPowerDown.h"

#include "../Data/CardEffect.h"
#include "CS3247_Project/UI/Texts/Text.h"

UCardEffect* UCardEnchantmentPowerDown::ComposeTo(UCardEffect* Effect) {
	const double Ratio = FMath::Clamp(1 - this->Value / 100.0, 0.0, 1.0);
	for (const auto& Entry : Effect->AtomicEffects) {
		if (this->IsApplicableTo(Entry.Value)) {
			Entry.Value->ScaleStrength(Ratio);
		}
	}

	return Effect;
}

FString UCardEnchantmentPowerDown::ToString() const {
	return FString::Printf(TEXT("%d%% power down"), this->Value);
}
FText UCardEnchantmentPowerDown::ToText() const {
	return FText::FromString(FString::Printf(TEXT("Subsequent effects become %d%% weaker"), this->Value));
}
FText UCardEnchantmentPowerDown::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("Subsequent effects become {0}% weaker")),
		UText::Red(FString::FromInt(this->Value)));
}

bool UCardEnchantmentPowerDown::IsApplicableTo(const UAtomicCardEffect* Effect) const {
	return true;
}
