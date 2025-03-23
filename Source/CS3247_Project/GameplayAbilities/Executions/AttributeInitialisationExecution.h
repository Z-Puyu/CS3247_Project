// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AttributeInitialisationExecution.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UAttributeInitialisationExecution : public UGameplayEffectExecutionCalculation {
	GENERATED_BODY()

public:
	UAttributeInitialisationExecution();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};


