#include "LongLong.h"
#include <iostream>

LongLong::LongLong(long num)
{
	if (num < 0) {
		this->NegativePart = abs(num);
		this->PositivePart = 0;
	}
	else {
		this->NegativePart = 0;
		this->PositivePart = num;
	}
}

void LongLong::plus(LongLong num)
{
}

void LongLong::minus(LongLong num)
{
	unsigned long number = num.getSingleNumber();
	if (this->NegativePart > 0) {
		this->NegativePart += number;
	}
	else if (this->PositivePart < number) {
		unsigned long remaining = number - this->PositivePart;
		this->PositivePart = 0;
		this->NegativePart = remaining;
	}
	else {
		this->PositivePart -= number;
	}
}

void LongLong::multi(LongLong num)
{
	long first;
	long second;

	this->getNegativePart() > 0 ? first = 0 - this->NegativePart : first = this->PositivePart;
	num.getNegativePart() > 0 ? second = 0 - num.getNegativePart() : second = num.getPositivePart();

	long result = first * second;
	if (result > 0) {
		this->PositivePart = result;
		this->NegativePart = 0;
	}
	else {
		this->NegativePart = abs(result);
		this->PositivePart = 0;
	}
}

void LongLong::division(LongLong num)
{
}

void LongLong::ShowNumber()
{
	if (this->NegativePart > 0) {
		std::cout << '-' << this->NegativePart;
	}
	else {
		std::cout << this->PositivePart;
	}
}

unsigned long LongLong::getPositivePart()
{
	return this->PositivePart;
}

unsigned long LongLong::getNegativePart()
{
	return this->NegativePart;
}

// ×ÒÎ-ÒÎ ÑÒÐÀÍÍÎÅ
unsigned long LongLong::getSingleNumber()
{
	return this->PositivePart + this->NegativePart;
}