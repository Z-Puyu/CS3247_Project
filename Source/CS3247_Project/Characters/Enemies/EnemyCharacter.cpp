// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "../../GameplayAbilities/AttributeSet/BasicAttributeSet.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay() {
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	if (IsValid(AbilitySystem)) {
		this->AttributeSet = AbilitySystem->GetSet<UBasicAttributeSet>();
	}

    Super::BeginPlay();
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

bool AEnemyCharacter::GetIsDead() {
	return this->isDead;
}

void AEnemyCharacter::SetIsDead() {
	this->isDead = true;
}