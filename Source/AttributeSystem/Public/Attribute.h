#pragma once

#include <stdexcept>

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Attribute.generated.h"

USTRUCT(BlueprintType)
struct ATTRIBUTESYSTEM_API FAttribute {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Value;

	FAttribute() : DisplayName(FText::GetEmpty()), Value(0) { }

	FAttribute(const FGameplayTag Name, const FText& DisplayName, const int32 Value)
		: Name(Name), DisplayName(DisplayName), Value(Value) { }

	FORCEINLINE static FAttribute Zero(const FGameplayTag& Name) {
		return FAttribute(Name, FText::FromName(Name.GetTagLeafName()), 0);
	}

	FORCEINLINE FAttribute operator+(const double Offset) const {
		return FAttribute(this->Name, this->DisplayName, FMath::RoundToInt32(this->Value + Offset));
	}

	FORCEINLINE FAttribute operator-(const double Offset) const {
		return FAttribute(this->Name, this->DisplayName, FMath::RoundToInt32(this->Value - Offset));
	}

	FORCEINLINE FAttribute operator*(const double Scale) const {
		return FAttribute(this->Name, this->DisplayName, FMath::RoundToInt32(this->Value * Scale));
	}

	FORCEINLINE bool operator==(const FAttribute &Other) const {
		return this->Name == Other.Name && this->Value == Other.Value;
	}

	FORCEINLINE bool operator!=(const FAttribute &Other) const {
		return this->Name != Other.Name || this->Value != Other.Value;
	}

	FORCEINLINE bool operator==(const float Number) const {
		return FMath::IsNearlyEqual(this->Value, Number);
	}

	FORCEINLINE bool operator!=(const float Number) const {
		return !FMath::IsNearlyEqual(this->Value, Number);
	}

	FORCEINLINE bool operator<(const float Number) const {
		return this->Value < Number;
	}

	FORCEINLINE bool operator>(const float Number) const {
		return this->Value > Number;
	}

	FORCEINLINE bool operator<=(const float Number) const {
		return FMath::IsNearlyEqual(this->Value, Number) || this->Value < Number;
	}

	FORCEINLINE bool operator>=(const float Number) const {
		return FMath::IsNearlyEqual(this->Value, Number) || this->Value > Number;
	}
};
