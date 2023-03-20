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
#pragma region plus
void LongLong::plus(LongLong num)
{
	long number = num.getSingleNumber();
	if (this->NegativePart > 0 && number < 0) {
		this->NegativePart += abs(number);
	}
	else if (this->NegativePart > 0 && number > 0 && number < this->NegativePart) {
		this->NegativePart -= abs(number);
	}
	else if (this->NegativePart > 0 && number > 0) {
		unsigned long remaining = abs(number) - this->NegativePart;
		this->NegativePart = 0;
		this->PositivePart = remaining;
	}
	else if (this->PositivePart > 0 && number < 0 && abs(number) > this->PositivePart) {
		unsigned long remaining = abs(number) - this->PositivePart;
		this->PositivePart = 0;
		this->NegativePart = remaining;
	}
	else if (this->PositivePart < abs(number) && number < 0) {
		unsigned long remaining = abs(number) - this->PositivePart;
		this->PositivePart = 0;
		this->NegativePart = remaining;
	}
	else if (this->PositivePart < abs(number) && number > 0) {
		this->PositivePart += number;
	}
	else {
		this->PositivePart += number;
	}
}
#pragma endregion
#pragma region minus
void LongLong::minus(LongLong num)
{
	long number = num.getSingleNumber();
	num.getNegativePart() > 0 ? number = 0 - number : number = number;
	if (this->NegativePart > 0 && number < 0) {
		unsigned long remaining = abs(number) - this->NegativePart;
		this->NegativePart = 0;
		this->PositivePart = remaining;
	}
	else if (this->NegativePart > 0) {
		this->NegativePart += number;
	}
	else if (this->PositivePart < number && number < 0) {
		this->PositivePart += abs(number);
	}
	else if (this->PositivePart < number && number > 0) {
		unsigned long remaining = abs(number) - this->PositivePart;
		this->PositivePart = 0;
		this->NegativePart = remaining;
	}
	else if (this->PositivePart > 0 && number < 0) {
		this->NegativePart -= number;
	}
	else {
		this->PositivePart -= number;
	}
}
#pragma endregion
#pragma region multi
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
#pragma endregion
#pragma region division
void LongLong::division(LongLong num)
{
	if (num.getSingleNumber() == 0) {
		std::cout << "Делить на ноль нельзя!" << std::endl;
		return;
	}

	long first;
	long second;

	this->getNegativePart() > 0 ? first = 0 - this->NegativePart : first = this->PositivePart;
	num.getNegativePart() > 0 ? second = 0 - num.getNegativePart() : second = num.getPositivePart();

	long result = first / second;
	if (result > 0) {
		this->PositivePart = result;
		this->NegativePart = 0;
	}
	else {
		this->NegativePart = abs(result);
		this->PositivePart = 0;
	}
}
#pragma endregion
void LongLong::Display()
{
	if (this->NegativePart > 0) {
		std::cout << '-' << this->NegativePart << std::endl;
	}
	else {
		std::cout << this->PositivePart << std::endl;
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

long LongLong::getSingleNumber()
{
	if (this->getNegativePart() > 0) {
		return 0 - this->getNegativePart();
	}
	return this->getPositivePart();
}