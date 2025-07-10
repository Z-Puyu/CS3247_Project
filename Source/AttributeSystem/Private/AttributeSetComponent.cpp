// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetComponent.h"

#include "Attribute.h"
#include "ModifierMediator.h"


// Sets default values for this component's properties
UAttributeSetComponent::UAttributeSetComponent() {
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
    this->ModifierMediator = NewObject<UModifierMediator>(this);
}


void UAttributeSetComponent::Recompute(const FGameplayTag& Attribute) {
    const int32 Base = this->BaseAttributeValues.FindOrAdd(Attribute, FAttribute::Zero(Attribute)).Value;
    this->BonusAttributeValues[Attribute] = this->ModifierMediator->QueryBonus(Attribute, Base);
}

// Called when the game starts
void UAttributeSetComponent::BeginPlay() {
    Super::BeginPlay();

    // ...
}

FAttribute UAttributeSetComponent::Query(const FGameplayTag& Name) {
    if (this->DirtyAttribute.Contains(Name)) {
        this->Recompute(Name);
    }
    
    FAttribute Value = this->BaseAttributeValues.FindOrAdd(Name, FAttribute::Zero(Name)) +
                       this->BonusAttributeValues.FindOrAdd(Name, 0);
    return Value;
}

void UAttributeSetComponent::AddModifier(const FGameplayTag& Target, const FModifier& Modifier) {
    this->ModifierMediator->Add(Target, Modifier);
    this->MarkDirty(Target);
}
