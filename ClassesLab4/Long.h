#pragma once
#include "Pair.h"
#include <iostream>
class Long : public Pair {
public:
	Long(int first, int second) : Pair(first, second) {};
	void sum(Long num);
	void minus(Long num);
	void mul(Long num);
	bool detectOverflow(Long num);
};