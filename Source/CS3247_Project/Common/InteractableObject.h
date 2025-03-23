// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.generated.h"

class APlayerCharacter;
class UBoxComponent;

UCLASS()
class CS3247_PROJECT_API AInteractableObject : public AActor {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText HintText;

	// Sets default values for this actor's properties
	AInteractableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnPlayerInRange(APlayerCharacter* Player);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnPlayerOutOfRange(APlayerCharacter* Player);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
