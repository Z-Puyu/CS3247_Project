// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../CardIngredient.h"
#include "FlowControl.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CS3247_PROJECT_API UFlowControl : public UCardIngredient {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int ModifierEffect;
	
	virtual TArray<TObjectPtr<UCardEffect>> Combine(UCardEffect* Left, UCardEffect* Right);
};
