// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyMove.h"
#include "../../../GameplayAbilities/GameplayEffectDescriptor.h"
#include "UObject/Object.h"
#include "EnemyAction.generated.h"

struct FUtilityScore;
struct FAiDecisionContext;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, DefaultToInstanced, EditInlineNew)
class CS3247_PROJECT_API UEnemyAction : public UDataAsset {
	GENERATED_BODY()

public:
	UEnemyAction() {}

	/**
	 * Evaluate the raw score of the action, normalised to [0, 1].
	 * @param World The game world.
	 * @param Context An AI decision context containing essential data for decision-making.
	 * @return 
	 */
	virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const;

	FORCEINLINE virtual bool IsHostile() const { return false; }

	FORCEINLINE virtual bool IsAoe() const { return false; }

	UFUNCTION(BlueprintCallable)
	virtual FORCEINLINE bool IsReflexive() const { return false; }
	
	virtual FGameplayEffectDescriptor ToGameplayEffect() const { return FGameplayEffectDescriptor(); }

protected:
	TSubclassOf<UGameplayEffect> GameplayEffectType;
};
