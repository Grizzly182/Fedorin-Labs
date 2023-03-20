#include "LongLong.h";
#include "LongLong.cpp";
#include "Rational.h";
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << endl << "Сложение:" << endl;
	Rational rat = Rational(LongLong(1), LongLong(6));
	Rational rat2 = Rational(LongLong(7), LongLong(15));
	rat.setCommonDenominatorAndMultiplyNumerators(rat2);
	Rational result = rat.sum(rat2);
	result.display();

	cout << endl << "Вычитание:" << endl;
	rat = Rational(LongLong(6), LongLong(7));
	rat2 = Rational(LongLong(9), LongLong(14));
	rat.setCommonDenominatorAndMultiplyNumerators(rat2);
	result = rat.min(rat2);
	result.display();

	cout << endl << "Умножение:" << endl;
	rat = Rational(LongLong(2), LongLong(5));
	rat2 = Rational(LongLong(3), LongLong(4));
	result = rat.mul(rat2);
	result.display();

	cout << endl << "Деление:" << endl;
	rat = Rational(LongLong(2), LongLong(5));
	rat2 = Rational(LongLong(3), LongLong(4));
	result = rat.div(rat2);
	result.display();
}