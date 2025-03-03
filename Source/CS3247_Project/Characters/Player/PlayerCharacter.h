// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CS3247_Project/Characters/BasicCharacter.h"
#include "CS3247_Project/GameplayAbilities/AttributeSet/PlayerAttributeSet.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CS3247_PROJECT_API APlayerCharacter : public ABasicCharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta=(AllowPrivateAccess="true"))
	const UPlayerAttributeSet* AttributeSet;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
