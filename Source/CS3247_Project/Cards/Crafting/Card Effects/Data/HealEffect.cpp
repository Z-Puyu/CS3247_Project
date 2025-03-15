// Fill out your copyright notice in the Description page of Project Settings.


#include "HealEffect.h"

#include "../../../../UI/Texts/Text.h"

void UHealEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	this->HealAmount *= Ratio;
}

void UHealEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	this->HealAmount += Offset;
}

FString UHealEffect::ToString() const {
	return FString::Printf(TEXT("Effect: heal %lf"), this->HealAmount);
}

FText UHealEffect::ToText() const {
	return FText::FromString(FString::Printf(TEXT("Heals %d HP"), this->GetHealAmount()));
}

FText UHealEffect::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("Heals {0} HP")),
		UText::Green(FString::FromInt(this->GetHealAmount())));
}

bool UHealEffect::operator==(const int32 Value) const {
	return this->GetHealAmount() == Value;
}

bool UHealEffect::operator!=(const int32 Value) const {
	return this->GetHealAmount() != Value;
}

bool UHealEffect::operator>=(const int32 Value) const {
	return this->GetHealAmount() >= Value;
}

bool UHealEffect::operator<=(const int32 Value) const {
	return this->GetHealAmount() <= Value;
}

bool UHealEffect::operator>(const int32 Value) const {
	return this->GetHealAmount() > Value;
}

bool UHealEffect::operator<(const int32 Value) const {
	return this->GetHealAmount() < Value;
}
