// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckComponent.h"


// Sets default values for this component's properties
UDeckComponent::UDeckComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	this->Deck = {};
	this->DefaultCards = {};
	// ...
}


// Called when the game starts
void UDeckComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

void UDeckComponent::AddCard(UCard* Card) {
	this->Deck.Add(Card);
	this->OnAddCard.Broadcast(Card);
}

UCard* UDeckComponent::RandomDraw() {
	if (this->Deck.Num() > 0) {
		UCard* Card = this->Deck[FMath::RandRange(0, this->Deck.Num() - 1)];
		this->Deck.Remove(Card);
		return Card;
	}
	
	return this->DefaultCards[FMath::RandRange(0, this->DefaultCards.Num() - 1)];
}


// Called every frame
void UDeckComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

