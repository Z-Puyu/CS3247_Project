// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../../../../UI/Texts/Text.h"

UCardEffect* UCardImpactDamage::Apply(UCard* OwningCard) {
	UCardEffect* Data = Super::Apply(OwningCard);
	UDamageEffect* Dmg = NewObject<UDamageEffect>(Data);
	Dmg->DamageType = this->DamageType;
	Dmg->DamageValue = this->Value;
	Data->SetEffect(UDamageEffect::StaticClass(), Dmg);
	return Data;
}

FString UCardImpactDamage::ToString() const {
	return FString::Printf(TEXT("%s damage: %d"),
		*this->DamageType.GetTagName().ToString(), this->Value);
}

FText UCardImpactDamage::ToText() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		this->Value, FText::FromString(this->DamageType.ToString()));
}
FText UCardImpactDamage::ToRichText() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		UText::Red(FString::FromInt(this->Value)),
		UText::BfIt(this->DamageType.ToString()));
}


