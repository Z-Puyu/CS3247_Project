#pragma once

#include "CoreMinimal.h"
#include "EnemyActions.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDied, AEnemyBase*, DeadEnemy);

UCLASS()
class CS3247_PROJECT_API AEnemyBase : public AActor
{
    GENERATED_BODY()

public:
    AEnemyBase();

    UPROPERTY(BlueprintAssignable, Category="Events")
    FOnEnemyDied OnEnemyDied;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Main function to pick an action via utility scoring
    UFUNCTION(BlueprintCallable, Category = "AI")
    void DecideAction();

    UFUNCTION(BlueprintCallable)
    void SetPlayer(APlayerCharacter* playerCharacter);

    UFUNCTION(BlueprintCallable, Category = "Health")
    void ReceiveDamage(int damage);

    UFUNCTION(BlueprintCallable, Category = "Health")
    int GetCurrentHealth() const;

    UFUNCTION(BlueprintCallable, Category = "status")
    void Die();

    UFUNCTION(BlueprintCallable, Category = "Enemy")
    virtual bool ReturnStatus();

    UPROPERTY()
    APlayerCharacter* player;

protected:

    // Potential health or other stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int CurrentHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int MaxHP;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    int AttackDamage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    bool IsGuard;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
    bool IsDead;

    // Example set of allowed actions
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TArray<EEnemyActions> AvailableActions;

    // Make these virtual so derived classes can override them
    virtual float ScoreAttack() const;
    virtual float ScoreGuard() const;
    virtual float ScoreHeal() const;

    virtual void PerformAttack();
    virtual void PerformGuard();
    virtual void PerformHeal();
};
