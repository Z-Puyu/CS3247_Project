// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "../EnemyAttack.h"
#include "AttackAction.generated.h"
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UAttackAction : public UEnemyAction {
	GENERATED_BODY()

public:
	UAttackAction();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FEnemyAttack DamageData;
	
	virtual float Evaluate(const UWorld* World, const FAiDecisionContext& Context) const override;

	FORCEINLINE virtual bool IsHostile() const override { return true; }

	FORCEINLINE virtual bool IsAoe() const override { return false; }

	FORCEINLINE virtual bool IsReflexive() const override { return false; }

	virtual FORCEINLINE FGameplayEffectDescriptor ToGameplayEffect() const override {
		return FGameplayEffectDescriptor(
			false,
			this->GameplayEffectType,
			FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Damage")),
			this->DamageData.DamageType,
			this->DamageData.Value);	
	}
};
