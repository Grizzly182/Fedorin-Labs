#include "Rational.h"
#include <iostream>

Rational::Rational(LongLong num = LongLong(1), LongLong denom = LongLong(1))
{
	this->numerator = num;
	if (denom.getSingleNumber() == 0) {
		std::cout << "на ноль делить нельзя" << std::endl;
	}
	this->denominator = denom;
}

void Rational::reduce()
{
	for (int i = 999; i >= 1; i--) {
		if (this->getNumerator() % i == 0 && this->getDenominator() % i == 0) {
			this->denominator.division(LongLong(i));
			this->numerator.division(LongLong(i));
		}
	}
}

long Rational::gcd(long a, long b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

long Rational::getLeastCommonDenominator(Rational other)
{
	long num = this->getDenominator();
	long denom = other.getDenominator();
	return (num * denom) / gcd(num, denom);
}

Rational Rational::sum(Rational other)
{
	setCommonDenominatorAndMultiplyNumerators(other);
	LongLong num = this->getNumerator() + other.getNumerator();
	LongLong denom = this->getDenominator();

	return Rational(num, denom);
}

Rational Rational::min(Rational other)
{
	setCommonDenominatorAndMultiplyNumerators(other);
	LongLong num = this->getNumerator() - other.getNumerator();
	LongLong denom = this->getDenominator();

	return Rational(num, denom);
}

Rational Rational::div(Rational other)
{
	if (other.getNumerator() == 0) {
		std::cout << "Числитель второй дроби не может быть равен нулю!" << std::endl;
		return Rational(this->getNumerator(), this->getDenominator());
	}
	LongLong num = this->getNumerator() * other.getDenominator();
	LongLong denom = this->getDenominator() * other.getNumerator();

	return Rational(num, denom);
}

Rational Rational::mul(Rational other)
{
	LongLong num = this->getNumerator() * other.getNumerator();
	LongLong denom = this->getDenominator() * other.getDenominator();

	return Rational(num, denom);
}

bool Rational::equals(Rational other)
{
	return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator();
}

long Rational::getNumerator()
{
	return this->numerator.getSingleNumber();
}

long Rational::getDenominator()
{
	return this->denominator.getSingleNumber();
}

void Rational::setNumerator(LongLong value)
{
	this->numerator = value;
}

void Rational::setDenominator(LongLong value)
{
	this->denominator = value;
}

void Rational::setCommonDenominatorAndMultiplyNumerators(Rational& other)
{
	long commonDenom = getLeastCommonDenominator(other);

	long num1 = (commonDenom / this->getDenominator());
	long num2 = (commonDenom / other.getDenominator());

	this->setNumerator(LongLong(this->getNumerator() * num1));
	other.setNumerator(LongLong(other.getNumerator() * num2));

	this->setDenominator(LongLong(commonDenom));
	other.setDenominator(LongLong(commonDenom));
}

void Rational::display()
{
	this->reduce();
	std::cout << this->numerator.getSingleNumber() << '/' << this->denominator.getSingleNumber() << std::endl;
}