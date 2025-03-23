// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../../Cards/Card.h"
#include "DeckComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UDeckComponent : public UActorComponent {
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddCardDispatcher, const UCard*, Card);
	
	// Sets default values for this component's properties
	UDeckComponent();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Deck", meta = (AllowPrivateAccess = "true"))
	TArray<UCard*> Deck;
	
	UPROPERTY(BlueprintReadOnly, Category = "Deck", meta = (AllowPrivateAccess = "true"))
	TArray<UCard*> InitialCards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck", DisplayName = "Initial Recipes", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<UCardRecipe>> TestRecipes;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Deck")
	FOnAddCardDispatcher OnAddCard;

	UFUNCTION(BlueprintCallable)
	void AddCard(UCard* Card);

	UFUNCTION(BlueprintCallable)
	UCard* RandomDraw();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
