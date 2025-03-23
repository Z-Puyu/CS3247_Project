#pragma once

#include "CoreMinimal.h"
#include "EnemyMove.generated.h"

UENUM(BlueprintType)
enum class EEnemyMove : uint8 {
	Attack UMETA(DisplayName = "Attack"),
	Guard  UMETA(DisplayName = "Guard"),
	Heal   UMETA(DisplayName = "Heal"),
};
