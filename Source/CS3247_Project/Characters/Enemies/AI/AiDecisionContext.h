#pragma once

#include "CoreMinimal.h"
#include "AiDecisionContext.generated.h"

class AEnemyCharacter;
class APlayerCharacter;
class ABasicCharacter;

/**
 * Data passed to actions for scoring (Evaluate)
 */
USTRUCT(BlueprintType)
struct FAiDecisionContext
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<AEnemyCharacter> SelfData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<APlayerCharacter> PlayerData;

    // Typically the "primary" target if we do single-target
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<ABasicCharacter*> TargetsData;
};
