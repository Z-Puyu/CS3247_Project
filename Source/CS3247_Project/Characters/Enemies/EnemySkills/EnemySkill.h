// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AI/EnemyAction.h"
#include "../../BasicCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "Engine/DataAsset.h"
#include "EnemySkill.generated.h"

class APlayerCharacter;
class ABasicCharacter;
class UEnemyAction;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class CS3247_PROJECT_API UEnemySkill : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Skill")
	FName Name;

	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly, Category = "Skill")
	TArray<UEnemyAction*> Effects;

	FORCEINLINE bool IsApplicableTo(const ABasicCharacter* Source, const ABasicCharacter* Target) const {
		const bool IsHostile = this->Effects.ContainsByPredicate(
			[](const UEnemyAction* Action) -> bool { return Action->IsHostile(); });
		if (IsHostile) {
			return Target->IsA(APlayerCharacter::StaticClass());
		}

		const bool IsSelfOnly = !this->Effects.ContainsByPredicate(
			[](const UEnemyAction* Action) -> bool { return Action->IsReflexive(); });
		return !IsSelfOnly || Source == Target;
	}

	FORCEINLINE bool IsAoe() const {
		return this->Effects.ContainsByPredicate([](const UEnemyAction* Action) -> bool {
			return Action->IsAoe();
			});
	}


	TArray<FGameplayEffectDescriptor> ToGameplayEffects() const;
};
