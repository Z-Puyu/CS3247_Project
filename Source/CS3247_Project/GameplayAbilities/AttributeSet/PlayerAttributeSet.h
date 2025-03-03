// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicAttributeSet.h"
#include "PlayerAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UPlayerAttributeSet : public UBasicAttributeSet {
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, MaxMana)

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxMana;
};
