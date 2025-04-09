// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Common/GameItem.h"
#include "Resource.generated.h"

/**
 * 
 */
UCLASS()
class CS3247_PROJECT_API UResource : public UGameItem {
	GENERATED_BODY()

public:
	UResource() : Super(EGameItemTag::Resource), Worth(0) {}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Basic Info")
	int32 Worth;
};
