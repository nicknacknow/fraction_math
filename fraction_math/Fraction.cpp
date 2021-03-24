#include "Fraction.h"

Fraction::Fraction(NUMBER n, NUMBER d) {
	this->numerator = n;
	this->denominator = d;
}

Fraction Fraction::operator+(Fraction f) {
	return this->add(f);
}
Fraction Fraction::operator+(NUMBER n) {
	return this->add(Fraction(n, 1));
}
Fraction Fraction::operator-(Fraction f) {
	return this->sub(f);
}
Fraction Fraction::operator-(NUMBER n) {
	return this->sub(Fraction(n, 1));
}
Fraction Fraction::operator*(Fraction f) {
	return this->mul(f);
}
Fraction Fraction::operator*(NUMBER n) {
	return this->mul(Fraction(n, 1));
}
Fraction Fraction::operator/(Fraction f) {
	return this->div(f);
}
Fraction Fraction::operator/(NUMBER n) {
	return this->div(Fraction(n, 1));
}

Fraction Fraction::add(Fraction f) {
	NUMBER denom = this->get_denominator() * f.get_denominator();
	NUMBER num1 = this->get_numerator() * f.get_denominator();
	NUMBER num2 = f.get_numerator() * this->get_denominator();
	return Fraction(num1 + num2, denom);
}
Fraction Fraction::sub(Fraction f) {
	NUMBER denom = this->get_denominator() * f.get_denominator();
	NUMBER num1 = this->get_numerator() * f.get_denominator();
	NUMBER num2 = f.get_numerator() * this->get_denominator();
	return Fraction(num1 - num2, denom);
}
Fraction Fraction::mul(Fraction f) {
	//printf("NUM: %d * %d = %d\n", this->get_numerator(), f.get_numerator(), this->get_numerator() * f.get_numerator());
	// printf("DEN: %d * %d = %d\n", this->get_denominator(), f.get_denominator(), this->get_denominator() * f.get_denominator());
	return Fraction(this->get_numerator() * f.get_numerator(), this->get_denominator() * f.get_denominator());
}
Fraction Fraction::div(Fraction f) {
	return this->mul(f.inverse());
}

Fraction Fraction::inverse() {
	return Fraction(this->get_denominator(), this->get_numerator());
}

NUMBER Fraction::get_numerator() {
	return this->numerator;
}
NUMBER Fraction::get_denominator() {
	return this->denominator;
}

char* Fraction::string() {
	NUMBER rnum = 0 ? this->get_numerator() % this->get_denominator() : this->get_numerator();
	NUMBER rext = rnum ? (this->get_numerator() - rnum) / this->get_denominator() : this->get_numerator();

	char buff[1024];
	sprintf(buff, "%d - (%d | %d)", rext, rnum, this->get_denominator());
	return buff;
}