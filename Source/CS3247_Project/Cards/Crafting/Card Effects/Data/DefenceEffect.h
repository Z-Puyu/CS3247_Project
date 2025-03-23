// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AtomicCardEffect.h"
#include "DefenceEffect.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UDefenceEffect : public UAtomicCardEffect {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	double DefenceAmount;

	UDefenceEffect() : DefenceAmount(0) {}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetDefenceAmount() const { return FMath::CeilToInt32(this->DefenceAmount); }

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
