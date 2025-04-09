// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../../../../UI/Texts/Text.h"

TArray<UCardEffect*> UCardImpactDamage::Apply(UCard* OwningCard) {
	TArray<UCardEffect*> Effects = Super::Apply(OwningCard);
	for (const auto& Data : Effects) {
		UDamageEffect* Dmg = NewObject<UDamageEffect>(Data);
		for (const auto& DamageData : this->Damages) {
			Dmg->SetDamageValue(DamageData.Key, DamageData.Value);
		}

		Data->SetEffect(UDamageEffect::StaticClass(), Dmg);
	}
	
	return Effects;
}

FString UCardImpactDamage::ToString_Implementation() const {
	TStringBuilder<256> Sb;
	TArray<FString> Lines = {}; 
	for (const auto& DamageData : this->Damages) {
		Lines.Add(FString::Printf(TEXT("%s damage: %d"), *DamageData.Key.GetTagName().ToString(), DamageData.Value));
	}
	
	return Sb.Join(Lines, '\n').ToString();
}

FText UCardImpactDamage::ToText_Implementation() const {
	TStringBuilder<256> Sb;
	TArray<FString> Lines = {}; 
	for (const auto& DamageData : this->Damages) {
		Lines.Add(FString::Printf(TEXT("%d %s damage"), DamageData.Value, *DamageData.Key.GetTagName().ToString()));
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCardImpactDamage::ToRichText_Implementation() const {
	return Execute_ToText(this);
}


