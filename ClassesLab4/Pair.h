#pragma once
#include <iostream>

class Pair {
private:
	int firstPart;
	int secondPart;
public:
	Pair(int first, int second);
	Pair sum(Pair num1, Pair num2);
	int getFirstPart();
	int getSecondPart();
	void setFirstPart(int num);
	void setSecondPart(int num);
	void display();
};

inline Pair::Pair(int first, int second) {
	this->firstPart = first;
	this->secondPart = second;
}

inline Pair Pair::sum(Pair num1, Pair num2)
{
	int a = num1.getFirstPart();
	int b = num1.getSecondPart();
	int c = num2.getFirstPart();
	int d = num2.getSecondPart();
	return Pair(a + b, c + d);
}

inline int Pair::getFirstPart()
{
	return this->firstPart;
}

inline int Pair::getSecondPart()
{
	return this->secondPart;
}

inline void Pair::setFirstPart(int num)
{
	this->firstPart = num;
}

inline void Pair::setSecondPart(int num)
{
	this->secondPart = num;
}

inline void Pair::display()
{
	std::cout << this->firstPart << ' ' << "|" << ' ' << this->secondPart << std::endl;
}
