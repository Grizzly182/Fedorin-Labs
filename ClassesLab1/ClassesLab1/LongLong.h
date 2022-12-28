#pragma once

class LongLong {
protected:
	unsigned long PositivePart = 0;
	unsigned long NegativePart = 0;
public:
	LongLong(long num); //Done
	void plus(LongLong num);//
	void minus(LongLong num);//Done
	void multi(LongLong num);//
	void division(LongLong num);//
	void ShowNumber();//Done
	unsigned long getSingleNumber();//Done
};