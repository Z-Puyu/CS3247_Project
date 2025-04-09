#pragma once

#include "CoreMinimal.h"
#include "../../../GameplayAbilities/GameplayEffectDescriptor.h"
#include "AiDecision.generated.h"


class ABasicCharacter;

/**
 * Represents the final AI choice of skill + targets.
 */
USTRUCT(BlueprintType)
struct FAiDecision {
	GENERATED_BODY()
	
public:
	// GameplayEffects to apply when executing the decision
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FGameplayEffectDescriptor> SkillEffects;

	// All recipients of this action
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<ABasicCharacter*> Targets;
};
