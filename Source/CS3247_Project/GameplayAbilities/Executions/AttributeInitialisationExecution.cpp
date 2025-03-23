// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeInitialisationExecution.h"
#include "../AttributeSet/BasicAttributeSet.h"

struct FInitCapture {
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxHealth);
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

	FInitCapture() {
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBasicAttributeSet, MaxHealth, Target, false);
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

static FInitCapture& GetInitCapture() {
	static FInitCapture InitCapture;
	return InitCapture;
}


UAttributeInitialisationExecution::UAttributeInitialisationExecution() {
	this->RelevantAttributesToCapture.Add(GetInitCapture().MaxHealthDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().HealthDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().DefenceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().ProjectileResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().ExplosionResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().SliceResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().PoisonResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().WaterResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().FireResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().AirResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().EarthResistanceDef);
	this->RelevantAttributesToCapture.Add(GetInitCapture().ElectricResistanceDef);
}

void UAttributeInitialisationExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
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
	float TargetMaxHealth = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().MaxHealthDef, EvalParams, TargetMaxHealth);
	float TargetHealth = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().HealthDef, EvalParams, TargetHealth);
	float TargetDefence = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().DefenceDef, EvalParams, TargetDefence);
	float TargetProjectileResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().ProjectileResistanceDef, EvalParams, TargetProjectileResistance);
	float TargetExplosionResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().ExplosionResistanceDef, EvalParams, TargetExplosionResistance);
	float TargetSliceResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().SliceResistanceDef, EvalParams, TargetSliceResistance);
	float TargetPoisonResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().PoisonResistanceDef, EvalParams, TargetPoisonResistance);
	float TargetWaterResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().WaterResistanceDef, EvalParams, TargetWaterResistance);
	float TargetFireResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().FireResistanceDef, EvalParams, TargetFireResistance);
	float TargetAirResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().AirResistanceDef, EvalParams, TargetAirResistance);
	float TargetEarthResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().EarthResistanceDef, EvalParams, TargetEarthResistance);
	float TargetElectricResistance = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetInitCapture().ElectricResistanceDef, EvalParams, TargetElectricResistance);
#pragma endregion

	const FGameplayTag DataTag = FGameplayTag::RequestGameplayTag(FName("GameplayEffect.AttributeInitialisation"));
	const float InitValue = Spec.GetSetByCallerMagnitude(DataTag);
	
	const FGameplayTagContainer& AssetTags = Spec.GetDynamicAssetTags();
#pragma region Initialise Attributes
	if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.MaxHealth")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().MaxHealthProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.Health")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().HealthProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.Defence")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().DefenceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.ProjectileResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().ProjectileResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.ExplosionResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().ExplosionResistanceProperty, EGameplayModOp::Override, InitValue)); 
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.SliceResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().SliceResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.PoisonResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().PoisonResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.WaterResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().WaterResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.FireResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().FireResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.AirResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().AirResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.EarthResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().EarthResistanceProperty, EGameplayModOp::Override, InitValue));
	} else if (AssetTags.HasTagExact(FGameplayTag::RequestGameplayTag(FName("GameData.Attribute.ElectricResistance")))) {
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(GetInitCapture().ElectricResistanceProperty, EGameplayModOp::Override, InitValue));
	}
#pragma endregion
}

