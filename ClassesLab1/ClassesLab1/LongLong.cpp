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

// ×ÒÎ-ÒÎ ÒÓÒ ÑÒÐÀÍÍÎÅ
unsigned long LongLong::getSingleNumber()
{
	return this->NegativePart + this->PositivePart;
}