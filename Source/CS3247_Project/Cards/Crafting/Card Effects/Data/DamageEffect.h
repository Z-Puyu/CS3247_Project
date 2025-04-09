// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "DamageEffect.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UDamageEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, double> Damages;
	
	UDamageEffect() : Damages({}) {}

	FORCEINLINE void SetDamageValue(const FGameplayTag DamageType, const double Value) {
		if (this->Damages.Contains(DamageType)) {
			this->Damages[DamageType] += Value;
		} else {
			this->Damages.Add(DamageType, Value);
		}
	}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE TMap<FGameplayTag, int32> GetDamageValues() const {
		TMap<FGameplayTag, int32> DamageValues = {};
		for (const auto& Damage : this->Damages) {
			DamageValues.Add(Damage.Key, FMath::CeilToInt(Damage.Value));
		}
		
		return DamageValues;
	}

	FORCEINLINE double GetTotal() const {
		TArray<double> Values;
		this->Damages.GenerateValueArray(Values);
		double Sum = 0;
		for (const auto& Value : Values) {
			Sum += Value;
		}

		return Sum;
	}

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;

	virtual void ScaleStrength(const double Ratio) override;

	virtual void OffsetStrength(const double Offset) override;
};
