// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowControl.h"
TArray<TObjectPtr<UCardEffect>> UFlowControl::Combine(UCardEffect* Left, UCardEffect* Right) {
	return {Left, Right};
}
