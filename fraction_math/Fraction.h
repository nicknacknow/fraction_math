#pragma once
#include <Windows.h>
#include <iostream>

typedef int NUMBER;

class Fraction {
public:
	Fraction(NUMBER n, NUMBER d);
	Fraction operator+(Fraction f);
	Fraction operator+(NUMBER n);
	Fraction operator-(Fraction f);
	Fraction operator-(NUMBER n);
	Fraction operator*(Fraction f);
	Fraction operator*(NUMBER n);
	Fraction operator/(Fraction f);
	Fraction operator/(NUMBER n);

	Fraction add(Fraction f);
	Fraction sub(Fraction f);
	Fraction mul(Fraction f);
	Fraction div(Fraction f);

	Fraction inverse();

	NUMBER get_numerator();
	NUMBER get_denominator();

	char* string();
private:
	NUMBER numerator, denominator;
};