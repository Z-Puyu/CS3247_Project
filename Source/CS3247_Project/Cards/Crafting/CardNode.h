// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card Effects/CardIngredient.h"
#include "Card Effects/Enchantments/CardEnchantment.h"
#include "CS3247_Project/UI/Texts/Localisable.h"
#include "UObject/Object.h"
#include "CardNode.generated.h"

/**
 * 
 */
UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardNode : public UDataAsset, public IPrintable, public ILocalisable {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	UCardIngredient* Ingredient;

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	FORCEINLINE bool CanInsertNodeAfter() const {
		return this->Ingredient->IsA(UCardEnchantment::StaticClass());
	}
	
	FORCEINLINE bool IsTerminal() const {
		return this->FirstSuccessor == nullptr && this->SecondSuccessor == nullptr;
	}

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool AddSuccessor(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category = "Node Connections")
	bool BreakLinkWith(UCardNode* Node, FText& ErrorMsg);

	UFUNCTION(BlueprintCallable, Category= "Node Connections")
	void BreakAllLinks();
	
	TArray<TObjectPtr<UCardEffect>> Build(UCard* OwningCard);

	virtual FORCEINLINE FString ToString() const override { return TEXT("[" + this->Ingredient->GetName() + "]"); }
	
	virtual FORCEINLINE FText ToText() const override {
		return FText::FromString("[" + this->Ingredient->GetName() + "]");
	}
	
	virtual FORCEINLINE FText ToRichText() const override { return this->ToText(); }
private:
	UPROPERTY()
	TObjectPtr<UCardNode> Predecessor;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCardNode> FirstSuccessor;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCardNode> SecondSuccessor;
};
