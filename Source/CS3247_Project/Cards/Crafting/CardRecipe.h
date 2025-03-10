// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardNode.h"
#include "CS3247_Project/Cards/Card.h"
#include "UObject/Object.h"
#include "CardRecipe.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CS3247_PROJECT_API UCardRecipe : public UObject, public ITextDescribable {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool IsValidRecipe() const;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void AddNode(UCardNode* Node) {
		this->Nodes.Add(Node);
		if (this->Source == nullptr) {
			this->Source = Node;
		}
	}

	UFUNCTION(BlueprintCallable)
	bool RemoveNode(UCardNode* Node);

	UFUNCTION(BlueprintCallable)
	UCard* Forge();

	UFUNCTION(BlueprintCallable)
	virtual FText GetDescription() const override;
	
private:
	UPROPERTY()
	TObjectPtr<UCardNode> Source = nullptr;
	
	UPROPERTY()
	TSet<TObjectPtr<UCardNode>> Nodes = {};
};
