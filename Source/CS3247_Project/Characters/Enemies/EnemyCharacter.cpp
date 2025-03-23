// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "../GameplayAbilities/AttributeSet/BasicAttributeSet.h"
#include "Characters/Enemy/EnemyActions.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyCharacter::SignalAttributeChange(const FGameplayAttribute& Attribute) const {
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	bool bIsAttributeFound = false;
	const float Curr = AbilitySystem->GetGameplayAttributeValue(Attribute, bIsAttributeFound);
	float Max = 100.0f;
	const UBasicAttributeSet* EnemyAttributeSet = Cast<UBasicAttributeSet>(
		AbilitySystem->GetAttributeSet(UBasicAttributeSet::StaticClass()));
	if (Attribute == EnemyAttributeSet->GetHealthAttribute()) {
		Max = EnemyAttributeSet->GetMaxHealth();
	}

	this->OnAttributeUpdated.Broadcast(Attribute, Curr, Max);
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay() {
	Super::BeginPlay();
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	if (IsValid(AbilitySystem)) {
		this->AttributeSet = AbilitySystem->GetSet<UBasicAttributeSet>();
	}
}

void AEnemyCharacter::Destroyed() {
	Super::Destroyed();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

