#pragma once

#include "CoreMinimal.h"
#include "../Impacts/CardImpact.h"
#include "ReactantKey.generated.h"

USTRUCT()
struct FReactantKey {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UCardImpact> First;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UCardImpact> Second;

	bool operator==(const FReactantKey& Other) const {
		return (this->First == Other.First && this->Second == Other.Second) ||
			(this->First == Other.Second && this->Second == Other.First);
	}
	
	bool operator!=(const FReactantKey& Other) const {
		return !(*this == Other);
	}
	
	friend uint32 GetTypeHash(const FReactantKey& Key) {
		const uint32 HashA = GetTypeHash(Key.First);
		const uint32 HashB = GetTypeHash(Key.Second);
		if (HashA < HashB) {
			return HashCombine(HashA, HashB);
		}
		
		return HashCombine(HashB, HashA);
	}
};
