#pragma once

#include "CoreMinimal.h"
#include "GameItemTag.generated.h"

UENUM(BlueprintType)
enum class EGameItemTag : uint8 {
	CardIngredient UMETA(DisplayName = "Card Ingredient"),
	SoulFragment  UMETA(DisplayName = "Soul Fragment")
};