// Fill out your copyright notice in the Description page of Project Settings.


#include "IsOfEffectTypeCondition.h"

#include "../../Data/AtomicCardEffect.h"

bool UIsOfEffectTypeCondition::IsSatisfiedBy(UAtomicCardEffect& Effect) const {
	return Effect.GetClass()->IsChildOf(this->AllowedType);
}
