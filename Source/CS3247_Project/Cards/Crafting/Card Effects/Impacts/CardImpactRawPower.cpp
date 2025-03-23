// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactRawPower.h"

#include "../Data/CardEffect.h"
#include "../Data/DamageEffect.h"
#include "../../../../UI/Texts/Text.h"

TArray<UCardEffect*> UCardImpactRawPower::Apply(UCard* OwningCard) {
	TArray<UCardEffect*> Effects = Super::Apply(OwningCard);
	for (const auto& Effect : Effects) {
		UDamageEffect* RawPowerDamage = NewObject<UDamageEffect>(Effect);
		RawPowerDamage->DamageType = FGameplayTag::RequestGameplayTag(FName("GameData.Damage"));
		RawPowerDamage->DamageValue = this->RawPower;
		Effect->SetEffect(UDamageEffect::StaticClass(), RawPowerDamage);
	}

	return Effects;
}

FString UCardImpactRawPower::ToString_Implementation() const {
	return FString::Printf(TEXT("%s damage: %d"),
		*FGameplayTag::RequestGameplayTag(FName("GameData.Damage")).GetTagName().ToString(),
		this->RawPower);
}

FText UCardImpactRawPower::ToText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		this->RawPower, FText::FromString(FGameplayTag::RequestGameplayTag(FName("GameData.Damage")).ToString()));
}

FText UCardImpactRawPower::ToRichText_Implementation() const {
	return FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
		UText::Red(FString::FromInt(this->RawPower)),
		UText::BfIt(FGameplayTag::RequestGameplayTag(FName("GameData.Damage")).ToString()));
}
