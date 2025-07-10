// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SpellCraftingGraph.generated.h"

class USpellCraftingNode;
/**
 * 
 */
UCLASS(BlueprintType)
class SPELLCRAFTINGSYSTEM_API USpellCraftingGraph final : public UObject {
	GENERATED_BODY()

private:
	UPROPERTY()
	TSet<USpellCraftingNode*> Nodes;

	UPROPERTY()
	TArray<USpellCraftingNode*> ExecutionOrder;

public:
	void Execute();

private:
	void TopologicalSort();
};
