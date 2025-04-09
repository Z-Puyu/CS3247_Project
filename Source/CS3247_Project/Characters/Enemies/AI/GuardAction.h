// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "GuardAction.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UGuardAction : public UEnemyAction {
	GENERATED_BODY()

public:
	UGuardAction();
	
	UPROPERTY(EditDefaultsOnly)
	int32 Amount;
	
	virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;
	
	virtual FORCEINLINE bool IsReflexive() const override { return this->bIsReflexive; }

	virtual FORCEINLINE bool IsAoe() const override { return this->bIsAoe; }

	virtual FORCEINLINE FGameplayEffectDescriptor ToGameplayEffect() const override {
		return FGameplayEffectDescriptor(
			this->IsReflexive(),
			this->GameplayEffectType,
			FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Defend")),
			FGameplayTag::EmptyTag,
			this->Amount);	
	}
protected:
	// If reflexive, this effect is always applied to the enemy itself regardless of which target it chooses.
	UPROPERTY(EditDefaultsOnly)
	bool bIsReflexive;

	// If true, the effect is applied to all targets.
	UPROPERTY(EditDefaultsOnly)
	bool bIsAoe;
};
