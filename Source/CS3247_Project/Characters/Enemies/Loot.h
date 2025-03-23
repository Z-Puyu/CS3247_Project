#pragma once

#include "CoreMinimal.h"
#include "Loot.generated.h"

class UGameItem;

USTRUCT(BlueprintType)
struct FLoot {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UGameItem> Item;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MinQuantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxQuantity;
};
