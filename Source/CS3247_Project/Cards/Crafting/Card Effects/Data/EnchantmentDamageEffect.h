// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "EnchantmentDamageEffect.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UEnchantmentDamageEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UEnchantmentDamageEffect() : EnchantmentDamages({}) {}

	FORCEINLINE double Get(const FGameplayTag DmgType) const {
		return this->EnchantmentDamages.Contains(DmgType) ? this->EnchantmentDamages[DmgType] : 0;
	}

	FORCEINLINE void Set(const FGameplayTag DmgType, const double DmgVal) {
		this->EnchantmentDamages.Add(DmgType, DmgVal);
	}

	void ScaleStrength(const FGameplayTag DmgType, const double Ratio);

	void OffsetStrength(const FGameplayTag DmgType, const double Offset);

	virtual void ScaleStrength(const double Ratio) override;

	virtual void OffsetStrength(const double Offset) override;

	virtual FString ToString() const override;

	virtual FText ToText() const override;

	virtual FText ToRichText() const override;
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FGameplayTag, double> EnchantmentDamages;
};
