// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrHP = 0;
	MaxHP = 20;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay() {
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	if (IsValid(AbilitySystem)) {
		this->AttributeSet = AbilitySystem->GetSet<UPlayerAttributeSet>();
	}

	Super::BeginPlay();
}

int APlayerCharacter::GetPlayerHealth() const {
	return CurrHP;
}

void APlayerCharacter::ReceiveDamage(int damage) {
	CurrHP -= damage;

	if (CurrHP <= 0) {
		CurrHP = 0;
		PlayerIsDead();
	}
}

void APlayerCharacter::PlayerIsDead() {
	UE_LOG(LogTemp, Log, TEXT("Player is Dead!"));
}

void APlayerCharacter::InitialiseAttributesUIData() {
	bool bIsAttributeFound = false;
	TArray<FGameplayAttribute> Attributes;
	this->AbilitySystemComponent->GetAllAttributes(Attributes);
	for (const auto& Attribute : Attributes) {
		const float Curr = this->AbilitySystemComponent->GetGameplayAttributeValue(Attribute, bIsAttributeFound);
		float Max = 100.0f;
		if (Attribute == this->AttributeSet->GetHealthAttribute()) {
			Max = this->AttributeSet->GetMaxHealth();
		} else if (Attribute == this->AttributeSet->GetManaAttribute()) {
			Max = this->AttributeSet->GetMaxMana();
		} else if (Attribute == this->AttributeSet->GetMaxManaAttribute() || Attribute == this->AttributeSet->GetMaxHealthAttribute()) {
			Max = static_cast<float>(INT32_MAX);
		}

		this->OnAttributeUpdated.Broadcast(Attribute, Curr, Curr, Max);
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}