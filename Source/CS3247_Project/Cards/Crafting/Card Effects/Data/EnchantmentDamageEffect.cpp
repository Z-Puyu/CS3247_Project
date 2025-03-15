// Fill out your copyright notice in the Description page of Project Settings.


#include "EnchantmentDamageEffect.h"

#include "../../../../UI/Texts/Text.h"

void UEnchantmentDamageEffect::ScaleStrength(const FGameplayTag DmgType, const double Ratio) {
	if (this->EnchantmentDamages.Contains(DmgType)) {
		this->EnchantmentDamages[DmgType] *= Ratio;
	}
}

void UEnchantmentDamageEffect::OffsetStrength(const FGameplayTag DmgType, const double Offset) {
	if (this->EnchantmentDamages.Contains(DmgType)) {
		this->EnchantmentDamages[DmgType] += Offset;
	}
}

void UEnchantmentDamageEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	for (auto& Entry : this->EnchantmentDamages) {
		Entry.Value *= Ratio;
	}
}

void UEnchantmentDamageEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	for (auto& Entry : this->EnchantmentDamages) {
		Entry.Value += Offset;
	}
}

FString UEnchantmentDamageEffect::ToString() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	for (auto& Entry : this->EnchantmentDamages) {
		Sb.Appendf(TEXT("%s enchantment damage: %lf\n"), *Entry.Key.GetTagName().ToString(), Entry.Value);
	}
	
	return Sb.ToString();	
}

FText UEnchantmentDamageEffect::ToText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->EnchantmentDamages) {
		Lines.Add(FString::Printf(TEXT("%d %s enchantment damage"),
			FMath::CeilToInt32(Entry.Value), *Entry.Key.GetTagName().ToString()));
	}
	
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
FText UEnchantmentDamageEffect::ToRichText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->EnchantmentDamages) {
		Lines.Add(FText::Format(FTextFormat::FromString("{0} {1} damage"),
			UText::Red(FString::FromInt(FMath::CeilToInt32(Entry.Value))),
			UText::BfIt(Entry.Key.GetTagName().ToString())).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
