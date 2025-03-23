// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3247_Project/Characters/BasicCharacter.h"
#include "CS3247_Project/GameplayAbilities/AttributeSet/PlayerAttributeSet.h"
#include "Misc/GeneratedTypeName.h"
#include "PlayerCharacter.generated.h"

class UCard;

UCLASS()
class CS3247_PROJECT_API APlayerCharacter : public ABasicCharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "Health")
	int GetPlayerHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ReceiveDamage(int AttackDamage);

	UFUNCTION(BlueprintCallable, Category = "Status")
	void PlayerIsDead();
	
	virtual void SignalAttributeChange(const FGameplayAttribute& Attribute) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta=(AllowPrivateAccess="true"))
	const UPlayerAttributeSet* AttributeSet;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int CurrHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int MaxHP;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
