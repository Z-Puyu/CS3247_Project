// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackAction.h"

#include "AiDecisionContext.h"
#include "../Enemy.h"
#include "../EnemyCharacter.h"
#include "../../Player/PlayerCharacter.h"
#include "../../../Common/BasicGameInstance.h"
#include "Kismet/GameplayStatics.h"

float UAttackAction::Evaluate(const FAiDecisionContext Context) const {
	UBasicGameInstance* GameInstance = Cast<UBasicGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	const APlayerCharacter* Player = Context.PlayerData;
	const AEnemyCharacter* Self = Context.SelfData;
	const auto [DamageType, Value] = Self->EnemyData.Get()->Attack;
	int32 ActualDamage = Value;
	if (GameInstance->ResistanceTypes.Contains(DamageType)) {
		const int32 PlayerResistance = Player->GetAttribute(GameInstance->ResistanceTypes[DamageType]);
		ActualDamage *= ((100 - PlayerResistance) / 100.0);
	}
	
	const UPlayerAttributeSet* PlayerAttributes = Cast<UPlayerAttributeSet>(
		Player->GetAbilitySystemComponent()->GetAttributeSet(UPlayerAttributeSet::StaticClass()));
	const float RandomMultiplier = FMath::FRandRange(1 - this->RandomnessAllowance, 1 + this->RandomnessAllowance);
	return this->EvaluationCurve.GetRichCurveConst()->Eval(ActualDamage / PlayerAttributes->GetHealth()) * RandomMultiplier;
}
