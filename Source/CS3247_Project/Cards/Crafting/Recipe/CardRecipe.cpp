// Fill out your copyright notice in the Description page of Project Settings.


#include "CardRecipe.h"

#include "RecipeEdge.h"
#include "../Nodes/CardNode.h"
#include "../../Card.h"
#include "../../../Characters/Player/Components/DeckComponent.h"
#include "../Card Effects/Impacts/CardImpact.h"
#include "../Nodes/MixerNode.h"

TMap<UResource*, int32> UCardRecipe::GetCosts() const {
	return this->Source->GetSubtreeCost();
}

UCard* UCardRecipe::Forge(UDeckComponent* PlayerDeckComponent, const bool bIsDefault) {
	UCard* Card = NewObject<UCard>(PlayerDeckComponent);
	Card->bIsDefault = bIsDefault;
	Card->Recipe = this;
	double ModifierPower = 1.0;
	Card->Effects = this->Source.Get()->Build(*Card, ModifierPower);
	return Card;
}

TArray<FRecipeEdge> UCardRecipe::ToEdgeList() {
	if (!this->Edges.IsEmpty()) {
		return this->Edges;
	}

	const FIngredientKey RootIngredient = this->Source->Unpack();
	this->Edges.Add(FRecipeEdge(RootIngredient, RootIngredient));
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this->Source);
	UCardNode* Curr;
	while (Queue.Dequeue(Curr)) {
		const FIngredientKey IngredientKey = Curr->Unpack();

		for (auto& Successor : Curr->GetSuccessors()) {
			this->Edges.Add(FRecipeEdge(IngredientKey, Successor->Unpack()));
			Queue.Enqueue(Successor);
		}
	}
	
	return this->Edges;
}

TArray<UCardImpact*> UCardRecipe::FetchImpacts() const {
	TArray<UCardImpact*> Impacts = {};
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this->Source);
	// return {Cast<UCardImpact>(this->Source->Unpack().Ingredient)};
	UCardNode* Curr;
	while (Queue.Dequeue(Curr)) {
		if (Curr->IsA(UMixerNode::StaticClass())) {
			Impacts.Add(Cast<UMixerNode>(Curr)->Impact);
			continue;
		}
		
		const auto [Ingredient, _] = Curr->Unpack();
		if (Ingredient.IsA(UCardImpact::StaticClass())) {
			Impacts.Add(Cast<UCardImpact>(Ingredient));
		}
		
		for (auto& Successor : Curr->GetSuccessors()) {
			Queue.Enqueue(Successor);
		}
	}

	return Impacts;
}

FText UCardRecipe::ToText_Implementation() const {
	return ILocalisable::ToText_Implementation();
}

FText UCardRecipe::ToRichText_Implementation() const {
	return ILocalisable::ToRichText_Implementation();
}

bool UCardRecipe::operator==(const UCardRecipe& Other) const {
	return this->Source == Other.Source;
}

int32 GetTypeHash(UCardRecipe& Recipe) {
	return GetTypeHash(Recipe.Source);
}
