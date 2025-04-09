#pragma once

#include "CoreMinimal.h"
#include "GameItemTag.generated.h"

UENUM(BlueprintType)
enum class EGameItemTag : uint8 {
	CardIngredient UMETA(DisplayName = "Charm"),
	Resource       UMETA(DisplayName = "Resource"),
	Document  UMETA(DisplayName = "Document")
};