// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateEnemySpawnAnchors.generated.h"

class ABasicCharacter;

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UGenerateEnemySpawnAnchors : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Utilities|Enemy Spawn Anchors")
    static TArray<FVector> GenerateAnchorsBasedOnPlayer(
	ABasicCharacter* Player,
	float ForwardDistance, 
	float LateralOffset
    );
};
