#pragma once

#include "CoreMinimal.h"
#include "Modifier.generated.h"

USTRUCT(BlueprintType)
struct ATTRIBUTESYSTEM_API FModifier {
	GENERATED_BODY()
	
public:
	static const FModifier Zero;
	int32 Offset;
	int32 Multiplier;
	int32 Shift;

	FModifier() : Offset(0), Multiplier(0), Shift(0) { }
	
	FModifier(const int32 Offset, const int32 Multiplier, const int32 Shift)
		: Offset(Offset), Multiplier(Multiplier), Shift(Shift) { }

	FORCEINLINE FString ToString() const {
		return FString::Printf(TEXT("Offset: %d, Multiplier: %d, Shift: %d"), this->Offset, this->Multiplier, this->Shift);
	}

	FORCEINLINE explicit operator FString() const {
		return this->ToString();
	}

	FORCEINLINE FModifier operator*(const double Scale) const {
		return FModifier(this->Offset * Scale, this->Multiplier * Scale, this->Shift * Scale);
	}

	FORCEINLINE FModifier operator*=(const double Scale) {
		return *this = *this * Scale;
	}
	
	FORCEINLINE FModifier operator+(const FVector3d& Add) const {
		return FModifier(this->Offset + Add.X, this->Multiplier + Add.Y, this->Shift + Add.Z);
	}

	FORCEINLINE FModifier operator+=(const FVector3d& Add) {
		return *this = *this + Add;
	}

	FORCEINLINE FModifier operator-(const FVector3d& Sub) const {
		return FModifier(this->Offset - Sub.X, this->Multiplier - Sub.Y, this->Shift - Sub.Z);
	}

	FORCEINLINE FModifier operator-=(const FVector3d& Sub) {
		return *this = *this - Sub;
	}

	FORCEINLINE FModifier operator*(const FVector3f& Scale) const {
		return FModifier(FMath::RoundToInt32(this->Offset * Scale.X), FMath::RoundToInt32(this->Offset * Scale.Y),
			FMath::RoundToInt32(this->Offset * Scale.Z));
	}

	FORCEINLINE FModifier operator*=(const FVector3f& Scale) {
		return *this = *this * Scale;
	}

	FORCEINLINE FModifier operator+(const FModifier& Other) const {
		return FModifier(this->Offset + Other.Offset, this->Multiplier + Other.Multiplier, this->Shift + Other.Shift);
	}

	FORCEINLINE FModifier operator+=(const FModifier& Other) {
		return *this = *this + Other;
	}

	FORCEINLINE FModifier operator-(const FModifier& Other) const {
		return FModifier(this->Offset - Other.Offset, this->Multiplier - Other.Multiplier, this->Shift - Other.Shift);
	}

	FORCEINLINE FModifier operator-=(const FModifier& Other) {
		return *this = *this - Other;
	}

	FORCEINLINE FModifier operator-() const {
		return FModifier(-this->Offset, -this->Multiplier, -this->Shift);
	}
};
