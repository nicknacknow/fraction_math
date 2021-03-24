#include <Windows.h>
#include <iostream>

#include "Fraction.h"

int main() {
	printf("init\n");

	Fraction f(5, 2);
	printf("%s\n", (f / Fraction(5,2)).string());
	printf("%d\n", 6 % 2);

	std::cin.get();
	return 0;
}