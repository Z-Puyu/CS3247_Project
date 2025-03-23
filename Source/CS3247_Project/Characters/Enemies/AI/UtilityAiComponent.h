// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemy/EnemyActions.h"
#include "Components/ActorComponent.h"
#include "UtilityAiComponent.generated.h"


struct FAiDecisionContext;
class UEnemyAction;

UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CS3247_PROJECT_API UUtilityAiComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUtilityAiComponent();

protected:
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TArray<UEnemyAction*> StrategySpace;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	EEnemyActions Decide(const FAiDecisionContext& Context) const;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
