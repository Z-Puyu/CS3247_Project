// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetComponent.h"
#include "Attribute.h"
#include "ModifierMediator.h"

UAttributeSetComponent::UAttributeSetComponent() {
    PrimaryComponentTick.bCanEverTick = false;
    this->ModifierMediator = this->CreateDefaultSubobject<UModifierMediator>("Modifier Mediator");
}


void UAttributeSetComponent::Recompute(const FGameplayTag& Attribute) {
    const int32 Base = this->BaseAttributeValues.FindOrAdd(Attribute, FAttribute::Zero(Attribute)).Value;
    this->BonusAttributeValues[Attribute] = this->ModifierMediator->QueryBonus(Attribute, Base);
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
