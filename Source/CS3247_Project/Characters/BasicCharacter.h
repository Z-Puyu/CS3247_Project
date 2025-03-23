// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "BasicCharacter.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class CS3247_PROJECT_API ABasicCharacter : public ACharacter, public IAbilitySystemInterface {
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAttributeUpdatedDispatcher, const FGameplayAttribute&, Attribute, int32, CurrentValue, int32, MaxValue);
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnAttributeUpdatedDispatcher OnAttributeUpdated;
	// Sets default values for this character's properties
	ABasicCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta=(AllowPrivateAccess="true"))
	UAbilitySystemComponent* AbilitySystemComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {
		return AbilitySystemComponent;
	}
	
	UFUNCTION(BlueprintCallable)
	virtual void SignalAttributeChange(const FGameplayAttribute& Attribute) const;

	UFUNCTION(BlueprintCallable)
	void SignalAllAttributeUpdates() const;
	
	UFUNCTION(BlueprintCallable)
	TMap<FGameplayAttribute, float> SaveAttributes() const;

	UFUNCTION(BlueprintCallable)
	void LoadAttributes(TMap<FGameplayAttribute, float> InAttributes) const;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE int32 GetAttribute(const FGameplayAttribute& Attribute) const {
		bool bFound = false;
		const int32 CurrValue = this->GetAbilitySystemComponent()->GetGameplayAttributeValue(Attribute, bFound);
		return bFound ? CurrValue : 0;
	}
};
