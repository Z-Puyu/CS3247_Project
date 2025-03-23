// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicGameInstance.h"

FName UBasicGameInstance::GetName_Implementation(const FGameplayTag Tag) const {
	if (this->GameplayTagLocalisations.Contains(Tag)) {
		return this->GameplayTagLocalisations[Tag];
	}

	return Tag.GetTagName();
}
