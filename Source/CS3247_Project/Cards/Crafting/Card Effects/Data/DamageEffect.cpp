// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageEffect.h"

#include "../../../../UI/Texts/Text.h"

FString UDamageEffect::ToString_Implementation() const {
	return FString::Printf(TEXT("%s damage: %lf"),
		*this->DamageType.GetTagName().ToString(), this->DamageValue);
}

FText UDamageEffect::ToText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		this->GetDamageValue(), FText::FromString(this->DamageType.ToString()));
}

FText UDamageEffect::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		UText::Red(FString::FromInt(this->GetDamageValue())),
		UText::BfIt(this->DamageType.ToString()));
}

void UDamageEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	this->DamageValue *= Ratio;
}

void UDamageEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	this->DamageValue += Offset;
}

bool UDamageEffect::operator>(const int32 Value) const {
	return this->GetDamageValue() > Value;
}

bool UDamageEffect::operator<(const int32 Value) const {
	return this->GetDamageValue() < Value;
}

bool UDamageEffect::operator==(const int32 Value) const {
	return this->GetDamageValue() == Value;
}

bool UDamageEffect::operator!=(const int32 Value) const {
	return this->GetDamageValue() != Value;
}

bool UDamageEffect::operator>=(const int32 Value) const {
	return this->GetDamageValue() >= Value;
}

bool UDamageEffect::operator<=(const int32 Value) const {
	return this->GetDamageValue() <= Value;
}
