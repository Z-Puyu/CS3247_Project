// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

#include "../../../UI/Texts/Text.h"

UCardEffect::UCardEffect() {
	this->ExtraDamageEffects = {};
	this->HealAmount = 0;
	this->SpecialEffects = FGameplayTagContainer();
}

FString UCardEffect::ToRichText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	if (this->BaseDamage > 0) {
		Lines.Add(this->BaseDamage.ToRichText());
	}

	const int Heal = FMath::CeilToInt(this->HealAmount);
	if (Heal > 0) {
		const FString HealNum = UText::Green(FString::Printf(TEXT("%d"), Heal));
		Lines.Add(FString::Printf(TEXT("Heals %s HP"), *HealNum));
	}

	for (auto& ExtraDamage : this->ExtraDamageEffects) {
		if (ExtraDamage.Value > 0) {
			Lines.Add(ExtraDamage.Value.ToRichText());
		}
	}

	if (!this->SpecialEffects.IsEmpty()) {
		for (auto& SpecialEffect : this->SpecialEffects) {
			Lines.Add(FString::Printf(TEXT("%s"), *SpecialEffect.ToString()));
		}
	}

	if (Lines.IsEmpty()) {
		return "";
	}
	
	return Sb.Join(Lines, TEXT("\n")).ToString();
}
