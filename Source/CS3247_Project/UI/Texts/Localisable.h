// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Localisable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, BlueprintType, MinimalAPI)
class ULocalisable : public UInterface {
	GENERATED_BODY()
};

/**
 * An interface for classes that can be localised into a text representation.
 * Commonly used for things that need to be displayed in the UI.
 */
class CS3247_PROJECT_API ILocalisable {
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Text Conversion")
	FText ToText() const;

	virtual FText ToText_Implementation() const { return FText::GetEmpty(); }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Text Conversion")
	FText ToRichText() const;

	virtual FText ToRichText_Implementation() const { return FText::GetEmpty(); }
};
