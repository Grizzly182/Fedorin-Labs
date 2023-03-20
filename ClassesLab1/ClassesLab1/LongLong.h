#pragma once
class LongLong {
private:
	unsigned long PositivePart = 0;
	unsigned long NegativePart = 0;
public:
	LongLong(long num = 0); //Done
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