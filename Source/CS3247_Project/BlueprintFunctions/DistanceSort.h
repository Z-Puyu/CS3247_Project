// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DistanceSort.generated.h"

/**
 * 
 */

UCLASS()
class CS3247_PROJECT_API UDistanceSort : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

 public:

     UFUNCTION(BlueprintCallable, Category = "Utilities|Sorting")
     static void SortFVectorsByDistance(
         UPARAM(ref) TArray<FVector>& InOutArray,
         FVector ReferenceLoc,
         bool bDescending
     );
};
