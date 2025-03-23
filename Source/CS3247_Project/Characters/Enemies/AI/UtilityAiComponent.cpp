// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAiComponent.h"
#include "AiDecisionContext.h"
#include "EnemyAction.h"


// Sets default values for this component's properties
UUtilityAiComponent::UUtilityAiComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUtilityAiComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

EEnemyMove UUtilityAiComponent::Decide(const FAiDecisionContext& Context) const {
	TArray<float> Scores = {};
	for (auto& Action : this->StrategySpace) {
		float Score = Action->Evaluate(Context);
		Scores.Add(Score);
	}

	float CurrMax = static_cast<float>(INT32_MIN);
	int Idx = 0;
	for (int i = 0; i < Scores.Num(); i += 1) {
		if (Scores[i] > CurrMax) {
			CurrMax = Scores[i];
			Idx = i;
		}
	}
	
	return this->StrategySpace[Idx]->ActionName;
}


// Called every frame
void UUtilityAiComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

