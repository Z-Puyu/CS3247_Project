// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffect.h"

FString UCardEffect::ToString() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToString());
	}

	return Sb.Join(Lines, '\n').ToString();
}

FText UCardEffect::ToText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToText().ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCardEffect::ToRichText() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Entry : this->AtomicEffects) {
		Lines.Add(Entry.Value->ToRichText().ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
