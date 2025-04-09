// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"

#include "CS3247_Project/GameplayAbilities/AttributeSet/PlayerAttributeSet.h"


// Sets default values
ABasicCharacter::ABasicCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay() {
	Super::BeginPlay();
}

TMap<FGameplayAttribute, float> ABasicCharacter::SaveAttributes() const {
	TMap<FGameplayAttribute, float> SaveData = {};
	TArray<FGameplayAttribute> Attributes = {};
	this->GetAbilitySystemComponent()->GetAllAttributes(Attributes);
    for (FGameplayAttribute Attribute : Attributes) {
    	float Value = this->GetAbilitySystemComponent()->GetNumericAttribute(Attribute);
        SaveData.Add(Attribute, Value);
    	FString AttributeName = Attribute.GetName();
    	UE_LOG(LogTemp, Display, TEXT("Saved attribute: %s, Value: %f"), *AttributeName, Value);
    }
	
    return SaveData;
}

void ABasicCharacter::LoadAttributes(TMap<FGameplayAttribute, float> InAttributes) const {
	for (auto& Entry : InAttributes) {
		this->GetAbilitySystemComponent()
			->ApplyModToAttribute(Entry.Key, EGameplayModOp::Override, Entry.Value);
	}

	// Twice because we want the clamping to work properly.
	// Obviously there are smarter ways to do it, but I lazy.
	for (auto& Entry : InAttributes) {
		FString AttributeName = Entry.Key.GetName();
		UE_LOG(LogTemp, Display, TEXT("Load attribute: %s, Value: %f"), *AttributeName, Entry.Value);
		this->GetAbilitySystemComponent()
			->ApplyModToAttribute(Entry.Key, EGameplayModOp::Override, Entry.Value);
	}
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

