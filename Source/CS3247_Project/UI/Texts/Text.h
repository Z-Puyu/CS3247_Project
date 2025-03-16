// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Text.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UText : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Rich-Text Formatting")
	static FORCEINLINE FText Bf(const FString& Str) {
		return FText::FromString(TEXT("<bf>" + Str + "</>"));
	}

	UFUNCTION(BlueprintCallable, Category = "Rich-Text Formatting")
	static FORCEINLINE FText It(const FString& Str) {
		return FText::FromString(TEXT("<it>" + Str + "</>"));
	}

	FORCEINLINE static FText BfIt(const FString& Str) {
		return FText::FromString(TEXT("<bfit>" + Str + "</>"));
	}

	FORCEINLINE static FText Rm(const FString& Str) {
		return FText::FromString(TEXT("<rm>" + Str + "</>"));
	}

	FORCEINLINE static FText Red(const FString& Str) {
		return FText::FromString(TEXT("<red>" + Str + "</>"));
	}

	FORCEINLINE static FText Green(const FString& Str) {
		return FText::FromString(TEXT("<green>" + Str + "</>"));
	}
};
