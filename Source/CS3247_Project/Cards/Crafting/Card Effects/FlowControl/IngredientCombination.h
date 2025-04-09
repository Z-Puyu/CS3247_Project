#pragma once

#include "CoreMinimal.h"
#include "../Impacts/CardImpact.h"
#include "IngredientCombination.generated.h"

USTRUCT(BlueprintType)
struct FIngredientCombination : public FTableRowBase {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UCardImpact> First;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UCardImpact> Second;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UCardImpact> Result;
};
