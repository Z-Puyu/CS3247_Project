#include "DamageData.h"

#include "CS3247_Project/UI/Texts/Text.h"

FString FDamageData::ToString() const {
	const int Dmg = FMath::CeilToInt(this->DamageValue);
	return FString::Printf(TEXT("%d %s damage"), Dmg, *this->DamageType.ToString());
}

FString FDamageData::ToRichText() const {
	const int Dmg = FMath::CeilToInt(this->DamageValue);
	const FString DmgNum = UText::Red(FString::Printf(TEXT("%d"), Dmg));
	const FString DmgType = UText::BfIt(FString::Printf(TEXT("%s"), *this->DamageType.ToString()));
	return FString::Printf(TEXT("Deals %s %s damage"), *DmgNum, *DmgType);
}

FDamageData FDamageData::operator+(const double Offset) const {
	return FDamageData(this->DamageType, this->DamageValue + Offset);
}

FDamageData FDamageData::operator-(const double Offset) const {
	return *this + (-Offset);
}

FDamageData FDamageData::operator*(const double Factor) const {
	return FDamageData(this->DamageType, this->DamageValue * Factor);
}

FDamageData FDamageData::operator+=(const double Value) const {
	return *this + Value;
}

FDamageData FDamageData::operator-=(const double Value) const {
	return *this - Value;
}

FDamageData FDamageData::operator*=(const double Value) const {
	return *this * Value;
}

bool FDamageData::operator>(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) > Value;
}

bool FDamageData::operator<(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) < Value;
}

bool FDamageData::operator==(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) == Value;
}

bool FDamageData::operator!=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) != Value;
}

bool FDamageData::operator>=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) >= Value;
}

bool FDamageData::operator<=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) <= Value;
}

