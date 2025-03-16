// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../UI/Texts/Localisable.h"
#include "../../../UI/Texts/Printable.h"
#include "Engine/DataAsset.h"
#include "CardIngredient.generated.h"

class UCardNode;
class UCard;
class UCardEffect;
/**
 * The abstract base class for all card ingredients in crafting.
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCardIngredient : public UDataAsset, public IPrintable, public ILocalisable {
	GENERATED_BODY()
	
public:
	__readonly FGuid Id;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	FText Desc;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	double UseCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cost")
	int32 CraftCost;

	UCardIngredient() : Id(FGuid::NewGuid()), UseCost(0), CraftCost(0) {}

	UFUNCTION(BlueprintCallable)
	virtual UCardNode* WrapIntoNode(UActorComponent* CardCrafter);

	virtual FString ToString_Implementation() const override;

	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
};
