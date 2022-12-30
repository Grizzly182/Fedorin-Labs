#pragma once

class LongLong {
protected:
	unsigned long PositivePart = 0;
	unsigned long NegativePart = 0;
public:
	LongLong(long num); //Done
	void plus(LongLong num);//Done
	void minus(LongLong num);//Done
	void multi(LongLong num);//Done
	void division(LongLong num);//
	void Display();//Done
	unsigned long getPositivePart();//Done
	unsigned long getNegativePart();//Done
	unsigned long getSingleNumber();//Done
};