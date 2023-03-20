#pragma once
#include "LongLong.h";

class Rational {
private:
	LongLong numeratorAndDenominator;
	void reduce();
	long gcd(long a, long b);
	long getLeastCommonDenominator(Rational other);
public:
	Rational(long num, long denom);
	Rational sum(Rational other);
	Rational min(Rational other);
	Rational div(Rational other);
	Rational mul(Rational other);
	bool equals(Rational other);
	long getNumerator();
	long getDenominator();
	void setNumerator(long value);
	void setDenominator(long value);
	void setCommonDenominatorAndMultiplyNumerators(Rational& other);
	void display();
};