#pragma once

#include "CoreMinimal.h"
#include "ReactantKey.generated.h"

USTRUCT()
struct FReactantKey {
	GENERATED_BODY()
	
public:
	FGuid First;
	FGuid Second;

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
		if (Key.First < Key.Second) {
			return HashCombine(HashA, HashB);
		}
		
		return HashCombine(HashB, HashA);
	}
};
