// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

class ILocalisable;
class UCard;
class UCardNode;
/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UCardNode> Source;

	UFUNCTION(BlueprintCallable)
	UCard* Forge(UActorComponent* PlayerDeckComponent) const;
};
