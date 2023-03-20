#include "LongLong.h";
#include "Rational.h";
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << endl << "Сложение:" << endl;
	Rational rat = Rational(1, 6);
	Rational rat2 = Rational(7, 15);
	rat.setCommonDenominatorAndMultiplyNumerators(rat2);
	Rational result = rat.sum(rat2);
	result.display();

	cout << endl << "Вычитание:" << endl;
	rat = Rational(6, 7);
	rat2 = Rational(9, 14);
	rat.setCommonDenominatorAndMultiplyNumerators(rat2);
	result = rat.min(rat2);
	result.display();

	cout << endl << "Умножение:" << endl;
	rat = Rational(2, 5);
	rat2 = Rational(3, 4);
	result = rat.mul(rat2);
	result.display();

	cout << endl << "Деление:" << endl;
	rat = Rational(2, 5);
	rat2 = Rational(3, 4);
	result = rat.div(rat2);
	result.display();
}