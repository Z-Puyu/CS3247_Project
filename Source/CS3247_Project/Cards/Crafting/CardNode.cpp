// Fill out your copyright notice in the Description page of Project Settings.


#include "CardNode.h"
#include "Card Effects/Enchantments/CardEnchantment.h"

bool UCardNode::AddSuccessor(UCardNode* Node, FText& ErrorMsg) {
	if (!IsValid(Node)) {
		ErrorMsg = FText::FromString(TEXT("The parent node is not alive."));
		return false;
	}
	
	// If the node already has a predecessor, cannot link.
	if (IsValid(Node->Predecessor)) {
		ErrorMsg = FText::FromString(TEXT("The child node already has a predecessor. Unlink first."));
		return false;
	}

	// If the node is already a successor, cannot re-link.
	if (Node == this->FirstSuccessor || Node == this->SecondSuccessor) {
		ErrorMsg = FText::FromString(TEXT("The child node is already a successor. Duplicated link."));
		return false;
	}

	if (!IsValid(this->FirstSuccessor)) {
		this->FirstSuccessor = Node;
		Node->Predecessor = this;
		return true;
	}

	if (!IsValid(this->SecondSuccessor)) {
		this->SecondSuccessor = Node;
		Node->Predecessor = Node;
		return true;
	}

	// The node already has two children.
	ErrorMsg = FText::FromString(TEXT("The parent node already has two successors. Unlink one of them first."));
	return false;
}

bool UCardNode::BreakLinkWith(UCardNode* Node, FText& ErrorMsg) {
	if (!IsValid(Node)) {
		ErrorMsg = FText::FromString(TEXT("The other node is not alive."));
		return false;
	}

	if (Node == this->Predecessor) {
		FText Empty = FText::GetEmpty();
		return Node->BreakLinkWith(this, Empty);
	}

	if (Node == this->FirstSuccessor && this == Node->Predecessor) {
		this->FirstSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}

	if (Node == this->SecondSuccessor && this == Node->Predecessor) {
		this->SecondSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}

	ErrorMsg = FText::Format(FTextFormat::FromString("{0} and {1} are not connected"),
		this->ToText(), Node->ToText());
	return false;
}

void UCardNode::BreakAllLinks() {
	FText Empty = FText::GetEmpty();
	if (IsValid(this->Predecessor)) {
		this->Predecessor->BreakLinkWith(this, Empty);
	}

	this->FirstSuccessor->BreakLinkWith(this, Empty);
	this->SecondSuccessor->BreakLinkWith(this, Empty);
}

TArray<TObjectPtr<UCardEffect>> UCardNode::Build(UCard* OwningCard) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Building from ") + this->Ingredient->GetName());
	// If this is a leaf node, we expect it to be an impact, so just build.
	if (this->IsTerminal()) {
		return {this->Ingredient->Apply(OwningCard)};
	}

	TArray<TObjectPtr<UCardEffect>> CardEffects = {};
	// Otherwise, build the first successor.
	TArray<TObjectPtr<UCardEffect>> LeftSubtree = this->FirstSuccessor->Build(OwningCard);
	
	
	
	
	if (this->Ingredient->IsA(UCardEnchantment::StaticClass())) {
		UCardEnchantment* Enchantment = Cast<UCardEnchantment>(this->Ingredient);
		/*for (const auto& Successor : this->Successors) {
			for (const auto& CardEffect : Successor->Build()) {
				CardEffects.Add(Enchantment->Enchant(CardEffect));
			}
		}*/
		
		return CardEffects;
	}

	/*for (const auto& Successor : this->Successors) {
		CardEffects.Append(Successor->Build());
	}*/
	
	return CardEffects;
}

