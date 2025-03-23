// Fill out your copyright notice in the Description page of Project Settings.

#include "DefenceEffect.h"
#include "../../../../UI/Texts/Text.h"

void UDefenceEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	this->DefenceAmount *= Ratio;
}

void UDefenceEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	this->DefenceAmount += Offset;
}

FString UDefenceEffect::ToString_Implementation() const {
	return FString::Printf(TEXT("Effect: heal %lf"), this->DefenceAmount);
}

FText UDefenceEffect::ToText_Implementation() const {
	return FText::FromString(FString::Printf(TEXT("Heals %d HP"), this->GetDefenceAmount()));
}

FText UDefenceEffect::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("Heals {0} HP")),
		UText::Green(FString::FromInt(this->GetDefenceAmount())));
}

bool UDefenceEffect::operator==(const int32 Value) const {
	return this->GetDefenceAmount() == Value;
}

bool UDefenceEffect::operator!=(const int32 Value) const {
	return this->GetDefenceAmount() != Value;
}

bool UDefenceEffect::operator>=(const int32 Value) const {
	return this->GetDefenceAmount() >= Value;
}

bool UDefenceEffect::operator<=(const int32 Value) const {
	return this->GetDefenceAmount() <= Value;
}

bool UDefenceEffect::operator>(const int32 Value) const {
	return this->GetDefenceAmount() > Value;
}

bool UDefenceEffect::operator<(const int32 Value) const {
	return this->GetDefenceAmount() < Value;
}