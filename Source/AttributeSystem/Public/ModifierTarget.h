#pragma once

#include "CoreMinimal.h"
#include "ModifierTarget.generated.h"

UENUM(BlueprintType, NotBlueprintable)
enum class EModifierTarget {
	CurrentValue UMETA(DisplayName = "Base Value"),
	MinValue UMETA(DisplayName = "Min Value"),
	MaxValue UMETA(DisplayName = "Max Value")
};
