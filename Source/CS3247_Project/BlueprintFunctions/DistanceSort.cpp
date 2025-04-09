// Fill out your copyright notice in the Description page of Project Settings.


#include "DistanceSort.h"

//Pass a copy of the actor array to sort and the "central" actor to measure distance from, output a reference to the sorted struct array created in the function

void UDistanceSort::SortFVectorsByDistance(
    TArray<FVector>& InOutArray,
    FVector ReferenceLoc,
    bool bDescending
)
{
    const int32 N = InOutArray.Num();
    if (N <= 1)
    {
        // No need to sort if array is empty or has one element
        return;
    }

    bool bSwapped = false;

    // Basic bubble sort demonstration
    for (int32 i = 0; i < N - 1; i++)
    {
        bSwapped = false;

        for (int32 j = 0; j < N - i - 1; j++)
        {
            // Compute squared distance to avoid sqrt for performance
            float DistA = FVector::DistSquared(InOutArray[j], ReferenceLoc);
            float DistB = FVector::DistSquared(InOutArray[j + 1], ReferenceLoc);

            bool bShouldSwap = false;

            if (bDescending)
            {
                // Descending: if DistA < DistB, swap
                bShouldSwap = (DistA < DistB);
            }
            else
            {
                // Ascending: if DistA > DistB, swap
                bShouldSwap = (DistA > DistB);
            }

            if (bShouldSwap)
            {
                FVector Temp = InOutArray[j];
                InOutArray[j] = InOutArray[j + 1];
                InOutArray[j + 1] = Temp;
                bSwapped = true;
            }
        }

        if (!bSwapped)
        {
            // Already sorted, break early
            break;
        }
    }
}