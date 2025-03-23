#pragma once

#include "CoreMinimal.h"
#include "IngredientWrappers/IngredientKey.h"
#include "RecipeEdge.generated.h"

class UCardIngredient;

USTRUCT(BlueprintType)
struct FRecipeEdge {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Edge")
	FIngredientKey From;

	UPROPERTY(BlueprintReadOnly, Category = "Ingredient Edge")
	FIngredientKey To;
};
