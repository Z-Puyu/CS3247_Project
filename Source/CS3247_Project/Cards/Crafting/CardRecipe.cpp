// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"
#include "Nodes/CardNode.h"
#include "../Card.h"

UCard* UCardRecipe::Forge(UActorComponent* PlayerDeckComponent) const {
	UCard* Card = NewObject<UCard>(PlayerDeckComponent);
	Card->Effects = this->Source.Get()->Build(Card);
	return Card;
}
