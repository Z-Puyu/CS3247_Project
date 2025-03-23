#pragma once

#include "CoreMinimal.h"
#include "EnemyActions.generated.h"

UENUM(BlueprintType)
enum class EEnemyActions : uint8
{
    Attack UMETA(DisplayName = "Attack"),
    Guard  UMETA(DisplayName = "Guard"),
    Heal   UMETA(DisplayName = "Heal"),
};
