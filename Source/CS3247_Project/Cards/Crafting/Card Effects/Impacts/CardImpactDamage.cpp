// Fill out your copyright notice in the Description page of Project Settings.


#include "CardImpactDamage.h"

#include "CS3247_Project/UI/Texts/Text.h"

UCardEffect* UCardImpactDamage::Apply() {
	UCardEffect* Data = Super::Apply();
	Data->BaseDamage = FDamageData(this->DamageType, this->Value);
	return Data;
}

FString UCardImpactDamage::ToRichText() const {
	const FString DmgNum = UText::Red(FString::Printf(TEXT("%d"), this->Value));
	const FString DmgType = UText::BfIt(FString::Printf(TEXT("%s"), *this->DamageType.ToString()));
	return FString::Printf(TEXT("Deals %s %s damage"), *DmgNum, *DmgType);
}
