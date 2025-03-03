// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UI/Texts/TextDescribable.h"
#include "Crafting/Card Effects/CardEffect.h"
#include "Card.generated.h"

#define DURABILITY_COEFFICIENT 100.0
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CS3247_PROJECT_API UCard : public UObject, public ITextDescribable {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	int Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn))
	int Durability;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(ExposeOnSpawn))
	TArray<UCardEffect*> Effects;
	
	UCard();

	UFUNCTION(BlueprintCallable)
	virtual FText GetDescription() const override;

	UFUNCTION(BlueprintCallable)
	void GetCardInfo(FText& CardName, FText& Desc, int& UseCost, int& CardDurability, TArray<UCardEffect*>& CardEffects) const;
};
