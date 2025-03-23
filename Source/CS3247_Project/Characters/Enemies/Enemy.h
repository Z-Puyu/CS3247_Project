// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EnemyAttack.h"
#include "Engine/DataAsset.h"
#include "Enemy.generated.h"

struct FLoot;
class UGameItem;
struct FGameplayAttribute;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UEnemy : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayAttribute, float> Attributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FEnemyAttack Attack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 HealAmount;

	/**
	 * How much defence can this enemy gain per action?
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Defence;

	/**
	 * Loots that this enemy can drop. The vector2 is the min and max amount of the loot.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FLoot> PossibleLoots;
};
