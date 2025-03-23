// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../../../UI/Texts/Localisable.h"
#include "../../../../UI/Texts/Printable.h"
#include "UObject/Object.h"
#include "AtomicCardEffect.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, DefaultToInstanced, EditInlineNew)
class CS3247_PROJECT_API UAtomicCardEffect : public UObject, public ILocalisable, public IPrintable {
	GENERATED_BODY()

public:
	virtual void OffsetStrength(const double Offset);

	virtual void ScaleStrength(const double Ratio);

	virtual FString ToString_Implementation() const override;
	
	virtual FText ToText_Implementation() const override;

	virtual FText ToRichText_Implementation() const override;
};
