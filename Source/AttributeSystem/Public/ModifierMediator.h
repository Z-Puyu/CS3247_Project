// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Modifier.h"
#include "UObject/Object.h"
#include "ModifierMediator.generated.h"

UCLASS(BlueprintType, NotBlueprintable)
class ATTRIBUTESYSTEM_API UModifierMediator : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TMap<FGameplayTag, FModifier> Modifiers;

	void Add(const FGameplayTag& Target, const FModifier& Modifier);
	int32 QueryBonus(const FGameplayTag& Attribute, const int32 Base);
	int32 QueryValue(const FGameplayTag& Attribute, const int32 Base);
	int32 ProjectValue(const FGameplayTag& Attribute, const FModifier& Modifier, const int32 Base);
};
