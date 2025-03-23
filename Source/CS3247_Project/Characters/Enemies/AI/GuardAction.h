// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAction.h"
#include "GuardAction.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UGuardAction : public UEnemyAction {
	GENERATED_BODY()

public:
	virtual float Evaluate(const FAiDecisionContext Context) const override;
};
