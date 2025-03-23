// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "DataManager.generated.h"

struct FGameplayTag;
// This class does not need to be modified.
UINTERFACE(Blueprintable, BlueprintType, MinimalAPI)
class UDataManager : public UInterface {
	GENERATED_BODY()
};

class CS3247_PROJECT_API IDataManager {
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Gameplay Tags")
	FName GetName(FGameplayTag Tag) const;

	virtual FName GetName_Implementation(const FGameplayTag Tag) const { return Tag.GetTagName(); }
};
