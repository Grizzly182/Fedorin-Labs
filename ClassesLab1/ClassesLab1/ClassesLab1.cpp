#include <Windows.h>
#include <iostream>
#include <string>
#include "LongLong.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LongLong first = LongLong(-44);
	LongLong second = LongLong(-11);

	first.division(LongLong(0));
	first.Display();

	first.multi(LongLong(0));
	first.Display();

	first.plus(LongLong(-35));
	first.Display();

	first.minus(LongLong(5));
	first.Display();
}