// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAttack.h"
#include "../BasicCharacter.h"
#include "EnemyCharacter.generated.h"

class UBasicAttributeSet;
class UEnemy;

UCLASS(BlueprintType, Blueprintable)
class CS3247_PROJECT_API AEnemyCharacter : public ABasicCharacter {
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDeadDispatcher, AEnemyCharacter*, DeadEnemy);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnemyAttackedDispatcher, AEnemyCharacter*, Attacker,
		FEnemyAttack, AttackData);
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnEnemyDeadDispatcher OnEnemyDead;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnEnemyAttackedDispatcher OnEnemyAttacked;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	TObjectPtr<UEnemy> EnemyData;

	UFUNCTION(BlueprintCallable, Category = "Status")
	bool GetIsDead();

	UFUNCTION(BlueprintCallable, Category = "Status")
	void SetIsDead();
	
	// Sets default values for this character's properties
	AEnemyCharacter();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta=(AllowPrivateAccess="true"))
	const UBasicAttributeSet* AttributeSet;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UPROPERTY(BlueprintReadOnly, Category = "Dead or Alive")
	bool isDead = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
