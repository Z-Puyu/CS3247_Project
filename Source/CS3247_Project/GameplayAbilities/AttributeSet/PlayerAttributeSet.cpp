// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributeSet.h"

void UPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	TArray<FGameplayAttribute> Attributes = {};
	GetAttributesFromSetClass(this->GetClass(), Attributes);
	const float OldValue = Attributes.FindByKey(Attribute)->GetNumericValue(this);
	float MaxValue = 100.0f;
	if (Attribute == this->GetHealthAttribute()) {
		MaxValue = this->GetMaxHealth();
	} else if (Attribute == this->GetManaAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, this->GetMaxMana());
	} else if (Attribute == this->GetMaxManaAttribute()) {
		NewValue = FMath::Max(NewValue, 0.0f);
	} else if (Attribute == this->GetMaxHealthAttribute() || Attribute == this->GetDefenceAttribute()) {
		MaxValue = static_cast<float>(INT32_MAX);
	}

	NewValue = FMath::Clamp(NewValue, 0.0f, MaxValue);
	
	this->OnAttributeChanged.Broadcast(Attribute, OldValue, NewValue);
}

bool UPlayerAttributeSet::PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) {
	this->SetMana(FMath::Clamp(this->GetMana(), 0.0f, this->GetMaxMana()));
	this->SetHealth(FMath::Clamp(this->GetHealth(), 0.0f, this->GetMaxHealth()));
	return true;
}

void UPlayerAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) {
	this->SetMana(FMath::Clamp(this->GetMana(), 0.0f, this->GetMaxMana()));
	this->SetHealth(FMath::Clamp(this->GetHealth(), 0.0f, this->GetMaxHealth()));
}
