// Fill out your copyright notice in the Description page of Project Settings.


#include "Text.h"
FString UText::Bf(const FString& Str) {
	return "<bf>" + Str + "</>";
}

FString UText::It(const FString& Str) {
	return "<it>" + Str + "</>";
}

FString UText::BfIt(const FString& Str) {
	return "<bfit>" + Str + "</>";
}

FString UText::Rm(const FString& Str) {
	return "<rm>" + Str + "</>";
}

FString UText::Red(const FString& Str) {
	return "<red>" + Str + "</>";
}

FString UText::Green(const FString& Str) {
	return "<green>" + Str + "</>";
}
