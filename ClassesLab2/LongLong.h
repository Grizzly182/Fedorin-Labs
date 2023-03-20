#pragma once
class LongLong {
private:
	long FirstPart = 0;
	long SecondPart = 0;
public:
	LongLong(long num1 = 0, long num2 = 0); //Done
	void plus(LongLong num);//Done
	void minus(LongLong num);//Done
	void multi(LongLong num);//Done
	void division(LongLong num);//Done
	bool equals(LongLong other);//Done
	void Display();//Done
	long getPositivePart();//Done
	long getNegativePart();//Done
	long getSingleNumber();//Done
	void setFirstPart(long num);//Done
	void setSecondPart(long num);//Done
};