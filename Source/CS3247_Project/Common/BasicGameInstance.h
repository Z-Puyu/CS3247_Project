// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "DataManager.h"
#include "Engine/GameInstance.h"
#include "BasicGameInstance.generated.h"

struct FGameplayTag;
/**
 * 
 */
UCLASS(Blueprintable)
class CS3247_PROJECT_API UBasicGameInstance : public UGameInstance, public IDataManager {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, FName> GameplayTagLocalisations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayAttribute, FGameplayTag> AttributesToTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag, FGameplayAttribute> ResistanceTypes;

	UFUNCTION(BlueprintCallable)
	virtual FName GetName_Implementation(const FGameplayTag Tag) const override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameplayTag AttributeToAssetTag(const FGameplayAttribute Attribute) {
		return this->AttributesToTags[Attribute];
	};
};
