// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributeSet.h"

void UPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	if (Attribute == this->GetManaAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, this->GetMaxMana());
	} else if (Attribute == this->GetMaxManaAttribute()) {
		NewValue = FMath::Max(NewValue, 0.0f);
	}
	
	Super::PreAttributeChange(Attribute, NewValue);
}
