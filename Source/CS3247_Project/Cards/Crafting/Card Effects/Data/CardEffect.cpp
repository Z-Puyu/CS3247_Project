// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

FString UCardEffect::ToString_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Execute_ToString(Entry.Value));
	}

	return Sb.Join(Lines, '\n').ToString();
}


FText UCardEffect::ToText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Execute_ToText(Entry.Value).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCardEffect::ToRichText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Execute_ToRichText(Entry.Value).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
