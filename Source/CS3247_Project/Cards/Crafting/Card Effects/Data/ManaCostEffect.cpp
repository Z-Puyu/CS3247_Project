// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaCostEffect.h"

#include "CS3247_Project/UI/Texts/Text.h"

void UManaCostEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	this->ManaCost *= Ratio;
}

void UManaCostEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	this->ManaCost += Offset;
}

FString UManaCostEffect::ToString() const {
	return FString::Printf(TEXT("Effect: use %d mana"), this->ManaCost);
}

FText UManaCostEffect::ToText() const {
	return FText::FromString(FString::FromInt(this->ManaCost));
}

FText UManaCostEffect::ToRichText() const {
	return UText::Bf(FString::FromInt(this->ManaCost));
}

bool UManaCostEffect::operator>(const int32 Value) const {
	return this->GetManaCost() > Value;
}

bool UManaCostEffect::operator<(const int32 Value) const {
	return this->GetManaCost() < Value;
}

bool UManaCostEffect::operator==(const int32 Value) const {
	return this->GetManaCost() == Value;
}

bool UManaCostEffect::operator!=(const int32 Value) const {
	return this->GetManaCost() != Value;
}

bool UManaCostEffect::operator>=(const int32 Value) const {
	return this->GetManaCost() >= Value;
}

bool UManaCostEffect::operator<=(const int32 Value) const {
	return this->GetManaCost() <= Value;
}
