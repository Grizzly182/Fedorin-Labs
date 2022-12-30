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

	LongLong ok = LongLong(-44);
	LongLong second = LongLong(-11);

	ok.division(second);
	ok.Display();
}