// Fill out your copyright notice in the Description page of Project Settings.


#include "BranchNode.h"

TArray<TObjectPtr<UCardEffect>> UBranchNode::Build(UCard* OwningCard) {
	TArray<TObjectPtr<UCardEffect>> CardEffects = this->FirstSuccessor->Build(OwningCard);
	this->Brancher->Merge(CardEffects, this->SecondSuccessor->Build(OwningCard));
	return CardEffects;
}
