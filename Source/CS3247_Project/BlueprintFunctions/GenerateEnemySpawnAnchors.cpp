// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateEnemySpawnAnchors.h"
#include "../Characters/BasicCharacter.h"

TArray<FVector> UGenerateEnemySpawnAnchors::GenerateAnchorsBasedOnPlayer(ABasicCharacter* Player, float ForwardDistance, float LateralOffset) {
    TArray<FVector> Anchors;

    // Get player's location and orientation
    const FVector PlayerLocation = Player->GetActorLocation();
    const FVector ForwardVector = Player->GetActorForwardVector();
    const FVector RightVector = Player->GetActorRightVector();

    // Compute two anchor points:
    // One to the right and one to the left relative to the player's forward direction.
    const FVector Anchor1 = PlayerLocation + (ForwardVector * ForwardDistance) + (RightVector * LateralOffset);
    const FVector Anchor2 = PlayerLocation + (ForwardVector * ForwardDistance) - (RightVector * LateralOffset);

    Anchors.Add(Anchor1);
    Anchors.Add(Anchor2);
    return Anchors;
}
