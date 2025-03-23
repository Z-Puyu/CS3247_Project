#pragma once

#include "CoreMinimal.h"
#include "AiDecisionContext.generated.h"

class APlayerCharacter;
class AEnemyCharacter;

USTRUCT(BlueprintType)
struct FAiDecisionContext {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AEnemyCharacter> SelfData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerCharacter> PlayerData;
};
