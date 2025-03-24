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
	FGameplayTag DamageType;

	UPROPERTY(EditAnywhere)
	double DamageValue;
	
	UDamageEffect() : DamageValue(0) {}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetDamageValue() const { return FMath::CeilToInt(DamageValue); }

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;
	
	virtual FText ToRichText_Implementation() const override;

	virtual void ScaleStrength(const double Ratio) override;

	virtual void OffsetStrength(const double Offset) override;

	bool operator> (const int32 Value) const;

	bool operator< (const int32 Value) const;

	bool operator== (const int32 Value) const;

	bool operator!= (const int32 Value) const;

	bool operator>= (const int32 Value) const;

	bool operator<= (const int32 Value) const;

	FORCEINLINE explicit operator double() const { return this->DamageValue; }
};
