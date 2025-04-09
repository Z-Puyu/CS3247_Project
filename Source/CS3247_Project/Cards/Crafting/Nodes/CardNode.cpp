// Fill out your copyright notice in the Description page of Project Settings.


#include "CardNode.h"
#include "../Card Effects/Enchantments/CardEnchantment.h"

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
		Node->Predecessor = this;
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

	if (this->Predecessor && this->Predecessor == Node) {
		FText Empty = FText::GetEmpty();
		return Node->BreakLinkWith(this, Empty);
	}

	if (this->FirstSuccessor && Node->Predecessor && this->FirstSuccessor == Node &&  Node->Predecessor == this) {
		this->FirstSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}

	if (this->SecondSuccessor && Node->Predecessor && Node == this->SecondSuccessor && this == Node->Predecessor) {
		this->SecondSuccessor = nullptr;
		Node->Predecessor = nullptr;
		return true;
	}

	ErrorMsg = FText::Format(FTextFormat::FromString("{0} and {1} are not connected"),
		Execute_ToText(this), Execute_ToText(Node));
	return false;
}

void UCardNode::BreakAllLinks() {
	FText Empty = FText::GetEmpty();
	if (this->Predecessor) {
		this->Predecessor->BreakLinkWith(this, Empty);
	}

	if (this->FirstSuccessor) {
		this->FirstSuccessor->BreakLinkWith(this, Empty);
	}

	if (this->SecondSuccessor) {
		this->SecondSuccessor->BreakLinkWith(this, Empty);
	}
}

TArray<UCardEffect*> UCardNode::Build(UCard& OwningCard, double& ModifierPower) {
	return {};
}

TMap<UResource*, int32> UCardNode::GetSubtreeCost() const {
	TMap<UResource*, int32> Cost = {};
	if (this->FirstSuccessor) {
		Cost.Append(this->FirstSuccessor->GetSubtreeCost());
	}

	if (this->SecondSuccessor) {
		Cost.Append(this->SecondSuccessor->GetSubtreeCost());
	}

	Cost.Append(this->Unpack().Ingredient->CraftCost);
	return Cost;
}

TArray<UCardNode*> UCardNode::GetSuccessors() const {
	if (this->FirstSuccessor && this->SecondSuccessor) {
		return { this->FirstSuccessor, this->SecondSuccessor };
	}

	if (this->FirstSuccessor) {
		return { this->FirstSuccessor };
	}

	if (this->SecondSuccessor) {
		return { this->SecondSuccessor };
	}
		
	return {};
}

bool UCardNode::operator==(const UCardNode& Other) const {
	return this->Unpack() == Other.Unpack() &&
		(this->FirstSuccessor == Other.FirstSuccessor && this->SecondSuccessor == Other.SecondSuccessor) ||
		(this->FirstSuccessor == Other.SecondSuccessor && this->SecondSuccessor == Other.FirstSuccessor);
}

int32 GetTypeHash(const UCardNode& Node) {
	const int32 FirstSuccessorHash = Node.FirstSuccessor ? GetTypeHash(Node.FirstSuccessor) : 0;
	const int32 SecondSuccessorHash = Node.SecondSuccessor ? GetTypeHash(Node.SecondSuccessor) : 0;
	const int32 SuccessorHash = FirstSuccessorHash < SecondSuccessorHash
		? HashCombine(FirstSuccessorHash, SecondSuccessorHash)
		: HashCombine(SecondSuccessorHash, FirstSuccessorHash);
	return HashCombine(GetTypeHash(Node.Unpack()), SuccessorHash);
}
