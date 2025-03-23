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
	Super::BeginPlay();
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	if (IsValid(AbilitySystem)) {
		this->AttributeSet = AbilitySystem->GetSet<UPlayerAttributeSet>();
	}

	CurrHP = MaxHP;
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

void APlayerCharacter::SignalAttributeChange(const FGameplayAttribute& Attribute) const {
	const UAbilitySystemComponent* AbilitySystem = this->GetAbilitySystemComponent();
	bool bIsAttributeFound = false;
	const float Curr = AbilitySystem->GetGameplayAttributeValue(Attribute, bIsAttributeFound);
	float Max = 100.0f;
	const UPlayerAttributeSet* PlayerAttributeSet = Cast<UPlayerAttributeSet>(
		AbilitySystem->GetAttributeSet(UPlayerAttributeSet::StaticClass()));
	if (Attribute == PlayerAttributeSet->GetHealthAttribute()) {
		Max = PlayerAttributeSet->GetMaxHealth();
	} else if (Attribute == PlayerAttributeSet->GetManaAttribute()) {
		Max = PlayerAttributeSet->GetMaxMana();
	} else if (Attribute == PlayerAttributeSet->GetMaxManaAttribute() || Attribute == PlayerAttributeSet->GetMaxHealthAttribute()) {
		Max = static_cast<float>(INT32_MAX);
	}

	this->OnAttributeUpdated.Broadcast(Attribute, Curr, Max);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

