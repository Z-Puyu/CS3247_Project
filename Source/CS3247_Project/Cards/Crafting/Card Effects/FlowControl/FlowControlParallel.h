// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowControl.h"
#include "FlowControlParallel.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UFlowControlParallel : public UFlowControl {
	GENERATED_BODY()

public:
	virtual TArray<TObjectPtr<UCardEffect>> Combine(UCardEffect* Left, UCardEffect* Right) override;
};
