// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "Enemy.generated.h"

class UEnemySkill;
struct FLoot;
class UGameItem;
struct FGameplayAttribute;
class UPaperSprite;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UEnemy : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UPaperSprite> Sprite;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayAttribute, float> Attributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSet<UEnemySkill*> Skills;

	/**
	 * Loots that this enemy can drop. The vector2 is the min and max amount of the loot.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FLoot> PossibleLoots;

	/**
	* Assoicate the data asset with the enemy spawning
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Spawning")
	TSubclassOf<class AEnemyCharacter> EnemyClass;

};
