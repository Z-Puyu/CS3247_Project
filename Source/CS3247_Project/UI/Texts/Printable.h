// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Printable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, BlueprintType, MinimalAPI)
class UPrintable : public UInterface {
	GENERATED_BODY()
};

/**
 * An interface for classes that can be converted to a debugging string.
 * Commonly used for things that need to be logged or printed to the screen.
 */
class CS3247_PROJECT_API IPrintable {
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Text Conversion")
	FString ToString() const;

	virtual FString ToString_Implementation() const { return TEXT(""); }
};
