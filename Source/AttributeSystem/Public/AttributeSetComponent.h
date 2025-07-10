// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attribute.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "AttributeSetComponent.generated.h"

struct FModifier;
class UModifierMediator;

UCLASS(ClassGroup=(AttributeSystem), meta=(BlueprintSpawnableComponent))
class ATTRIBUTESYSTEM_API UAttributeSetComponent final : public UActorComponent {
	GENERATED_BODY()

private:
	TMap<FGameplayTag, FAttribute> BaseAttributeValues;
	TMap<FGameplayTag, int32> BonusAttributeValues;
	UPROPERTY()
	TObjectPtr<UModifierMediator> ModifierMediator;
	TSet<FGameplayTag> DirtyAttribute;

public:
	// Sets default values for this component's properties
	UAttributeSetComponent();

private:
	FORCEINLINE void MarkDirty(const FGameplayTag& Attribute) {
		this->DirtyAttribute.Add(Attribute);
	}

	void Recompute(const FGameplayTag& Attribute);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	FAttribute Query(const FGameplayTag& Name);
	void AddModifier(const FGameplayTag& Target, const FModifier& Modifier);
};
