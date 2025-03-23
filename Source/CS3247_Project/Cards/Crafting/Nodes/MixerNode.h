// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardNode.h"
#include "../Card Effects/FlowControl/IngredientMixer.h"
#include "MixerNode.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UMixerNode : public UCardNode {
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UIngredientMixer> Mixer;

	FORCEINLINE virtual FIngredientKey Unpack() const override { return FIngredientKey(this->Mixer, this->Id); }

	virtual TArray<UCardEffect*> Build(UCard& OwningCard, double& ModifierPower) override;

	FORCEINLINE virtual FString ToString_Implementation() const override { return TEXT("[" + this->Mixer->GetName() + "]"); }
};
