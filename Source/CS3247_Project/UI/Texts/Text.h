// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Text.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UText : public UObject {
	GENERATED_BODY()

public:
	FORCEINLINE static FText Bf(const FString& Str) {
		return FText::FromString(TEXT("<bf>" + Str + "</bf>"));
	}

	FORCEINLINE static FText It(const FString& Str) {
		return FText::FromString(TEXT("<it>" + Str + "</it>"));
	}

	FORCEINLINE static FText BfIt(const FString& Str) {
		return FText::FromString(TEXT("<bfit>" + Str + "</bfit>"));
	}

	FORCEINLINE static FText Rm(const FString& Str) {
		return FText::FromString(TEXT("<rm>" + Str + "</rm>"));
	}

	FORCEINLINE static FText Red(const FString& Str) {
		return FText::FromString(TEXT("<red>" + Str + "</red>"));
	}

	FORCEINLINE static FText Green(const FString& Str) {
		return FText::FromString(TEXT("<green>" + Str + "</green>"));
	}
};
