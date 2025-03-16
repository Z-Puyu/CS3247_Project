// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardNode.h"
#include "../Card Effects/FlowControl/IngredientBrancher.h"
#include "BranchNode.generated.h"
/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UBranchNode : public UCardNode {
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UIngredientBrancher> Brancher;

	virtual TArray<TObjectPtr<UCardEffect>> Build(UCard* OwningCard) override;

	FORCEINLINE virtual FString ToString_Implementation() const override { return TEXT("[" + this->Brancher->GetName() + "]"); }
};
