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
	static FString Bf(const FString& Str);

	static FString It(const FString& Str);

	static FString BfIt(const FString& Str);

	static FString Rm(const FString& Str);

	static FString Red(const FString& Str);

	static FString Green(const FString& Str);
};
