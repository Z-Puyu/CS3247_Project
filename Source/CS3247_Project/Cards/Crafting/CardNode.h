// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card Effects/CardEffect.h"
#include "Card Effects/CardIngredient.h"
#include "Card Effects/Impacts/CardImpact.h"
#include "UObject/Object.h"
#include "CardNode.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardNode : public UDataAsset {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	UCardIngredient* Ingredient;

	UFUNCTION(BlueprintCallable)
	bool AddSuccessor(UCardNode* Node);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool Precedes(UCardNode* Node) const { return Node->Predecessor == this; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool Succeeds(UCardNode* Node) const { return this->Predecessor == Node; }

	UFUNCTION(BlueprintCallable)
	bool BreakLinkWith(UCardNode* Node);

	UFUNCTION(BlueprintCallable)
	int CountBuildableConnectedNodes();

	UFUNCTION(BlueprintCallable)
	TArray<UCardEffect*> Build();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsReadyToCraft() const { return this->IsTerminal() || this->Successors.Num() > 0; }

	UFUNCTION(BlueprintCallable)
	UCardNode* GetRoot();
private:
	UPROPERTY()
	UCardNode* Predecessor;
	
	TSet<UCardNode*> Successors;
	
	FORCEINLINE bool IsTerminal() const {
		return this->Ingredient->IsA(UCardImpact::StaticClass()) &&
			this->Successors.Num() == 0;
	}
};
