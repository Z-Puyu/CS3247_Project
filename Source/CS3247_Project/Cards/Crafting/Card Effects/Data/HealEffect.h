// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "HealEffect.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UHealEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	double HealAmount;

	UHealEffect() : HealAmount(0) {}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetHealAmount() const { return FMath::CeilToInt32(this->HealAmount); }

	virtual void ScaleStrength(const double Ratio) override;

	virtual void OffsetStrength(const double Offset) override;

	virtual FString ToString_Implementation() const override;
	
	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;

	bool operator==(const int32 Value) const;

	bool operator!=(const int32 Value) const;

	bool operator>=(const int32 Value) const;

	bool operator<=(const int32 Value) const;

	bool operator>(const int32 Value) const;

	bool operator<(const int32 Value) const;
};
