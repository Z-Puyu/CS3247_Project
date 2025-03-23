// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttributeSet.h"

void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) {
	if (Attribute == this->GetHealthAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, this->GetMaxHealth());
	} else if (Attribute == this->GetMaxHealthAttribute() || Attribute == this->GetDefenceAttribute()) {
		NewValue = FMath::Max(NewValue, 0.0f);
	} else if (Attribute == this->GetPoisonResistanceAttribute() ||
		Attribute == this->GetWaterResistanceAttribute() ||
		Attribute == this->GetFireResistanceAttribute() ||
		Attribute == this->GetAirResistanceAttribute() ||
		Attribute == this->GetEarthResistanceAttribute() ||
		Attribute == this->GetElectricResistanceAttribute() ||
		Attribute == this->GetProjectileResistanceAttribute() ||
		Attribute == this->GetSliceResistanceAttribute() ||
		Attribute == this->GetExplosionResistanceAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
	}

	Super::PreAttributeChange(Attribute, NewValue);
}
