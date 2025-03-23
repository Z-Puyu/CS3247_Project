// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"

#include "RecipeEdge.h"
#include "../Nodes/CardNode.h"
#include "../../Card.h"
#include "../../../Characters/Player/Components/DeckComponent.h"

UCard* UCardRecipe::Forge(UDeckComponent* PlayerDeckComponent) const {
	UCard* Card = NewObject<UCard>(PlayerDeckComponent);
	double ModifierPower = 1.0;
	Card->Effects = this->Source.Get()->Build(*Card, ModifierPower);
	return Card;
}

TArray<FRecipeEdge> UCardRecipe::ToEdgeList() {
	if (!this->Edges.IsEmpty()) {
		return this->Edges;
	}
	
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this->Source);
	UCardNode* Curr;
	while (!Queue.Dequeue(Curr)) {
		const FIngredientKey IngredientKey = Curr->Unpack();

		for (auto& Successor : Curr->GetSuccessors()) {
			this->Edges.Add(FRecipeEdge(IngredientKey, Successor->Unpack()));
			Queue.Enqueue(Successor);
		}
	}
	
	return this->Edges;
}

bool UCardRecipe::operator==(const UCardRecipe& Other) const {
	return this->Source == Other.Source;
}

int32 GetTypeHash(UCardRecipe& Recipe) {
	return GetTypeHash(Recipe.Source);
}
