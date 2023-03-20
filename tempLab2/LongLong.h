#pragma once
class LongLong {
private:
	unsigned long FirstPart = 0;
	unsigned long SecondPart = 0;
public:
	LongLong(long num1, long num2); //Done
	void plus(LongLong num);//Done
	void minus(LongLong num);//Done
	void multi(LongLong num);//Done
	void division(LongLong num);//Done
	bool equals(LongLong other);
	void Display();//Done
	unsigned long getPositivePart();//Done
	unsigned long getNegativePart();//Done
	long getSingleNumber();//Done
};