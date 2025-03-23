// Fill out your copyright notice in the Description page of Project Settings.


#include "CompositeImpact.h"

TArray<UCardEffect*> UCompositeImpact::Apply(UCard* OwningCard) {
	TArray<UCardEffect*> Effects = {};
	for (const auto& Impact : this->InnerImpacts) {
		Effects.Append(Impact->Apply(OwningCard));
	}
	
	return Effects;
}

FString UCompositeImpact::ToString_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Impact : this->InnerImpacts) {
		Lines.Add(Execute_ToString(Impact));
	}

	return Sb.Join(Lines, '\n').ToString();
}

FText UCompositeImpact::ToText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Impact : this->InnerImpacts) {
		Lines.Add(Execute_ToText(Impact).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

FText UCompositeImpact::ToRichText_Implementation() const {
	TStringBuilder<256> Sb = TStringBuilder<256>();
	TArray<FString> Lines = {};
	for (auto& Impact : this->InnerImpacts) {
		Lines.Add(Execute_ToRichText(Impact).ToString());
	}

	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}
