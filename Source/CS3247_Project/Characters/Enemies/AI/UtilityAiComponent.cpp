// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAiComponent.h"

#include "AiDecision.h"
#include "AiDecisionContext.h"
#include "CombatContext.h"
#include "../Enemy.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../EnemySkills/EnemySkill.h"

// Sets default values for this component's properties
UUtilityAiComponent::UUtilityAiComponent(): RandomnessAllowance(0) {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UUtilityAiComponent::BeginPlay() {
	Super::BeginPlay();
	TSet<UEnemySkill*> EnemySkills = Cast<AEnemyCharacter>(this->GetOwner())->EnemyData.Get()->Skills;
	for (auto& Skill : EnemySkills) {
		this->StrategySpace.Add(Skill);
	}
}

float UUtilityAiComponent::Evaluate(const UEnemySkill& Action, const FAiDecisionContext& Context) const {
	const float RandomMultiplier = FMath::RandRange(1.0f - this->RandomnessAllowance, 1.0f + this->RandomnessAllowance);
	float Total = 0.0f;
	float Max = -1.0f;
	for (auto& Effect : Action.Effects) {
		// For each action effect, normalise its raw utility to [0, 1].
		const float EffectRawScore = Effect->Evaluate(GetWorld(), Context) * RandomMultiplier;
        float EffectScore = 0;
        if (const FRuntimeFloatCurve* FoundCurve = EvaluationCurves.Find(Effect->GetClass()))
        {
            EffectScore = FoundCurve->GetRichCurveConst()->Eval(EffectRawScore);
        }
		Total += EffectScore;
		Max = FMath::Max(Max, EffectScore);
	}

	// Formula suggested by ChatGPT >.<
	return Max + (1.0f - Max) * Total / Action.Effects.Num();
}

FAiDecision UUtilityAiComponent::Decide(const FCombatContext& Context) const {
    // Retrieve context data
    AEnemyCharacter* Self = Context.SelfData;
    APlayerCharacter* Player = Context.PlayerData;
    TArray<AEnemyCharacter*> Enemies = Context.Enemies;

    float MaxScore = -1.f;
    FAiDecision BestDecision;

    // Iterate over each possible skill in our strategy space
    for (auto& Skill : this->StrategySpace) {
        // Hostile branch: if the skill is applicable to the Player, we assume it is hostile.
        if (Skill->IsApplicableTo(Self, Player)) {
            TArray<ABasicCharacter*> SingleTarget;
            SingleTarget.Add(Player);
            FAiDecisionContext DecisionContext(Self, Player, SingleTarget);
            float Score = this->Evaluate(*Skill, DecisionContext);
            if (Score > MaxScore) {
                MaxScore = Score;
                BestDecision = FAiDecision(Skill->ToGameplayEffects(), SingleTarget);
            }
        }
        // AoE branch: if the skill is marked as AOE, gather all valid allies (and self, if applicable)
        else if (Skill->IsAoe()) {
            TArray<ABasicCharacter*> AoeTargets;
            for (AEnemyCharacter* Ally : Enemies) {
                if (Skill->IsApplicableTo(Self, Ally)) {
                    AoeTargets.Add(Ally);
                }
            }
            // Optionally include self if applicable
            if (Skill->IsApplicableTo(Self, Self)) {
                AoeTargets.Add(Self);
            }
            // Only evaluate if we found at least one valid target.
            if (AoeTargets.Num() > 0) {
                FAiDecisionContext DecisionContext(Self, Player, AoeTargets);
                float Score = this->Evaluate(*Skill, DecisionContext);
                if (Score > MaxScore) {
                    MaxScore = Score;
                    BestDecision = FAiDecision(Skill->ToGameplayEffects(), AoeTargets);
                }
            }
        }
        // Non-hostile, non-AOE branch: single-target actions for allies (e.g. a single-target heal)
        else {
            for (AEnemyCharacter* Enemy : Enemies) {
                if (!Skill->IsApplicableTo(Self, Enemy)) {
                    continue;
                }
                TArray<ABasicCharacter*> SingleTarget;
                SingleTarget.Add(Enemy);
                FAiDecisionContext DecisionContext(Self, Player, SingleTarget);
                float Score = this->Evaluate(*Skill, DecisionContext);
                if (Score > MaxScore) {
                    MaxScore = Score;
                    BestDecision = FAiDecision(Skill->ToGameplayEffects(), SingleTarget);
                }
            }
        }
    }

    return BestDecision;
}

// Called every frame
void UUtilityAiComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

