// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageEffect.h"

#include "../../../../UI/Texts/Text.h"
#include "../../../../Common/DataManager.h"
#include "../../../../Common/BasicGameInstance.h"
#include "Kismet/GameplayStatics.h"

FString UDamageEffect::ToString_Implementation() const {
	TStringBuilder<256> Sb;
	TArray<FString> Lines = {}; 
	for (const auto& DamageData : this->Damages) {
		Lines.Add(FString::Printf(TEXT("%s damage: %lf"), *DamageData.Key.GetTagName().ToString(), DamageData.Value));
	}
	
	return Sb.Join(Lines, '\n').ToString();
}

FText UDamageEffect::ToText_Implementation() const {
	return FText::FromString(Execute_ToString(this));
}

FText UDamageEffect::ToRichText_Implementation() const {
	const UBasicGameInstance* GameInstance = Cast<UBasicGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	TStringBuilder<256> Sb;
	TArray<FString> Lines = {};
	TMap<FGameplayTag, int32> DamageValues = this->GetDamageValues();
	for (const auto& DamageData : DamageValues) {
		FString Line = FText::Format(FTextFormat::FromString(TEXT("{0} {1} damage")),
			UText::Red(FString::FromInt(DamageData.Value)),
			UText::BfIt(IDataManager::Execute_GetName(GameInstance, DamageData.Key).ToString())).ToString();
		Lines.Add(Line);
	}
	return FText::FromString(Sb.Join(Lines, '\n').ToString());
}

void UDamageEffect::ScaleStrength(const double Ratio) {
	Super::ScaleStrength(Ratio);
	for (auto& Entry : this->Damages) {
		this->Damages[Entry.Key] *= Ratio;
	}
}

void UDamageEffect::OffsetStrength(const double Offset) {
	Super::OffsetStrength(Offset);
	for (auto& Entry : this->Damages) {
		this->Damages[Entry.Key] += Offset;
	}
}
