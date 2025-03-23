// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Cards/Crafting/Recipe/CardRecipe.h"
#include "CardCrafterComponent.generated.h"


class UDeckComponent;
class UCardNode;
struct FRecipeEdge;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UCardCrafterComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCardCrafterComponent();

protected:
	UPROPERTY()
	TObjectPtr<UCardRecipe> CurrentRecipe;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void LoadRecipe(TArray<FRecipeEdge> EdgeList);

	UFUNCTION(BlueprintCallable)
	TArray<FRecipeEdge> ParseRecipe() const;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UCard* Forge(UDeckComponent* PlayerDeckComponent) const { return this->CurrentRecipe->Forge(PlayerDeckComponent); }
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
