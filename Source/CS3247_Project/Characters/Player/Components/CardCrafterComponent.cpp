// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCrafterComponent.h"

#include "CS3247_Project/Cards/Crafting/Card Effects/CardIngredient.h"
#include "CS3247_Project/Cards/Crafting/Nodes/CardNode.h"
#include "CS3247_Project/Cards/Crafting/Recipe/CardRecipe.h"
#include "CS3247_Project/Cards/Crafting/Recipe/RecipeEdge.h"
#include "CS3247_Project/Cards/Crafting/Recipe/IngredientWrappers/IngredientKey.h"


// Sets default values for this component's properties
UCardCrafterComponent::UCardCrafterComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCardCrafterComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

void UCardCrafterComponent::LoadRecipe(TArray<FRecipeEdge> EdgeList) {
	if (EdgeList.IsEmpty()) {
		return;
	}

	FIngredientKey Root = EdgeList[0].From;
	UCardNode* RootNode = NewObject<UCardNode>(this->CurrentRecipe);
	TMap<FIngredientKey, UCardNode*> NodeMap = {{Root, RootNode}};
	for (const auto& [From, To] : EdgeList) {
		UCardNode* ParentNode = NodeMap[From]; // This should exist!
		// Create a node for the child.
		UCardNode* ChildNode = To.Ingredient->WrapIntoNode(this);
		// Link parent to child.
		FText ErrorMsg = FText::GetEmpty();
		if (ParentNode->AddSuccessor(ChildNode, ErrorMsg)) {
			// this->OnAddIngredient.Broadcast()
			// Add child to map
			NodeMap.Add(To, ChildNode);
			return;
		} 
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ErrorMsg.ToString());
	}
}

TArray<FRecipeEdge> UCardCrafterComponent::ParseRecipe() const {
	return this->CurrentRecipe->ToEdgeList();
}


// Called every frame
void UCardCrafterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

