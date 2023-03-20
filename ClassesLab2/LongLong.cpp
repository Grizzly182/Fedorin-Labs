#include "LongLong.h"
#include <iostream>

LongLong::LongLong(long num1, long num2)
{
	this->FirstPart = num1;
	this->SecondPart = num2;
}
#pragma region plus
void LongLong::plus(LongLong num)
{
	long number = num.getSingleNumber();
	if (this->SecondPart > 0 && number < 0) {
		this->SecondPart += abs(number);
	}
	else if (this->SecondPart > 0 && number > 0 && number < this->SecondPart) {
		this->SecondPart -= abs(number);
	}
	else if (this->SecondPart > 0 && number > 0) {
		unsigned long remaining = abs(number) - this->SecondPart;
		this->SecondPart = 0;
		this->FirstPart = remaining;
	}
	else if (this->FirstPart > 0 && number < 0 && abs(number) > this->FirstPart) {
		unsigned long remaining = abs(number) - this->FirstPart;
		this->FirstPart = 0;
		this->SecondPart = remaining;
	}
	else if (this->FirstPart < abs(number) && number < 0) {
		unsigned long remaining = abs(number) - this->FirstPart;
		this->FirstPart = 0;
		this->SecondPart = remaining;
	}
	else if (this->FirstPart < abs(number) && number > 0) {
		this->FirstPart += number;
	}
	else {
		this->FirstPart += number;
	}
}
#pragma endregion
#pragma region minus
void LongLong::minus(LongLong num)
{
	long number = num.getSingleNumber();
	num.getNegativePart() > 0 ? number = 0 - number : number = number;
	if (this->SecondPart > 0 && number < 0) {
		unsigned long remaining = abs(number) - this->SecondPart;
		this->SecondPart = 0;
		this->FirstPart = remaining;
	}
	else if (this->SecondPart > 0) {
		this->SecondPart += number;
	}
	else if (this->FirstPart < number && number < 0) {
		this->FirstPart += abs(number);
	}
	else if (this->FirstPart < number && number > 0) {
		unsigned long remaining = abs(number) - this->FirstPart;
		this->FirstPart = 0;
		this->SecondPart = remaining;
	}
	else if (this->FirstPart > 0 && number < 0) {
		this->SecondPart -= number;
	}
	else {
		this->FirstPart -= number;
	}
}
#pragma endregion
#pragma region multi
void LongLong::multi(LongLong num)
{
	long first;
	long second;

	this->getNegativePart() > 0 ? first = 0 - this->SecondPart : first = this->FirstPart;
	num.getNegativePart() > 0 ? second = 0 - num.getNegativePart() : second = num.getPositivePart();

	long result = first * second;
	if (result > 0) {
		this->FirstPart = result;
		this->SecondPart = 0;
	}
	else {
		this->SecondPart = abs(result);
		this->FirstPart = 0;
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

	this->getNegativePart() > 0 ? first = 0 - this->SecondPart : first = this->FirstPart;
	num.getNegativePart() > 0 ? second = 0 - num.getNegativePart() : second = num.getPositivePart();

	long result = first / second;
	if (result > 0) {
		this->FirstPart = result;
		this->SecondPart = 0;
	}
	else {
		this->SecondPart = abs(result);
		this->FirstPart = 0;
	}
}
#pragma endregion

bool LongLong::equals(LongLong other) {
	return this->getSingleNumber() == other.getSingleNumber();
}

void LongLong::Display()
{
	if (this->SecondPart > 0) {
		std::cout << '-' << this->SecondPart << std::endl;
	}
	else {
		std::cout << this->FirstPart << std::endl;
	}
}

long LongLong::getPositivePart()
{
	return this->FirstPart;
}

long LongLong::getNegativePart()
{
	return this->SecondPart;
}

long LongLong::getSingleNumber()
{
	if (this->getNegativePart() > 0) {
		return 0 - this->getNegativePart();
	}
	return this->getPositivePart();
}

void LongLong::setFirstPart(long num)
{
	this->FirstPart = num;
}

void LongLong::setSecondPart(long num)
{
	this->SecondPart = num;
}