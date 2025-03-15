// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowControlParallel.h"

#include "../Data/CardEffect.h"

TArray<TObjectPtr<UCardEffect>> UFlowControlParallel::Combine(UCardEffect* Left, UCardEffect* Right) {
	const double Multiplier = FMath::Max(1 + this->ModifierEffect / 100.0, 0);
	
	
	return {Left, Right};
}
