// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../../../../UI/Texts/Text.h"

TArray<UCardEffect*> UCardImpactDamage::Apply(UCard* OwningCard) {
	TArray<UCardEffect*> Effects = Super::Apply(OwningCard);
	for (const auto& Data : Effects) {
		UDamageEffect* Dmg = NewObject<UDamageEffect>(Data);
		Dmg->DamageType = this->DamageType;
		Dmg->DamageValue = this->Value;
		Data->SetEffect(UDamageEffect::StaticClass(), Dmg);
	}
	
	return Effects;
}

FString UCardImpactDamage::ToString_Implementation() const {
	return FString::Printf(TEXT("%s damage: %d"),
		*this->DamageType.GetTagName().ToString(), this->Value);
}

FText UCardImpactDamage::ToText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		this->Value, FText::FromString(this->DamageType.ToString()));
}
FText UCardImpactDamage::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		UText::Red(FString::FromInt(this->Value)),
		UText::BfIt(this->DamageType.ToString()));
}


