// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageExecution.h"
#include "../AttributeSet/BasicAttributeSet.h"

struct FDamageCapture {
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Defence);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ProjectileResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ExplosionResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(SliceResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(PoisonResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(WaterResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(FireResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AirResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(EarthResistance);
	DECLARE_ATTRIBUTE_CAPTUREDEF(ElectricResistance);

	FDamageCapture() {
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, Health, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, Defence, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, ProjectileResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, ExplosionResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, SliceResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, PoisonResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, WaterResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, FireResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, AirResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, EarthResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, ElectricResistance, Target, false);
	}
};

static FDamageCapture& GetDamageCapture() {
	static FDamageCapture DamageCapture;
	return DamageCapture;
}


UDamageExecution::UDamageExecution() {
	this->RelevantAttributesToCapture.Add(GetDamageCapture().HealthDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().DefenceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().ProjectileResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().ExplosionResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().SliceResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().PoisonResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().WaterResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().FireResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().AirResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().EarthResistanceDef);
	this->RelevantAttributesToCapture.Add(GetDamageCapture().ElectricResistanceDef);
}

void UDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const {
#pragma region Boilerplate Set-up
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	const UAbilitySystemComponent* TargetAbilitySystem = ExecutionParams.GetTargetAbilitySystemComponent();
	AActor* TargetActor = TargetAbilitySystem ? TargetAbilitySystem->GetAvatarActor() : nullptr;
	const UAbilitySystemComponent* SourceAbilitySystem = ExecutionParams.GetSourceAbilitySystemComponent();
	AActor* SourceActor = SourceAbilitySystem ? SourceAbilitySystem->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = SourceTags;
	EvalParams.TargetTags = TargetTags;
#pragma endregion

#pragma region Read Attributes
	float TargetHealth = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().HealthDef, EvalParams, TargetHealth);
	float TargetDefence = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().DefenceDef, EvalParams, TargetDefence);
	float TargetProjectileResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().ProjectileResistanceDef, EvalParams, TargetProjectileResistance);
	float TargetExplosionResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().ExplosionResistanceDef, EvalParams, TargetExplosionResistance);
	float TargetSliceResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().SliceResistanceDef, EvalParams, TargetSliceResistance);
	float TargetPoisonResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().PoisonResistanceDef, EvalParams, TargetPoisonResistance);
	float TargetWaterResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().WaterResistanceDef, EvalParams, TargetWaterResistance);
	float TargetFireResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().FireResistanceDef, EvalParams, TargetFireResistance);
	float TargetAirResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().AirResistanceDef, EvalParams, TargetAirResistance);
	float TargetEarthResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().EarthResistanceDef, EvalParams, TargetEarthResistance);
	float TargetElectricResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetDamageCapture().ElectricResistanceDef, EvalParams, TargetElectricResistance);
#pragma endregion

	const FGameplayTag DmgTag = FGameplayTag::RequestGameplayTag(FName("GameplayEffect.Combat.Damage"));
	float DmgAmount = -Spec.GetSetByCallerMagnitude(DmgTag);
	
	const FGameplayTagContainer& AssetTags = Spec.GetDynamicAssetTags();
#pragma region Calculate Resistance
	if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Projectile")))) {
		DmgAmount *= 1.0f - TargetProjectileResistance / 100.0f;	
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Explosion")))) {
		DmgAmount *= 1.0f - TargetExplosionResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Slice")))) {
		DmgAmount *= 1.0f - TargetSliceResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Poison")))) {
		DmgAmount *= 1.0f - TargetPoisonResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Water")))) {
		DmgAmount *= 1.0f - TargetWaterResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Fire")))) {
		DmgAmount *= 1.0f - TargetFireResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Air")))) {
		DmgAmount *= 1.0f - TargetAirResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Earth")))) {
		DmgAmount *= 1.0f - TargetEarthResistance / 100.0f;
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Damage.Electric")))) {
		DmgAmount *= 1.0f - TargetElectricResistance / 100.0f;
	}
#pragma endregion

	const float DmgToDefence = FMath::Min(DmgAmount, TargetDefence);
	const float DmgToHp = DmgAmount - DmgToDefence;

	OutExecutionOutput.AddOutputModifier(
		FGameplayModifierEvaluatedData(GetDamageCapture().DefenceProperty, EGameplayModOp::Additive, -DmgToDefence));
	OutExecutionOutput.AddOutputModifier(
		FGameplayModifierEvaluatedData(GetDamageCapture().HealthProperty, EGameplayModOp::Additive, -DmgToHp));
}

