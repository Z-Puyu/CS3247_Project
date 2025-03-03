#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DamageData.generated.h"

USTRUCT(BlueprintType)
struct FDamageData {
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta=(Categories="Damage"))
	FGameplayTag DamageType;
	
	UPROPERTY(BlueprintReadOnly)
	double DamageValue;
	
	FDamageData() : DamageValue(0) {}
	
	FDamageData(const FGameplayTag DamageType, const double DamageValue) :
		DamageType(DamageType), DamageValue(DamageValue) {}
	
	FString ToString() const;

	FString ToRichText() const;
	
	FDamageData operator+ (const double Offset) const; 

	FDamageData operator- (const double Offset) const;

	FDamageData operator* (const double Factor) const;

	FDamageData operator+= (const double Value) const;

	FDamageData operator-= (const double Value) const;

	FDamageData operator*= (const double Value) const;

	bool operator> (const int Value) const;

	bool operator< (const int Value) const;

	bool operator== (const int Value) const;

	bool operator!= (const int Value) const;

	bool operator>= (const int Value) const;

	bool operator<= (const int Value) const;
};
