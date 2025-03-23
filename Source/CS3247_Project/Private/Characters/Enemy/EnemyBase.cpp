// Fill out your copyright notice in the Description page of Project Settings.


#include "CS3247_Project/Public/Characters/Enemy/EnemyBase.h"
#include "CS3247_Project/Characters/Player/PlayerCharacter.h"
#include "Engine/Engine.h"         
#include "Kismet/GameplayStatics.h" 
#include "Math/UnrealMathUtility.h"

// EnemyBase.cpp

AEnemyBase::AEnemyBase()
{
    CurrentHP = 0;
    MaxHP = 10;
    AttackDamage = 4;

    AvailableActions.Add(EEnemyActions::Attack);
    AvailableActions.Add(EEnemyActions::Guard);
    AvailableActions.Add(EEnemyActions::Heal);

}

void AEnemyBase::BeginPlay()
{
    Super::BeginPlay();

    // Initialize HP at spawn
    CurrentHP = MaxHP;
    IsDead = false;
}

void AEnemyBase::SetPlayer(APlayerCharacter* playerCharacter)
{
    player = playerCharacter;
}

int AEnemyBase::GetCurrentHealth() const {
    return CurrentHP;
}

void AEnemyBase::ReceiveDamage(int damage) {
    if (IsGuard) {
        IsGuard = false;
        damage = damage / 2 + 1;
    }
    CurrentHP -= damage;
    if (CurrentHP <= 0) {
        CurrentHP = 0;
        IsDead = true;
        Die();
    }
}

bool AEnemyBase::ReturnStatus() {
    return IsDead;
}

void AEnemyBase::Die() {

    OnEnemyDied.Broadcast(this);
    UE_LOG(LogTemp, Log, TEXT("Enemy is dead."));
    Destroy();
}

float AEnemyBase::ScoreAttack() const
{
    float Score = 5.f;

    int PlayerHP = player->GetPlayerHealth();

    // If we can *kill* the player, add a big bonus
    if (PlayerHP < AttackDamage)
    {
        Score += 10.f; // Guaranteed finishing blow
    }
    else
    {
        // Gradual bonus if AttackDamage is somewhat close to finishing them
        float HealthDiff = static_cast<float>(AttackDamage - PlayerHP);
        Score += FMath::Clamp(HealthDiff / 5.f, 0.f, 10.f);
    }

    // Prevent negative

    float randomOffset = FMath::FRandRange(-2.f, 2.f);
    Score += randomOffset;

    Score = FMath::Max(Score, 0.f);
    return Score;
}


float AEnemyBase::ScoreGuard() const
{
    float Score = 2.f;

    // If HP is below 40%, raise the priority
    if (static_cast<float>(CurrentHP) < (MaxHP * 0.4f))
    {
        Score += 10.f;
    }

    // (Optional) If we suspect a strong incoming attack, add synergy
    // e.g. if (player->IsChargingStrongAttack()) { Score += 5.f; }

    float randomOffset = FMath::FRandRange(-2.f, 2.f);
    Score += randomOffset;


    return Score;
}


float AEnemyBase::ScoreHeal() const
{
    // If HP is 50% => Score is 7.5, at 20% => 12, at near 0 => 15
    float HealthRatio = static_cast<float>(CurrentHP) / static_cast<float>(MaxHP);
    float Score = (1.f - HealthRatio) * 15.f;

    // Optionally clamp or add conditions if you want a floor/ceiling
    // Score = FMath::Clamp(Score, 0.f, 15.f);

    // If you have limited heal usage or cost, factor that in
    // e.g., if (!bCanHealAgain) { Score = 0.f; }

    float randomOffset = FMath::FRandRange(-2.f, 2.f);
    Score += randomOffset;


    return Score;
}


void AEnemyBase::DecideAction()
{
    // If no actions available, bail out
    if (AvailableActions.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No actions available!"));
        return;
    }

    float BestScore = -FLT_MAX;
    EEnemyActions BestAction = EEnemyActions::Attack; // default fallback

    // Compute utility scores for each possible action
    for (EEnemyActions Action : AvailableActions)
    {
        float Score = 0.f;
        switch (Action)
        {
        case EEnemyActions::Attack:
            Score = ScoreAttack();
            break;
        case EEnemyActions::Guard:
            Score = ScoreGuard();
            break;
        case EEnemyActions::Heal:
            Score = ScoreHeal();
            break;
        default:
            break;
        }

        // Track highest
        if (Score > BestScore)
        {
            BestScore = Score;
            BestAction = Action;
        }
    }

    // Execute the best action
    switch (BestAction)
    {
    case EEnemyActions::Attack:
        PerformAttack();
        break;
    case EEnemyActions::Guard:
        PerformGuard();
        break;
    case EEnemyActions::Heal:
        PerformHeal();
        break;
    default:
        break;
    }
}

void AEnemyBase::PerformAttack()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is ATTACKING!"));
    player->ReceiveDamage(AttackDamage);
    // Apply damage, show animation, etc.
}

void AEnemyBase::PerformGuard()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is GUARDING!"));
    IsGuard = true;
    // Set guard flags, reduce incoming damage next turn, etc.
}

void AEnemyBase::PerformHeal()
{
    UE_LOG(LogTemp, Log, TEXT("Enemy is HEALING!"));
    CurrentHP = FMath::Clamp(CurrentHP + (MaxHP * 0.2f), 0, MaxHP);
    // Possibly remove Heal from AvailableActions if it's a one-time ability
}
