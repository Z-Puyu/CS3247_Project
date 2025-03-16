// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "UObject/Object.h"
#include "ManaCostEffect.generated.h"

/**
 * A card effect to use mana.
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UManaCostEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UManaCostEffect() : ManaCost(0) {}
	
	double ManaCost;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetManaCost() const { return FMath::CeilToInt32(this->ManaCost); }

	virtual void ScaleStrength(const double Ratio) override;

	virtual void OffsetStrength(const double Offset) override;

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;

	bool operator> (const int32 Value) const;

	bool operator< (const int32 Value) const;

	bool operator== (const int32 Value) const;

	bool operator!= (const int32 Value) const;

	bool operator>= (const int32 Value) const;

	bool operator<= (const int32 Value) const;
};
