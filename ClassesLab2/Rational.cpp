#include "Rational.h"
#include <iostream>

Rational::Rational(long num, long denom)
{
	this->numeratorAndDenominator.setFirstPart(num);
	if (denom == 0) {
		std::cout << "на ноль делить нельзя" << std::endl;
	}
	this->numeratorAndDenominator.setSecondPart(denom);
}

void Rational::reduce()
{
	for (int i = 999; i >= 1; i--) {
		if (this->getNumerator() % i == 0 && this->getDenominator() % i == 0) {
			this->numeratorAndDenominator.setFirstPart(this->getNumerator() / i);
			this->numeratorAndDenominator.setSecondPart(this->getDenominator() / i);
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
	long num = this->getNumerator() + other.getNumerator();
	long denom = this->getDenominator();

	return Rational(num, denom);
}

Rational Rational::min(Rational other)
{
	setCommonDenominatorAndMultiplyNumerators(other);
	long num = this->getNumerator() - other.getNumerator();
	long denom = this->getDenominator();

	return Rational(num, denom);
}

Rational Rational::div(Rational other)
{
	if (other.getNumerator() == 0) {
		std::cout << "Числитель второй дроби не может быть равен нулю!" << std::endl;
		return Rational(this->getNumerator(), this->getDenominator());
	}
	long num = this->getNumerator() * other.getDenominator();
	long denom = this->getDenominator() * other.getNumerator();

	return Rational(num, denom);
}

Rational Rational::mul(Rational other)
{
	long num = this->getNumerator() * other.getNumerator();
	long denom = this->getDenominator() * other.getDenominator();

	return Rational(num, denom);
}

bool Rational::equals(Rational other)
{
	return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator();
}

long Rational::getNumerator()
{
	return this->numeratorAndDenominator.getPositivePart();
}

long Rational::getDenominator()
{
	return this->numeratorAndDenominator.getNegativePart();
}

void Rational::setNumerator(long value)
{
	this->numeratorAndDenominator.setFirstPart(value);
}

void Rational::setDenominator(long value)
{
	this->numeratorAndDenominator.setSecondPart(value);
}

void Rational::setCommonDenominatorAndMultiplyNumerators(Rational& other)
{
	long commonDenom = getLeastCommonDenominator(other);

	long num1 = (commonDenom / this->getDenominator());
	long num2 = (commonDenom / other.getDenominator());

	this->setNumerator(this->getNumerator() * num1);
	other.setNumerator(other.getNumerator() * num2);

	this->setDenominator(commonDenom);
	other.setDenominator(commonDenom);
}

void Rational::display()
{
	this->reduce();
	std::cout << this->getNumerator() << '/' << this->getDenominator() << std::endl;
}